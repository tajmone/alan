#ifndef _SCRIPT_H_
#define _SCRIPT_H_
/*----------------------------------------------------------------------*\

			       Script.h

			     Script Nodes
                                                                     
\*----------------------------------------------------------------------*/


/* USE other definitions */
#include "Srcp.h"
#include "List.h"
#include "Id.h"

#include "acode.h"


/* Types: */

typedef struct Script {		/* SCRIPT */
  Srcp srcp;			/* Source position */
  Id *id;			/* Name for this script */
  int code;			/* Code for the script */
  List *description;		/* List of optional description statements */
  Aaddr stmadr;			/* ACODE address description statements */
  List *steps;			/* List of step-blocks */
  Aaddr stpadr;			/* ACODE address to step table */
} Script;


/* Data: */


/* Functions: */
#ifdef _PROTOTYPES_

/* Create a new Script node */
extern Script *newScript(Srcp *srcp,
			 Id *id,
			 List *description,
			 List *steps);

/* Analyse a list of Scripts */
extern void analyseScripts(List *scripts);

/* Generate script routines for an actor */
extern Aword generateScripts();

/* Dump a Script node */
extern void dumpScript(Script *script);

#else
extern Script *newScript();
extern void analyseScripts();
extern Aword generateScripts();
extern void dumpScript();
#endif

#endif
