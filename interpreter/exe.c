/*----------------------------------------------------------------------*\

  exe.c

  Amachine instruction execution unit of Alan interpreter

\*----------------------------------------------------------------------*/

#include "types.h"

#include "arun.h"
#include "parse.h"
#include "inter.h"
#include "stack.h"
#include "decode.h"

#include "exe.h"

#define WIDTH 80

#define N_EVTS 100


/* PUBLIC DATA */

/* The event queue */
EvtqElem eventq[N_EVTS];	/* Event queue */
int etop = 0;			/* Event queue top pointer */


#ifdef _PROTOTYPES_
void dscrobjs(void);
void dscracts(void);
#else
void dscrobjs();
void dscracts();
#endif



#ifdef _PROTOTYPES_
void print(Aword fpos, Aword len)
#else
void print(fpos, len)
     Aword fpos, len;
#endif
{
  char str[2*WIDTH];		/* String buffer */
  int outlen = 0;		/* Current output length */
  int ch;
  int i;
  long savfp;			/* Temporary saved text file position */
  static Boolean printFlag = FALSE; /* Printing already? */
  Boolean savedPrintFlag = printFlag;
  void *info;			/* Saved decoding info */


  if (len == 0) return;

  if (isHere(HERO)) {		/* Check if the player will see it */
    if (printFlag) {		/* Already printing? */
      /* Save current text file position and/or decoding info */
      if (header->pack)
	info = pushDecode();
      else
	savfp = ftell(txtfil);
    }
    printFlag = TRUE;		/* We're printing now! */
    fseek(txtfil, fpos, 0);	/* Position to start of text */
    if (header->pack)
      startDecoding();
    for (outlen = 0; outlen != len; outlen = outlen + strlen(str)) {
      /* Fill the buffer from the beginning */
      for (i = 0; i <= WIDTH || (i > WIDTH && ch != ' '); i++) {
	if (outlen + i == len)	/* No more characters? */
	  break;
	if (header->pack)
	  ch = decodeChar();
	else
	  ch = getc(txtfil);
	if (ch == EOFChar)	/* Or end of text? */
	  break;
	str[i] = ch;
      }
      str[i] = '\0';
#if ISO == 0
      fromIso(str, str);
#endif
      output(str);
    }
    /* And restore */
    printFlag = savedPrintFlag;
    if (printFlag) {
      if (header->pack)
	popDecode(info);
      else
	fseek(txtfil, savfp, 0);
    }
  }
}


#ifdef _PROTOTYPES_
void sys(Aword fpos, Aword len)
#else
void sys(fpos, len)
     Aword fpos, len;
#endif
{
  char *command;

  getstr(fpos, len);		/* Returns address to string on stack */
  command = (char *)pop();
#ifndef __amiga__
  system(command);
#endif
  free(command);
}


#ifdef _PROTOTYPES_
void getstr(Aword fpos, Aword len)
#else
void getstr(fpos, len)
     Aword fpos, len;
#endif
{
  char *buf = allocate(len+1);

  push((Aword) buf);		/* Push the address to the string */
  fseek(txtfil, fpos, 0);	/* Position to start of text */
  if (header->pack)
    startDecoding();
  while (len--)
    if (header->pack)
      *(buf++) = decodeChar();
    else
      *(buf++) = getc(txtfil);
  *buf = '\0';
}



#ifdef _PROTOTYPES_
void score(Aword sc)
#else
void score(sc)
     Aword sc;
#endif
{
  char buf[80];

  if (sc == 0) {
    prmsg(M_SCORE1);
    sprintf(buf, "%ld", cur.score);
    output(buf);
    prmsg(M_SCORE2);
    sprintf(buf, "%ld.", header->maxscore);
    output(buf);
  } else {
    cur.score += scores[sc-1];
    scores[sc-1] = 0;
  }
}

#ifdef _PROTOTYPES_
void visits(Aword v)
#else
void visits(v)
     Aword v;
#endif
{
  cur.visits = v;
}


#ifdef _PROTOTYPES_
Boolean confirm(MsgKind msgno)
#else
Boolean confirm(msgno)
     MsgKind msgno;
#endif
{
  char str[80];
  char *msg, ch = '\0';
  int i;

  /* Can't use prmsg() here because we want to look for the '(y)' part */
  getstr(msgs[msgno].fpos, msgs[msgno].len);
  msg = (char *)pop();
  output(msg);
  gets(str); col = 1;
  
  /* Use a character inside parenthesis as affirmative */
  for (i = 0; msg[i]; i++)
    if (msg[i] == '(' && msg[i+2] == ')') {
      ch = msg[i+1];
      break;
    }
  free(msg);
  return (str[0] == '\0' || (ch && toupper(str[0]) == toupper(ch)));
}


#ifdef _PROTOTYPES_
void quit(void)
#else
void quit()
#endif
{
  para();
  if (confirm(M_RETRY)) {
    longjmp(restart, TRUE);
  } else {
    if (logflg)
      fclose(logfil);
    newline();
    terminate(0);
  }
  syserr("Fallthrough in QUIT");
}



