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
static void showAttributes(
  Aword atradr
)
#else
static void showAttributes(atradr)
  Aword atradr;
#endif
{
  AttributeEntry *at;
  int i;
  char str[80];

  if (atradr == 0) return;

  i = 1;
  for (at = (AttributeEntry *) pointerTo(atradr); !endOfTable(at); at++) {
    sprintf(str, "$i$t%s(%d) = %ld", (char *) pointerTo(at->stringAddress), i, at->value);
#if ISO == 0
    fromIso(str, str);
#endif
    output(str);
    i++;
  }
}


static void showContents(int cnt) {
  int i;
  char str[80];
  Abool found;

  output("$iContains:");
  for (i = 1; i <= header->instanceMax; i++) {
    if (in(i, cnt)) { /* Yes, it's in this container */
      if (!found)
	found = TRUE;
      output("$i$t");
      say(i);
      sprintf(str, "(%d) ", i);
      output(str);
    }
  }
  if (!found)
    output("nothing");
}



#ifdef _PROTOTYPES_
static void showInstances(void)
#else
static void showInstances()
#endif
{
  char str[80];
  int ins;

  output("Instances:");
  for (ins = 1; ins <= header->instanceMax; ins++) {
    sprintf(str, "$i%3d: ", ins);
    output(str);
    say(ins);
    if (instance[ins].container)
      output("(container)");
  }
}


#ifdef _PROTOTYPES_
static void showInstance(
  int ins
)
#else
static void showInstance(ins)
  int ins;
#endif
{
  char str[80];

  if (ins > header->instanceMax) {
    sprintf(str, "Instance code %d is out of range", ins);
    output(str);
    return;
  }

  output("The $$");
  say(ins);
  sprintf(str, "$$ (%d)", ins);
  output(str);
  if (instance[ins].parent) {
    sprintf(str, "Isa %s", (char *)pointerTo(class[instance[ins].parent].idAddress));
    output(str);
  }

  if (!isA(ins, header->locationClassId)) {
    sprintf(str, "$iLocation: ");
    output(str);
    if (instance[ins].location == 0)
      output("- (0)");
    else if (isLoc(instance[ins].location)) {
      say(instance[ins].location);
      sprintf(str, "(%ld)", where(ins));
      output(str);
    } else if (isCnt(instance[ins].location)) {

      if (isObj(instance[ins].location))
	output("in");
      else if (isAct(instance[ins].location))
	output("carried by");
      say(instance[ins].location);
      sprintf(str, "(%ld)", instance[ins].location);
      output(str);

    } else
      output("Illegal location!");
  }

  output("$iAttributes:");
  showAttributes(instance[ins].attributes);

  if (instance[ins].container)
    showContents(ins);
      
  if (isA(ins, header->actorClassId)) {
    if (admin[ins].script == 0)
      output("$iIs idle");
    else {
      sprintf(str, "$iExecuting script: %ld, Step: %ld", admin[ins].script, admin[ins].step);
      output(str);
    }
  }
}


#ifdef _PROTOTYPES_
static void showObjects(void)
#else
static void showObjects()
#endif
{
  char str[80];
  int obj;

  output("Objects:");
  for (obj = 1; obj <= header->instanceMax; obj++) {
    if (isObj(obj)) {
      sprintf(str, "$i%3d: ", obj);
      output(str);
      say(obj);
    }
  }
}


#ifdef _PROTOTYPES_
static void showObject(
  int obj
)
#else
static void showObject(obj)
  int obj;
#endif
{
  char str[80];


  if (!isObj(obj)) {
    sprintf(str, "Instance %d is not an object", obj);
    output(str);
    return;
  }

  showInstance(obj);

}


#ifdef _PROTOTYPES_
static void showcnts(void)
#else
static void showcnts()
#endif
{
  char str[80];
  int cnt;

  output("Containers:");
  for (cnt = 1; cnt <= header->containerMax; cnt++) {
    sprintf(str, "$i%3d: ", cnt);
    output(str);
    if (container[cnt].owner != 0)
      say(container[cnt].owner);
  }

}


#ifdef _PROTOTYPES_
static void showClass(int c)
#else
static void showClass(c)
     int c;
#endif
{
  char str[80];

  output("$t");
  output((char *)pointerTo(class[c].idAddress));
  sprintf(str, "(%d)", c);
  output(str);
  if (class[c].parent != 0) {
    output("Isa");
    output((char *)pointerTo(class[class[c].parent].idAddress));
    sprintf(str, "(%ld)", class[c].parent);
    output(str);
  }
}


#ifdef _PROTOTYPES_
static void showClasses(void)
#else
static void showClasses()
#endif
{
  int c;

  output("Classes:");
  for (c = 1; c <= header->classMax; c++) {
    output("$n");
    showClass(c);
  }
}


