/*----------------------------------------------------------------------*\
  sysdep.c

  This file contains necessary system dependent routines and routines
  possibbly not implemented in the current environment.

  strdup()

  realloc()
  strlow()
  strupp()
  memcpy()
  memset()

\*----------------------------------------------------------------------*/

#include <time.h>
#include "sysdep.h"


#ifdef __vms__

char *strdup(char str[])		/* IN - String to duplicate */
{
  char *new = (char *) malloc(strlen(str)+1);

  strcpy(new, str);
  return new;
}

#endif


#ifdef AZTEC_C

char *strdup(str)
     char str[];			/* IN - String to duplicate */
{
  char *new = (char *) malloc(strlen(str)+1);

  strcpy(new, str);
  return new;
}


void memcpy(out, in, length)
    char *out;
    char *in;
    int length;
{
  while(length--)
    *out++ = *in++;
}


void memset(mem, val, length)
    char *mem;
    char val;
    int length;
{
  while(length--)
    *mem++ = val;
}

void *realloc(old, newLength)
     void *old;			/* IN - address to the old area */
     int newLength;		/* IN - new length */
{
  void *new;

  new = malloc(newLength);
  memcpy(new, old, newLength);
  free(old);
  return new;
}

#endif

#ifdef __vms__

/* Cheat implementation of strftime */
size_t strftime (
		 char *outbuf,
		 size_t len,
		 const char *format,
		 const struct tm *t)
{
  char buf[100];
  time_t ticks;

  time(&ticks);
  strcpy(buf, ctime(&ticks));
  buf[strlen(buf)-1] = '\0';
  strcpy(outbuf, &buf[4]);
}

#endif

#ifdef __dos__

/* Cheat implementation of strftime */
size_t strftime (
		 char *outbuf,
		 size_t len,
		 const char *format,
		 const struct tm *t)
{
  char buf[100];
  time_t ticks;

  time(&ticks);
  strcpy(buf, ctime(&ticks));
  buf[strlen(buf)-1] = '\0';
  strcpy(outbuf, &buf[4]);
}

#endif


#ifdef _PROTOTYPES_
int isSpace(int c)		/* IN - character to test */
#else
int isSpace(c)
     int c;			/* IN - character to test */
#endif
{
  static char spcChrs[] = " \t\n";

  return (c != '\0' && strchr(spcChrs, c) != 0);
}


#ifdef _PROTOTYPES_
int isLower(int c)			/* IN - character to test */
#else
int isLower(c)
     int c;			/* IN - character to test */
#endif
{
  static char lowChrs[] = "abcdefghijklmnopqrstuvwxyz|{}\340\341\342\343\344\345\346\347\360\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372\373\374\375\376\377";

  return (strchr(lowChrs, c) != 0);
}


#ifdef _PROTOTYPES_
int isUpper(int c)		/* IN - character to test */
#else
int isUpper(c)
     int c;			/* IN - character to test */
#endif
{
  static char uppChrs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ][\\\300\301\302\303\304\305\306\307\300\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337";

  return (strchr(uppChrs, c) != 0);
}


#ifdef _PROTOTYPES_
char lowerCase(int c)
#else
char lowerCase(c)
     int c;
#endif
{
  return (isUpper(c)? c + ('a' - 'A'): c);
}


#ifdef _PROTOTYPES_
char upperCase(int c)
#else
char upperCase(c)
     int c;
#endif
{
  return (isLower(c)? c - ('a' - 'A'): c);
}


#ifdef _PROTOTYPES_
int isLetter(int c)		/* IN - character to test */
#else
int isLetter(c)
     int c;			/* IN - character to test */
#endif
{
  return(isLower(c)? !0: isUpper(c));
}


#ifdef _PROTOTYPES_
char *strlow(char str[])	/* INOUT - string to convert */
#else
char *strlow(str)
     char str[];		/* INOUT - string to convert */
#endif
{
  char *s;

  for (s = str; *s; s++)
    *s = lowerCase(*s);
  return(str);
}


#ifdef _PROTOTYPES_
char *strupp(char str[])	/* INOUT - string to convert */
#else
char *strupp(str)
     char str[];		/* INOUT - string to convert */
#endif
{
  char *s;

  for (s = str; *s; s++)
    *s = upperCase(*s);
  return(str);
}

#ifdef _PROTOTYPES_
void toIso(char copy[],	/* OUT - Mapped string */
	     char original[])	/* IN - string to convert */
#else
void toIso(copy, original)
     char copy[];		/* OUT - Mapped string */
     char original[];		/* IN - string to convert */