#ifdef _PROTOTYPES_
void cancl(Aword evt)
#else
void cancl(evt)
     Aword evt;
#endif
{
  int i;

  for(i = etop-1; i>=0; i--)
    if (eventq[i].event == evt) {
      while (i < etop-1) {
	eventq[i].event = eventq[i+1].event;
	eventq[i].time = eventq[i+1].time;
	eventq[i].where = eventq[i+1].where;
	i++;
      }
      etop--;
      return;
    }
}


#ifdef _PROTOTYPES_
void schedule(Aword evt, Aword whr, Aword aft)
#else
void schedule(evt, whr, aft)
     Aword evt, whr, aft;
#endif
{  int i;
   int time;
  
  cancl(evt);
  /* Check for overflow */
  if (etop == N_EVTS) syserr("Out of event space.");
  
  time = cur.tick+aft;
  
  /* Bubble this event down */
  for (i = etop; i >= 1 && eventq[i-1].time <= time; i--) {
    eventq[i].event = eventq[i-1].event;
    eventq[i].time = eventq[i-1].time;
    eventq[i].where = eventq[i-1].where;
  }
  
  eventq[i].time = time;
  eventq[i].where = whr;
  eventq[i].event = evt;
  etop++;
}


/*----------------------------------------------------------------------

  getatr()

  Get an attribute value from an attribute list

 */
#ifdef _PROTOTYPES_
static Aword getatr(
     Aaddr atradr,		/* IN - ACODE address to attribute table */
     Aaddr atr			/* IN - The attribute to read */
)
#else
static Aword getatr(atradr, atr)
     Aaddr atradr;		/* IN - ACODE address to attribute table */
     Aaddr atr;			/* IN - The attribute to read */
#endif
{
  AtrElem *at;

  at = (AtrElem *) addrTo(atradr);
  return(at[atr-1].val);
}
  

/*----------------------------------------------------------------------

  setatr()

  Set a particular attribute to a value.

 */
#ifdef _PROTOTYPES_
static void setatr(
     Aaddr atradr,		/* IN - ACODE address to attribute table */
     Aword atr,			/* IN - attribute code */
     Aword val			/* IN - new value */
)
#else
static void setatr(atradr, atr, val)
     Aaddr atradr;		/* IN - ACODE address to attribute table */
     Aword atr;			/* IN - attribute code */
     Aword val;			/* IN - new value */
#endif
{
  AtrElem *at;
  
  at = (AtrElem *) addrTo(atradr);
  at[atr-1].val = val;
}


/*----------------------------------------------------------------------

  make()

  */

#ifdef _PROTOTYPES_
static void makloc(Aword loc, Aword atr, Aword val)
#else
static void makloc(loc, atr, val)
     Aword loc, atr, val;
#endif
{
  setatr(locs[loc-LOCMIN].atrs, atr, val);
}

#ifdef _PROTOTYPES_
static void makobj(Aword obj, Aword atr, Aword val)
#else
static  void makobj(obj, atr, val)
	    Aword obj, atr, val;
#endif
{
  setatr(objs[obj-OBJMIN].atrs, atr, val);
}

#ifdef _PROTOTYPES_
static void makact(Aword act, Aword atr, Aword val)
#else
static void makact(act, atr, val)
	    Aword act, atr, val;
#endif
{
  setatr(acts[act-ACTMIN].atrs, atr, val);
}


#ifdef _PROTOTYPES_
void make(Aword id, Aword atr, Aword val)
#else
void make(id, atr, val)
	  Aword id, atr, val;
#endif
{
  char str[80];

  if (isObj(id))
    makobj(id, atr, val);
  else if (isLoc(id))
    makloc(id, atr, val);
  else if (isAct(id))
    makact(id, atr, val);
  else {
    sprintf(str, "Can't MAKE item (%ld).", id);
    syserr(str);
  }
}


/*----------------------------------------------------------------------------

  set()

 */

#ifdef _PROTOTYPES_
static void setloc(Aword loc, Aword atr, Aword val)
#else
static void setloc(loc, atr, val)
     Aword loc, atr, val;
#endif
{
  setatr(locs[loc-LOCMIN].atrs, atr, val);
  locs[loc-LOCMIN].describe = 0;
}


#ifdef _PROTOTYPES_
static void setobj(Aword obj, Aword atr, Aword val)
#else
static void setobj(obj, atr, val)
     Aword obj, atr, val;
#endif
{
  setatr(objs[obj-OBJMIN].atrs, atr, val);
}

#ifdef _PROTOTYPES_
static void setact(Aword act, Aword atr, Aword val)
#else
static void setact(act, atr, val)
     Aword act, atr, val;
#endif
{
  setatr(acts[act-ACTMIN].atrs, atr, val);
}


#ifdef _PROTOTYPES_
void set(Aword id, Aword atr, Aword val)
#else
void set(id, atr, val)
     Aword id, atr, val;
