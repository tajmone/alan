/*----------------------------------------------------------------------*\

                               RES.C
		   Element Class Restriction Nodes

\*----------------------------------------------------------------------*/

#include "alan.h"
#include "util.h"

#include "srcp.h"
#include "lmList.h"

#include "res.h"                /* RES-nodes */

#include "sym.h"		/* SYM-nodes */
#include "lst.h"		/* LST-nodes */
#include "nam.h"		/* NAM-nodes */
#include "stm.h"                /* STM-nodes */

#include "emit.h"

#include "acode.h"

#include "dump.h"


/* PUBLIC: */


/*======================================================================

  newres()

  Allocates and initialises an element class restriction node.

 */
ResNod *newres(Srcp *srcp,	/* IN - Source Position */
	       IdNod *id,	/* IN - The name */
	       Bool single,	/* IN - A single class identifier? */
	       List *classes,	/* IN - Allowed classes */
	       List *stms)	/* IN - Statements to execute otherwise */
{
  ResNod *new;			/* The newly created node */

  if (verbose) { printf("%8ld\b\b\b\b\b\b\b\b", counter++); fflush(stdout); }

  new = NEW(ResNod);

  new->srcp = *srcp;
  new->id = id;
  new->single = single;
  new->classes = classes;
  new->stms = stms;

  return(new);
}



/*----------------------------------------------------------------------

  anres()

  Analyzes one element class restriction node.

 */
static void anres(
     ResNod *res,		/* IN - Restriction node to analyze */
     List *params		/* IN - Possible syntax parameters */
)
{
  Bool found = FALSE;
  List *p;
  List *idList;

  /* Check for the id in the parameter list */
  for (p = params; p != NULL; p = p->next)
    if (eqids(res->id, p->element.elm->id)) {
      found = TRUE;
      break;
    }
  if (!found)
    lmLog(&res->id->srcp, 222, sevERR, res->id->string);

  /* Analyse the class list */
  for (idList = res->classes; idList; idList = idList->next) {
    syserr("UNIMPLEMENTED: anres - Look up the classes and attach them to here");
    /* For now "actor" etc. are converted to their restriction kinds */
    if (strcmp(idList->element.nam->str, "actor") == 0)
      res->classbits |= NAMACT;
    else if (strcmp(idList->element.nam->str, "object") == 0)
      res->classbits |= NAMOBJ;
    else if (strcmp(idList->element.nam->str, "container") == 0)
      res->classbits |= NAMCNT;
    else if (strcmp(idList->element.nam->str, "#containeractor") == 0)
      res->classbits |= NAMCACT;
    else if (strcmp(idList->element.nam->str, "#containerobject") == 0)
      res->classbits |= NAMCOBJ;
    else if (strcmp(idList->element.nam->str, "#integer") == 0)
      res->classbits |= NAMNUM;
    else if (strcmp(idList->element.nam->str, "#string") == 0)
      res->classbits |= NAMSTR;
    else
      unimpl(&idList->element.nam->srcp, "analyzer");
  }

  /* Analyse the statements to execute if the restrictions was not met */
  anstms(res->stms, NULL, NULL, params);
}



/*======================================================================

  anress()

  Analyzes all class restriction nodes in a list by calling the analyzer
  for each.

 */
void anress(
    List *ress,			/* IN - List of nodes to analyze */
    List *params		/* IN - Possible syntax parameters */
)
{
  List *lst;

  for (lst = ress; lst != NULL; lst = lst->next)
    anres(lst->element.res, params);
}



/*----------------------------------------------------------------------

  geres()

  Generate code for one syntax class restriction node.

 */
static void geres(ResNod *res)	/* IN - Node to generate */
{
  res->stmadr = emadr();
  gestms(res->stms, NULL);
  emit0(C_STMOP, I_RETURN);
}



/*----------------------------------------------------------------------

  geresent()

  Generate an entry for one restriction node.

 */
static void geresent(ResNod *res) /* IN - Node to generate */
{
#ifndef FIXME
  syserr("UNIMPL: geresent()");
#else
  emit(res->id->code);
  emit(res->classbits);
  emit(res->stmadr);
#endif
}



/*======================================================================

  geress()

  Generate the data structure for the element class restrictions.

 */
Aaddr geress(List *ress,	/* IN - The element class restriction nodes */
	     StxNod *stx)	/* IN - Syntax node containing the res */
{
  List *lst;
  Aaddr resadr;

  for (lst = ress; lst != NULL; lst = lst->next)
    geres(lst->element.res);

  resadr = emadr();
  for (lst = ress; lst != NULL; lst = lst->next)
    geresent(lst->element.res);

  /* End it with an End of file and the code for the verb */
  emit(EOF);
  geid(stx->id);

  return(resadr);
}


/*----------------------------------------------------------------------

  dumpRestrictionKind()

*/
static void dumpRestrictionKind(ResKind resKd)
{
  switch (resKd) {
  case ID_RESTRICTION: put("ID"); break;
  case INTEGER_RESTRICTION: put("INTEGER"); break;
  case STRING_RESTRICTION: put("STRING"); break;
  case OBJECT_RESTRICTION: put("OBJECT"); break;
  case ACTOR_RESTRICTION: put("ACTOR"); break;
  case CONTAINER_RESTRICTION: put("CONTAINER"); break;
  case CONTAINEROBJECT_RESTRICTION: put("CONTAINEROBJECT"); break;
  case CONTAINERACTOR_RESTRICTION: put("CONTAINERACTOR"); break;
  default: syserr("Unknown restriction kind in dumpRestricitionKind()");
  }
}    



/*======================================================================

  dures()

  Dump a syntax element Class restriction node.

 */
void dures(ResNod *res)
{
  if (res == NULL) {
    put("NULL");
    return;
  }

  put("RES: "); dusrcp(&res->srcp); in();
  put("id: "); dumpId(res->id); nl();
  put("single: "); dumpBool(res->single); nl();
  put("classbits: "); dumpNamKind(res->classbits); nl();
  put("classes: "); dulst(res->classes, LIST_NAM); nl();
  put("stms: "); dulst(res->stms, LIST_STM); out();
}
