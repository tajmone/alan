/*----------------------------------------------------------------------*\

  emit.c


\*---------------------------------------------------------------------*/

#include "sysdep.h"
#include "types.h"
#include "util.h"
#ifdef __POSIX__
#include <sys/time.h>
#else
#include <sys/timeb.h>
#endif

#ifdef __mac__
#include "Files.h"
#include "Strings.h"
#endif

#ifdef __amiga__
/* On the Amiga we can't include alan.h since it includes the lst.h (List type)
   and this conflicts with the exec/lists.h. So we explicitly declare needed things */
 
extern char advnam[];		/* The name of the adventure */
extern void *allocate(int len);

#else
#include "alan.h"
#endif


#include "../interpreter/acode.h"
#include "alan.version.h"

#include "emit.h"


/* PUBLIC DATA */
ACodeHeader acodeHeader;


static FILE *acdfil;
static Aword *emitBuffer;
static Aword eBuffer[BLOCKLEN];

static Aaddr pc;
static Aword crc;


/*----------------------------------------------------------------------*/
static void buffer(Aword w)
{
  crc += w&0xff;			/* Check sum calculation */
  crc += (w>>8)&((Aword)0xff);
  crc += (w>>16)&((Aword)0xff);
  crc += (w>>24)&((Aword)0xff);

  emitBuffer[pc++%BLOCKLEN] = w;
  if (pc%BLOCKLEN == 0)
    fwrite(emitBuffer, BLOCKSIZE, 1, acdfil);
}

/* First attempt at trying a generic endian macro... */
#define NATIVE(w)   \
    ( (((Aword)((w)[3])      ) & 0x000000ff)    \
    | (((Aword)((w)[2]) <<  8) & 0x0000ff00)    \
    | (((Aword)((w)[1]) << 16) & 0x00ff0000)    \
    | (((Aword)((w)[0]) << 24) & 0xff000000))


/*----------------------------------------------------------------------*/
static Aword reversed(Aword w)	/* IN - The ACODE word to swap bytes in */
{
  Aword s;			/* The swapped ACODE word */
  char *wp, *sp;
  int i;
  
  wp = (char *) &w;
  sp = (char *) &s;

  for (i = 0; i < sizeof(Aword); i++)
    sp[sizeof(Aword)-1 - i] = wp[i];

  return (s);
}

/*======================================================================*/
Aword nextEmitAddress(void)
{
  return(pc);
}

/*======================================================================*/
void emit(Aword c)		/* IN - Constant to emit */
{
  if (littleEndian())
      buffer(reversed(c));
  else
      buffer(c);
}


/*======================================================================*/
void emitEntry(void *address, int noOfBytes)
{
  int i;
  Aword *words = address;

  /* Should never start an entry with an EOF word since the reversal process
     depends on it for terminating. */
  if (words[0] == EOF) SYSERR("First word of an entry should never be EOF");

  if (noOfBytes%sizeof(Aword) != 0) SYSERR("Emitting unaligned data");

  for (i = 0; i < noOfBytes/sizeof(Aword); i++)
    if (littleEndian())
      buffer(reversed(words[i]));
    else
      buffer(words[i]);
}


/*======================================================================*/
void emitN(void *address, int noOfWords) /* IN - Constant to emit */
{
  int i;
  Aword *words = address;

  for (i = 0; i < noOfWords; i++)
    if (littleEndian())
      buffer(reversed(words[i]));
    else
      buffer(words[i]);
}


