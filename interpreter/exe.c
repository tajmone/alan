/*----------------------------------------------------------------------*\

  exe.c

  Amachine instruction execution unit of Alan interpreter

\*----------------------------------------------------------------------*/

#include "sysdep.h"
#include "types.h"
#include "act.h"
#include "set.h"
#include "debug.h"
#include "params.h"
#include "parse.h"
#include "syserr.h"

#ifdef USE_READLINE
#include "readline.h"
#endif


#ifdef HAVE_GLK
#include "glk.h"
#define MAP_STDIO_TO_GLK
#include "glkio.h"
#endif

#include "main.h"
#include "parse.h"
#include "inter.h"
#include "act.h"
#include "stack.h"
#include "decode.h"

#include "exe.h"

#define WIDTH 80

#ifdef DMALLOC
#include "dmalloc.h"
#endif

/* PUBLIC DATA */

int dscrstkp = 0;               /* Describe-stack pointer */


/* PRIVATE TYPES */
typedef struct GameState {
  /* Current data, can't use all of the CurVars (tick changes every move) */
  int score;

  /* Event queue */
  EventQueueEntry *eventQueue;
  int eventQueueTop;		/* Event queue top pointer */

  /* Amachine data structures - Dynamic */
  AdminEntry *admin;		/* Administrative data about instances */
  AttributeEntry *attributes;	/* Attributes data area */
  Aword *scores;		/* Score table pointer */

} GameState;

/* PRIVATE DATA */
static int gameStateTop = 0;
static int gameStateSize = 0;
static GameState *gameState = NULL;

/*----------------------------------------------------------------------*/
static void ensureSpaceForGameState() {
  if (gameStateTop == gameStateSize) {
    gameState = realloc(gameState, (gameStateSize+2)*sizeof(GameState));
    if (gameState == NULL) syserr("Out of memory in pushGameState()");
    gameStateSize += 2;
  }
}


/*----------------------------------------------------------------------*/
static Bool gameStateChanged(void)
{
  Aword *previousEventQueue = (Aword *)gameState[gameStateTop-1].eventQueue;
  Aword *previousAdmin = (Aword *)gameState[gameStateTop-1].admin;
  Aword *previousAttributes = (Aword *)gameState[gameStateTop-1].attributes;
  Aword *previousScores = (Aword *)gameState[gameStateTop-1].scores;

  if (gameStateTop == 0) return TRUE;

  /* Compare current game state with last saved */

  if (gameState[gameStateTop-1].eventQueueTop != eventQueueTop) return TRUE;

  if (eventQueueTop != gameState[gameStateTop-1].eventQueueTop)
    return TRUE;
  if (eventQueueTop > 0)
    if (!memcmp(eventQueue, previousEventQueue, eventQueueTop*sizeof(EventQueueEntry)/sizeof(Aword)))
      return TRUE;

  if (admin == NULL) syserr("admin[] == NULL in pushGameState()");

  if (memcmp(admin, previousAdmin, (header->instanceMax+1)*sizeof(AdminEntry)) != 0)
    return TRUE;

  if (attributes == NULL) syserr("attributes[] == NULL in gameStateChanged()");
  if (memcmp(attributes, previousAttributes, header->attributesAreaSize*sizeof(Aword)) != 0)
    return TRUE;

  if (gameState[gameStateTop-1].score != current.score) return TRUE;
  if (memcmp(scores, previousScores, header->scoreCount*sizeof(scores[0])) != 0)
    return TRUE;

  return FALSE;
}


/*======================================================================*/
void pushGameState(void) {

  ensureSpaceForGameState();

  if (gameStateChanged()) {
    gameState[gameStateTop].eventQueueTop = eventQueueTop;
    gameState[gameStateTop].eventQueue = duplicate(eventQueue, eventQueueTop*sizeof(EventQueueEntry));

    gameState[gameStateTop].admin = duplicate(admin, (header->instanceMax+1)*sizeof(AdminEntry));
    gameState[gameStateTop].attributes = duplicate(attributes, header->attributesAreaSize*sizeof(Aword));

    gameState[gameStateTop].score = current.score;
    gameState[gameStateTop].scores = duplicate(scores, header->scoreCount*sizeof(Aword));

    gameStateTop++;
  }
}
  
  
/*======================================================================*/
Bool popGameState(void) {

  if (gameStateTop == 0) {
    return FALSE;
  }

  gameStateTop--;

  eventQueueTop = gameState[gameStateTop].eventQueueTop;
  memcpy(eventQueue, gameState[gameStateTop].eventQueue,
	 (eventQueueTop+1)*sizeof(EventQueueEntry));
  free(gameState[gameStateTop].eventQueue);

  if (admin == NULL) syserr("admin[] == NULL in popGameState()");
  memcpy(admin, gameState[gameStateTop].admin,
 	 (header->instanceMax+1)*sizeof(AdminEntry));
  free(gameState[gameStateTop].admin);

  if (attributes == NULL) syserr("attributes[] == NULL in pushGameState()");
  memcpy(attributes, gameState[gameStateTop].attributes,
	 header->attributesAreaSize*sizeof(Aword));
  free(gameState[gameStateTop].attributes);

  current.score = gameState[gameStateTop].score;
  memcpy(scores, gameState[gameStateTop].scores,
	 header->scoreCount*sizeof(Aword));
  free(gameState[gameStateTop].scores);

  return TRUE;
}

/* Forward: */
void describeInstances(void);


/*----------------------------------------------------------------------*/
static void printMessageUsingParameter(MsgKind message, int i) {
  setupParameterForInstance(1, i);
  printMessage(message);
  restoreParameters();
}

/*----------------------------------------------------------------------*/
static void printMessageUsing2Parameters(MsgKind message, int instance1,
					 int instance2) {
  setupParameterForInstance(1, instance1);
  setupParameterForInstance(2, instance2);
  printMessage(message);
  restoreParameters();
}


/*======================================================================*/
void setStyle(Aint style)
{
#ifdef HAVE_GLK
  switch (style) {
  case NORMAL_STYLE: glk_set_style(style_Normal); break;
  case EMPHASIZED_STYLE: glk_set_style(style_Emphasized); break;
  case PREFORMATTED_STYLE: glk_set_style(style_Preformatted); break;
  case ALERT_STYLE: glk_set_style(style_Alert); break;
  case QUOTE_STYLE: glk_set_style(style_BlockQuote); break;
  }
#endif
}

