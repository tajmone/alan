/*----------------------------------------------------------------------*\

                               ALT.C
		       Verb Alternatives Nodes

\*----------------------------------------------------------------------*/

#include "util.h"

#include "lmList.h"

#include "srcp_x.h"
#include "id_x.h"
#include "chk_x.h"
#include "lst_x.h"
#include "stm_x.h"
#include "sym_x.h"
#include "context_x.h"


#include "alt.h"                /* ALT-nodes */
#include "elm.h"

#include "emit.h"
#include "../interpreter/acode.h"
#include "dump.h"


/* PUBLIC: */


/*======================================================================

  newalt()

  Allocates and initialises a syntax element node.

 */
AltNod *newalt(Srcp *srcp,	/* IN - Source Position */
	       IdNode *id,	/* IN - The name */
	       List *chks,	/* IN - Checks */
	       QualKind qual,	/* IN - Action qualifier */
	       List *stms)	/* IN - Statements (does-part) */
{
  AltNod *new;			/* The newly created node */

  showProgress();

  new = NEW(AltNod);

  new->srcp = *srcp;
  new->id = id;
  new->chks = chks;
  new->qual = qual;
  new->stms = stms;

  return(new);
}



/*----------------------------------------------------------------------*/
static void analyzeAlternative(AltNod *alt,
			       Context *context)
{
  Symbol *parameter;

  if (alt->id != NULL) {
    /* Alternatives given, find out for which parameter this one is */
    parameter = lookupParameter(alt->id, context->verb->fields.verb.parameterSymbols);
    if (parameter == NULL)
      lmLog(&alt->id->srcp, 214, sevERR, alt->id->string);
    else {
      alt->id->symbol = parameter;
      alt->parameterNumber = parameter->code;
    }
  } else
    if (inLocationContext(context))
      alt->parameterNumber = 0;
    else if (context->verb != NULL && context->verb->fields.verb.parameterSymbols != NULL)
      alt->parameterNumber = 1;

  analyzeChecks(alt->chks, context);
  analyzeStatements(alt->stms, context);
}



/*======================================================================*/
void analyzeAlternatives(List *alts,
			 Context *context)
{
  List *lst;

  for (lst = alts; lst != NULL; lst = lst->next)
    analyzeAlternative(lst->element.alt, context);
}



/*----------------------------------------------------------------------

  gealtent()

  Generate an entry in an alt-table
  
  */
static void gealtent(AltNod *alt) /* IN - The alt to make an entry for */
{
  emit(0);			/* Auto-Reverse flag */

  emit(alt->parameterNumber);

  switch (alt->qual) {
  case QUAL_BEFORE:
    emit(Q_BEFORE);
    break;
    
  case QUAL_AFTER:
    emit(Q_AFTER);
    break;
    
  case QUAL_ONLY:
    emit(Q_ONLY);
    break;
    
  case QUAL_DEFAULT:
    emit(Q_DEFAULT);
    break;
    
  default:
    syserr("Unrecognized switch in gealtent()");
    break;
  }

  emit(alt->chkadr);
  emit(alt->stmadr);
}


/*----------------------------------------------------------------------*/
static void generateAlternative(AltNod *alt)
{
  /* First the action, if there is any */
  if (alt->stms == NULL)
    alt->stmadr = 0;
  else {
    alt->stmadr = emadr();
    generateStatements(alt->stms);
    emit0(I_RETURN);
  }
  
  /* Then possible CHECKs */
  if (alt->chks == NULL)
    alt->chkadr = 0;
  else
    alt->chkadr = generateChecks(alt->chks);
}



/*======================================================================*/
Aaddr gealts(List *alts)
{
  List *lst;
  Aaddr altadr;

  for (lst = alts; lst != NULL; lst = lst->next)
    generateAlternative(lst->element.alt);

  altadr = emadr();
  for (lst = alts; lst != NULL; lst = lst->next)
    gealtent(lst->element.alt);
  emit(EOF);

  return(altadr);
}



/*----------------------------------------------------------------------

  duqual()

  Dump a verb qualifier.

  */
static void duqual (QualKind qual)
{
  switch (qual) {
  case QUAL_AFTER:   put("AFTER"); break;
  case QUAL_BEFORE:  put("BEFORE"); break;
  case QUAL_ONLY:    put("ONLY"); break;
  case QUAL_DEFAULT: put("DEFAULT"); break;
  default: put("*** ERROR ***");
  }
}



/*======================================================================

  dualt()

  Dump a verb Alternative node.

 */
void dualt(AltNod *alt)
{
  if (alt == NULL) {
    put("NULL");
    return;
  }

  put("ALT: "); dumpSrcp(&alt->srcp); put(" qual: "); duqual(alt->qual); in();
  put("id: "); dumpId(alt->id); nl();
  put("chks: "); dumpList(alt->chks, CHECK_LIST); nl();
  put("stms: "); dumpList(alt->stms, STATEMENT_LIST); out();
}
