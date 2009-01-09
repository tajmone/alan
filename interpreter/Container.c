#include "Container.h"

#include "instance.h"
#include "exe.h"
#include "syserr.h"
#include "inter.h"
#include "lists.h"
#include "memory.h"


/* PUBLIC DATA */
ContainerEntry *containers;  /* Container table pointer */


/*----------------------------------------------------------------------*/
static int countInContainer(int containerIndex)	/* IN - the container to count in */
{
  int instanceIndex, j = 0;

  for (instanceIndex = 1; instanceIndex <= header->instanceMax; instanceIndex++)
    if (in(instanceIndex, containerIndex, TRUE))
      /* Then it's in this container also */
      j++;
  return(j);
}



/*----------------------------------------------------------------------*/
static int sumAttributeInContainer(
    Aint containerIndex,			/* IN - the container to sum */
    Aint attributeIndex			/* IN - the attribute to sum over */
) {
  int instanceIndex;
  int sum = 0;

  for (instanceIndex = 1; instanceIndex <= header->instanceMax; instanceIndex++)
    if (in(instanceIndex, containerIndex, TRUE)) {		/* Then it's directly in this cont */
      if (instances[instanceIndex].container != 0)	/* This is also a container! */
	sum = sum + sumAttributeInContainer(instanceIndex, attributeIndex);
      sum = sum + getInstanceAttribute(instanceIndex, attributeIndex);
    }
  return(sum);
}


/*======================================================================*/
Bool passesContainerLimits(
     Aint theContainer,		/* IN - Container id */
     Aint theAddedInstance	/* IN - The object to add */
) {
  LimEntry *lim;
  Aword props;

  if (!isContainer(theContainer))
    syserr("Checking limits for a non-container.");

  /* Find the container properties */
  props = instances[theContainer].container;

  if (containers[props].limits != 0) { /* Any limits at all? */
    for (lim = (LimEntry *) pointerTo(containers[props].limits); !isEndOfList(lim); lim++)
      if (lim->atr == 1-I_COUNT) {
	if (countInContainer(theContainer) >= lim->val) {
	  interpret(lim->stms);
	  return(FALSE);
	}
      } else {
	if (sumAttributeInContainer(theContainer, lim->atr) + getInstanceAttribute(theAddedInstance, lim->atr) > lim->val) {
	  interpret(lim->stms);
	  return(FALSE);
	}
      }
  }
  return(TRUE);
}