/*======================================================================

  emitString()

  Function to emit strings to the ACD file. Note that strings are
  *always* stored with their first character at the lowest address so
  we have to be careful how we do this.

  On all machines strings can be copied word by word, except if they are
  not aligned on words. In this case we have to read them byte by byte and
  create the words. And in this case of course on reversed architectures
  the word must be reversed before emitting it.

*/
void emitString(char *str)
{
  int i;
  char *copy;

  copy = allocate(strlen(str)+4);
  memset(copy, 0, strlen(str)+4);
  toIso(copy, str, charset);

#ifdef WORDADDRESS
  {
    Aword w;

    for (i = 0; i < strlen(copy) + 1; i = i+4) {
      w =  (unsigned long)((unsigned char)copy[i])<<24;
      w += (unsigned long)((unsigned char)copy[i+1])<<16;
      w += (unsigned long)((unsigned char)copy[i+2])<<8;
      w += (unsigned long)((unsigned char)copy[i+3]);
      if (littleEndian())
	buffer(reversed(w));
      else
	buffer(w);
    }
  }
#else
  {
    Aword *w;
    int len = strlen(copy) + 1;

    for (i = 0; i < len; i = i+4) {
      w =  (Aword *)&copy[i];
      buffer(*w);
    }
  }
#endif
  free(copy);
}


/*======================================================================*/
void emitVariable(Aword var)
{
  emit(((Aword)C_CURVAR<<28)|((Aword)var&0x0fffffff));
}


/*======================================================================*/
void emitConstant(Aword arg)
{
  emit(((Aword)C_CONST<<28)|((Aword)arg&0x0fffffff));
}


/*======================================================================*/
void emit0(Aword op)
{
  emit(INSTRUCTION(op));
}


/*======================================================================*/
void emit1(Aword op, Aword arg1)
{
  emitConstant(arg1);
  emit0(op);
}

/*======================================================================*/
void emit2(Aword op, Aword arg1, Aword arg2)
{
  emitConstant(arg2);
  emitConstant(arg1);
  emit0(op);
}

/*======================================================================*/
void emit3(Aword op, Aword arg1, Aword arg2, Aword arg3)
{
  emitConstant(arg3);
  emitConstant(arg2);
  emitConstant(arg1);
  emit0(op);
}


/*======================================================================*/
void emitLine(Srcp srcp) {
  emitConstant(srcp.file);
  emitConstant(srcp.line);
  emit0(I_LINE);
}


/*======================================================================*/
void initEmitBuffer(Aword *bufferToUse) {
  pc = 0;
  crc = 0;

  emitBuffer = bufferToUse;
}



