#include "cgreen/cgreen.h"
#include "cgreen/mocks.h"

#include "AltInfo.c"

Describe(AltInfo);
BeforeEach(AltInfo) {}
AfterEach(AltInfo) {}

Ensure(canPrimeAltInfo) {
  AltInfo altInfos[2];
  const int level = 17;
  const int parameter = 18;
  const int instance = 19;
  const int class = 20;

  primeAltInfo(altInfos, level, parameter, instance, class);

  assert_that(level, is_equal_to(altInfos[0].level));
  assert_that(parameter, is_equal_to(altInfos[0].parameter));
  assert_that(instance, is_equal_to(altInfos[0].instance));
  assert_that(class, is_equal_to(altInfos[0].class));
}

/*----------------------------------------------------------------------*/
Ensure(canDuplicateAltInfoArray) {
  AltInfo original[20];
  AltInfo *duplicate;
  static int COPYSIZE = 15;
  int i;

  for (i = 0; i < COPYSIZE; i++) {
	  original[i].instance = i;
	  original[i].end = FALSE;
  }
  original[COPYSIZE].end = TRUE;

  duplicate = duplicateAltInfoArray(original);
  for (i = 0; i < COPYSIZE; i++) {
      assert_that(i, is_equal_to(duplicate[i].instance));
      assert_that(!duplicate[i].end);
  }
  assert_true(duplicate[COPYSIZE].end);
  free(duplicate);
}


/*----------------------------------------------------------------------*/
Ensure(canFindLastAltInfoIndex) {
  AltInfo array[20];
  static int SIZE = 13;
  int i;

  for (i = 0; i < SIZE; i++)
    array[i].end = FALSE;
  array[SIZE].end = TRUE;

  assert_equal(lastAltInfoIndex(array), SIZE-1);
}

/*----------------------------------------------------------------------*/
Ensure(canFindNextFreeAltInfo) {
  AltInfo array[20];
  static int SIZE = 13;
  int i;

  for (i = 0; i < SIZE; i++)
    array[i].end = FALSE;
  array[SIZE].end = TRUE;

  assert_equal(nextFreeAltInfo(array), &array[SIZE]);
}

/*----------------------------------------------------------------------*/
AltEntry altEntry;

AltEntry *finder(int verb, int parameterNumber, int theInstance, int theClass) {
  return &altEntry;
}

Ensure(canAddGlobalAlternatives) {
  AltInfo altInfos[10];
  altInfos[0].end = TRUE;

  addGlobalAlternatives(altInfos, current.verb, &finder);

  assert_false(altInfos[0].end);
  assert_equal(&altEntry, altInfos[0].alt);
  assert_equal(NO_PARAMETER, altInfos[0].parameter);
  assert_equal(NO_INSTANCE, altInfos[0].instance);
  assert_equal(NO_CLASS, altInfos[0].class);
  assert_true(altInfos[1].end);
}


static AltInfo *mockedAlternativeFinder(int verb, Parameter parameters[]) {
    mock(verb);
    return NULL;
}

Ensure(possibleIndicatesFalseOnEmptyAlternatives) {
    globalParameters = newParameterArray();
    assert_false(possibleWithFinder(current.verb, globalParameters, mockedAlternativeFinder));
}

TestSuite *altInfoTests() {
  TestSuite *suite = create_test_suite();

  add_test(suite, canPrimeAltInfo);
  add_test(suite, canDuplicateAltInfoArray);
  add_test(suite, canFindLastAltInfoIndex);
  add_test(suite, canFindNextFreeAltInfo);
  add_test(suite, canAddGlobalAlternatives);
  add_test(suite, possibleIndicatesFalseOnEmptyAlternatives);

  return suite;
}
