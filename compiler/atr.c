/*----------------------------------------------------------------------*\

				ATR.C
			   Attribute Nodes

\*----------------------------------------------------------------------*/

#include "atr_x.h"


/* IMPORT: */
#include "srcp_x.h"
#include "id_x.h"
#include "sym_x.h"
#include "lst_x.h"
#include "exp_x.h"

#include "util.h"
#include "emit.h"

#include "adv.h"		/* ADV-node */
#include "ins.h"		/* INS-nodes */
#include "opt.h"		/* OPT-nodes */

#include "acode.h"

#include "lmList.h"
#include "encode.h"
#include "dump.h"


/* Exported data: */

int atrmax;



/*======================================================================

  newatr()

  Allocates and initialises an atrnod.

 */
AtrNod *newatr(Srcp *srcp,	/* IN - Source Position */
	       TypeKind typ,	/* IN - Type of this atribute */
	       IdNode *id,	/* IN - The id */
	       int value,	/* IN - The initial value */
	       long int fpos,	/* IN - File position for initial string */
	       int len)		/* IN - D:o length */
{
  AtrNod *new;			/* The newly allocated area */

  if (verbose) { printf("%8ld\b\b\b\b\b\b\b\b", counter++); fflush(stdout); }

  new = NEW(AtrNod);

  new->srcp = *srcp;
  new->typ = typ;
  new->id = id;
  new->inheritance = UNKNOWN_INHERITANCE;
  new->value = value;
  new->stringAddress = 0;
  new->encoded = FALSE;
  new->fpos = fpos;
  new->len = len;

  return(new);
}


/*======================================================================

  checkMutipleAttributes()

  Check for multiple declarations of attributes in a list.

 */
void checkMultipleAttributes(List *atrs)
{
  List *al;

  while (atrs) {
    for (al = atrs->next; al; al = al->next) {
      if (equalId(atrs->element.atr->id, al->element.atr->id))
	  lmLog(&al->element.atr->id->srcp, 218, sevERR, al->element.atr->id->string);
    }
    atrs = atrs->next;
  }
}


/*======================================================================

  findAttribute()

*/
AtrNod *findAttribute(List *attributes, IdNode *id)
{
  List *this;

  for (this = attributes; this != NULL; this = this->next)
    if (equalId(this->element.atr->id, id))
      return this->element.atr;
  return NULL;
}


/*======================================================================

  sortAttributes()

  Sort a list of attributes.

 */
List *sortAttributes(List *attributes)
{
  List *sortedList = attributes;
  Bool change;			/* Change during sorting */
  List **lstp;			/* Pointer to a list pointer */
  List *tmp1, *tmp2;		/* Temporary pointers */

  if (attributes != NULL) {
    change = TRUE;
    while (change) {
      change = FALSE;
      for (lstp = &sortedList; (*lstp)->next != NULL; lstp = &(*lstp)->next) {
	tmp1 = *lstp;
	tmp2 = tmp1->next;
	if (tmp1->element.atr->id->code > tmp2->element.atr->id->code){
	  change = TRUE;
	  tmp1->next = tmp2->next;
	  tmp2->next = tmp1;
	  *lstp = tmp2;
	}
      }
    }
  }
  return sortedList;
}



/*----------------------------------------------------------------------

  copyAttribute()

  Make a copy of an attribute

*/
static AtrNod *copyAttribute(AtrNod *theOriginal)
{
  AtrNod *theCopy = NEW(AtrNod);

  memcpy(theCopy, theOriginal, sizeof(AtrNod));
  theCopy->inheritance = INHERITED;
  return theCopy;
}


/*----------------------------------------------------------------------

  copyAttributeList()

  Make a copy of a complete attribute list

*/
static List *copyAttributeList(List *theOriginal)
{
  List *theCopy = NULL;
  List *traversal;

  for (traversal = theOriginal; traversal != NULL; traversal = traversal->next)
    theCopy = concat(theCopy, copyAttribute(traversal->element.atr),
		     LIST_ATR);
  return theCopy;
}



/*======================================================================

  combineAttributes()

  Insert all attributes from the list to add that are not there
  already, then sort the list.

*/
List *combineAttributes(List *ownAttributes, List *attributesToAdd)
{
  List *own = ownAttributes;
  List *toAdd = attributesToAdd;
  List *added = NULL;

  while (own != NULL) {
    if (toAdd == NULL)
      break;
    else if (own->element.atr->id->code == toAdd->element.atr->id->code) {
      own = own->next;
      toAdd = toAdd->next;
    } else if (own->element.atr->id->code < toAdd->element.atr->id->code) {
      own = own->next;
    } else if (own->element.atr->id->code > toAdd->element.atr->id->code) {
      insert(own, copyAttribute(toAdd->element.atr), LIST_ATR);
      toAdd = toAdd->next;
    }
  }
  if (toAdd != NULL)
    added = combine(added, copyAttributeList(toAdd));
  own = combine(ownAttributes, added);
  own = sortAttributes(own);
  return own;
}



/*======================================================================

  anatrs()

  Analyze a list of attributes.

 */