#endif
{
  char str[80];

  if (isObj(id))
    setobj(id, atr, val);
  else if (isLoc(id))
    setloc(id, atr, val);
  else if (isAct(id))
    setact(id, atr, val);
  else {
    sprintf(str, "Can't SET item (%ld).", id);
    syserr(str);
  }
}


#ifdef _PROTOTYPES_
void setstr(Aword id, Aword atr, Aword str)
#else
void setstr(id, atr, str)
     Aword id, atr, str;
#endif
{
  free((char *)attribute(id, atr));
  set(id, atr, str);
}



/*-----------------------------------------------------------------------------

  incr/decr

  */

/*----------------------------------------------------------------------

  incratr()

  Increment a particular attribute by a value.

 */
#ifdef _PROTOTYPES_
static void incratr(
	Aaddr atradr,		/* IN - ACODE address to attribute table */
	Aword atr,		/* IN - attribute code */
	Aword step		/* IN - step to increment by */
)
#else
static void incratr(atradr, atr, step)
     Aaddr atradr, atr, step;
#endif
{
  AtrElem *at;
  
  at = (AtrElem *) addrTo(atradr);
  at[atr-1].val += step;
}


#ifdef _PROTOTYPES_
static void incrloc(Aword loc, Aword atr, Aword step)
#else
static void incrloc(loc, atr, step)
     Aword loc, atr, step;
#endif
{
  incratr(locs[loc-LOCMIN].atrs, atr, step);
  locs[loc-LOCMIN].describe = 0;
}


#ifdef _PROTOTYPES_
static void incrobj(Aword obj, Aword atr, Aword step)
#else
static void incrobj(obj, atr, step)
     Aword obj, atr, step;
#endif
{
  incratr(objs[obj-OBJMIN].atrs, atr, step);
}

#ifdef _PROTOTYPES_
static void incract(Aword act, Aword atr, Aword step)
#else
static void incract(act, atr, step)
     Aword act, atr, step;
#endif
{
  incratr(acts[act-ACTMIN].atrs, atr, step);
}


#ifdef _PROTOTYPES_
void incr(Aword id, Aword atr, Aword step)
#else
void incr(id, atr, step)
     Aword id, atr, step;
#endif
{
  char str[80];

  if (isObj(id))
    incrobj(id, atr, step);
  else if (isLoc(id))
    incrloc(id, atr, step);
  else if (isAct(id))
    incract(id, atr, step);
  else {
    sprintf(str, "Can't INCR item (%ld).", id);
    syserr(str);
  }
}

#ifdef _PROTOTYPES_
void decr(Aword id, Aword atr, Aword step)
#else
void decr(id, atr, step)
     Aword id, atr, step;
#endif
{
  char str[80];

  if (isObj(id))
    incrobj(id, atr, -step);
  else if (isLoc(id))
    incrloc(id, atr, -step);
  else if (isAct(id))
    incract(id, atr, -step);
  else {
    sprintf(str, "Can't DECR item (%ld).", id);
    syserr(str);
  }
}



/*----------------------------------------------------------------------

  attribute()

  */

#ifdef _PROTOTYPES_
static Aword locatr(Aword loc, Aword atr)
#else
static Aword locatr(loc, atr)
     Aword loc, atr;
#endif
{
  return(getatr(locs[loc-LOCMIN].atrs, atr));
}



#ifdef _PROTOTYPES_
static Aword objatr(Aword obj, Aword atr)
#else
static Aword objatr(obj, atr)
     Aword obj, atr;
#endif
{
  return(getatr(objs[obj-OBJMIN].atrs, atr));
}

#ifdef _PROTOTYPES_
static Aword actatr(Aword act, Aword atr)
#else
static Aword actatr(act, atr)
     Aword act, atr;
#endif
{
  Aword val;			/* Value */
  char str[80];

  val = getatr(acts[act-ACTMIN].atrs, atr);
  if (val != EOF)
    return(val);
  else {
    sprintf(str, "Unknown actor attribute requested (%ld, %ld).", act, atr);
    syserr(str);
  }
  return(EOF);
}

#ifdef _PROTOTYPES_
static Aword litatr(Aword lit, Aword atr)
#else
static Aword litatr(lit, atr)
     Aword lit, atr;
#endif
{
  char str[80];

  if (atr == 1)
    return litValues[lit-LITMIN].value;
  else {
    sprintf(str, "Unknown attribute for literal (%ld).", atr);
    syserr(str);
  }
  return(EOF);
}


#ifdef _PROTOTYPES_
Aword attribute(Aword id, Aword atr)
#else
Aword attribute(id, atr)
     Aword id, atr;
#endif
{
  char str[80];

  if (isObj(id))
    return objatr(id, atr);
  else if (isLoc(id))
    return locatr(id, atr);
  else if (isAct(id))
    return actatr(id, atr);
  else if (isLit(id))
    return litatr(id, atr);
  else {
    sprintf(str, "Can't ATTRIBUTE item (%ld).", id);
    syserr(str);
  }
  return(EOF);
}


#ifdef _PROTOTYPES_
Aword strattr(Aword id, Aword atr)
#else
Aword strattr(id, atr)
     Aword id, atr;
