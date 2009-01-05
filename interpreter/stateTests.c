#include "cgreen/cgreen.h"


#include "state.c"

#define INSTANCEMAX 7
#define ATTRIBUTECOUNT 5

static void setupInstances(void) {
  int adminSize = (INSTANCEMAX+1)*sizeof(AdminEntry)/sizeof(Aword);
  int attributeAreaSize = (INSTANCEMAX+1)*ATTRIBUTECOUNT*sizeof(Attribute)/sizeof(Aword);
  int i;

  header = allocate(sizeof(ACodeHeader));
  header->attributesAreaSize = attributeAreaSize;
  header->instanceMax = INSTANCEMAX;

  admin = allocate((INSTANCEMAX+1)*sizeof(AdminEntry));
  for (i = 0; i < adminSize; i++) ((Aword *)admin)[i] = i;

  attributes = allocate((INSTANCEMAX+1)*ATTRIBUTECOUNT*sizeof(Attribute));
  for (i = 0; i < attributeAreaSize; i++) ((Aword *)attributes)[i] = i;

}

static void teardownInstances() {
	free(header);
	free(admin);
	free(attributes);
}


Ensure pushGameStateCollectsAdminAndAttributesData() {
  int adminSize = (INSTANCEMAX+1)*sizeof(AdminEntry)/sizeof(Aword);
  int attributeAreaSize = ATTRIBUTECOUNT*INSTANCEMAX*sizeof(Attribute)/sizeof(Aword);

  eventQueueTop = 0;

  rememberGameState();

  assert_true(memcmp(gameState.attributes, attributes, attributeAreaSize*sizeof(Aword)) == 0);
  assert_true(memcmp(gameState.admin, admin, adminSize*sizeof(Aword)) == 0);
}

Ensure pushAndPopCanHandleSetAttributes() {
  Set *originalSet = newSet(3);
  SetInitEntry *initEntry;

  admin[1].attributes = attributes;
  attributes[0].code = 1;
  attributes[0].value = (Aword)originalSet;
  addToSet(originalSet, 7);

  eventQueueTop = 0;

  /* Set up a set initialization */
  memory = allocate(sizeof(SetInitEntry)+2*sizeof(Aword));
  header->setInitTable = 1;
  initEntry = (SetInitEntry*)&memory[1];
  initEntry->instanceCode = 1;
  initEntry->attributeCode = 1;
  memory[1+sizeof(SetInitEntry)/sizeof(Aword)] = EOF;


  rememberGameState();

  assert_not_equal(gameState.sets[0], (Aword)originalSet);
  assert_true(equalSets((Set*)gameState.sets[0], originalSet));

  Set *modifiedSet = newSet(4);
  attributes[0].value = (Aword)modifiedSet;
  addToSet(modifiedSet, 11);
  addToSet(modifiedSet, 12);
  assert_false(equalSets((Set*)gameState.sets[0], modifiedSet));
  assert_true(equalSets((Set*)attributes[0].value, modifiedSet));

  recallGameState();

  assert_not_equal(attributes[0].value, (Aword)modifiedSet);
  assert_not_equal(attributes[0].value, (Aword)originalSet);
  assert_true(equalSets((Set*)attributes[0].value, originalSet));
}

Ensure canPushAndPopAttributeState() {

  attributes[0].value = 12;
  attributes[2].value = 3;

  rememberGameState();

  attributes[0].value = 11;
  attributes[2].value = 4;

  rememberGameState();

  attributes[0].value = 55;
  attributes[2].value = 55;

  recallGameState();

  assert_equal(11, attributes[0].value);
  assert_equal(4, attributes[2].value);

  recallGameState();

  assert_equal(12, attributes[0].value);
  assert_equal(3, attributes[2].value);
}