#ifdef __amiga__
#include <intuition/intuition.h>
#include <workbench/workbench.h>
#include <functions.h>
extern struct Library *IconBase;
static UWORD iconData1[400] = {
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x001f, 0xffff, 0xcfff, 0xff00, 0x0000, 
			0x0010, 0x0000, 0x7800, 0x0100, 0x0000, 
			0x0028, 0x0000, 0x3000, 0x0080, 0x0000, 
			0x07e8, 0x4801, 0x11b1, 0x8880, 0x0000, 
			0x07c4, 0x4324, 0x104b, 0x4040, 0x0000, 
			0x07c4, 0x52c5, 0x08c8, 0x0840, 0x0000, 
			0x07e2, 0x2000, 0x0800, 0x0020, 0x0000, 
			0x07e2, 0x0000, 0x0446, 0x3820, 0x0000, 
			0x07f1, 0x0caf, 0x0468, 0xa210, 0x0000, 
			0x07f1, 0x0320, 0x4400, 0x0010, 0x0000, 
			0x0778, 0x8000, 0x0220, 0x2008, 0x0000, 
			0x0778, 0x8000, 0x021b, 0x9e88, 0x0000, 
			0x0778, 0x85aa, 0x4112, 0x8004, 0x0000, 
			0x073c, 0x4288, 0x5100, 0x0004, 0x0000, 
			0x073c, 0x4000, 0x0100, 0x0002, 0x0000, 
			0x07be, 0x2020, 0x009e, 0x0002, 0x0000, 
			0x07de, 0x2004, 0x008f, 0x0001, 0x0000, 
			0x077f, 0x1147, 0x384f, 0x0001, 0x0000, 
			0x073f, 0x1034, 0x4447, 0x8000, 0x8000, 
			0x071f, 0x8800, 0x0040, 0x0000, 0x8000, 
			0x070f, 0x8800, 0x0020, 0x0000, 0x4000, 
			0x070f, 0x87ff, 0xff21, 0xffff, 0xe000, 
			0x0307, 0xc400, 0x0096, 0x0000, 0x6000, 
			0x0107, 0xcc00, 0x0078, 0x0000, 0x2000, 
			0x0003, 0xe800, 0x0010, 0x0000, 0x39c0, 
			0x0003, 0xe800, 0x003c, 0x0000, 0x3f68, 
			0x0002, 0xffff, 0xffff, 0xffff, 0xfe3c, 
			0x0001, 0xffff, 0xffff, 0xffff, 0xfe1a, 
			0x0001, 0x7fff, 0xffff, 0xffff, 0xfe0e, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x000e, 
			0x0000, 0x4000, 0x0000, 0x0000, 0x0008, 
			0x0000, 0x2000, 0x0000, 0x0000, 0x003e, 
			0x0000, 0x1892, 0x4924, 0x9261, 0xa8f0, 
			0x0000, 0x0424, 0x9249, 0x24f0, 0x8060, 
			0x0000, 0x020d, 0x2492, 0x4978, 0x9400, 
			0x0000, 0x0080, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0040, 0x0000, 0x0000, 0x0000, 

			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x001f, 0xffff, 0xcfff, 0xff00, 0x0000, 
			0x001f, 0xffff, 0xffff, 0xff00, 0x0000, 
			0x003f, 0xffff, 0xffff, 0xff80, 0x0000, 
			0x043f, 0xb7fe, 0xfe4e, 0x7780, 0x0000, 
			0x067f, 0xbcdb, 0xffb4, 0xbfc0, 0x0000, 
			0x057f, 0xad3a, 0xff37, 0xf7c0, 0x0000, 
			0x053f, 0xdfff, 0xffff, 0xffe0, 0x0000, 
			0x053f, 0xffff, 0xffb9, 0xc7e0, 0x0000, 
			0x049f, 0xf350, 0xff97, 0x5df0, 0x0000, 
			0x049f, 0xfcdf, 0xbfff, 0xfff0, 0x0000, 
			0x044f, 0xffff, 0xffdf, 0xdff8, 0x0000, 
			0x044f, 0xffff, 0xffe4, 0x6178, 0x0000, 
			0x044f, 0xfa55, 0xbfed, 0x7ffc, 0x0000, 
			0x0427, 0xfd77, 0xafff, 0xfffc, 0x0000, 
			0x0427, 0xffff, 0xffff, 0xfffe, 0x0000, 
			0x04a3, 0xffdf, 0xffe1, 0xfffe, 0x0000, 
			0x0453, 0xfffb, 0xfff0, 0xffff, 0x0000, 
			0x0431, 0xfeb8, 0xc7f0, 0xffff, 0x0000, 
			0x0411, 0xffcb, 0xbbf8, 0x7fff, 0x8000, 
			0x0408, 0xffff, 0xffff, 0xffff, 0x8000, 
			0x0400, 0xffff, 0xffff, 0xffff, 0xc000, 
			0x0408, 0xbfff, 0xffff, 0xffff, 0xe000, 
			0x0004, 0x7fff, 0xffff, 0xffff, 0xe000, 
			0x0004, 0x7fff, 0xffff, 0xffff, 0xe000, 
			0x0002, 0x3fff, 0xffef, 0xffff, 0xe000, 
			0x0002, 0x3fff, 0xffc3, 0xffff, 0xf000, 
			0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x7fff, 0xffff, 0xffff, 0xfc00, 
			0x0000, 0x7fff, 0xffff, 0xffff, 0xfe00, 
			0x0000, 0x7f6d, 0xb6db, 0x6d9e, 0x5700, 
			0x0000, 0x7fdb, 0x6db6, 0xdb0f, 0x7f80, 
			0x0000, 0x0ff2, 0xdb6d, 0xb687, 0x6bc0, 
			0x0000, 0x03ff, 0xffff, 0xffff, 0xffe0, 
			0x0000, 0x007f, 0xffff, 0xffff, 0xffe0
			};
