/*----------------------------------------------------------------------*\

  debug.c

  Debugger unit in Alan interpreter ARUN

\*----------------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#include "types.h"
#ifdef HAVE_SHORT_FILENAMES
#include "av.h"
#else
#include "alan.version.h"
#endif


#ifdef USE_READLINE
#include "readline.h"
#endif


#include "inter.h"
#include "main.h"
#include "parse.h"
#include "exe.h"

#include "debug.h"

#ifdef GLK
#include "glkio.h"
#endif

#ifdef _PROTOTYPES_
static void showatrs(
  Aword atradr
)
#else
static void showatrs(atradr)
  Aword atradr;
#endif
{
  AttributeEntry *at;
  int i;
  char str[80];

  if (atradr == 0) return;

  i = 1;
  for (at = (AttributeEntry *) addrTo(atradr); !endOfTable(at); at++) {
    sprintf(str, "$i%3d: %ld (%s)", i, at->value, (char *) addrTo(at->stringAddress));
#if ISO == 0
    fromIso(str, str);
#endif
    output(str);
    i++;
  }
}


#ifdef _PROTOTYPES_
static void showobjs(void)
#else
static void showobjs()
#endif
{
  char str[80];
  int obj;

  output("OBJECTS:");
  for (obj = OBJMIN; obj <= OBJMAX; obj++) {
    sprintf(str, "$i%3d: ", obj);
    output(str);
    say(obj);
  }
}


#ifdef _PROTOTYPES_
static void showobj(
  int obj
)
#else
static void showobj(obj)
  int obj;
#endif
{
  char str[80];


  if (!isObj(obj)) {
    sprintf(str, "Object number out of range. Between %ld and %ld, please.", OBJMIN, OBJMAX);
    output(str);
    return;
  }

  sprintf(str, "OBJECT %d :", obj);
  output(str);
  say(obj);

  sprintf(str, "$iLocation = %ld", where(obj));
  output(str);
  if (isLoc(instance[obj].location))
    say(instance[obj].location);
  else if (isCnt(instance[obj].location)) {

    if (isObj(instance[obj].location))
      output("in");
    else if (isAct(instance[obj].location))
      output("carried by");
    say(instance[obj].location);

  } else if (instance[obj].location == 0)
    output("nowhere");
  else
    output("Illegal location!");


  output("$iAttributes =");
  showatrs(instance[obj].attributes);

}


#ifdef _PROTOTYPES_
static void showcnts(void)
#else
static void showcnts()
#endif
{
  char str[80];
  int cnt;

  output("CONTAINERS:");
  for (cnt = CNTMIN; cnt <= CNTMAX; cnt++) {
    sprintf(str, "$i%3d: ", cnt);
    output(str);
    if (container[cnt].parent != 0)
      say(container[cnt].parent);
  }

}


#ifdef _PROTOTYPES_
static void showcnt(
  int cnt
)
#else
static void showcnt(cnt)
  int cnt;
#endif
{
  char str[80];
  int i;
  Abool found = FALSE;

  if (cnt < CNTMIN || cnt > CNTMAX) {
    sprintf(str, "Container number out of range. Between %ld and %ld, please.", CNTMIN, CNTMAX);
    output(str);
    return;
  }

  sprintf(str, "CONTAINER %d :", cnt);
  output(str);
  if (container[cnt].parent != 0) {
    cnt = container[cnt].parent;
    say(cnt);
    sprintf(str, "$iLocation = %ld", where(cnt));
    output(str);
  }
  output("$iContains ");
  for (i = OBJMIN; i <= OBJMAX; i++) {
    if (in(i, cnt)) { /* Yes, it's in this container */
      if (!found) {
	output("$n");
	found = TRUE;
      }
      sprintf(str, "$t$t%d: ", i);
      output(str);
      say(i);
    }
  }
  if (!found)
    output("nothing");
}


#ifdef _PROTOTYPES_
static void showlocs(void)
#else
static void showlocs()
#endif
{
  char str[80];
  int loc;

  output("LOCATIONS:");
  for (loc = LOCMIN; loc <= LOCMAX; loc++) {
    sprintf(str, "$i%3d: ", loc);
    output(str);
    say(loc);
  }
}


#ifdef _PROTOTYPES_
static void showloc(
  int loc
)
#else
static void showloc(loc)
  int loc;
#endif
{
  char str[80];


  if (!isLoc(loc)) {
    sprintf(str, "Location number out of range. Between %ld and %ld, please.", LOCMIN, LOCMAX);
    output(str);
    return;
  }

  sprintf(str, "LOCATION %d :", loc);
  output(str);
  say(loc);

  output("$iAttributes =");
  showatrs(instance[loc].attributes);
}


#ifdef _PROTOTYPES_
static void showacts(void)
#else
static void showacts()
#endif
{
  char str[80];
  int act;

  output("ACTORS:");
  for (act = ACTMIN; act <= ACTMAX; act++) {
    sprintf(str, "$i%3d:", act);
    output(str);
    say(act);
  }
}