#endif
{
#if ISO == 0
static char map[256]
#if defined __mac__
= {
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0A,0x0E,0x0F,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
0xC4,0xC5,0xC7,0xC9,0xD1,0xD6,0xDC,0xE1,0xE0,0xE2,0xE4,0xE3,0xE5,0xE7,0xE9,0xE8,
0xEA,0xEB,0xED,0xEC,0xEE,0xEF,0xF1,0xF3,0xF2,0xF4,0xF6,0xF5,0xFA,0xF9,0xFB,0xFC,
0xB9,0xB0,0xA2,0xA3,0xA7,0xB7,0xB6,0xDF,0xAE,0xA9,0xB2,0xB4,0xA8,0xD7,0xC6,0xD8,
0xA4,0xB1,0xCD,0xCC,0xA5,0xB5,0xF0,0xCA,0xDE,0xFE,0xA6,0xAA,0xBA,0xD4,0xE6,0xF8,
0xBF,0xA1,0xAC,0xCE,0xCF,0xC8,0xD0,0xAB,0xBB,0xCB,0xA0,0xC0,0xC3,0xD5,0xDD,0xFD,
0xAD,0xAF,0xDA,0xD9,0xB8,0xB3,0xF7,0xC2,0xFF,0xBC,0xBD,0xBE,0xC1,0xD2,0xD3,0xDB,
0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F};
#elif defined __dos__
= {
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0A,0x0E,0x0F,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
0xC7,0xFC,0xE9,0xE2,0xE4,0xE0,0xE5,0xE7,0xEA,0xEB,0xE8,0xEF,0xEE,0xEC,0xC4,0xC5,
0xC9,0xE6,0xC6,0xF4,0xF6,0xF2,0xFB,0xF9,0xFF,0xD6,0xDC,0xA2,0xA3,0xA5,0xDE,0xA6,
0xE1,0xED,0xF3,0xFA,0xF1,0xD1,0xAA,0xBA,0xBF,0xC0,0xC1,0xBD,0xBC,0xCF,0xAB,0xBB,
0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
0xA1,0xA7,0xAD,0xB3,0xB8,0xB9,0xC3,0xCE,0xD2,0xD3,0xDB,0xDD,0xE3,0xF5,0xF8,0xFD,
0xA9,0xDF,0xC8,0xB6,0xCA,0xA4,0xB5,0xAE,0xD5,0xD0,0xD4,0xF0,0xD7,0xD8,0xCB,0xC2,
0xBE,0xB1,0xD9,0xDA,0xCD,0xCC,0xF7,0xA8,0xB0,0xB7,0xAF,0xAC,0xFE,0xB2,0xB4,0xA0};
#endif
  char *o, *c;

  for (o = original, c = copy; *o; o++, c++)
    *c = map[(int)*o];
  *c = '\0';
#else
  strcpy(copy, original);
#endif
}

#ifdef _PROTOTYPES_
void fromIso(char copy[],	/* OUT - Mapped string */
	     char original[])	/* IN - string to convert */
#else
void fromIso(copy, original)
     char copy[];		/* OUT - Mapped string */
     char original[];		/* IN - string to convert */
#endif
{
#if ISO == 0
static char map[256]
#if defined __mac__
= {
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0D,0x0B,0x0C,0x0D,0x0E,0x0F,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF,
0xCA,0xC1,0xA2,0xA3,0xB0,0xB4,0xBA,0xA4,0xAC,0xA9,0xBB,0xC7,0xC2,0xD0,0xA8,0xD1,
0xA1,0xB1,0xAA,0xD5,0xAB,0xB5,0xA6,0xA5,0xD4,0xA0,0xBC,0xC8,0xD9,0xDA,0xDB,0xC0,
0xCB,0xDC,0xD7,0xCC,0x80,0x81,0xAE,0x82,0xC5,0x83,0xB7,0xC9,0xB3,0xB2,0xC3,0xC4,
0xC6,0x84,0xDD,0xDE,0xBD,0xCD,0x85,0xAD,0xAF,0xD3,0xD2,0xDF,0x86,0xCE,0xB8,0xA7,
0x88,0x87,0x89,0x8B,0x8A,0x8C,0xBE,0x8D,0x8F,0x8E,0x90,0x91,0x93,0x92,0x94,0x95,
0xB6,0x96,0x98,0x97,0x99,0x9B,0x9A,0xD6,0xBF,0x9D,0x9C,0x9E,0x9F,0xCF,0xB9,0xD8};
#elif defined __dos__
= {
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0D,0x0B,0x0C,0x0D,0x0E,0x0F,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,
0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
0xFF,0xD0,0x9B,0x9C,0xE5,0x9D,0x9F,0xD1,0xF7,0xE0,0xA6,0xAE,0xFB,0xD2,0xE7,0xFA,
0xF8,0xF1,0xFD,0xD3,0xFE,0xE6,0xE3,0xF9,0xD4,0xD5,0xA7,0xAF,0xAC,0xAB,0xF0,0xA8,
0xA9,0xAA,0xEF,0xD6,0x8E,0x8F,0x92,0x80,0xE2,0x90,0xE4,0xEE,0xF5,0xF4,0xD7,0xAD,
0xE9,0xA5,0xD8,0xD9,0xEA,0xE8,0x99,0xEC,0xED,0xF2,0xF3,0xDA,0x9A,0xDB,0x9E,0xE1,
0x85,0xA0,0x83,0xDC,0x84,0x86,0x91,0x87,0x8A,0x82,0x88,0x89,0x8D,0xA1,0x8C,0x8B,
0xEB,0xA4,0x95,0xA2,0x93,0xDD,0x94,0xF6,0xDE,0x97,0xA3,0x96,0x81,0xDF,0xFC,0x98};
#endif
  char *o, *c;

  for (o = original, c = copy; *o; o++, c++)
    *c = map[(int)*o];
  *c = '\0';
#else
  strcpy(copy, original);
#endif
}