static UWORD iconData2[400] = {
			0x0000, 0x0000, 0x07fc, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0803, 0x0000, 0x0000, 
			0x001f, 0xffff, 0xc803, 0xff00, 0x0000, 
			0x0010, 0x0000, 0x7801, 0x0100, 0x0000, 
			0x0028, 0x0000, 0x3029, 0x0080, 0x0000, 
			0x07e8, 0x4801, 0x1109, 0x8880, 0x0000, 
			0x07c4, 0x4324, 0x1008, 0x8040, 0x0000, 
			0x07c4, 0x52c5, 0x08c0, 0x8840, 0x0000, 
			0x07e2, 0x2000, 0x0800, 0x8020, 0x0000, 
			0x07e2, 0x0000, 0x0414, 0xe820, 0x0000, 
			0x07f1, 0x0caf, 0x0410, 0xe210, 0x0000, 
			0x07f1, 0x0320, 0x4440, 0x3010, 0x0000, 
			0x0778, 0x8000, 0x0200, 0x3808, 0x0000, 
			0x0778, 0x8000, 0x0221, 0x9a88, 0x0000, 
			0x0778, 0x85aa, 0x4108, 0x0804, 0x0000, 
			0x073c, 0x4288, 0x5102, 0x0404, 0x0000, 
			0x073c, 0x4000, 0x0110, 0x7a02, 0x0000, 
			0x07be, 0x2020, 0x0081, 0xcf02, 0x0000, 
			0x07de, 0x2004, 0x0081, 0x01c1, 0x0000, 
			0x077f, 0x1147, 0x3843, 0x0001, 0x0000, 
			0x073f, 0x1034, 0x4447, 0x8000, 0x8000, 
			0x071f, 0x8800, 0x0044, 0x0000, 0x8000, 
			0x070f, 0x8800, 0x002c, 0x0000, 0x4000, 
			0x070f, 0x87ff, 0xff2d, 0xffff, 0xe000, 
			0x0307, 0xc400, 0x0096, 0x0000, 0x6000, 
			0x0107, 0xcc00, 0x0078, 0x0000, 0x2000, 
			0x0003, 0xe800, 0x0010, 0x0000, 0x39c0, 
			0x0003, 0xe800, 0x003c, 0x0000, 0x3f68, 
			0x0002, 0xffff, 0xffff, 0xffff, 0xfe3c, 
			0x0001, 0xffff, 0xffff, 0xffff, 0xfe1a, 
			0x0001, 0x7fff, 0xffff, 0xffff, 0xfe0e, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0004, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x000e, 
			0x0000, 0x4000, 0x0000, 0x0000, 0x0008, 
			0x0000, 0x2000, 0x0000, 0x0000, 0x003e, 
			0x0000, 0x1892, 0x4924, 0x9261, 0xa8f0, 
			0x0000, 0x0424, 0x9249, 0x24f0, 0x8060, 
			0x0000, 0x020d, 0x2492, 0x4978, 0x9400, 
			0x0000, 0x0080, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0040, 0x0000, 0x0000, 0x0000, 

			0x0000, 0x0000, 0x07fc, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0fff, 0x0000, 0x0000, 
			0x001f, 0xffff, 0xcfff, 0xff00, 0x0000, 
			0x001f, 0xffff, 0xffff, 0xff00, 0x0000, 
			0x003f, 0xffff, 0xffd7, 0xff80, 0x0000, 
			0x043f, 0xb7fe, 0xfef7, 0x7780, 0x0000, 
			0x067f, 0xbcdb, 0xfff7, 0xffc0, 0x0000, 
			0x057f, 0xad3a, 0xff3f, 0xf7c0, 0x0000, 
			0x053f, 0xdfff, 0xffff, 0xffe0, 0x0000, 
			0x053f, 0xffff, 0xffeb, 0xd7e0, 0x0000, 
			0x049f, 0xf350, 0xffef, 0x7df0, 0x0000, 
			0x049f, 0xfcdf, 0xbfbf, 0xfff0, 0x0000, 
			0x044f, 0xffff, 0xffff, 0xdff8, 0x0000, 
			0x044f, 0xffff, 0xffde, 0x6d78, 0x0000, 
			0x044f, 0xfa55, 0xbff7, 0xfffc, 0x0000, 
			0x0427, 0xfd77, 0xaffd, 0xfffc, 0x0000, 
			0x0427, 0xffff, 0xffef, 0xfffe, 0x0000, 
			0x04a3, 0xffdf, 0xffff, 0xfffe, 0x0000, 
			0x0453, 0xfffb, 0xffff, 0xffff, 0x0000, 
			0x0431, 0xfeb8, 0xc7ff, 0xffff, 0x0000, 
			0x0411, 0xffcb, 0xbbfe, 0x7fff, 0x8000, 
			0x0408, 0xffff, 0xffff, 0xffff, 0x8000, 
			0x0400, 0xffff, 0xffff, 0xffff, 0xc000, 
			0x0408, 0xbfff, 0xffff, 0xffff, 0xe000, 
			0x0004, 0x7fff, 0xffff, 0xffff, 0xe000, 
			0x0004, 0x7fff, 0xffff, 0xffff, 0xe000, 
			0x0002, 0x3fff, 0xffef, 0xffff, 0xe000, 
			0x0002, 0x3fff, 0xffc3, 0xffff, 0xf000, 
			0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x7fff, 0xffff, 0xffff, 0xfc00, 
			0x0000, 0x7fff, 0xffff, 0xffff, 0xfe00, 
			0x0000, 0x7f6d, 0xb6db, 0x6d9e, 0x5700, 
			0x0000, 0x7fdb, 0x6db6, 0xdb0f, 0x7f80, 
			0x0000, 0x0ff2, 0xdb6d, 0xb687, 0x6bc0, 
			0x0000, 0x03ff, 0xffff, 0xffff, 0xffe0, 
			0x0000, 0x007f, 0xffff, 0xffff, 0xffe0 
			};

