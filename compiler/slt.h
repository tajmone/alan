#ifndef _SLT_H_
#define _SLT_H_
/*----------------------------------------------------------------------*\

				SLT.H
			     Slots Nodes
                                                                     
\*----------------------------------------------------------------------*/


/* USE: */
#include "types.h"
#include "lst.h"
#include "whr.h"
#include "cnt.h"

#include "acode.h"


/* Types */

typedef struct SlotsNode {	/* SLOTS  */
  List *namslst;		/* List of lists of adjectives and a noun */
  List *namstms;		/* Name printing statements */
  Aword namsadr;		/* ACODE address to name printing */
  WhrNod *whr;			/* Where is it initially? */
  CntNod *cnt;			/* Container properties */
  List *atrs;			/* Attributes ... */
  Aword atradr;			/* ACODE address to attribute list */
  List *dscr;			/* Long description statements */
  Aword dscradr;		/* ACODE address to long description code */
  List *art;			/* Article printing statements */
  Aword artadr;			/* ACODE address to article statements */
  List *ment;			/* Short (inventory like) statements */
  Aword mentadr;		/* ACODE address to short description (mentioned) code */
  List *vrbs;			/* List of verbs */
  Aword vrbadr;			/* ACODE address to local verb table */
  List *scrs;			/* List of scripts */
  Aaddr scradr;			/* ACODE address to scripts */
  List *exts;			/* List of exits */
  Aaddr extadr;			/* ACODE address to exits */
} SlotsNode;


#endif