#endif
{
  return (Aword) strdup((char *)attribute(id, atr));
}


/*----------------------------------------------------------------------

  where()

  */

#ifdef _PROTOTYPES_
static Aword objloc(Aword obj)
#else
static Aword objloc(obj)
     Aword obj;
#endif
{
  if (isCnt(objs[obj-OBJMIN].loc)) /* In something ? */
    if (isObj(objs[obj-OBJMIN].loc) || isAct(objs[obj-OBJMIN].loc))
      return(where(objs[obj-OBJMIN].loc));
    else /* Containers not anywhere is where the hero is! */
      return(where(HERO));
  else
    return(objs[obj-OBJMIN].loc);
}


#ifdef _PROTOTYPES_
static Aword actloc(Aword act)
#else
static Aword actloc(act)
     Aword act;
#endif
{
  return(acts[act-ACTMIN].loc);
}


#ifdef _PROTOTYPES_
Aword where(Aword id)
#else
Aword where(id)
     Aword id;
#endif
{
  char str[80];

  if (isObj(id))
    return objloc(id);
  else if (isAct(id))
    return actloc(id);
  else {
    sprintf(str, "Can't WHERE item (%ld).", id);
    syserr(str);
  }
  return(EOF);
}



/*----------------------------------------------------------------------

  aggregates

  */

#ifdef _PROTOTYPES_
Aword agrmax(Aword atr, Aword whr)
#else
Aword agrmax(atr, whr)
     Aword atr, whr;
#endif
{
  Aword i;
  Aword max = 0;

  for (i = OBJMIN; i <= OBJMAX; i++) {
    if (isLoc(whr)) {
      if (where(i) == whr && attribute(i, atr) > max)
	max = attribute(i, atr);
    } else if (objs[i-OBJMIN].loc == whr && attribute(i, atr) > max)
	max = attribute(i, atr);
  }
  return(max);
}

#ifdef _PROTOTYPES_
Aword agrsum(Aword atr, Aword whr)
#else
Aword agrsum(atr, whr)
     Aword atr, whr;
#endif
{
  Aword i;
  Aword sum = 0;

  for (i = OBJMIN; i <= OBJMAX; i++) {
    if (isLoc(whr)) {
      if (where(i) == whr)
	sum += attribute(i, atr);
    } else if (objs[i-OBJMIN].loc == whr)
      sum += attribute(i, atr);
  }
  return(sum);
}


#ifdef _PROTOTYPES_
Aword agrcount(Aword whr)
#else
Aword agrcount(whr)
     Aword whr;
#endif
{
  Aword i;
  Aword count = 0;

  for (i = OBJMIN; i <= OBJMAX; i++) {
    if (isLoc(whr)) {
      if (where(i) == whr)
	count++;
    } else if (objs[i-OBJMIN].loc == whr)
	count++;
  }
  return(count);
}


/*----------------------------------------------------------------------

  locate()

  */

#ifdef _PROTOTYPES_
static void locobj(Aword obj, Aword whr)
#else
static void locobj(obj, whr)
     Aword obj, whr;
#endif
{
  if (isCnt(whr)) { /* Into a container */
    if (whr == obj)
      syserr("Locating something inside itself.");
    if (checklim(whr, obj))
      return;
    else
      objs[obj-OBJMIN].loc = whr;
  } else {
    objs[obj-OBJMIN].loc = whr;
    /* Make sure the location is described since it's changed */
    locs[whr-LOCMIN].describe = 0;
  }
}


#ifdef _PROTOTYPES_
static void locact(Aword act, Aword whr)
#else
static void locact(act, whr)
     Aword act, whr;
#endif
{
  Aword prevact = cur.act;
  Aword prevloc = cur.loc;

  cur.loc = whr;
  acts[act-ACTMIN].loc = whr;
  if (act == HERO) {
    if (locs[acts[act-ACTMIN].loc-LOCMIN].describe % (cur.visits+1) == 0)
      look();
    else {
      if (anyOutput)
	para();
      say(where(HERO));
      prmsg(M_AGAIN);
      needsp = FALSE;
      output(".");
      newline();
      dscrobjs();
      dscracts();
    }
    locs[where(HERO)-LOCMIN].describe++;
    locs[where(HERO)-LOCMIN].describe %= (cur.visits+1);
  } else
    locs[whr-LOCMIN].describe = 0;
  if (locs[cur.loc-LOCMIN].does != 0) {
    cur.act = act;
    interpret(locs[cur.loc-LOCMIN].does);
    cur.act = prevact;
  }

  if (cur.act != act)
    cur.loc = prevloc;
}


#ifdef _PROTOTYPES_
void locate(Aword id, Aword whr)
#else
void locate(id, whr)
     Aword id, whr;
#endif
{
  char str[80];

  if (isObj(id))
    locobj(id, whr);
  else if (isAct(id))
    locact(id, whr);
  else {
    sprintf(str, "Can't LOCATE item (%ld).", id);
    syserr(str);
  }
}