void anatrs(List *atrs)		/* IN - pointer to a pointer to the list */
{
  List *al;

  while (atrs) {
    for (al = atrs->next; al; al = al->next) {
      if (equalId(atrs->element.atr->id, al->element.atr->id))
	  lmLog(&al->element.atr->id->srcp, 218, sevERR, al->element.atr->id->string);
    }
    atrs = atrs->next;
  }
}


/*======================================================================

  resolveAttributeReference()

  Analyze a reference to an attribute. Will handle static identifiers and
  parameters and return a reference to the attribute node, if all is well.

 */
AtrNod *resolveAttributeReference(WhtNod *what, IdNode *attribute, Context *context)
{
  AtrNod *atr = NULL;
  SymNod *sym;
  SymNod *classOfParameter;

  sym = symcheck(what->id, INSTANCE_SYMBOL, context);
  if (sym) {
    if (sym->kind == INSTANCE_SYMBOL) {
      what->id->code = sym->code;
      atr = findAttribute(sym->fields.claOrIns.slots->attributes, attribute);
      if (atr == NULL)
	lmLog(&attribute->srcp, 315, sevERR, what->id->string);
    } else if (sym->kind == PARAMETER_SYMBOL) {
      if (sym->fields.parameter.class != NULL) {
	classOfParameter = sym->fields.parameter.class;
	atr = findAttribute(classOfParameter->fields.claOrIns.slots->attributes, attribute);
	if (atr == NULL)
	  lmLogv(&attribute->srcp, 316, sevERR, attribute->string,
		 what->id->string, classOfParameter->string, NULL);
      } else
	lmLog(&attribute->srcp, 406, sevERR, "");
    }
    return atr;
  } else /* no symbol found */
    return NULL;
}


/*----------------------------------------------------------------------

  generateAttribute()

  */
static void generateAttribute(AtrNod *attribute)
{
  AttributeEntry entry;
  AtrNod *new;

  if (attribute->typ == STRING_TYPE) {
    if (!attribute->encoded) {
      encode(&attribute->fpos, &attribute->len);
      attribute->encoded = TRUE;
    }
    attribute->address = emadr(); /* Record on which Aadress to put it */

    /* Now make a copy to use for initialisation if attribute is
       inherited, else the address will be overwritten by generation
       of other instances of the same attribute */
    new = newatr(&attribute->srcp, STRING_TYPE, NULL, attribute->value,
		 attribute->fpos, attribute->len);
    new->address = attribute->address;
    adv.stratrs = concat(adv.stratrs, new, LIST_ATR);
  }

  entry.code = attribute->id->code;
  entry.value = attribute->value;
  entry.stringAddress = attribute->stringAddress;
  emitEntry(&entry, sizeof(entry));
}


/*======================================================================

  generateAttributes()

  Generate all entries in an attribute list.

 */
Aword generateAttributes(List *atrs) /* IN - List of attribute nodes */
{
  Aaddr adr;
  List *lst;

  /* First generate the names of the attributes if needed */ 
  if ((Bool) opts[OPTDEBUG].value) {
    for (lst = atrs; lst != NULL; lst = lst->next) {
      lst->element.atr->stringAddress = emadr();
      emitstr(lst->element.atr->id->string);
    }
  }

  adr = emadr();

  for (lst = atrs; lst != NULL; lst = lst->next)
    generateAttribute(lst->element.atr);
  emit(EOF);

  return(adr);
}



/*======================================================================

  generateStringInit()

  Generate initialisation value table for string attributes.

 */
Aaddr generateStringInit(void)
{
  List *atrs;
  Aaddr adr = emadr();

  for (atrs = adv.stratrs; atrs != NULL; atrs = atrs->next) {
    emit(atrs->element.atr->fpos);
    emit(atrs->element.atr->len);
    emit(atrs->element.atr->address);
  }
  emit(EOF);
  return adr;
}


/*----------------------------------------------------------------------

  dumpInheritance()

*/
static void dumpInheritance(AttributeInheritance inheritance)
{
  switch (inheritance) {
  case UNKNOWN_INHERITANCE: put("UNKNOWN"); break;
  case LOCAL: put("LOCAL"); break;
  case INHERITED_REDEFINED: put("INHERITED/REDEFINED"); break;
  case INHERITED: put("INHERITED"); break;
  }
}


/*======================================================================

  dumpAttribute()

  Dump an Attribute node.

 */
void dumpAttribute(AtrNod *atr)
{
  put("ATR: "); dumpSrcp(&atr->srcp); in();
  put("type: "); dumpType(atr->typ); nl();
  put("id: "); dumpId(atr->id); nl();
  put("inheritance: "); dumpInheritance(atr->inheritance); nl();
  put("stringAddress: "); dumpAddress(atr->stringAddress); nl();
  put("address: "); dumpAddress(atr->address); nl();
  put("value: "); dumpInt(atr->value); nl();
  put("fpos: "); dumpInt(atr->fpos); nl();
  put("len: "); dumpInt(atr->len); out();
}