static struct Image iconImage1 = {
  0,				/* LeftEdge */
  0,				/* TopEdge */
  79,				/* Width */
  40,				/* Height */
  2,				/* Depth */
  &iconData1,		/* ImageData */
  3,				/* PlanePick */
  0,				/* PlaneOnOff */
  NULL				/* NextImage */
  };

static struct Image iconImage2 = {
  0,				/* LeftEdge */
  0,				/* TopEdge */
  79,				/* Width */
  40,				/* Height */
  2,				/* Depth */
  &iconData2,		/* ImageData */
  3,				/* PlanePick */
  0,				/* PlaneOnOff */
  NULL				/* NextImage */
  };

static UBYTE *toolTypes[] = {
  "(WINDOW=CON:10/10/480/160)",
  NULL};

static struct DiskObject iconObject = {
  WB_DISKMAGIC, WB_DISKVERSION,
  {
    NULL,			/* NextGadget */
    215,			/* LeftEdge */
    20,				/* TopEdge */
    79,				/* Width */
    41,				/* Height */
    GADGIMAGE|GADGHIMAGE,	/* Flags */
    RELVERIFY|GADGIMMEDIATE,	/* Activation */
    BOOLGADGET,			/* GadgetType */
    (APTR)&iconImage1,		/* GadgetRender */
    (APTR)&iconImage2,		/* SelectRender */
    NULL,			/* GadgetText */
    0,				/* MutualExclude */
    NULL,			/* SpecialInfo */
    0,				/* GadgetId */
    NULL			/* UserData */
    },
  WBPROJECT,			/* Type */
  "AlanDir:arun",		/* DefaultTool */
  &toolTypes,				/* ToolTypes */
  NO_ICON_POSITION,		/* CurrentX */
  NO_ICON_POSITION,		/* CurrentY */
  NULL,				/* DrawerData */
  NULL,				/* ToolWindow */
  0				/* StackSize */
  };
#endif