/*----------------------------------------------------------------------

  isHere()

  */

#ifdef _PROTOTYPES_
static Abool objhere(Aword obj)
#else
static Abool objhere(obj)
     Aword obj;
#endif
{
  if (isCnt(objs[obj-OBJMIN].loc)) {	/* In something? */
    if (isObj(objs[obj-OBJMIN].loc) || isAct(objs[obj-OBJMIN].loc))
      return(isHere(objs[obj-OBJMIN].loc));
    else /* If the container wasn't anywhere, assume where HERO is! */
      return(where(HERO) == cur.loc);
  } else
    return(objs[obj-OBJMIN].loc == cur.loc);
}


#ifdef _PROTOTYPES_
static Aword acthere(Aword act)
#else
static Aword acthere(act)
     Aword act;
#endif
{
  return(acts[act-ACTMIN].loc == cur.loc);
}


#ifdef _PROTOTYPES_
Aword isHere(Aword id)
#else
Aword isHere(id)
     Aword id;
#endif
{
  char str[80];

  if (isObj(id))
    return objhere(id);
  else if (isAct(id))
    return acthere(id);
  else {
    sprintf(str, "Can't HERE item (%ld).", id);
    syserr(str);
  }
  return(EOF);
}

/*----------------------------------------------------------------------

  isNear()

  */

#ifdef _PROTOTYPES_
static Aword objnear(Aword obj)
#else
static Aword objnear(obj)
     Aword obj;
#endif
{
  if (isCnt(objs[obj-OBJMIN].loc)) {	/* In something? */
    if (isObj(objs[obj-OBJMIN].loc) || isAct(objs[obj-OBJMIN].loc))
      return(isNear(objs[obj-OBJMIN].loc));
    else  /* If the container wasn't anywhere, assume here, so not nearby! */
      return(FALSE);
  } else
    return(exitto(where(obj), cur.loc));
}


#ifdef _PROTOTYPES_
static Aword actnear(Aword act)
#else
static Aword actnear(act)
     Aword act;
#endif
{
  return(exitto(where(act), cur.loc));
}


#ifdef _PROTOTYPES_
Abool isNear(Aword id)
#else
Abool isNear(id)
     Aword id;
#endif
{
  char str[80];

  if (isObj(id))
    return objnear(id);
  else if (isAct(id))
    return actnear(id);
  else {
    sprintf(str, "Can't NEAR item (%ld).", id);
    syserr(str);
  }
  return(EOF);
}



/*----------------------------------------------------------------------

  in()

  */

#ifdef _PROTOTYPES_
Abool in(Aword obj, Aword cnt)
#else
Abool in(obj, cnt)
     Aword obj;
     Aword cnt;
#endif
{
  if (!isObj(obj))
    return(FALSE);
  if (!isCnt(cnt))
    syserr("IN in a non-container.");

  return(objs[obj-OBJMIN].loc == cnt);
}


/*----------------------------------------------------------------------

  say()

  */

#ifdef _PROTOTYPES_
static void sayloc(Aword loc)
#else
static void sayloc(loc)
     Aword loc;
#endif
{
  interpret(locs[loc-LOCMIN].nams);
}


#ifdef _PROTOTYPES_
static void sayobj(Aword obj)
#else
static void sayobj(obj)
     Aword obj;
#endif
{
  interpret(objs[obj-OBJMIN].dscr2);
}

#ifdef _PROTOTYPES_
static void sayact(Aword act)
#else
static void sayact(act)
     Aword act;
#endif
{
  interpret(acts[act-ACTMIN].nam);
}


#ifdef _PROTOTYPES_
void sayint(Aword val)
#else
void sayint(val)
     Aword val;
#endif
{
  char buf[25];

  sprintf(buf, "%ld", val);
  output(buf);
}


#ifdef _PROTOTYPES_
void saystr(char *str)
#else
void saystr(str)
     char *str;
#endif
{
  output(str);
  free(str);
}


#ifdef _PROTOTYPES_
static void saylit(Aword lit)
#else
static void saylit(lit)
     Aword lit;
#endif
{
  char *str;

  if (isNum(lit))
    sayint(litValues[lit-LITMIN].value);
  else {
    str = (char *)strdup((char *)litValues[lit-LITMIN].value);
    saystr(str);
  }    
}

#ifdef _PROTOTYPES_
void say(Aword id)
#else
void say(id)
     Aword id;
#endif
{
  char str[80];

  if (isObj(id))
    sayobj(id);
  else if (isLoc(id))
    sayloc(id);
  else if (isAct(id))
    sayact(id);
  else if (isLit(id))
    saylit(id);
  else {
    sprintf(str, "Can't SAY item (%ld).", id);
    syserr(str);
  }
}


/*----------------------------------------------------------------------

  describe()

  */

#ifdef _PROTOTYPES_
static void dscrloc(Aword loc)
#else
static void dscrloc(loc)
     Aword loc;
#endif
{
  if (locs[loc-LOCMIN].dscr != 0)
    interpret(locs[loc-LOCMIN].dscr);
}