Ensure canPushAndPopAdminState() {
  int INSTANCE1_LOCATION = 12;
  int INSTANCE2_LOCATION = 22;
  int INSTANCE2_FIRST_SCRIPT = 3;

  admin[1].location = INSTANCE1_LOCATION;
  admin[2].script = INSTANCE2_FIRST_SCRIPT;

  rememberGameState();

  admin[2].location = INSTANCE2_LOCATION;

  admin[2].alreadyDescribed = 2;
  admin[2].visitsCount = 13;
  admin[2].script = 33;
  admin[2].step = 3886;
  admin[2].waitCount = 38869878;

  rememberGameState();

  admin[2].location = 55;
  admin[2].alreadyDescribed = 55;
  admin[2].visitsCount = 55;
  admin[2].script = 55;
  admin[2].step = 55;
  admin[2].waitCount = 55;

  recallGameState();

  assert_equal(INSTANCE2_LOCATION, admin[2].location);
  assert_equal(2, admin[2].alreadyDescribed);
  assert_equal(13, admin[2].visitsCount);
  assert_equal(33, admin[2].script);
  assert_equal(3886, admin[2].step);
  assert_equal(38869878, admin[2].waitCount);

  recallGameState();

  assert_equal(INSTANCE1_LOCATION, admin[1].location);
  assert_equal(INSTANCE2_FIRST_SCRIPT, admin[2].script);
}

Ensure canPushAndPopEvents() {
  eventQueue = NULL;
  eventQueueTop = 0;

  rememberGameState();

  eventQueue = allocate(5*sizeof(EventQueueEntry));
  eventQueueTop = 2;
  eventQueue[1].after = 47;

  rememberGameState();

  eventQueueTop = 0;
  eventQueue[1].after = 1;

  recallGameState();

  assert_equal(2, eventQueueTop);
  assert_equal(47, eventQueue[1].after);

  recallGameState();

  assert_equal(0, eventQueueTop);
}

Ensure doesNotCrashOnSequenceOfRememberForgetAndRecall() {
	rememberGameState();
	forgetGameState();
	rememberGameState();
	rememberGameState();
	forgetGameState();
	recallGameState();
	rememberGameState();
	forgetGameState();
	rememberGameState();
	rememberGameState();
	rememberGameState();
	forgetGameState();
	rememberGameState();
	forgetGameState();
	recallGameState();
	rememberGameState();
	forgetGameState();
	rememberGameState();
	forgetGameState();
	recallGameState();
	rememberGameState();
}

Ensure canRememberPlayerCommand() {
  int i;
  char *command = "go w, e and south";

  playerWords[0].code = EOF;
  for (i = 0; i < 4; i++)
    playerWords[i].code = i;
  playerWords[4].code = EOF;

  firstWord = 0;
  lastWord = 3;
  playerWords[firstWord].start = command;
  playerWords[lastWord].end = &command[4];

  rememberGameState();
  rememberCommands();
  recallGameState();

  assert_true(strcmp(playerCommand, command) != 0);
  assert_true(strncmp(playerCommand, command, 3) == 0);
}

Ensure freeGameStateFreesMemory() {
	gameState.admin = allocate(1);
	gameState.attributes = allocate(1);
	gameState.eventQueue = allocate(1);
	gameState.scores = allocate(1);
	gameState.sets = allocate(1);
	gameState.strings = allocate(1);

	freeGameState();

	assert_equal(gameState.admin, 0);
	assert_equal(gameState.attributes, 0);
	assert_equal(gameState.eventQueue, 0);
	assert_equal(gameState.scores, 0);
	assert_equal(gameState.sets, 0);
	assert_equal(gameState.strings, 0);
}


TestSuite *stateTests() {
  TestSuite *suite = create_test_suite();

  setup(suite, setupInstances);
  teardown(suite, teardownInstances);

  add_test(suite, freeGameStateFreesMemory);
  add_test(suite, canRememberPlayerCommand);
  add_test(suite, pushGameStateCollectsAdminAndAttributesData);
  add_test(suite, canPushAndPopAttributeState);
  add_test(suite, canPushAndPopAdminState);
  add_test(suite, canPushAndPopEvents);
  add_test(suite, pushAndPopCanHandleSetAttributes);
  add_test(suite, doesNotCrashOnSequenceOfRememberForgetAndRecall);

  return suite;
}