#ifdef _PROTOTYPES_
static void showact(
  int act
)
#else
static void showact(act)
  int act;
#endif
{
  char str[80];
  Boolean oldstp;
  
  if (!isAct(act)) {
    sprintf(str, "Actor number out of range. Between %ld and %ld, please.", ACTMIN, ACTMAX);
    output(str);
    return;
  }
  
  sprintf(str, "ACTOR %d :", act);
  output(str);
  oldstp = stpflg; stpflg = FALSE; /* Make sure not to trace this! */
  say(act);
  stpflg = oldstp;

  sprintf(str, "$iLocation = %ld", instance[act].location);
  output(str);
  if (isLoc(instance[act].location))
    say(instance[act].location);
  else if (instance[act].location == 0)
    output("nowhere");
  else
    output("Illegal location!");

  sprintf(str, "$iScript = %ld", admin[act].script);
  output(str);

  sprintf(str, "$iStep = %ld", admin[act].step);
  output(str);

  output("$iAttributes =");
  showatrs(instance[act].attributes);
}


#ifdef _PROTOTYPES_
static void showevts(void)
#else
static void showevts()
#endif
{
  int evt, i;
  char str[80];
  Boolean scheduled;

  output("EVENTS:");
  for (evt = EVTMIN; evt <= EVTMAX; evt++) {
    sprintf(str, "$i%d (%s):", evt, (char *)addrTo(evts[evt-EVTMIN].stradr));
#if ISO == 0
    fromIso(str, str);
#endif
    output(str);
    scheduled = FALSE;
    for (i = 0; i < etop; i++)
      if ((scheduled = (eventq[i].event == evt)))
	break;
    if (scheduled) {
      sprintf(str, "Scheduled for +%d, at ", eventq[i].time-cur.tick);
      output(str);
      say(eventq[i].where);
    } else
      output("Not scheduled.");
  }
}


static Boolean trc, stp;
static int loc;

#ifdef _PROTOTYPES_
void saveInfo(void)
#else
void saveInfo()
#endif
{
  /* Save some important things */
  trc = trcflg; trcflg = FALSE;
  stp = stpflg; stpflg = FALSE;
  loc = cur.loc; cur.loc = where(HERO);
}

#ifdef _PROTOTYPES_
void restoreInfo(void)
#else
void restoreInfo()
#endif
{
  /* Restore! */
  trcflg = trc;
  stpflg = stp;
  cur.loc = loc;
}


#ifdef _PROTOTYPES_
void debug(void)
#else
void debug()
#endif
{
  char buf[256];
  char c;
  int i;

  saveInfo();
  while (TRUE) {
    if (anyOutput)
      para();
    do {
      output("ABUG> ");
#ifdef USE_READLINE
      (void) readline(buf);
#else
      fgets(buf, 255, stdin);
#endif
      lin = 1;
      c = buf[0];
      i = 0;
      sscanf(&buf[1], "%d", &i);
    } while (buf && c == '\0');

    switch (toUpper(c)) {
    case 'H':
    case '?':
      output(alan.longHeader);
      output("$nABUG Commands:\
      $iO [n] -- show object[s]\
      $iA [n] -- show actor[s]\
      $iL [n] -- show location[s]\
      $iC [n] -- show container[s]\
      $iE -- show events\
      $iG -- go on\
      $iT -- toggle trace mode\
      $iS -- toggle step mode\
      $iX -- exit debug mode\
      $iQ -- quit game");
      break;
    case 'Q':
      terminate(0);
    case 'X':
      dbgflg = FALSE;		/* Fall through to 'G' */
    case 'G':
      restoreInfo();
      return;
    case 'O':
      if (i == 0)
        showobjs();
      else
	showobj(i);
      break;
    case 'C':
      if (i == 0)
        showcnts();
      else
	showcnt(i);
      break;
    case 'A':
      if (i == 0)
        showacts();
      else
	showact(i);
      break;
    case 'L':
      if (i == 0)
        showlocs();
      else
	showloc(i);
      break;
    case 'E':
      showevts();
      break;
    case 'S':
      if ((stp = !stp))
        printf("Step on.");
      else
        printf("Step off.");
      break;      
    case 'T':
      if ((trc = !trc))
        printf("Trace on.");
      else
        printf("Trace off.");
      break;      
    default:
      output("Unknown ABUG command. ? for help.");
      break;
    }
  }
}


/*======================================================================

  debugsay()

  Say somethin, but make sure we don't disturb anything and that it is
  shown to the player.

*/
#ifdef _PROTOTYPES_
void debugsay(int item)
#else
void debugsay(item)
     int item;
#endif
{
  saveInfo();
  needsp = FALSE;
  col = 1;
  if (item == 0)
    printf("$null$");
  else
    say(item);
  needsp = FALSE;
  col = 1;
  restoreInfo();
}