#ifdef _PROTOTYPES_
static void dscrobj(Aword obj)
#else
static void dscrobj(obj)
     Aword obj;
#endif
{
  objs[obj-OBJMIN].describe = FALSE;
  if (objs[obj-OBJMIN].dscr1 != 0)
    interpret(objs[obj-OBJMIN].dscr1);
  else {
    prmsg(M_SEEOBJ1);
    say(obj);
    prmsg(M_SEEOBJ4);
    if (objs[obj-OBJMIN].cont != 0)
      list(obj);
  }
}


#ifdef _PROTOTYPES_
static void dscract(Aword act)
#else
static void dscract(act)
     Aword act;
#endif
{
  ScrElem *scr = NULL;

  if (acts[act-ACTMIN].script != 0) {
    for (scr = (ScrElem *) addrTo(acts[act-ACTMIN].scradr); !endOfTable(scr); scr++)
      if (scr->code == acts[act-ACTMIN].script)
	break;
    if (endOfTable(scr)) scr = NULL;
  }
  if (scr != NULL && scr->dscr != 0)
    interpret(scr->dscr);
  else if (acts[act-ACTMIN].dscr != 0)
    interpret(acts[act-ACTMIN].dscr);
  else {
    interpret(acts[act-ACTMIN].nam);
    prmsg(M_SEEACT);
  }
  acts[act-ACTMIN].describe = FALSE;
}


static Aword dscrstk[255];
int dscrstkp = 0;

#ifdef _PROTOTYPES_
void describe(Aword id)
#else
void describe(id)
     Aword id;
#endif
{
  int i;
  char str[80];

  for (i = 0; i < dscrstkp; i++)
    if (dscrstk[i] == id)
      syserr("Recursive DESCRIBE.");
  dscrstk[dscrstkp++] = id;

  if (isObj(id))
    dscrobj(id);
  else if (isLoc(id))
    dscrloc(id);
  else if (isAct(id))
    dscract(id);
  else {
    sprintf(str, "Can't DESCRIBE item (%ld).", id);
    syserr(str);
  }

  dscrstkp--;
}


/*----------------------------------------------------------------------

  use()

  */

#ifdef _PROTOTYPES_
void use(Aword act, Aword scr)
#else
void use(act, scr)
     Aword act, scr;
#endif
{
  char str[80];

  if (!isAct(act)) {
    sprintf(str, "Item is not an Actor (%ld).", act);
    syserr(str);
  }

  acts[act-ACTMIN].script = scr;
  acts[act-ACTMIN].step = 0;
}



/*----------------------------------------------------------------------

  list()

  */

#ifdef _PROTOTYPES_
void list(Aword cnt)
#else
void list(cnt)
     Aword cnt;
#endif
{
  int i;
  Aword props;
  Aword prevobj;
  Boolean found = FALSE;
  Boolean multiple = FALSE;

  /* Find container properties */
  if (isObj(cnt))
    props = objs[cnt-OBJMIN].cont;
  else if (isAct(cnt))
    props = acts[cnt-ACTMIN].cont;
  else
    props = cnt;

  for (i = OBJMIN; i <= OBJMAX; i++) {
    if (in(i, cnt)) { /* Yes, it's in this container */
      if (!found) {
	found = TRUE;
	if (cnts[props-CNTMIN].header != 0)
	  interpret(cnts[props-CNTMIN].header);
	else {
	  prmsg(M_CONTAINS1);
	  if (cnts[props-CNTMIN].parent != 0) /* It is actually an object or actor */
	    say(cnts[props-CNTMIN].parent);
	  else
	    interpret(cnts[props-CNTMIN].nam);
	  prmsg(M_CONTAINS2);
	}
      } else {
	if (multiple) {
	  needsp = FALSE;
	  prmsg(M_CONTAINS3);
	}
	multiple = TRUE;
	say(prevobj);
      }
      prevobj = i;
    }
  }

  if (found) {
    if (multiple)
      prmsg(M_CONTAINS4);
    say(prevobj);
    prmsg(M_CONTAINS5);
  } else {
    if (cnts[props-CNTMIN].empty != 0)
      interpret(cnts[props-CNTMIN].empty);
    else {
      prmsg(M_EMPTY1);
      if (cnts[props-CNTMIN].parent != 0) /* It is actually an object or actor */
	say(cnts[props-CNTMIN].parent);
      else
	interpret(cnts[props-CNTMIN].nam);
      prmsg(M_EMPTY2);
    }
  }
  needsp = TRUE;
}


/*----------------------------------------------------------------------

  empty()

  */

#ifdef _PROTOTYPES_
void empty(Aword cnt, Aword whr)
#else
void empty(cnt, whr)
     Aword cnt;
     Aword whr;
#endif
{
  int i;

  for (i = OBJMIN; i <= OBJMAX; i++)
    if (in(i, cnt))
      locate(i, whr);
}



/*----------------------------------------------------------------------*\

  Description of current location

  dscrobjs()
  dscracts()
  look()

\*----------------------------------------------------------------------*/

