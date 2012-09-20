#include "cgreen/cgreen.h"

#include "stack.c"

Describe(stack, setup, teardown);

static Stack theStack;

static void setup() {
  theStack = createStack(50);
}

static void teardown() {
  deleteStack(theStack);
}


/*----------------------------------------------------------------------*/
Ensure(allocatesCorrectSpaceInNewFrame) {
  /* Add a block with four local variables */
  newFrame(theStack, 4);
  assert_equal(1/*old fp*/ + 4/*Locals*/, stackDepth(theStack));
}


/*----------------------------------------------------------------------*/
Ensure(testNewFrameInStack) {
  /* Add a block with four local variables */
  newFrame(theStack, 4);
  assert_equal(1/*old fp*/ + 4/*Locals*/, stackDepth(theStack));
  assert_equal(1, theStack->framePointer);

  assert_equal(0, getLocal(theStack, 0,1));
  setLocal(theStack, 0,1,14);
  assert_equal(14, getLocal(theStack, 0,1));
  assert_equal(14, theStack->stack[theStack->stackp - 4]);
  assert_equal(-1, theStack->stack[theStack->stackp - 5]);

  endFrame(theStack);
  assert_equal(0, stackDepth(theStack));
}


/*----------------------------------------------------------------------*/
Ensure(testFrameInFrame) {
  /* Add a block with one local variable */
  newFrame(theStack, 1);
  setLocal(theStack, 0,1,14);
  assert_equal(14, getLocal(theStack, 0,1));

  newFrame(theStack, 1);
  setLocal(theStack, 0,1,15);
  assert_equal(15, getLocal(theStack, 0,1));
  assert_equal(14, getLocal(theStack, 1,1));
  endFrame(theStack);
  endFrame(theStack);
  assert_equal(0, stackDepth(theStack));
}

/*----------------------------------------------------------------------*/
Ensure(testPushAndPop) {
  Stack myStack = createStack(10);

  push(myStack, 1);
  push(myStack, 2);
  push(myStack, 3);
  push(myStack, 4);
  assert_equal(4, stackDepth(myStack));
  assert_equal(4, pop(myStack));
  assert_equal(3, pop(myStack));
  assert_equal(2, pop(myStack));
  assert_equal(1, pop(myStack));
  assert_equal(0, stackDepth(myStack));
}


TestSuite *stackTests()
{
  TestSuite *suite = create_test_suite();

  set_setup(suite, setup);
  set_teardown(suite, teardown);

  add_test(suite, allocatesCorrectSpaceInNewFrame);
  add_test(suite, testNewFrameInStack);
  add_test(suite, testFrameInFrame);
  add_test(suite, testPushAndPop);

  return suite;
}