/*======================================================================*/
void initEmit(char *acdfnm)	/* IN - File name for ACODE instructions */
{
  int i;

  initEmitBuffer(eBuffer);

#ifdef __amiga__
  struct DiskObject *existingIcon;

  if ((IconBase = OpenLibrary("icon.library", 0)) == NULL)
      syserr("Could not open 'icon.library'");
  if ((existingIcon = GetDiskObject(advnam)) == 0)
      PutDiskObject(advnam, &iconObject);
  else
      FreeDiskObject(existingIcon);
#endif

#ifdef __MWERKS__
	_fcreator = 'Arun';
	_ftype = 'Acod';
#endif
  acdfil = fopen(acdfnm, WRITE_MODE);
  if (!acdfil) {
    char errorString[1000];
    sprintf(errorString, "Could not open output file '%s' for writing.", acdfnm);
    SYSERR(errorString);
  }

  /* Make space for ACODE header */
  for (i = 0; i < (sizeof(ACodeHeader)/sizeof(Aword)); i++)
      emit(0L);

#ifdef __mac__
  /* Add FinderInfo to point to Arun */
  {
    char fnm[256];
    short vRefNum = 0;
    FInfo finfo;
    OSErr oe;

    strcpy(fnm, acdfnm);
    c2pstr(fnm);
    oe = GetFInfo((ConstStr255Param)fnm, 0, &finfo);

    strncpy((char *)&finfo.fdType, "Acod", 4);
    strncpy((char *)&finfo.fdCreator, "Arun", 4);
    oe = SetFInfo((ConstStr255Param)fnm, 0, &finfo);
  }
#endif
}


void terminateEmit()
{
  if (pc%BLOCKSIZE > 0)
    fwrite(emitBuffer, BLOCKSIZE, 1, acdfil);

  acodeHeader.acdcrc = crc;	/* Save checksum */
  acodeHeader.size = nextEmitAddress();	/* Save last address as size */
}


void emitTextDataToAcodeFile(char dataFileName[])
{
  int c;
  FILE *dataFile = fopen(dataFileName, READ_MODE);

  acodeHeader.stringOffset = ftell(acdfil);

  while ((c = fgetc(dataFile)) != EOF)
    fputc(c, acdfil);
  fclose(dataFile);
}


void emitHeader()
{
  Aword *hp;			/* Pointer to header as words */
  int i;
#ifdef __POSIX__
  struct timeval times;
#else
  struct timeb times;
#endif

  (void) rewind(acdfil);
  pc = 0;

  /* Generate header tag "ALAN" */
  if (littleEndian()) {
    acodeHeader.tag[3] = 'A';
    acodeHeader.tag[2] = 'L';
    acodeHeader.tag[1] = 'A';
    acodeHeader.tag[0] = 'N';
  } else {
    acodeHeader.tag[0] = 'A';
    acodeHeader.tag[1] = 'L';
    acodeHeader.tag[2] = 'A';
    acodeHeader.tag[3] = 'N';
  }

  /* Construct version marking */
  if (littleEndian()) {
    acodeHeader.vers[3] = (Aword)alan.version.version;
    acodeHeader.vers[2] = (Aword)alan.version.revision;
    acodeHeader.vers[1] = (Aword)alan.version.correction;
    acodeHeader.vers[0] = (Aword)alan.version.state[0];
  } else {
    acodeHeader.vers[0] = (Aword)alan.version.version;
    acodeHeader.vers[1] = (Aword)alan.version.revision;
    acodeHeader.vers[2] = (Aword)alan.version.correction;
    acodeHeader.vers[3] = (Aword)alan.version.state[0];
  }

  /* The timestamping isn't important, it is only used to give the
     compiled game a semi-unique id so that loading a saved game can
     not be done if it was not created with exactly the same compiled
     game. You can remove it or replace it by something other. It does
     not affect game compatibility. */
#ifdef __POSIX__
  gettimeofday(&times, NULL);
  acdHeader.uid = times.tv_usec;
#else
  ftime(&times);
  acodeHeader.uid = times.millitm;
#endif

  hp = (Aword *) &acodeHeader;		/* Point to header */
  for (i = 0; i < (sizeof(ACodeHeader)/sizeof(Aword)); i++) /* Emit header */
    emit(*hp++);
  fwrite(emitBuffer, sizeof(ACodeHeader), 1, acdfil); /* Flush first block out */
  fclose(acdfil);
}