#ifdef _PROTOTYPES_
void dscrobjs(void)
#else
void dscrobjs()
#endif
{
  int i;
  int prevobj;
  Boolean found = FALSE;
  Boolean multiple = FALSE;

  /* First describe everything here with its own description */
  for (i = OBJMIN; i <= OBJMAX; i++)
    if (objs[i-OBJMIN].loc == cur.loc &&
	objs[i-OBJMIN].describe &&
	objs[i-OBJMIN].dscr1)
      describe(i);

  /* Then list everything else here */
  for (i = OBJMIN; i <= OBJMAX; i++)
    if (objs[i-OBJMIN].loc == cur.loc &&
	objs[i-OBJMIN].describe) {
      if (!found) {
	prmsg(M_SEEOBJ1);
	say(i);
	found = TRUE;
      } else {
	if (multiple) {
	  needsp = FALSE;
	  prmsg(M_SEEOBJ2);
	  say(prevobj);
	}
	multiple = TRUE;
      }
      prevobj = i;
    }

  if (found) {
    if (multiple) {
      prmsg(M_SEEOBJ3);
      say(prevobj);
    }
    prmsg(M_SEEOBJ4);
  }
  
  /* Set describe flag for all objects */
  for (i = OBJMIN; i <= OBJMAX; i++)
    objs[i-OBJMIN].describe = TRUE;
}


#ifdef _PROTOTYPES_
void dscracts(void)
#else
void dscracts()
#endif
{
  int i;
  
  for (i = HERO+1; i <= ACTMAX; i++)
    if (acts[i-ACTMIN].loc == cur.loc &&
	acts[i-ACTMIN].describe)
      describe(i);

  /* Set describe flag for all actors */
  for (i = HERO; i <= ACTMAX; i++)
    acts[i-ACTMIN].describe = TRUE;
}


#ifdef _PROTOTYPES_
void look(void)
#else
void look()
#endif
{
  int i;
  static Boolean looking = FALSE;

  if (looking)
    syserr("Recursive LOOK.");

  looking = TRUE;
  /* Set describe flag for all objects and actors */
  for (i = OBJMIN; i <= OBJMAX; i++)
    objs[i-OBJMIN].describe = TRUE;
  for (i = ACTMIN; i <= ACTMAX; i++)
    acts[i-ACTMIN].describe = TRUE;

  if (anyOutput)
    para();
  say(cur.loc);
  needsp = FALSE;
  output(".");
  newline();
  describe(cur.loc);
  dscrobjs();
  dscracts();
  looking = FALSE;
}



static char savfnm[256];


/*----------------------------------------------------------------------

  save()

  */

#ifdef _PROTOTYPES_
void save(void)
#else
void save()
#endif
{
  int i;
  FILE *savfil;
  char str[256];
  AtrElem *atr;

  /* First save ? */
  if (savfnm[0] == '\0') {
    strcpy(savfnm, advnam);
    strcat(savfnm, ".sav");
  }
  prmsg(M_SAVEWHERE);
  sprintf(str, "(%s) : ", savfnm);
  output(str);
  gets(str); col = 1;
  if (str[0] == '\0')
    strcpy(str, savfnm);
  if ((savfil = fopen(str, "r")) != NULL)
    /* It already existed */
    if (!confirm(M_SAVEOVERWRITE))
      error(M_NOMSG);
  if ((savfil = fopen(str, "w")) == NULL)
    error(M_SAVEFAILED);
  strcpy(savfnm, str);

  /* Save version of interpreter and name of game */
  fwrite((void *)&header->vers, sizeof(Aword), 1, savfil);
  fwrite((void *)advnam, strlen(advnam)+1, 1, savfil);
  /* Save current values */
  fwrite((void *)&cur, sizeof(cur), 1, savfil);
  /* Save actors */
  for (i = ACTMIN; i <= ACTMAX; i++) {
    fwrite((void *)&acts[i-ACTMIN].loc, sizeof(Aword), 1, savfil);
    fwrite((void *)&acts[i-ACTMIN].script, sizeof(Aword), 1, savfil);
    fwrite((void *)&acts[i-ACTMIN].step, sizeof(Aword), 1, savfil);
    fwrite((void *)&acts[i-ACTMIN].count, sizeof(Aword), 1, savfil);
    if (acts[i-ACTMIN].atrs)
      for (atr = (AtrElem *) addrTo(acts[i-ACTMIN].atrs); !endOfTable(atr); atr++)
	fwrite((void *)&atr->val, sizeof(Aword), 1, savfil);
  }

  /* Save locations */
  for (i = LOCMIN; i <= LOCMAX; i++) {
    fwrite((void *)&locs[i-LOCMIN].describe, sizeof(Aword), 1, savfil);
    if (locs[i-LOCMIN].atrs)
      for (atr = (AtrElem *) addrTo(locs[i-LOCMIN].atrs); !endOfTable(atr); atr++)
	fwrite((void *)&atr->val, sizeof(Aword), 1, savfil);
  }

  /* Save objects */
  for (i = OBJMIN; i <= OBJMAX; i++) {
    fwrite((void *)&objs[i-OBJMIN].loc, sizeof(Aword), 1, savfil);
    if (objs[i-OBJMIN].atrs)
      for (atr = (AtrElem *) addrTo(objs[i-OBJMIN].atrs); !endOfTable(atr); atr++)
	fwrite((void *)&atr->val, sizeof(atr->val), 1, savfil);
  }

  /* Save the event queue */
  eventq[etop].time = 0;	/* Mark the top */
  fwrite((void *)&eventq[0], sizeof(eventq[0]), etop+1, savfil);

  /* Save scores */
  for (i = 0; scores[i] != EOF; i++)
    fwrite((void *)&scores[i], sizeof(Aword), 1, savfil);

  fclose(savfil);
}