#ifdef _PROTOTYPES_
static void showContainer(
  int cnt
)
#else
static void showContainer(cnt)
  int cnt;
#endif
{
  char str[80];

  if (cnt < 1 || cnt > header->containerMax) {
    sprintf(str, "Container number out of range. Between 1 and %ld, please.", header->containerMax);
    output(str);
    return;
  }

  sprintf(str, "Container %d :", cnt);
  output(str);
  if (container[cnt].owner != 0) {
    cnt = container[cnt].owner;
    say(cnt);
    sprintf(str, "$iLocation: %ld", where(cnt));
    output(str);
  }
  showContents(cnt);
}


#ifdef _PROTOTYPES_
static void showLocations(void)
#else
static void showLocations()
#endif
{
  char str[80];
  int loc;

  output("Locations:");
  for (loc = 1; loc <= header->instanceMax; loc++) {
    if (isLoc(loc)) {
      sprintf(str, "$i%3d: ", loc);
      output(str);
      say(loc);
    }
  }
}


#ifdef _PROTOTYPES_
static void showLocation(
  int loc
)
#else
static void showLocation(loc)
  int loc;
#endif
{
  char str[80];


  if (!isLoc(loc)) {
    sprintf(str, "Instance %d is not a location.", loc);
    output(str);
    return;
  }

  output("The ");
  say(loc);
  sprintf(str, "(%d) Isa location :", loc);
  output(str);

  output("$iAttributes =");
  showAttributes(instance[loc].attributes);
}


#ifdef _PROTOTYPES_
static void showActors(void)
#else
static void showActors()
#endif
{
  char str[80];
  int act;

  output("Actors:");
  for (act = 1; act <= header->instanceMax; act++) {
    if (isAct(act)) {
      output("$i");
      say(act);
      sprintf(str, "(%d)", act);
      output(str);
      if (instance[act].container)
	output("(container)");
    }
  }
}


#ifdef _PROTOTYPES_
static void showActor(
  int act
)
#else
static void showActor(act)
  int act;
#endif
{
  char str[80];
  
  if (!isAct(act)) {
    sprintf(str, "Instance %d is not an actor.", act);
    output(str);
    return;
  }
  
  showInstance(act);
}


#ifdef _PROTOTYPES_
static void showEvents(void)
#else
static void showEvents()
#endif
{
  int event, i;
  char str[80];
  Boolean scheduled;

  output("EVENTS:");
  for (event = 1; event <= header->eventMax; event++) {
    sprintf(str, "$i%d (%s):", event, (char *)pointerTo(events[event].stringAddress));
#if ISO == 0
    fromIso(str, str);
#endif
    output(str);
    scheduled = FALSE;
    for (i = 0; i < etop; i++)
      if ((scheduled = (eventQueue[i].event == event)))
	break;
    if (scheduled) {
      sprintf(str, "Scheduled for +%d, at ", eventQueue[i].time-current.tick);
      output(str);
      say(eventQueue[i].where);
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
  trc = traceOption; traceOption = FALSE;
  stp = singleStepOption; singleStepOption = FALSE;
  loc = current.location; current.location = where(HERO);
}

#ifdef _PROTOTYPES_
void restoreInfo(void)
#else
void restoreInfo()
#endif
{
  /* Restore! */
  traceOption = trc;
  singleStepOption = stp;
  current.location = loc;
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
      output("abug> ");
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
      $iC [n] -- show class[es]\
      $iI [n] -- show instance[s]\
      $iO [n] -- show instances that are object[s]\
      $iA [n] -- show instances that are actor[s]\
      $iL [n] -- show instances that are location[s]\
      $iE -- show events\
      $iG -- go another player turn\
      $iT -- toggle trace mode\
      $iS -- toggle step mode\
      $iX -- exit debug mode and return to game\
      $iQ -- quit game");
      break;
    case 'Q':
      terminate(0);
    case 'X':
      debugOption = FALSE;		/* Fall through to 'G' */
    case 'G':
      restoreInfo();
      return;
    case 'I':
      if (i == 0)
	showInstances();
      else
	showInstance(i);
      break;
    case 'O':
      if (i == 0)
        showObjects();
      else
	showObject(i);
      break;
    case 'C':
      if (i == 0)
        showClasses();
      else
	showClass(i);
      break;
    case 'A':
      if (i == 0)
        showActors();
      else
	showActor(i);
      break;
    case 'L':
      if (i == 0)
        showLocations();
      else
	showLocation(i);
      break;
    case 'E':
      showEvents();
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


/*======================================================================*/
void traceSay(int item)
{
  /*
    Say somethin, but make sure we don't disturb anything and that it is
    shown to the player. Needed for tracing. During debugging things are
    set up to avoid this problem.
  */

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
