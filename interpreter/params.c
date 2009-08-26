/*----------------------------------------------------------------------

  params.c

  Various utility functions for handling parameters

  ----------------------------------------------------------------------*/
#include "params.h"

/* IMPORTS */
#include "lists.h"
#include "memory.h"
#include "literal.h"


/* PUBLIC DATA */
Parameter *parameters; /* List of params */



/*======================================================================*/
Parameter *allocateParameterArray(Parameter *currentList, int size) {
    if (currentList == NULL)
        currentList = allocate(sizeof(Parameter)*(size+1));
    clearList(currentList);
    return currentList;
}


/*======================================================================*/
Parameter *findEndOfList(Parameter *parameters) {
    Parameter *parameter;
    for (parameter = parameters; !isEndOfList(parameter); parameter++);
    return parameter;
}


/*======================================================================*/
/* A parameter position with code == 0 means this is a multiple position.
 * We must loop over this position (and replace it by each present in the
 * matched list)
 */
int findMultiplePosition(Parameter parameters[]) {
    int multiplePosition;
    for (multiplePosition = 0; !isEndOfList(&parameters[multiplePosition]); multiplePosition++)
	if (parameters[multiplePosition].instance == 0)
	    return multiplePosition;
    return -1;
}


/*======================================================================*/
void compress(Parameter theList[])
{
    int i, j;

    for (i = 0, j = 0; theList[j].instance != EOF; j++)
	if (theList[j].instance != 0)
	    theList[i++] = theList[j];
    setEndOfList(&theList[i]);
}


/*======================================================================*/
int listLength(Parameter theList[])
{
    int i = 0;

    while (!isEndOfList(&theList[i]))
	i++;
    return i;
}


/*======================================================================*/
Bool inList(Parameter theList[], Aword theCode)
{
    int i;

    for (i = 0; !isEndOfList(&theList[i]) && theList[i].instance != theCode; i++);
    return (theList[i].instance == theCode);
}


/*======================================================================*/
void copyParameterList(Parameter to[], Parameter from[])
{
    int i;

    for (i = 0; !isEndOfList(&from[i]); i++)
	to[i] = from[i];
    setEndOfList(&to[i]);
}


/*======================================================================*/
void subtractListFromList(Parameter theList[], Parameter remove[])
{
    int i;

    for (i = 0; !isEndOfList(&theList[i]); i++)
	if (inList(remove, theList[i].instance))
	    theList[i].instance = 0;		/* Mark empty */
    compress(theList);
}


/*======================================================================*/
void mergeLists(Parameter one[], Parameter other[])
{
    int i,last;

    for (last = 0; !isEndOfList(&one[last]); last++); /* Find end of list */
    for (i = 0; !isEndOfList(&other[i]); i++)
	if (!inList(one, other[i].instance)) {
	    one[last++] = other[i];
	    setEndOfList(&one[last]);
	}
}


/*======================================================================*/
void intersect(Parameter one[], Parameter other[])
{
    int i, last = 0;

    for (i = 0; !isEndOfList(&one[i]); i++)
	if (inList(other, one[i].instance))
	    one[last++] = one[i];
    setEndOfList(&one[last]);
}


/*======================================================================*/
void copyReferences(Parameter parameterList[], Aint references[])
{
    int i;

    for (i = 0; !isEndOfList(&references[i]); i++) {
        parameterList[i].instance = references[i];
        parameterList[i].firstWord = EOF; /* Ensure that there is no word that can be used */
    }
    setEndOfList(&parameterList[i]);
}


/*======================================================================*/
void addParameterForInstance(Parameter *parameters, int instance) {
    Parameter *parameter = findEndOfList(parameters);

    parameter->instance = instance;
    parameter->useWords = FALSE;

    setEndOfList(parameter+1);
}


/*======================================================================*/
void addParameterForInteger(Parameter *parameters, int value) {
    Parameter *parameter = findEndOfList(parameters);

    createIntegerLiteral(value);
    parameter->instance = instanceFromLiteral(litCount);
    parameter->useWords = FALSE;

    setEndOfList(parameter+1);
}

/*======================================================================*/
void addParameterForString(Parameter *parameters, char *value) {
    Parameter *parameter = findEndOfList(parameters);

    createStringLiteral(value);
    parameter->instance = instanceFromLiteral(litCount);
    parameter->useWords = FALSE;

    setEndOfList(parameter+1);
}