/*----------------------------------------------------------------------

  restore()

  */

#ifdef _PROTOTYPES_
void restore(void)
#else
void restore()
#endif
{
  int i;
  FILE *savfil;
  char str[256];
  AtrElem *atr;
  Aword savedVersion;
  char savedName[256];

  /* First save ? */
  if (savfnm[0] == '\0') {
    strcpy(savfnm, advnam);
    strcat(savfnm, ".sav");
  }
  prmsg(M_RESTOREFROM);
  sprintf(str, "(%s) : ", savfnm);
  output(str);
  gets(str); col = 1;
  if (str[0] == '\0')
    strcpy(str, savfnm);	/* Use the name temporarily */
  if ((savfil = fopen(str, "r")) == NULL)
    error(M_SAVEMISSING);
  strcpy(savfnm, str);		/* Save it for future use */

  fread((void *)&savedVersion, sizeof(Aword), 1, savfil);
  if (savedVersion != header->vers) {
    fclose(savfil);
    error(M_SAVEVERS);
    return;
  }
  i = 0;
  while ((savedName[i++] = fgetc(savfil)) != '\0');
  if (strcmp(savedName, advnam) != 0) {
    fclose(savfil);
    error(M_SAVENAME);
    return;
  }

  /* Restore current values */
  fread((void *)&cur, sizeof(cur), 1, savfil);
  /* Restore actors */
  for (i = ACTMIN; i <= ACTMAX; i++) {
    fread((void *)&acts[i-ACTMIN].loc, sizeof(Aword), 1, savfil);
    fread((void *)&acts[i-ACTMIN].script, sizeof(Aword), 1, savfil);
    fread((void *)&acts[i-ACTMIN].step, sizeof(Aword), 1, savfil);
    fread((void *)&acts[i-ACTMIN].count, sizeof(Aword), 1, savfil);
    if (acts[i-ACTMIN].atrs)
      for (atr = (AtrElem *) addrTo(acts[i-ACTMIN].atrs); !endOfTable(atr); atr++)
	fread((void *)&atr->val, sizeof(Aword), 1, savfil);
  }

  /* Restore locations */
  for (i = LOCMIN; i <= LOCMAX; i++) {
    fread((void *)&locs[i-LOCMIN].describe, sizeof(Aword), 1, savfil);
    if (locs[i-LOCMIN].atrs)
      for (atr = (AtrElem *) addrTo(locs[i-LOCMIN].atrs); !endOfTable(atr); atr++)
	fread((void *)&atr->val, sizeof(Aword), 1, savfil);
  }

  /* Restore objects */
  for (i = OBJMIN; i <= OBJMAX; i++) {
    fread((void *)&objs[i-OBJMIN].loc, sizeof(Aword), 1, savfil);
    if (objs[i-OBJMIN].atrs)
      for (atr = (AtrElem *) addrTo(objs[i-OBJMIN].atrs); !endOfTable(atr); atr++)
	fread((void *)&atr->val, sizeof(atr->val), 1, savfil);
  }

  /* Restore the eventq */
  etop = 0;
  do {
    fread((void *)&eventq[etop], sizeof(eventq[0]), 1, savfil);
    etop++;
  } while (eventq[etop-1].time != 0);
  etop--;

  /* Restore scores */
  for (i = 0; scores[i] != EOF; i++)
    fread((void *)&scores[i], sizeof(Aword), 1, savfil);

  fclose(savfil);
}



/*----------------------------------------------------------------------

  rnd()

  */

#ifdef _PROTOTYPES_
Aword rnd(Aword from, Aword to)
#else
Aword rnd(from, to)
     Aword from, to;
#endif
{
  if (to == from)
    return to;
  else if (to > from)
    return rand()%(to-from+1)+from;
  else
    return rand()%(from-to+1)+to;
}



/*----------------------------------------------------------------------

  streq()

  Compare two strings approximately, ignore case

  */
#ifdef _PROTOTYPES_
Abool streq(char a[], char b[])
#else
Abool streq(a, b)
     char a[], b[];		/* IN - Strings to compare */
#endif
{
  Boolean eq;

  strlow(a);
  strlow(b);

  eq = (strcmp(a, b) == 0);

  free(a);
  free(b);

  return(eq);
}