/*======================================================================*/
void print(Aword fpos, Aword len)
{
  char str[2*WIDTH];            /* String buffer */
  int outlen = 0;               /* Current output length */
  int ch = 0;
  int i;
  long savfp = 0;		/* Temporary saved text file position */
  static Bool printFlag = FALSE; /* Printing already? */
  Bool savedPrintFlag = printFlag;
  void *info = NULL;		/* Saved decoding info */


  if (len == 0) return;

  if (isHere(HERO, TRUE)) {	/* Check if the player will see it */
    if (printFlag) {            /* Already printing? */
      /* Save current text file position and/or decoding info */
      if (header->pack)
	info = pushDecode();
      else
	savfp = ftell(textFile);
    }
    printFlag = TRUE;           /* We're printing now! */

    /* Position to start of text */
    fseek(textFile, fpos+header->stringOffset, 0);

    if (header->pack)
      startDecoding();
    for (outlen = 0; outlen != len; outlen = outlen + strlen(str)) {
      /* Fill the buffer from the beginning */
      for (i = 0; i <= WIDTH || (i > WIDTH && ch != ' '); i++) {
	if (outlen + i == len)  /* No more characters? */
	  break;
	if (header->pack)
	  ch = decodeChar();
	else
	  ch = getc(textFile);
	if (ch == EOFChar)      /* Or end of text? */
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
	fseek(textFile, savfp, 0);
    }
  }
}


/*======================================================================*/
void sys(Aword fpos, Aword len)
{
  char *command;

  command = getStringFromFile(fpos, len);
  system(command);
  free(command);
}


/*======================================================================*/
char *getStringFromFile(Aword fpos, Aword len)
{
  char *buf = allocate(len+1);
  char *bufp = buf;

  /* Position to start of text */
  fseek(textFile, fpos+header->stringOffset, 0);

  if (header->pack)
    startDecoding();
  while (len--)
    if (header->pack)
      *(bufp++) = decodeChar();
    else
      *(bufp++) = getc(textFile);

  /* Terminate string with zero */
  *bufp = '\0';

  return buf;
}



/*======================================================================*/
void score(Aword sc)
{
  if (sc == 0) {
    setupParameterForInteger(1, current.score);
    setupParameterForInteger(2, header->maximumScore);
    printMessage(M_SCORE);
  } else {
    current.score += scores[sc-1];
    scores[sc-1] = 0;
  }
}


/*======================================================================*/
void visits(Aword v)
{
  current.visits = v;
}


/*======================================================================*/
Bool confirm(MsgKind msgno)
{
  char buf[80];

  /* This is a bit of a hack since we really want to compare the input,
     it could be affirmative, but for now any input is NOT! */
  printMessage(msgno);

#ifdef USE_READLINE
  if (!readline(buf)) return TRUE;
#else
  if (gets(buf) == NULL) return TRUE;
#endif
  col = 1;

  return (buf[0] == '\0');
}


/*======================================================================*/
Bool undo(void) {
  if (gameStateTop != 0) {
    gameStateTop--;
    printMessage(M_UNDONE);
    return popGameState();
  } else {
    printMessage(M_NO_UNDO);
    return FALSE;
  }
}


/*======================================================================*/
void quitGame(void)
{
  char buf[80];

  para();
  while (TRUE) {
    col = 1;
    statusline();
    printMessage(M_QUITACTION);
#ifdef USE_READLINE
    if (!readline(buf)) terminate(0);
#else
    if (gets(buf) == NULL) terminate(0);
#endif
    if (strcmp(buf, "restart") == 0)
      longjmp(restartLabel, TRUE);
    else if (strcmp(buf, "restore") == 0) {
      restore();
      return;
    } else if (strcmp(buf, "quit") == 0) {
      terminate(0);
    } else if (strcmp(buf, "undo") == 0) {
      undo();
      return;
    }
  }
  syserr("Fallthrough in QUIT");
}



/*======================================================================*/
void restartGame(void)
{
  para();
  if (confirm(M_REALLY)) {
    longjmp(restartLabel, TRUE);
  } else
    return;
  syserr("Fallthrough in RESTART");
}



/*======================================================================*/
void cancelEvent(Aword evt)
{
  int i;

  for(i = eventQueueTop-1; i>=0; i--)
    if (eventQueue[i].event == evt) {
      while (i < eventQueueTop-1) {
	eventQueue[i].event = eventQueue[i+1].event;
	eventQueue[i].time = eventQueue[i+1].time;
	eventQueue[i].where = eventQueue[i+1].where;
	i++;
      }
      eventQueueTop--;
      return;
    }
}


/*======================================================================*/
void increaseEventQueue(void)
{
  eventQueue = realloc(eventQueue, (eventQueueTop+2)*sizeof(EventQueueEntry));
  if (eventQueue == NULL) syserr("Out of memory in increaseEventQueue()");

  eventQueueSize = eventQueueTop + 2;
}


/*======================================================================*/
void schedule(Aword event, Aword where, Aword after)
{  int i;
   int time;

   if (event == 0) syserr("NULL event");
  
   cancelEvent(event);
   /* Check for overflow */
   if (eventQueueTop == eventQueueSize)
     increaseEventQueue();
  
   time = current.tick+after;
  
   /* Bubble this event down */
   for (i = eventQueueTop; i >= 1 && eventQueue[i-1].time <= time; i--) {
     eventQueue[i].event = eventQueue[i-1].event;
     eventQueue[i].time = eventQueue[i-1].time;
     eventQueue[i].where = eventQueue[i-1].where;
   }
  
   eventQueue[i].time = time;
   eventQueue[i].where = where;
   eventQueue[i].event = event;
   eventQueueTop++;
}



/*======================================================================*/
AttributeEntry *findAttribute(AttributeEntry *attributeTable,
			      Aint attributeCode)
{
  AttributeEntry *attribute = attributeTable;
  while (attribute->code != attributeCode) {
    attribute++;
    if (endOfTable(attribute))
      syserr("Attribute not found.");
  }
  return attribute;
}




/*----------------------------------------------------------------------*/
static Aword getAttribute(AttributeEntry *attributeTable,
			  Aint attributeCode)
{
  AttributeEntry *attribute = findAttribute(attributeTable, attributeCode);

  return attribute->value;
}
  

/*----------------------------------------------------------------------*/
static void setAttribute(AttributeEntry *attributeTable,
			 Aword attributeCode,
			 Aword newValue)
{
  AttributeEntry *attribute = findAttribute(attributeTable, attributeCode);

  attribute->value = newValue;
}


/*======================================================================*/
void setValue(Aint id, Aint atr, Aword val)
{
  char str[80];

  if (id > 0 && id <= header->instanceMax) {
    setAttribute(admin[id].attributes, atr, val);
    if (isLocation(id))	/* May have changed so describe next time */
      admin[id].visitsCount = 0;
  } else {
    sprintf(str, "Can't SET/MAKE instance (%ld).", id);
    syserr(str);
  }
}


/*======================================================================*/
void setStringAttribute(Aint id, Aint atr, char *str)
{
  free((char *)attributeOf(id, atr));
  setValue(id, atr, (Aword)str);
}


/*======================================================================*/
void setSetAttribute(Aint id, Aint atr, Aword set)
{
  freeSet((Set *)attributeOf(id, atr));
  setValue(id, atr, (Aword)set);
}


/*======================================================================*/
void clearSetAttribute(Aint id, Aint atr)
{
  clearSet((Set *)attributeOf(id, atr));
}


/*======================================================================*/
void addSetAttribute(Aint id, Aint atr, Aword set) {
  Set *attribute = (Set *)attributeOf(id, atr);
  Set *theSet = (Set *)set;
  int i;

  for (i = 0; i < theSet->size; i++)
    addToSet(attribute, theSet->members[i]);
}


/*======================================================================*/
void addSet(Set *addend, Set *target) {
  int i;

  for (i = 0; i < addend->size; i++)
    addToSet(target, addend->members[i]);
}


/*----------------------------------------------------------------------*/
static Aword literalAttribute(Aword lit, Aint atr)
{
  char str[80];

  if (atr == 1)
    return literal[literalFromInstance(lit)].value;
  else {
    sprintf(str, "Unknown attribute for literal (%ld).", atr);
    syserr(str);
  }
  return(EOF);
}


/*======================================================================*/
Aword attributeOf(Aint id, Aint atr)
{
  char str[80];

  if (isLiteral(id))
    return literalAttribute(id, atr);
  else {
    if (id > 0 && id <= header->instanceMax)
      return getAttribute(admin[id].attributes, atr);
    else {
      sprintf(str, "Can't ATTRIBUTE item (%ld).", id);
      syserr(str);
    }
  }
  return(EOF);
}


/*======================================================================*/
Aword getStringAttribute(Aint id, Aint atr)
{
  return (Aword) strdup((char *)attributeOf(id, atr));
}


/*======================================================================*/
Aword getSetAttribute(Aint id, Aint atr)
{
  return (Aword) copySet((Set *)attributeOf(id, atr));
}


/*======================================================================*/
Aword concat(Aword s1, Aword s2)
{
  char *result = allocate(strlen((char*)s1)+strlen((char*)s2)+1);
  strcpy(result, (char*)s1);
  strcat(result, (char*)s2);
  free((char*)s1);
  free((char*)s2);
  return (Aword)result;
}


/*----------------------------------------------------------------------*/
static char *stripCharsFromStringForwards(int count, char *initialString, char **theRest)
{
  int stripPosition;
  char *strippedString;
  char *rest;

  if (count > strlen(initialString))
    stripPosition = strlen(initialString);
  else
    stripPosition = count;
  rest = strdup(&initialString[stripPosition]);
  strippedString = strdup(initialString);
  strippedString[stripPosition] = '\0';
  *theRest = rest;
  return strippedString;
}

/*----------------------------------------------------------------------*/
static char *stripCharsFromStringBackwards(Aint count, char *initialString, char **theRest) {
  int stripPosition;
  char *strippedString;
  char *rest;

  if (count > strlen(initialString))
    stripPosition = 0;
  else
    stripPosition = strlen(initialString)-count;
  strippedString = strdup(&initialString[stripPosition]);
  rest = strdup(initialString);
  rest[stripPosition] = '\0';
  *theRest = rest;
  return strippedString;
}


/*----------------------------------------------------------------------*/
static int countLeadingBlanks(char *string, int position) {
  static char blanks[] = " ";
  return strspn(&string[position], blanks);
}

/*----------------------------------------------------------------------*/
static int skipWordForwards(char *string, int position)
{
  char separators[] = " .,?";

  int i;

  for (i = position; i<=strlen(string) && strchr(separators, string[i]) == NULL; i++)
    ;
  return i;
}


/*----------------------------------------------------------------------*/
static char *stripWordsFromStringForwards(Aint count, char *initialString, char **theRest) {
  int skippedChars;
  int position = 0;
  char *stripped;
  int i;

  for (i = count; i>0; i--) {
    /* Ignore any initial blanks */
    skippedChars = countLeadingBlanks(initialString, position);
    position += skippedChars;
    position = skipWordForwards(initialString, position);
  }

  stripped = (char *)allocate(position+1);
  strncpy(stripped, initialString, position);
  stripped[position] = '\0';

  skippedChars = countLeadingBlanks(initialString, position);
  *theRest = strdup(&initialString[position+skippedChars]);

  return(stripped);
}


/*----------------------------------------------------------------------*/
static int skipWordBackwards(char *string, int position)
{
  char separators[] = " .,?";
  int i;

  for (i = position; i>0 && strchr(separators, string[i-1]) == NULL; i--)
    ;
  return i;
}


/*----------------------------------------------------------------------*/
static int countTrailingBlanks(char *string, int position) {
  int skippedChars, i;
  skippedChars = 0;

  if (position > strlen(string)-1)
    syserr("position > length in countTrailingBlanks");
  for (i = position; i >= 0 && string[i] == ' '; i--)
    skippedChars++;
  return(skippedChars);
}


/*----------------------------------------------------------------------*/
static char *stripWordsFromStringBackwards(Aint count, char *initialString, char **theRest) {
  int skippedChars;
  char *stripped;
  int strippedLength;
  int position = strlen(initialString);
  int i;

  for (i = count; i>0 && position>0; i--) {
    position -= 1;
    /* Ignore trailing blanks */
    skippedChars = countTrailingBlanks(initialString, position);
    if (position - skippedChars < 0) break; /* No more words to strip */
    position -= skippedChars;
    position = skipWordBackwards(initialString, position);
  }

  skippedChars = countLeadingBlanks(initialString, 0);
  strippedLength = strlen(initialString)-position-skippedChars;
  stripped = (char *)allocate(strippedLength+1);
  strncpy(stripped, &initialString[position+skippedChars], strippedLength);
  stripped[strippedLength] = '\0';

  if (position > 0) {
    skippedChars = countTrailingBlanks(initialString, position-1);
    position -= skippedChars;
  }
  *theRest = strdup(initialString);
  (*theRest)[position] = '\0';
  return(stripped);
}



/*======================================================================*/
Aword strip(Abool stripFromBeginningNotEnd, Aint count, Abool stripWordsNotChars, Aint id, Aint atr)
{
  char *initialString = (char *)attributeOf(id, atr);
  char *theStripped;
  char *theRest;

  if (stripFromBeginningNotEnd) {
    if (stripWordsNotChars)
      theStripped = stripWordsFromStringForwards(count, initialString, &theRest);
    else
      theStripped = stripCharsFromStringForwards(count, initialString, &theRest);
  } else {
    if (stripWordsNotChars)
      theStripped = stripWordsFromStringBackwards(count, initialString, &theRest);
    else
      theStripped = stripCharsFromStringBackwards(count, initialString, &theRest);
  }
  setStringAttribute(id, atr, theRest);
  return (Aword)theStripped;
}


/*----------------------------------------------------------------------*/
#ifdef FIXME
static Aword objloc(Aword obj)
{
  /* Keep this for container handling */
  if (isCnt(objs[obj-OBJMIN].loc)) /* In something ? */
    if (isObj(objs[obj-OBJMIN].loc) || isAct(objs[obj-OBJMIN].loc))
      return(where(objs[obj-OBJMIN].loc));
    else /* Containers not anywhere is where the hero is! */
      return(where(HERO));
  else
    return(objs[obj-OBJMIN].loc);
}

#endif

/*----------------------------------------------------------------------*/
static void verifyId(Aint id, char action[]) {
  char message[200];

  if (id == 0) {
    sprintf(message, "Can't %s instance (%ld).", action, id);
    syserr(message);
  } else if (id > header->instanceMax) {
    sprintf(message, "Can't %s instance (%ld > instanceMax).", action, id);
    syserr(message);
  }
}


/*======================================================================*/
/* Return the current position of an instance, directly or not */
Aword where(Aint id, Abool directly)
{
  verifyId(id, "WHERE");

  if (isLocation(id))
    return 0;
  else if (directly)
    return admin[id].location;
  else
    return location(id);
}



/*======================================================================*/
/* Return the *location* of an instance, non-transitive, i.e. not directly */
Aword location(Aint id)
{
  int loc;
  int container = 0;

  verifyId(id, "LOCATION");

  loc = admin[id].location;
  while (loc != 0 && !isLocation(loc)) {
    container = loc;
    loc = admin[loc].location;
  }
  if (loc != 0)
    return loc;
  else {
    if (container == 0)
      if (!isA(id, THING) && !isLocation(id))
	return location(HERO);
      else
	return 0;		/* Nowhere */
    else
      if (!isA(container, THING) && !isLocation(container))
	return location(HERO);
      else
	return 0;		/* Nowhere */
  }
}


/*======================================================================*/
Aint containerSize(Aint container, Abool directly) {
  Aint i;
  Aint count = 0;

  for (i = 1; i <= header->instanceMax; i++) {
    if (in(i, container, directly))
      count++;
  }
  return(count);
}


/*======================================================================*/
Aint getContainerMember(Aint container, Aint index, Abool directly) {
  Aint i;
  Aint count = 0;

  for (i = 1; i <= header->instanceMax; i++) {
    if (in(i, container, directly)) {
      count++;
      if (count == index)
	return i;
    }
  }
  syserr("Index not in container in 'containerMember()'");
  return 0;
}

/*----------------------------------------------------------------------*/
static void locateIntoContainer(Aword theInstance, Aword theContainer) {
  if (!isA(theInstance, container[instance[theContainer].container].class))
    printMessageUsing2Parameters(M_CANNOTCONTAIN, theContainer, theInstance);
  else if (checklim(theContainer, theInstance))
    error(MSGMAX);		/* Return to player without any message */
  else
    admin[theInstance].location = theContainer;
}


/*----------------------------------------------------------------------*/
static void locateObject(Aword obj, Aword whr)
{
  if (isContainer(whr)) { /* Into a container */
    locateIntoContainer(obj, whr);
  } else {
    admin[obj].location = whr;
    /* Make sure the location is described since it's changed */
    admin[whr].visitsCount = 0;
  }
}


/*----------------------------------------------------------------------*/
static void executeInheritedEntered(Aint theClass) {
  if (theClass == 0) return;
  if (class[theClass].entered)
    interpret(class[theClass].entered);
  else
    executeInheritedEntered(class[theClass].parent);
}


/*----------------------------------------------------------------------*/
static void locateActor(Aword movingActor, Aword whr)
{
  Aint previousCurrentLocation = current.location;
  Aint previousActorLocation = admin[movingActor].location;
  Aint previousActor = current.actor;

  /* FIXME: Actors locating into containers is dubious, anyway as it
   is now it allows the hero to be located into a container. And what
   happens with current location if so... */
  if (isContainer(whr))
    locateIntoContainer(movingActor, whr);
  else {
    current.location = whr;
    admin[movingActor].location = whr;
  }
  if (movingActor == HERO) {
    if (admin[admin[movingActor].location].visitsCount % (current.visits+1) == 0)
      look();
    else {
      if (anyOutput)
	para();
      say(where(HERO, TRUE));
      printMessage(M_AGAIN);
      newline();
      describeInstances();
    }
    admin[where(HERO, TRUE)].visitsCount++;
    admin[where(HERO, TRUE)].visitsCount %= (current.visits+1);
  } else
    admin[whr].visitsCount = 0;
  current.actor = movingActor;
  if (instance[current.location].entered != 0) {
    if (previousActorLocation != current.location)
      interpret(instance[current.location].entered);
  } else
    executeInheritedEntered(instance[current.location].parent);
  current.actor = previousActor;

  if (current.actor != movingActor)
    current.location = previousCurrentLocation;
}


/*======================================================================*/
void locate(Aint id, Aword whr)
{
  Aword containerId;
  ContainerEntry *theContainer;
  Aword previousInstance = current.instance;

  verifyId(id, "LOCATE");
  verifyId(whr, "LOCATE AT");

  /* First check if the instance is in a container, if so run extract checks */
  if (isContainer(admin[id].location)) {    /* In something? */
    current.instance = admin[id].location;
    containerId = instance[admin[id].location].container;
    theContainer = &container[containerId];

    if (theContainer->extractChecks != 0) {
      if (sectionTraceOption) {
	printf("\n<EXTRACT from ");
	traceSay(id);
	printf("(%ld, container %ld), Checking:>\n", id, containerId);
      }
      if (!trycheck(theContainer->extractChecks, EXECUTE)) {
	fail = TRUE;
	return;
      }
      current.instance = previousInstance;
    }
    if (theContainer->extractStatements != 0) {
      if (sectionTraceOption) {
	printf("\n<EXTRACT from ");
	traceSay(id);
	printf("(%ld, container %ld), Executing:>\n", id, containerId);
      }
      interpret(theContainer->extractStatements);
    }
  }
    
  if (isActor(id))
    locateActor(id, whr);
  else
    locateObject(id, whr);
}


/*----------------------------------------------------------------------*/


/*======================================================================*/
Aword isHere(Aint id, Abool directly)
{
  verifyId(id, "HERE");

  if (directly)
    return(admin[id].location == current.location);
  else
    return location(id) == current.location;
}


/*======================================================================*/
Abool isNearby(Aint instance, Abool directly)
{
  verifyId(instance, "NEARBY");

  if (isLocation(instance))
    return exitto(current.location, instance);
  else
    return exitto(current.location, where(instance, directly));
}


/*======================================================================*/
Abool isNear(Aint id, Aint other, Abool directly)
{
  Aint l1, l2;

  verifyId(id, "NEAR");

  if (isLocation(id))
    l1 = id;
  else
    l1 = where(id, directly);
  if (isLocation(other))
    l2 = other;
  else
    l2 = where(other, directly);
  return exitto(l2, l1);
}


/*======================================================================*/
Abool isA(Aint instanceId, Aint ancestor)
{
  int parent;

  if (isLiteral(instanceId))
    parent = literal[instanceId-header->instanceMax].class;
  else
    parent = instance[instanceId].parent;
  while (parent != 0 && parent != ancestor)
    parent = class[parent].parent;

  return (parent != 0);
}



/*======================================================================*/
/* Look in a container to see if the instance is in it. */
Abool in(Aint theInstance, Aint container, Abool directly)
{
  int loc;

  if (!isContainer(container))
    syserr("IN in a non-container.");

  if (directly)
    return admin[theInstance].location == container;
  else {
    loc = admin[theInstance].location;
    while (loc != 0)
      if (loc == container)
	return TRUE;
      else
	loc = admin[loc].location;
    return FALSE;
  }
}



/*======================================================================*/
/* Look see if an instance is AT another. */
Abool at(Aint theInstance, Aint other, Abool directly)
{
  int loc;

  if (theInstance == 0 || other == 0) return FALSE;

  if (directly) {
    if (isLocation(other))
      return admin[theInstance].location == other;
    else
      return admin[theInstance].location == admin[other].location;
  } else {
    if (!isLocation(other))
      /* If it's not a location get the instances location */
      loc = location(other);
    else
      loc = other;
    return location(theInstance) == loc;
  }
}


/*----------------------------------------------------------------------*/
static void executeInheritedMentioned(Aword theClass) {
  if (theClass == 0) return;

  if (class[theClass].mentioned)
    interpret(class[theClass].mentioned);
  else
    executeInheritedMentioned(class[theClass].parent);
}


/*----------------------------------------------------------------------*/
static void mention(Aint id) {
  if (instance[id].mentioned)
    interpret(instance[id].mentioned);
  else
    executeInheritedMentioned(instance[id].parent);
}


/*----------------------------------------------------------------------*/
static void sayLiteral(Aword lit)
{
  char *str;

  if (isNumeric(lit))
    sayInteger(literal[lit-header->instanceMax].value);
  else {
    str = (char *)strdup((char *)literal[lit-header->instanceMax].value);
    sayString(str);
  }    
}

	
/*----------------------------------------------------------------------*/
static void sayInstance(Aint id)
{
#ifdef SAY_INSTANCE_WITH_PLAYER_WORDS_IF_PARAMETER
  int p, i;

  /* Find the id in the parameters... */
  if (params != NULL)
    for (p = 0; params[p].code != EOF; p++)
      if (params[p].code == id) {
	/* Found it so.. */
	if (params[p].firstWord == EOF) /* Any words he used? */
	  break;		/* No... */
	else {				/* Yes, so use them... */ 
	  char *capitalized;
	  /* Assuming the noun is the last word we can simply output the adjectives... */
	  for (i = params[p].firstWord; i <= params[p].lastWord-1; i++)
	    output((char *)pointerTo(dict[wrds[i]].wrd));
	  /* ... and then the noun, capitalized if necessary */
	  if (header->capitalizeNouns) {
	    capitalized = strdup((char *)pointerTo(dict[wrds[params[p].lastWord]].wrd));
	    capitalized[0] = IsoToUpperCase(capitalized[0]);
	    output(capitalized);
	    free(capitalized);
	  } else
	    output((char *)pointerTo(dict[wrds[params[p].lastWord]].wrd));
	}
	return;
      }
#endif
  mention(id);
}


/*======================================================================*/
void sayInteger(Aword val)
{
  char buf[25];

  if (isHere(HERO, FALSE)) {
    sprintf(buf, "%ld", val);
    output(buf);
  }
}


/*======================================================================*/
void sayString(char *str)
{
  if (isHere(HERO, FALSE))
    output(str);
  free(str);
}


/*----------------------------------------------------------------------*/
static char *wordWithCode(Aint classBit, Aint code) {
  int w;
  char str[50];

  for (w = 0; w < dictsize; w++)
    if (dictionary[w].code == code && ((classBit&dictionary[w].classBits) != 0))
      return pointerTo(dictionary[w].wrd);
  sprintf(str, "Could not find word of class %ld with code %ld.", classBit, code);
  syserr(str);
  return NULL;
}


/*----------------------------------------------------------------------*/
static Bool sayInheritedDefiniteForm(Aword theClass) {
  if (theClass == 0) {
    printMessage(M_DEFINITE);
    return FALSE;
  } else {
    if (class[theClass].definite) {
      interpret(class[theClass].definite);
      return class[theClass].definiteIsForm;
    } else
      return sayInheritedDefiniteForm(class[theClass].parent);
  }
}


/*----------------------------------------------------------------------*/
static void sayDefinite(Aint id) {
  if (instance[id].definite) {
    interpret(instance[id].definite);
    if (!instance[id].definiteIsForm)
      sayInstance(id);
  } else
    if (!sayInheritedDefiniteForm(instance[id].parent))
      mention(id);
}

/*----------------------------------------------------------------------*/
static Bool sayInheritedIndefiniteForm(Aword theClass) {
  if (theClass == 0) {
    printMessage(M_INDEFINITE);
    return FALSE;
  } else {
    if (class[theClass].indefinite) {
      interpret(class[theClass].indefinite);
      return class[theClass].indefiniteIsForm;
    } else
      return sayInheritedIndefiniteForm(class[theClass].parent);
  }
}


/*----------------------------------------------------------------------*/
static void sayIndefinite(Aint id) {
  if (instance[id].indefinite) {
    interpret(instance[id].indefinite);
    if (!instance[id].indefiniteIsForm)
      sayInstance(id);
  } else
    if (!sayInheritedIndefiniteForm(instance[id].parent))
      mention(id);
}


/*----------------------------------------------------------------------*/
static void sayInheritedPronoun(Aint id) {
  if (id != 0) {
    if (class[id].pronoun != 0)
      output(wordWithCode(PRONOUN_BIT, class[id].pronoun));
    else
      sayInheritedPronoun(class[id].parent);
  } else
    printMessage(M_PRONOUN);
}

/*----------------------------------------------------------------------*/
static void sayPronoun(Aint id) {
  if (instance[id].pronoun != 0)
      output(wordWithCode(PRONOUN_BIT, instance[id].pronoun));
  else
    sayInheritedPronoun(instance[id].parent);
}


/*----------------------------------------------------------------------*/
static void sayArticleOrForm(Aint id, SayForm form)
{
  if (!isLiteral(id))
    switch (form) {
    case SAY_DEFINITE:
      sayDefinite(id);
      break;
    case SAY_INDEFINITE:
      sayIndefinite(id);
      break;
    case SAY_PRONOUN:
      sayPronoun(id);
      break;
    case SAY_SIMPLE:
      say(id);
      break;
    default:
      syserr("Unexpected form in 'sayArticleOrForm()'");
    }
  else
    say(id);
}


/*======================================================================*/
void say(Aint id)
{
  Aword previousInstance = current.instance;
  current.instance = id;

  if (isHere(HERO, FALSE)) {
    if (isLiteral(id))
      sayLiteral(id);
    else {
      verifyId(id, "SAY");
      sayInstance(id);
    }
  }
  current.instance = previousInstance;
}


/*======================================================================*/
void sayForm(Aint id, SayForm form)
{
  Aword previousInstance = current.instance;
  current.instance = id;

  sayArticleOrForm(id, form);

  current.instance = previousInstance;
}


/***********************************************************************\

  Description Handling

\***********************************************************************/


FORWARD void list(Aword cnt);

/*----------------------------------------------------------------------*/
static Bool inheritedDescriptionCheck(Aint classId)
{
  if (classId == 0) return TRUE;
  if (!inheritedDescriptionCheck(class[classId].parent)) return FALSE;
  if (class[classId].descriptionChecks == 0) return TRUE;
  return trycheck(class[classId].descriptionChecks, TRUE);
}

/*----------------------------------------------------------------------*/
static Bool descriptionCheck(Aint instanceId)
{
  if (inheritedDescriptionCheck(instance[instanceId].parent)) {
    if (instance[instanceId].checks == 0) return TRUE;
    return trycheck(instance[instanceId].checks, TRUE);
  } else
    return FALSE;
}

/*----------------------------------------------------------------------*/
static Abool inheritsDescriptionFrom(Aword classId)
{
  if (class[classId].description != 0)
    return TRUE;
  else if (class[classId].parent != 0)
    return inheritsDescriptionFrom(class[classId].parent);
  else
    return FALSE;
}  

/*----------------------------------------------------------------------*/
static Abool haveDescription(Aword instanceId)
{
  if (instance[instanceId].description != 0)
    return TRUE;
  else if (instance[instanceId].parent != 0)
    return inheritsDescriptionFrom(instance[instanceId].parent);
  else
    return FALSE;
}

/*----------------------------------------------------------------------*/
static void describeClass(Aint id)
{
  if (class[id].description != 0) {
    /* This class has a description, run it */
    interpret(class[id].description);
  } else {
    /* Search up the inheritance tree, if any, to find a description */
    if (class[id].parent != 0)
      describeClass(class[id].parent);
  }
}


/*----------------------------------------------------------------------*/
static void describeAnything(Aint id)
{
  if (instance[id].description != 0) {
    /* This instance has its own description, run it */
    interpret(instance[id].description);
  } else {
    /* Search up the inheritance tree to find a description */
    if (instance[id].parent != 0)
      describeClass(instance[id].parent);
  }
  admin[id].alreadyDescribed = TRUE;
}


/*----------------------------------------------------------------------*/
static Bool describeable(Aint i) {
  return isObject(i) || isActor(i);
}


/*----------------------------------------------------------------------*/
static Bool containerIsEmpty(Aword cnt)
{
  int i;

  for (i = 1; i <= header->instanceMax; i++)
    if (describeable(i) && in(i, cnt, FALSE))
      return FALSE;
  return TRUE;
}


/*----------------------------------------------------------------------*/
static void describeContainer(Aint id)
{
  if (!containerIsEmpty(id) && !attributeOf(id, OPAQUEATTRIBUTE))
    list(id);
}    


/*----------------------------------------------------------------------*/
static void describeObject(Aword obj)
{
  if (haveDescription(obj))
    describeAnything(obj);
  else {
    printMessageUsingParameter(M_SEE_OBJ_START, obj);
    printMessage(M_SEE_OBJ_END);
    if (instance[obj].container != 0)
      describeContainer(obj);
  }
  admin[obj].alreadyDescribed = TRUE;
}


/*----------------------------------------------------------------------*/
static void describeActor(Aword act)
{
  ScriptEntry *scr = NULL;

  if (admin[act].script != 0) {
    for (scr = (ScriptEntry *) pointerTo(header->scriptTableAddress); !endOfTable(scr); scr++)
      if (scr->code == admin[act].script)
	break;
    if (endOfTable(scr)) scr = NULL;
  }
  if (scr != NULL && scr->description != 0)
    interpret(scr->description);
  else if (haveDescription(act))
    describeAnything(act);
  else {
    printMessageUsingParameter(M_SEE_ACT, act);
    if (instance[act].container != 0)
      describeContainer(act);
  }
  admin[act].alreadyDescribed = TRUE;
}



static Bool descriptionOk;

/*======================================================================*/
void describe(Aint id)
{
  Aword previousInstance = current.instance;

  current.instance = id;
  verifyId(id, "DESCRIBE");
  if (descriptionCheck(id)) {
    descriptionOk = TRUE;
    if (isObject(id)) {
      describeObject(id);
    } else if (isActor(id)) {
      describeActor(id);
    } else
      describeAnything(id);
  } else
    descriptionOk = FALSE;
  dscrstkp--;
  current.instance = previousInstance;
}


/*======================================================================*/
void describeInstances(void)
{
  int i;
  int lastInstanceFound = 0;
  int found = 0;

  /* First describe every object here with its own description */
  for (i = 1; i <= header->instanceMax; i++)
    if (admin[i].location == current.location && isObject(i) &&
	!admin[i].alreadyDescribed && haveDescription(i))
      describe(i);

  /* Then list all other objects here */
  for (i = 1; i <= header->instanceMax; i++)
    if (admin[i].location == current.location && isObject(i) &&
	!admin[i].alreadyDescribed) {
      if (found == 0) {
	printMessageUsingParameter(M_SEE_OBJ_START, i);
	if (instance[i].container && containerSize(i, TRUE) > 0) {
	  printMessage(M_SEE_OBJ_END);
	  describeContainer(i);
	  continue;		/* Actually start another list. */
	}
      } else {
	if (found > 1)
	  printMessageUsingParameter(M_SEE_OBJ_COMMA, lastInstanceFound);
      }
      found++;
      lastInstanceFound = i;
    }

  if (found > 0) {
    if (found > 1) {
      printMessageUsingParameter(M_SEE_OBJ_AND, lastInstanceFound);
    }
    printMessage(M_SEE_OBJ_END);
  }
  
  /* Now for all actors */
  for (i = 1; i <= header->instanceMax; i++)
    if (admin[i].location == current.location && i != HERO && isActor(i)
	&& !admin[i].alreadyDescribed)
      describe(i);

  /* Clear the describe flag for all instances */
  for (i = 1; i <= header->instanceMax; i++)
    admin[i].alreadyDescribed = FALSE;
}


/*======================================================================*/
void look(void)
{
  int i;

  /* Set describe flag for all objects and actors */
  for (i = 1; i <= header->instanceMax; i++)
    admin[i].alreadyDescribed = FALSE;

  if (anyOutput)
    para();

#ifdef HAVE_GLK
  glk_set_style(style_Subheader);
#endif

  mention(current.location);

#ifdef HAVE_GLK
  glk_set_style(style_Normal);
#endif

  newline();
  capitalize = TRUE;
  describe(current.location);
  if (descriptionOk)
    describeInstances();
}


/*======================================================================*/
void list(Aword cnt)
{
  int i;
  Aword props;
  Aword foundInstance[2] = {0,0};
  int found = 0;
  Aint previousThis = current.instance;

  current.instance = cnt;

  /* Find container table entry */
  props = instance[cnt].container;
  if (props == 0) syserr("Trying to list something not a container.");

  for (i = 1; i <= header->instanceMax; i++) {
    if (describeable(i)) {
      /* We can only see objects and actors directly in this container... */
      if (admin[i].location == cnt) { /* Yes, it's in this container */
	if (found == 0) {
	  if (container[props].header != 0)
	    interpret(container[props].header);
	  else {
	    if (isActor(container[props].owner))
	      printMessageUsingParameter(M_CARRIES, container[props].owner);
	    else
	      printMessageUsingParameter(M_CONTAINS, container[props].owner);
	  }
	  foundInstance[0] = i;
	} else if (found == 1)
	  foundInstance[1] = i;
	else {
	  printMessageUsingParameter(M_CONTAINS_COMMA, i);
	}
	found++;
      }
    }
  }

  if (found > 0) {
    if (found > 1)
      printMessageUsingParameter(M_CONTAINS_AND, foundInstance[1]);
    printMessageUsingParameter(M_CONTAINS_END, foundInstance[0]);
  } else {
    if (container[props].empty != 0)
      interpret(container[props].empty);
    else {
      if (isActor(container[props].owner))
	printMessageUsingParameter(M_EMPTYHANDED, container[props].owner);
      else
	printMessageUsingParameter(M_EMPTY, container[props].owner);
    }
  }
  needSpace = TRUE;
  current.instance = previousThis;
}


/*======================================================================*/
void showImage(Aword image, Aword align)
{
#ifdef HAVE_GLK
  glui32 ecode;

  if ((glk_gestalt(gestalt_Graphics, 0) == 1) &&
      (glk_gestalt(gestalt_DrawImage, wintype_TextBuffer) == 1)) {
    glk_window_flow_break(glkMainWin);
    printf("\n");
    ecode = glk_image_draw(glkMainWin, image, imagealign_MarginLeft, 0);
  }
#endif
}    
 

/*======================================================================*/
void playSound(Aword sound)
{
#ifdef HAVE_GLK
#ifdef GLK_MODULE_SOUND
  static schanid_t soundChannel = NULL;
  glui32 ecode;

  if (glk_gestalt(gestalt_Sound, 0) == 1) {
    if (soundChannel == NULL)
      soundChannel = glk_schannel_create(0);
    if (soundChannel != NULL) {
      glk_schannel_stop(soundChannel);
      ecode = glk_schannel_play(soundChannel, sound);
    }
  }
#endif
#endif
}    
 


/*======================================================================*/
void empty(Aword cnt, Aword whr)
{
  int i;

  for (i = 1; i <= header->instanceMax; i++)
    if (in(i, cnt, TRUE))
      locate(i, whr);
}



/*======================================================================*/
void use(Aword act, Aword scr)
{
  char str[80];

  if (!isActor(act)) {
    sprintf(str, "Instance is not an Actor (%ld).", act);
    syserr(str);
  }

  admin[act].script = scr;
  admin[act].step = 0;
}

/*======================================================================*/
void stop(Aword act)
{
  char str[80];

  if (!isActor(act)) {
    sprintf(str, "Instance is not an Actor (%ld).", act);
    syserr(str);
  }

  admin[act].script = 0;
  admin[act].step = 0;
}




#ifndef HAVE_GLK
static char saveFileName[256];
typedef FILE *AFILE;
#else
typedef strid_t AFILE;
#endif


/*----------------------------------------------------------------------*/
static void saveStrings(AFILE saveFile) {

  StringInitEntry *initEntry;

  if (header->stringInitTable != 0)
    for (initEntry = (StringInitEntry *)pointerTo(header->stringInitTable);
	 !endOfTable(initEntry); initEntry++) {
      char *attr = (char *)getStringAttribute(initEntry->instanceCode, initEntry->attributeCode);
      Aint length = strlen(attr) + 1;
      fwrite((void *)&length, sizeof(length), 1, saveFile);
      fwrite((void *)attr, 1, length, saveFile);
    }
}


/*----------------------------------------------------------------------*/
static void saveSets(AFILE saveFile) {
  SetInitEntry *initEntry;

  if (header->setInitTable != 0)
    for (initEntry = (SetInitEntry *)pointerTo(header->setInitTable);
	 !endOfTable(initEntry); initEntry++) {
      Set *attr = (Set *)getSetAttribute(initEntry->instanceCode, initEntry->attributeCode);
      fwrite((void *)&attr->size, sizeof(attr->size), 1, saveFile);
      fwrite((void *)attr->members, sizeof(attr->members[0]), attr->size, saveFile);
    }
}


/*----------------------------------------------------------------------*/
static void saveGameInfo(AFILE saveFile) {
  fwrite((void *)"ASAV", 1, 4, saveFile);
  fwrite((void *)&header->vers, 1, sizeof(Aword), saveFile);
  fwrite((void *)adventureName, 1, strlen(adventureName)+1, saveFile);
  fwrite((void *)&header->uid, 1, sizeof(Aword), saveFile);
}


/*----------------------------------------------------------------------*/
static void saveAdmin(AFILE saveFile) {
  fwrite((void *)&admin[1], sizeof(AdminEntry), header->instanceMax, saveFile);
}


/*----------------------------------------------------------------------*/
static void saveAttributeArea(AFILE saveFile) {
  fwrite((void*)attributes, header->attributesAreaSize, sizeof(Aword), saveFile);
}


/*----------------------------------------------------------------------*/
static void saveEventQueue(AFILE saveFile) {
  fwrite((void *)&eventQueueTop, sizeof(eventQueueTop), 1, saveFile);
  fwrite((void *)&eventQueue[0], sizeof(eventQueue[0]), eventQueueTop, saveFile);
}


/*----------------------------------------------------------------------*/
static void saveCurrentValues(AFILE saveFile) {
  fwrite((void *)&current, sizeof(current), 1, saveFile);
}


/*----------------------------------------------------------------------*/
static void saveScores(AFILE saveFile) {
  fwrite((void *)scores, sizeof(Aword), header->scoreCount, saveFile);
}


/*----------------------------------------------------------------------*/
static void saveGame(AFILE saveFile) {
  /* Save tag, version of interpreter, name and uid of game */
  saveGameInfo(saveFile);

  /* Save current values */
  saveCurrentValues(saveFile);

  saveAttributeArea(saveFile);
  saveAdmin(saveFile);

  saveEventQueue(saveFile);

  saveScores(saveFile);

  saveStrings(saveFile);
  saveSets(saveFile);
}


/*----------------------------------------------------------------------*/
void save(void)
{
#ifdef HAVE_GLK
  frefid_t saveFileRef;
  strid_t saveFile;
  saveFileRef = glk_fileref_create_by_prompt(fileusage_SavedGame, filemode_Write, 0);
  if (saveFileRef == NULL)
    error(M_SAVEFAILED);
  saveFile = glk_stream_open_file(saveFileRef, filemode_Write, 0);

#else

  FILE *saveFile;
  char str[256];

  /* First save ? */
  if (saveFileName[0] == '\0') {
    strcpy(saveFileName, adventureName);
    strcat(saveFileName, ".sav");
  }
  printMessage(M_SAVEWHERE);
  sprintf(str, "(%s) : ", saveFileName);
  output(str);
#ifdef USE_READLINE
  readline(str);
#else
  gets(str);
#endif
  if (str[0] == '\0')
    strcpy(str, saveFileName);
  col = 1;
  if ((saveFile = fopen(str, READ_MODE)) != NULL)
    /* It already existed */
    if (!confirm(M_SAVEOVERWRITE))
      error(MSGMAX);            /* Return to player without saying anything */
  if ((saveFile = fopen(str, WRITE_MODE)) == NULL)
    error(M_SAVEFAILED);
  strcpy(saveFileName, str);
#endif

  saveGame(saveFile);

  fclose(saveFile);
}


/*----------------------------------------------------------------------*/
static void restoreStrings(AFILE saveFile) {
  StringInitEntry *initEntry;

  if (header->stringInitTable != 0)
    for (initEntry = (StringInitEntry *)pointerTo(header->stringInitTable);
	 !endOfTable(initEntry); initEntry++) {
      Aint length;
      char *string;
      fread((void *)&length, sizeof(Aint), 1, saveFile);
      string = allocate(length+1);
      fread((void *)string, 1, length, saveFile);
      setValue(initEntry->instanceCode, initEntry->attributeCode, (Aword)string);
    }
}


/*----------------------------------------------------------------------*/
static void restoreSets(AFILE saveFile) {
  SetInitEntry *initEntry;

  if (header->setInitTable != 0)
    for (initEntry = (SetInitEntry *)pointerTo(header->setInitTable);
	 !endOfTable(initEntry); initEntry++) {
      Aint setSize;
      Set *set;
      int i;

      fread((void *)&setSize, sizeof(setSize), 1, saveFile);
      set = newSet(setSize);
      for (i = 0; i < setSize; i++) {
	Aword member;
	fread((void *)&member, sizeof(member), 1, saveFile);
	addToSet(set, member);
      }
      setValue(initEntry->instanceCode, initEntry->attributeCode, (Aword)set);
    }
}


/*----------------------------------------------------------------------*/
static void restoreScores(AFILE saveFile) {
  fread((void *)scores, sizeof(Aword), header->scoreCount, saveFile);
}


/*----------------------------------------------------------------------*/
static void restoreEventQueue(AFILE saveFile) {
  fread((void *)&eventQueueTop, sizeof(eventQueueTop), 1, saveFile);
  if (eventQueueTop > eventQueueSize) {
    free(eventQueue);
    eventQueue = allocate(eventQueueTop*sizeof(eventQueue[0]));
  }
  fread((void *)&eventQueue[eventQueueTop], sizeof(eventQueue[0]), eventQueueTop, saveFile);
}


/*----------------------------------------------------------------------*/
static void restoreAdmin(AFILE saveFile) {
  /* Restore admin for instances, remember to reset attribute area pointer */
  int i;
  for (i = 1; i <= header->instanceMax; i++) {
    AttributeEntry *currentAttributesArea = admin[i].attributes;
    fread((void *)&admin[i], sizeof(AdminEntry), 1, saveFile);
    admin[i].attributes = currentAttributesArea;
  }
}


/*----------------------------------------------------------------------*/
static void restoreAttributeArea(AFILE saveFile) {
  fread((void *)attributes, header->attributesAreaSize, sizeof(Aword), saveFile);
}


/*----------------------------------------------------------------------*/
static void restoreCurrentValues(AFILE saveFile) {
  fread((void *)&current, sizeof(current), 1, saveFile);
}


/*----------------------------------------------------------------------*/
static void verifyGameId(AFILE saveFile) {
  Aword savedUid;

  fread((void *)&savedUid, sizeof(Aword), 1, saveFile);
  if (!ignoreErrorOption && savedUid != header->uid)
    error(M_SAVEVERS);
}


/*----------------------------------------------------------------------*/
static void verifyGameName(AFILE saveFile) {
  char savedName[256];
  int i = 0;

  while ((savedName[i++] = fgetc(saveFile)) != '\0');
  if (strcmp(savedName, adventureName) != 0)
    error(M_SAVENAME);
}


/*----------------------------------------------------------------------*/
static void verifyCompilerVersion(AFILE saveFile) {
  char savedVersion[4];

  fread((void *)&savedVersion, sizeof(Aword), 1, saveFile);
  if (!ignoreErrorOption && strncmp(savedVersion, header->vers, 4))
    error(M_SAVEVERS);
}


/*----------------------------------------------------------------------*/
static void verifySaveFile(AFILE saveFile) {
  char string[256];

  fread((void *)&string, 1, 4, saveFile);
  string[4] = '\0';
  if (strcmp(string, "ASAV") != 0)
    error(M_NOTASAVEFILE);
}


/*----------------------------------------------------------------------*/
static void restoreGame(AFILE saveFile)
{
  if (saveFile == NULL) syserr("'restoreGame()' from a null fileref");

  verifySaveFile(saveFile);

  /* Verify version of compiler/interpreter of saved game with us */
  verifyCompilerVersion(saveFile);

  /* Verify name of game */
  verifyGameName(saveFile);

  /* Verify unique id of game */
  verifyGameId(saveFile);

  restoreCurrentValues(saveFile);
  restoreAttributeArea(saveFile);
  restoreAdmin(saveFile);
  restoreEventQueue(saveFile);
  restoreScores(saveFile);
  restoreStrings(saveFile);
  restoreSets(saveFile);
}


/*----------------------------------------------------------------------*/
void restore(void)
{
#ifdef HAVE_GLK
  frefid_t saveFileRef;
  strid_t saveFile;
  saveFileRef = glk_fileref_create_by_prompt(fileusage_SavedGame, filemode_Read, 0);
  if (saveFileRef == NULL) return;
  saveFile = glk_stream_open_file(saveFileRef, filemode_Read, 0);

#else
  char str[1000];
  FILE *saveFile;

  /* First save ? */
  if (saveFileName[0] == '\0') {
    strcpy(saveFileName, adventureName);
    strcat(saveFileName, ".sav");
  }
  printMessage(M_RESTOREFROM);
  sprintf(str, "(%s) : ", saveFileName);
  output(str);
#ifdef USE_READLINE
  readline(str);
#else
  gets(str);
#endif

  if (str[0] == '\0')
    strcpy(str, saveFileName);
  col = 1;
  if (str[0] == '\0')
    strcpy(str, saveFileName);        /* Use the name temporarily */
  if ((saveFile = fopen(str, READ_MODE)) == NULL)
    error(M_SAVEMISSING);
  strcpy(saveFileName, str);          /* Save it for future use */

#endif

  restoreGame(saveFile);

  fclose(saveFile);
}



/*----------------------------------------------------------------------*/
Aword randomInteger(Aword from, Aword to)
{
  if (to == from)
    return to;
  else if (to > from)
    return (rand()/10)%(to-from+1)+from;
  else
    return (rand()/10)%(from-to+1)+to;
}



/*----------------------------------------------------------------------*/
Abool btw(Aint val, Aint low, Aint high)
{
  if (high > low)
    return low <= val && val <= high;
  else
    return high <= val && val <= low;
}



/*======================================================================*/
Aword contains(Aword string, Aword substring)
{
  Abool found;

  strlow((char *)string);
  strlow((char *)substring);

  found = (strstr((char *)string, (char *)substring) != 0);

  free((char *)string);
  free((char *)substring);

  return(found);
}


/*======================================================================*/
Abool streq(char a[], char b[])
{
  Bool eq;

  strlow(a);
  strlow(b);

  eq = (strcmp(a, b) == 0);

  free(a);
  free(b);

  return(eq);
}
