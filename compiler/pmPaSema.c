/*----------------------------------------------------------------------*\

	pmPaSema.c

	ParserMaker generated semantic actions

\*----------------------------------------------------------------------*/

/* %%IMPORT */


#include "util.h"
#include "acode.h"

#include "types.h"
#include "smScan.h"
#include "token.h"

#include "lmList.h"

#include "alt.h"
#include "evt.h"
#include "lim.h"
#include "msg.h"
#include "opt.h"
#include "sco.h"
#include "str.h"
#include "syn.h"
#include "adv_x.h"
#include "add_x.h"
#include "article_x.h"
#include "atr_x.h"
#include "cla_x.h"
#include "chk_x.h"
#include "cnt_x.h"
#include "elm_x.h"
#include "exp_x.h"
#include "ext_x.h"
#include "id_x.h"
#include "ins_x.h"
#include "description_x.h"
#include "initialize_x.h"
#include "resource_x.h"
#include "rul_x.h"
#include "lst_x.h"
#include "prop_x.h"
#include "res_x.h"
#include "scr_x.h"
#include "stm_x.h"
#include "stp_x.h"
#include "stx_x.h"
#include "sym_x.h"
#include "srcp_x.h"
#include "vrb_x.h"
#include "whr_x.h"
#include "wht_x.h"

/* END %%IMPORT */

/* System dependencies
 * -------------------
 */

/* These datatypes should be defined to be unsigned integers of length 1, 2
 * and 4 bytes respectively.
 */
typedef unsigned char UByte1;
typedef unsigned short UByte2;
typedef unsigned int UByte4;

/* Token and Srcp definition */
#include "alanCommon.h"

/* Attribute stacks *\
\* ---------------- */
/* %%ATTRIBUTES */
/* The semantic attributes for grammar symbols */
typedef struct pmGrammar {
    Bool wordOrChar;
    What *wht;
    Where *whr;
    List *vrbs;
    Verb *vrb;
    int val;
    List *syns;
    Synonym *syn;
    List *stxs;
    Syntax *stx;
    char *str;
    List *stps;
    Step *stp;
    List *stms3;
    List *stms2;
    List *stms;
    Statement *stm;
    Srcp srcp2;
    Srcp srcp;
    List *set;
    List *scrs;
    Script *scr;
    SayForm sayForm;
    List *ruls;
    RulNod *rul;
    RestrictionKind restrictionKind;
    List *ress;
    Restriction *res;
    QualKind qual;
    Srcp pronounsSrcp;
    List *pronouns;
    List *prompt;
    Bool present;
    Bool opaque;
    OperatorKind op;
    Bool on_or_off;
    Article *negative;
    List *nams;
    List *nam;
    List *msgs;
    Message *msg;
    Bool minus;
    Srcp mentionedSrcp;
    List *mentioned;
    List *lims;
    LimNod *lim;
    Bool isForm;
    List *inss;
    Instance *ins;
    Article *indefinite;
    List *idList2;
    List *idList;
    Id *id;
    List *form;
    Bool first;
    List *exts;
    Exit *ext;
    List *exps;
    Expression *exp;
    List *evts;
    Event *evt;
    Initialize *initialize;
    Srcp enteredSrcp;
    List *entered;
    List *elms;
    Element *elm;
    Srcp descriptionSrcp;
    List *descriptionDoes;
    List *descriptionChecks;
    Srcp descriptionCheckSrcp;
    Description *description;
    Srcp definiteSrcp;
    Bool definiteIsForm;
    Article *definite;
    List *cnts;
    Container *cnt;
    List *clas;
    Class *cla;
    List *chks;
    CheckNode *chk;
    List *cases;
    int bits;
    List *atrs;
    Attribute *atr;
    Article *article;
    List *alts;
    Alternative *alt;
    AggregateKind agr;
    AddNode *add;
} pmGrammar;

/* END %%ATTRIBUTES */

extern short pmStkP;
extern Token pmSySt[];
extern pmGrammar pmSeSt[];

/* %%DECLARATIONS - User data and routines */

#line 84 "alan.pmk"


static int val(char str[])
{
  int temp;

  sscanf(str, "%d", &temp);
  return(temp);
}



/* END %%DECLARATIONS */


/*----------------------------------------------------------------------------
 * pmPaSema - The semantic actions
 *----------------------------------------------------------------------------
 */
void pmPaSema(
int rule			/* IN production number */
)
{
#line 202 "alan.pmk"
    switch (rule) {
    case 8: { /* <option> = ID '.'; */
#line 222 "alan.pmk"

	optBool(pmSeSt[pmStkP+1].id->string, &pmSeSt[pmStkP+1].id->srcp, TRUE);
    	break;}
    case 9: { /* <option> = ID ID '.'; */
#line 227 "alan.pmk"

	optenum(pmSeSt[pmStkP+1].id->string, &pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+2].id->string);
    	break;}
    case 10: { /* <option> = ID Integer '.'; */
#line 232 "alan.pmk"

	optint(pmSeSt[pmStkP+1].id->string, &pmSeSt[pmStkP+1].id->srcp, val(pmSySt[pmStkP+2].chars));
    	break;}
    case 19: { /* <declaration> = <synonyms>; */
#line 245 "alan.pmk"
 adv.syns = combine(adv.syns, pmSeSt[pmStkP+1].syns);	break;}
    case 15: { /* <declaration> = <messages>; */
#line 248 "alan.pmk"
 adv.msgs = combine(adv.msgs, pmSeSt[pmStkP+1].msgs); 	break;}
    case 20: { /* <declaration> = <syntax>; */
#line 251 "alan.pmk"
 adv.stxs = combine(adv.stxs, pmSeSt[pmStkP+1].stxs); 	break;}
    case 21: { /* <declaration> = <verb>; */
#line 254 "alan.pmk"
 adv.vrbs = concat(adv.vrbs, pmSeSt[pmStkP+1].vrb, VERB_LIST); 	break;}
    case 16: { /* <declaration> = <class>; */
#line 257 "alan.pmk"
 adv.clas = concat(adv.clas, pmSeSt[pmStkP+1].cla, CLASS_LIST); 	break;}
    case 22: { /* <declaration> = <addition>; */
#line 260 "alan.pmk"
 adv.adds = concat(adv.adds, pmSeSt[pmStkP+1].add, ADD_LIST); 	break;}
    case 17: { /* <declaration> = <instance>; */
#line 263 "alan.pmk"
 adv.inss = concat(adv.inss, pmSeSt[pmStkP+1].ins, INSTANCE_LIST); 	break;}
    case 23: { /* <declaration> = <event>; */
#line 266 "alan.pmk"
 adv.evts = concat(adv.evts, pmSeSt[pmStkP+1].evt, EVENT_LIST); 	break;}
    case 18: { /* <declaration> = <rule>; */
#line 269 "alan.pmk"
 adv.ruls = concat(adv.ruls, pmSeSt[pmStkP+1].rul, RULE_LIST); 	break;}
    case 14: { /* <declaration> = <prompt>; */
#line 272 "alan.pmk"

      if (adv.prompt != NULL)
        lmLog(&pmSeSt[pmStkP+1].srcp, 308, sevWAR, "PROMPT");
      adv.prompt = pmSeSt[pmStkP+1].prompt;
    	break;}
    case 24: { /* <prompt> = 'prompt' <statements>; */
#line 283 "alan.pmk"

      pmSeSt[pmStkP+1].prompt = pmSeSt[pmStkP+2].stms;
      pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 25: { /* <attributes> = <attribute_definition> '.'; */
#line 292 "alan.pmk"

	pmSeSt[pmStkP+1].atrs = newList(pmSeSt[pmStkP+1].atr, ATTRIBUTE_LIST);
    	break;}
    case 26: { /* <attributes> = <attributes> <attribute_definition> '.'; */
#line 297 "alan.pmk"

	pmSeSt[pmStkP+1].atrs = concat(pmSeSt[pmStkP+1].atrs, pmSeSt[pmStkP+2].atr, ATTRIBUTE_LIST);
    	break;}
    case 27: { /* <attribute_definition> = ID; */
#line 304 "alan.pmk"

	pmSeSt[pmStkP+1].atr = newBooleanAttribute(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id, TRUE);
    	break;}
    case 28: { /* <attribute_definition> = 'not' ID; */
#line 309 "alan.pmk"

	pmSeSt[pmStkP+1].atr = newBooleanAttribute(pmSeSt[pmStkP+2].id->srcp,	pmSeSt[pmStkP+2].id, FALSE);
    	break;}
    case 31: { /* <attribute_definition> = ID <optional_minus> Integer; */
#line 314 "alan.pmk"

	if (pmSeSt[pmStkP+2].minus)
		pmSeSt[pmStkP+1].atr = newIntegerAttribute(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id, -val(pmSySt[pmStkP+3].chars));
	else
		pmSeSt[pmStkP+1].atr = newIntegerAttribute(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id, val(pmSySt[pmStkP+3].chars));
    	break;}
    case 29: { /* <attribute_definition> = ID STRING; */
#line 322 "alan.pmk"

	pmSeSt[pmStkP+1].atr = newStringAttribute(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id, pmSySt[pmStkP+2].fpos, pmSySt[pmStkP+2].len);
    	break;}
    case 30: { /* <attribute_definition> = ID ID; */
#line 326 "alan.pmk"

	pmSeSt[pmStkP+1].atr = newReferenceAttribute(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id, pmSeSt[pmStkP+2].id);
    	break;}
    case 32: { /* <attribute_definition> = ID '{' <optional_members> '}'; */
#line 331 "alan.pmk"

	pmSeSt[pmStkP+1].atr = newSetAttribute(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id,
			newSetExpression(pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+3].set));
    	break;}
    case 33: { /* <optional_members> =; */
#line 339 "alan.pmk"
 pmSeSt[pmStkP+1].set = NULL; 	break;}
    case 34: { /* <optional_members> = <set_members>; */
#line 342 "alan.pmk"
 pmSeSt[pmStkP+1].set = pmSeSt[pmStkP+1].set; 	break;}
    case 35: { /* <set_members> = <set_member>; */
#line 347 "alan.pmk"

	pmSeSt[pmStkP+1].set = newList(pmSeSt[pmStkP+1].exp, EXPRESSION_LIST);
    	break;}
    case 36: { /* <set_members> = <set_members> ',' <set_member>; */
#line 352 "alan.pmk"

	pmSeSt[pmStkP+1].set = concat(pmSeSt[pmStkP+1].set, pmSeSt[pmStkP+3].exp, EXPRESSION_LIST);
    	break;}
    case 37: { /* <set_member> = <what>; */
#line 359 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp;
    	break;}
    case 39: { /* <set_member> = <optional_minus> Integer; */
#line 364 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newIntegerExpression(pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].minus?-val(pmSySt[pmStkP+2].chars):val(pmSySt[pmStkP+2].chars));
    	break;}
    case 38: { /* <set_member> = STRING; */
#line 369 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newStringExpression(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].fpos, pmSySt[pmStkP+1].len);
    	break;}
    case 40: { /* <synonyms> = 'synonyms' <synonym_list>; */
#line 377 "alan.pmk"

	pmSeSt[pmStkP+1].syns = pmSeSt[pmStkP+2].syns;
    	break;}
    case 41: { /* <synonym_list> = <synonym_declaration>; */
#line 384 "alan.pmk"

	pmSeSt[pmStkP+1].syns = newList(pmSeSt[pmStkP+1].syn, SYNONYM_LIST);
    	break;}
    case 42: { /* <synonym_list> = <synonym_list> <synonym_declaration>; */
#line 389 "alan.pmk"

	pmSeSt[pmStkP+1].syns = concat(pmSeSt[pmStkP+1].syns, pmSeSt[pmStkP+2].syn, SYNONYM_LIST);
    	break;}
    case 43: { /* <synonym_declaration> = <id_list> '=' ID '.'; */
#line 396 "alan.pmk"

	pmSeSt[pmStkP+1].syn = newSynonym(&pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].idList, pmSeSt[pmStkP+3].id);
    	break;}
    case 44: { /* <messages> = 'message' <message_list>; */
#line 404 "alan.pmk"

	pmSeSt[pmStkP+1].msgs = pmSeSt[pmStkP+2].msgs;
    	break;}
    case 45: { /* <message_list> = <message>; */
#line 411 "alan.pmk"

	pmSeSt[pmStkP+1].msgs = newList(pmSeSt[pmStkP+1].msg, MESSAGE_LIST);
    	break;}
    case 46: { /* <message_list> = <message_list> <message>; */
#line 416 "alan.pmk"

	pmSeSt[pmStkP+1].msgs = concat(pmSeSt[pmStkP+1].msgs, pmSeSt[pmStkP+2].msg, MESSAGE_LIST);
    	break;}
    case 47: { /* <message> = ID ':' <statements>; */
#line 423 "alan.pmk"

	pmSeSt[pmStkP+1].msg = newMessage(&pmSySt[pmStkP+2].srcp,
				      	pmSeSt[pmStkP+1].id,
					pmSeSt[pmStkP+3].stms);
    	break;}
    case 48: { /* <syntax> = 'syntax' <syntax_list>; */
#line 434 "alan.pmk"

	pmSeSt[pmStkP+1].stxs = pmSeSt[pmStkP+2].stxs;
    	break;}
    case 49: { /* <syntax_list> = <syntax_item>; */
#line 441 "alan.pmk"

	pmSeSt[pmStkP+1].stxs = newList(pmSeSt[pmStkP+1].stx, SYNTAX_LIST);
    	break;}
    case 50: { /* <syntax_list> = <syntax_list> <syntax_item>; */
#line 446 "alan.pmk"

	pmSeSt[pmStkP+1].stxs = concat(pmSeSt[pmStkP+1].stxs, pmSeSt[pmStkP+2].stx, SYNTAX_LIST);
    	break;}
    case 51: { /* <syntax_item> = ID '=' <syntax_elements> <optional_syntax_restrictions>; */
#line 453 "alan.pmk"

	pmSeSt[pmStkP+1].stx = newSyntax(pmSySt[pmStkP+2].srcp,
				  	pmSeSt[pmStkP+1].id,
				  	concat(pmSeSt[pmStkP+3].elms,
				        	newEndOfSyntax(),
						ELEMENT_LIST),
					pmSeSt[pmStkP+4].ress,
					pmSeSt[pmStkP+4].srcp);
    	break;}
    case 52: { /* <syntax_elements> = <syntax_element>; */
#line 466 "alan.pmk"

	pmSeSt[pmStkP+1].elms = newList(pmSeSt[pmStkP+1].elm, ELEMENT_LIST);
    	break;}
    case 53: { /* <syntax_elements> = <syntax_elements> <syntax_element>; */
#line 471 "alan.pmk"

	pmSeSt[pmStkP+1].elms = concat(pmSeSt[pmStkP+1].elms,
				       pmSeSt[pmStkP+2].elm,
	                                ELEMENT_LIST);
    	break;}
    case 54: { /* <syntax_element> = ID; */
#line 480 "alan.pmk"

	pmSeSt[pmStkP+1].elm = newWordElement(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id);
    	break;}
    case 55: { /* <syntax_element> = '(' ID ')' <optional_indicators>; */
#line 486 "alan.pmk"

	pmSeSt[pmStkP+1].elm = newParameterElement(pmSeSt[pmStkP+2].id->srcp,
					   pmSeSt[pmStkP+2].id,
					   pmSeSt[pmStkP+4].bits);
    	break;}
    case 56: { /* <optional_indicators> =; */
#line 495 "alan.pmk"

	pmSeSt[pmStkP+1].bits = 0;
    	break;}
    case 57: { /* <optional_indicators> = <optional_indicators> <indicator>; */
#line 500 "alan.pmk"

	pmSeSt[pmStkP+1].bits |= pmSeSt[pmStkP+2].bits;
    	break;}
    case 58: { /* <indicator> = '*'; */
#line 507 "alan.pmk"

	pmSeSt[pmStkP+1].bits = MULTIPLEBIT;
    	break;}
    case 59: { /* <indicator> = '!'; */
#line 512 "alan.pmk"

	pmSeSt[pmStkP+1].bits = OMNIBIT;
    	break;}
    case 60: { /* <syntax_restriction_clauses> = <syntax_restriction>; */
#line 525 "alan.pmk"

	pmSeSt[pmStkP+1].ress = newList(pmSeSt[pmStkP+1].res, RESTRICTION_LIST);
    	break;}
    case 61: { /* <syntax_restriction_clauses> = <syntax_restriction_clauses> 'and' <syntax_restriction>; */
#line 530 "alan.pmk"

	pmSeSt[pmStkP+1].ress = concat(pmSeSt[pmStkP+1].ress,
				       pmSeSt[pmStkP+3].res, RESTRICTION_LIST);
    	break;}
    case 62: { /* <syntax_restriction> = ID 'isa' <restriction_class> 'else' <statements>; */
#line 538 "alan.pmk"

	pmSeSt[pmStkP+1].res = newRestriction(pmSySt[pmStkP+2].srcp,
			  			  pmSeSt[pmStkP+1].id,
						  pmSeSt[pmStkP+3].restrictionKind,
						  pmSeSt[pmStkP+3].id,
						  pmSeSt[pmStkP+5].stms);
    	break;}
    case 63: { /* <restriction_class> = ID; */
#line 549 "alan.pmk"

	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+1].id;
	pmSeSt[pmStkP+1].restrictionKind = ID_RESTRICTION;
    	break;}
    case 64: { /* <restriction_class> = 'container'; */
#line 555 "alan.pmk"

	pmSeSt[pmStkP+1].id = NULL;
	pmSeSt[pmStkP+1].restrictionKind = CONTAINER_RESTRICTION;
    	break;}
    case 65: { /* <optional_syntax_restrictions> = '.'; */
#line 563 "alan.pmk"

	pmSeSt[pmStkP+1].ress = NULL;
    	break;}
    case 66: { /* <optional_syntax_restrictions> = 'where' <syntax_restriction_clauses>; */
#line 568 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].ress = pmSeSt[pmStkP+2].ress;
    	break;}
    case 67: { /* <verb> = <verb_header> <verb_body> <verb_tail>; */
#line 578 "alan.pmk"

	pmSeSt[pmStkP+1].vrb = newVerb(&pmSeSt[pmStkP+1].srcp,
			   pmSeSt[pmStkP+1].idList,
			   pmSeSt[pmStkP+2].alts);
	if (pmSeSt[pmStkP+3].id != NULL) { /* END-id given */
	    if (compareStrings(pmSeSt[pmStkP+1].str, pmSeSt[pmStkP+3].id->string) != 0)
		lmLog(&pmSeSt[pmStkP+3].id->srcp, 200, sevWAR, pmSeSt[pmStkP+1].str);
	}
    	break;}
    case 68: { /* <verb_header> = 'verb' <id_list>; */
#line 591 "alan.pmk"

	pmSeSt[pmStkP+1].srcp   = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].str    = pmSeSt[pmStkP+2].str;
	pmSeSt[pmStkP+1].idList   = pmSeSt[pmStkP+2].idList;
    	break;}
    case 69: { /* <verb_body> = <simple_verb_body>; */
#line 600 "alan.pmk"

	pmSeSt[pmStkP+1].alts = newList(newAlternative(pmSeSt[pmStkP+1].srcp,
					NULL,
					pmSeSt[pmStkP+1].chks,
					pmSeSt[pmStkP+1].qual,
					pmSeSt[pmStkP+1].stms),
				   ALTERNATIVE_LIST);
    	break;}
    case 70: { /* <verb_body> = <verb_alternatives>; */
#line 610 "alan.pmk"

	pmSeSt[pmStkP+1].alts = pmSeSt[pmStkP+1].alts;
    	break;}
    case 71: { /* <verb_alternatives> = <verb_alternative>; */
#line 617 "alan.pmk"

	pmSeSt[pmStkP+1].alts = newList(pmSeSt[pmStkP+1].alt, ALTERNATIVE_LIST);
    	break;}
    case 72: { /* <verb_alternatives> = <verb_alternatives> <verb_alternative>; */
#line 622 "alan.pmk"

	pmSeSt[pmStkP+1].alts = concat(pmSeSt[pmStkP+1].alts,
					 pmSeSt[pmStkP+2].alt,
	     				ALTERNATIVE_LIST);
    	break;}
    case 73: { /* <verb_alternative> = 'when' ID <simple_verb_body>; */
#line 631 "alan.pmk"

	pmSeSt[pmStkP+1].alt = newAlternative(pmSySt[pmStkP+1].srcp,
						pmSeSt[pmStkP+2].id,
						pmSeSt[pmStkP+3].chks,
						pmSeSt[pmStkP+3].qual,
						pmSeSt[pmStkP+3].stms);
    	break;}
    case 74: { /* <simple_verb_body> = <optional_checks> <optional_does>; */
#line 642 "alan.pmk"

	if (pmSeSt[pmStkP+2].stms == NULL) /* No DOES */
	  pmSeSt[pmStkP+1].srcp = pmSeSt[pmStkP+1].srcp;
	else
	  pmSeSt[pmStkP+1].srcp = pmSeSt[pmStkP+2].srcp;
	pmSeSt[pmStkP+1].chks = pmSeSt[pmStkP+1].chks;
	pmSeSt[pmStkP+1].qual = pmSeSt[pmStkP+2].qual;
	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
    	break;}
    case 75: { /* <verb_tail> = 'end' 'verb' <optional_id> '.'; */
#line 655 "alan.pmk"

	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+3].id;
    	break;}
    case 76: { /* <optional_checks> =; */
#line 663 "alan.pmk"

	pmSeSt[pmStkP+1].chks = NULL;
	pmSeSt[pmStkP+1].srcp = nulsrcp;
    	break;}
    case 77: { /* <optional_checks> = 'check' <statements>; */
#line 669 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].chks = newList(newCheck(NULL, pmSeSt[pmStkP+2].stms), CHECK_LIST);
    	break;}
    case 78: { /* <optional_checks> = 'check' <check_list>; */
#line 675 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].chks = pmSeSt[pmStkP+2].chks;
    	break;}
    case 79: { /* <check_list> = <check>; */
#line 683 "alan.pmk"

	pmSeSt[pmStkP+1].chks = newList(pmSeSt[pmStkP+1].chk, CHECK_LIST);
    	break;}
    case 80: { /* <check_list> = <check_list> 'and' <check>; */
#line 688 "alan.pmk"

	pmSeSt[pmStkP+1].chks = concat(pmSeSt[pmStkP+1].chks, pmSeSt[pmStkP+3].chk, CHECK_LIST);
    	break;}
    case 81: { /* <check> = <expression> 'else' <statements>; */
#line 695 "alan.pmk"

	pmSeSt[pmStkP+1].chk = newCheck(pmSeSt[pmStkP+1].exp, pmSeSt[pmStkP+3].stms);
    	break;}
    case 82: { /* <optional_does> =; */
#line 703 "alan.pmk"

	pmSeSt[pmStkP+1].qual = QUAL_DEFAULT;
	pmSeSt[pmStkP+1].srcp = nulsrcp;
	pmSeSt[pmStkP+1].stms = NULL;
    	break;}
    case 83: { /* <optional_does> = <does>; */
#line 710 "alan.pmk"

	pmSeSt[pmStkP+1].qual = pmSeSt[pmStkP+1].qual;
	pmSeSt[pmStkP+1].srcp = pmSeSt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+1].stms;
    	break;}
    case 84: { /* <does> = 'does' <optional_qual> <statements>; */
#line 719 "alan.pmk"

	pmSeSt[pmStkP+1].qual = pmSeSt[pmStkP+2].qual;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+3].stms;
    	break;}
    case 85: { /* <class> = 'every' ID <optional_heritage> <properties> <class_tail>; */
#line 730 "alan.pmk"

	pmSeSt[pmStkP+1].cla = newClass(&pmSySt[pmStkP+1].srcp,
				pmSeSt[pmStkP+2].id,
				pmSeSt[pmStkP+3].id,
				newProps(pmSeSt[pmStkP+4].whr,
					pmSeSt[pmStkP+4].nams,
					pmSeSt[pmStkP+4].pronounsSrcp,
					pmSeSt[pmStkP+4].pronouns,
					pmSeSt[pmStkP+4].atrs,
					pmSeSt[pmStkP+4].initialize,
					pmSeSt[pmStkP+4].description,
					pmSeSt[pmStkP+4].mentionedSrcp,
					pmSeSt[pmStkP+4].mentioned,
					pmSeSt[pmStkP+4].definite,
					pmSeSt[pmStkP+4].indefinite,
					pmSeSt[pmStkP+4].negative,
					pmSeSt[pmStkP+4].cnt,
					pmSeSt[pmStkP+4].vrbs,
					pmSeSt[pmStkP+4].enteredSrcp,
					pmSeSt[pmStkP+4].entered,
					pmSeSt[pmStkP+4].exts,
					pmSeSt[pmStkP+4].scrs));
	if (pmSeSt[pmStkP+5].id != NULL)  /* END-id given */
	    if (!equalId(pmSeSt[pmStkP+2].id, pmSeSt[pmStkP+5].id))
		lmLog(&pmSeSt[pmStkP+5].id->srcp, 200, sevWAR, pmSeSt[pmStkP+2].id->string);
    	break;}
    case 86: { /* <class_tail> = 'end' 'every' <optional_id> __genSym#1; */
#line 760 "alan.pmk"
 pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+3].id; 	break;}
    case 89: { /* <addition> = 'add' 'to' __genSym#2 ID <optional_heritage> <properties> <add_tail>; */
#line 767 "alan.pmk"

	pmSeSt[pmStkP+1].add = newAdd(pmSySt[pmStkP+1].srcp,
				pmSeSt[pmStkP+4].id,
				pmSeSt[pmStkP+5].id,
				newProps(pmSeSt[pmStkP+6].whr,
					pmSeSt[pmStkP+6].nams,
					pmSeSt[pmStkP+6].pronounsSrcp,
					pmSeSt[pmStkP+6].pronouns,
					pmSeSt[pmStkP+6].atrs,
					pmSeSt[pmStkP+6].initialize,
					pmSeSt[pmStkP+6].description,
					pmSeSt[pmStkP+6].mentionedSrcp,
					pmSeSt[pmStkP+6].mentioned,
					pmSeSt[pmStkP+6].definite,
					pmSeSt[pmStkP+6].indefinite,
					pmSeSt[pmStkP+6].negative,
					pmSeSt[pmStkP+6].cnt,
					pmSeSt[pmStkP+6].vrbs,
					pmSeSt[pmStkP+6].enteredSrcp,
					pmSeSt[pmStkP+6].entered,
					pmSeSt[pmStkP+6].exts,
					pmSeSt[pmStkP+6].scrs));
	if (pmSeSt[pmStkP+7].id != NULL)  /* END-id given */
	    if (!equalId(pmSeSt[pmStkP+4].id, pmSeSt[pmStkP+7].id))
		lmLog(&pmSeSt[pmStkP+7].id->srcp, 200, sevWAR, pmSeSt[pmStkP+4].id->string);
    	break;}
    case 92: { /* <add_tail> = 'end' 'add' __genSym#3 <optional_id> __genSym#4; */
#line 797 "alan.pmk"
 pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+4].id; 	break;}
    case 97: { /* <instance> = 'the' ID <optional_heritage> <properties> <instance_tail>; */
#line 804 "alan.pmk"

	pmSeSt[pmStkP+1].ins = newInstance(&pmSySt[pmStkP+1].srcp,
				pmSeSt[pmStkP+2].id,
				pmSeSt[pmStkP+3].id,
				newProps(pmSeSt[pmStkP+4].whr,
					pmSeSt[pmStkP+4].nams,
					pmSeSt[pmStkP+4].pronounsSrcp,
					pmSeSt[pmStkP+4].pronouns,
					pmSeSt[pmStkP+4].atrs,
					pmSeSt[pmStkP+4].initialize,
					pmSeSt[pmStkP+4].description,
					pmSeSt[pmStkP+4].mentionedSrcp,
					pmSeSt[pmStkP+4].mentioned,
					pmSeSt[pmStkP+4].definite,
					pmSeSt[pmStkP+4].indefinite,
					pmSeSt[pmStkP+4].negative,
					pmSeSt[pmStkP+4].cnt,
					pmSeSt[pmStkP+4].vrbs,
					pmSeSt[pmStkP+4].enteredSrcp,
					pmSeSt[pmStkP+4].entered,
					pmSeSt[pmStkP+4].exts,
					pmSeSt[pmStkP+4].scrs));
	if (pmSeSt[pmStkP+5].id != NULL)  /* END-id given */
	    if (!equalId(pmSeSt[pmStkP+2].id, pmSeSt[pmStkP+5].id))
		lmLog(&pmSeSt[pmStkP+5].id->srcp, 200, sevWAR, pmSeSt[pmStkP+2].id->string);
    	break;}
    case 98: { /* <instance_tail> = 'end' 'the' <optional_id> __genSym#5; */
#line 834 "alan.pmk"
 pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+3].id; 	break;}
    case 101: { /* <optional_heritage> =; */
#line 839 "alan.pmk"

	pmSeSt[pmStkP+1].id = NULL;
    	break;}
    case 102: { /* <optional_heritage> = <heritage>; */
#line 844 "alan.pmk"

	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+1].id;
    	break;}
    case 103: { /* <heritage> = 'isa' ID __genSym#6; */
#line 851 "alan.pmk"
 pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+2].id; 	break;}
    case 106: { /* <properties> =; */
#line 856 "alan.pmk"

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out all fields */
    	break;}
    case 107: { /* <properties> = <properties> <property>; */
#line 861 "alan.pmk"

	pmSeSt[pmStkP+1].nams = concat(pmSeSt[pmStkP+1].nams, pmSeSt[pmStkP+2].nam, NAME_LIST);

        if (pmSeSt[pmStkP+2].pronouns != NULL) {
            if (pmSeSt[pmStkP+1].pronouns != NULL) 
                /* WHERE clause already declared */
	        lmLogv(&pmSeSt[pmStkP+2].srcp, 204, sevERR, "PRONOUN", "class/instance", NULL);
	    else {
		pmSeSt[pmStkP+1].pronouns = combine(pmSeSt[pmStkP+1].pronouns, pmSeSt[pmStkP+2].pronouns);
		pmSeSt[pmStkP+1].pronounsSrcp = pmSeSt[pmStkP+2].pronounsSrcp;
	    }
        }

        if (pmSeSt[pmStkP+2].whr != NULL) {
            if (pmSeSt[pmStkP+1].whr != NULL) 
                /* WHERE clause already declared */
	        lmLogv(&pmSeSt[pmStkP+2].srcp, 204, sevERR, "WHERE", "class/instance", NULL);
	    else
	        pmSeSt[pmStkP+1].whr = pmSeSt[pmStkP+2].whr;
        }

	pmSeSt[pmStkP+1].atrs = combine(pmSeSt[pmStkP+1].atrs, pmSeSt[pmStkP+2].atrs);

	if (pmSeSt[pmStkP+2].initialize != NULL) {
            if (pmSeSt[pmStkP+1].initialize != NULL)
                /* INITIALIZE properties already declared */
	        lmLogv(&pmSeSt[pmStkP+2].initialize->srcp, 204, sevERR, "INITIALIZE property", "class/instance", NULL);
	    else 
	        pmSeSt[pmStkP+1].initialize = pmSeSt[pmStkP+2].initialize;
        }

	if (pmSeSt[pmStkP+2].cnt != NULL) {
            if (pmSeSt[pmStkP+1].cnt != NULL)
                /* CONTAINER properties already declared */
	        lmLogv(&pmSeSt[pmStkP+2].srcp, 204, sevERR, "CONTAINER properties", "class/instance", NULL);
	    else 
	        pmSeSt[pmStkP+1].cnt = pmSeSt[pmStkP+2].cnt;
        }

	if (pmSeSt[pmStkP+2].description != NULL) {
	  if (pmSeSt[pmStkP+2].description->checks != NULL) {
            if(pmSeSt[pmStkP+1].description != NULL && pmSeSt[pmStkP+1].description->checks != NULL)
                /* DESCRIPTION CHECK already declared */
	        lmLogv(&pmSeSt[pmStkP+2].description->checkSrcp, 204, sevERR, "DESCRIPTION CHECK", "class/instance", NULL);
	    else {
		if (pmSeSt[pmStkP+1].description != NULL)
		  pmSeSt[pmStkP+1].description->checks = pmSeSt[pmStkP+2].description->checks;
	    }
          }

	  if (pmSeSt[pmStkP+2].description->does != NULL) {
            if (pmSeSt[pmStkP+1].description != NULL && pmSeSt[pmStkP+1].description->does != NULL)
	        /* DESCRIPTION DOES already declared */
	        lmLogv(&pmSeSt[pmStkP+2].description->doesSrcp, 204, sevERR, "DESCRIPTION", "class/instance", NULL);
	    else 
		if (pmSeSt[pmStkP+1].description != NULL)
		  pmSeSt[pmStkP+1].description->does = pmSeSt[pmStkP+2].description->does;
          }

	  if (pmSeSt[pmStkP+1].description == NULL)
	    pmSeSt[pmStkP+1].description = pmSeSt[pmStkP+2].description;

	}

	if (pmSeSt[pmStkP+2].entered != NULL) {
            if (pmSeSt[pmStkP+1].entered != NULL)
                /* ENTERED already declared */
	        lmLogv(&pmSeSt[pmStkP+2].srcp, 204, sevERR, "ENTERED", "class/instance", NULL);
	    else {
                pmSeSt[pmStkP+1].entered = pmSeSt[pmStkP+2].entered;
		pmSeSt[pmStkP+1].enteredSrcp = pmSeSt[pmStkP+2].srcp;
	    }
        }

	if (pmSeSt[pmStkP+2].mentioned != NULL) {
            if (pmSeSt[pmStkP+1].mentioned != NULL)
                /* MENTIONED already declared */
	        lmLogv(&pmSeSt[pmStkP+2].srcp, 204, sevERR, "MENTIONED", "class/instance", NULL);
	    else {
                pmSeSt[pmStkP+1].mentioned = pmSeSt[pmStkP+2].mentioned;
		pmSeSt[pmStkP+1].mentionedSrcp = pmSeSt[pmStkP+2].srcp;
	    }
        }

	if (pmSeSt[pmStkP+2].indefinite != NULL) {
            if (pmSeSt[pmStkP+1].indefinite != NULL)
                /* Indefinite Article/Form already declared */
	        lmLogv(&pmSeSt[pmStkP+2].indefinite->srcp, 204, sevERR, "[Indefinite] Article/Form", "class/instance", NULL);
            else
	        pmSeSt[pmStkP+1].indefinite = pmSeSt[pmStkP+2].indefinite;
        }

	if (pmSeSt[pmStkP+2].definite != NULL) {
            if (pmSeSt[pmStkP+1].definite != NULL)
                /* Definite Article/Form already declared */
	        lmLogv(&pmSeSt[pmStkP+2].definite->srcp, 204, sevERR, "Definite Article/Form", "class/instance", NULL);
            else
	        pmSeSt[pmStkP+1].definite = pmSeSt[pmStkP+2].definite;
        }

	if (pmSeSt[pmStkP+2].negative != NULL) {
            if (pmSeSt[pmStkP+1].negative != NULL)
                /* Negative Article/Form already declared */
	        lmLogv(&pmSeSt[pmStkP+2].negative->srcp, 204, sevERR, "Negative Article/Form", "class/instance", NULL);
            else
	        pmSeSt[pmStkP+1].negative = pmSeSt[pmStkP+2].negative;
        }

	pmSeSt[pmStkP+1].exts = concat(pmSeSt[pmStkP+1].exts, pmSeSt[pmStkP+2].ext, EXIT_LIST);
	pmSeSt[pmStkP+1].vrbs = concat(pmSeSt[pmStkP+1].vrbs, pmSeSt[pmStkP+2].vrb, VERB_LIST);
	pmSeSt[pmStkP+1].scrs = concat(pmSeSt[pmStkP+1].scrs, pmSeSt[pmStkP+2].scr, SCRIPT_LIST);
    	break;}
    case 112: { /* <property> = <name>; */
#line 978 "alan.pmk"
{ List *nam = pmSeSt[pmStkP+1].nam;
	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].nam = nam;
    }	break;}
    case 113: { /* <property> = <pronoun>; */
#line 984 "alan.pmk"
{ List *idList = pmSeSt[pmStkP+1].idList;
	Srcp pronounsSrcp = pmSeSt[pmStkP+1].pronounsSrcp;
	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].pronouns = idList;
	pmSeSt[pmStkP+1].pronounsSrcp = pronounsSrcp;
    }	break;}
    case 108: { /* <property> = <where> __genSym#7; */
#line 992 "alan.pmk"
{
        Where *whr = pmSeSt[pmStkP+1].whr;
        Srcp srcp = pmSeSt[pmStkP+1].srcp;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].whr = whr;
	pmSeSt[pmStkP+1].srcp = srcp;
    }	break;}
    case 119: { /* <property> = <is> <attributes>; */
#line 1002 "alan.pmk"

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].atrs = pmSeSt[pmStkP+2].atrs;
    	break;}
    case 114: { /* <property> = <initialize>; */
#line 1008 "alan.pmk"
{
        Initialize *initialize = pmSeSt[pmStkP+1].initialize;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].initialize = initialize;
    }	break;}
    case 109: { /* <property> = <container_properties>; */
#line 1016 "alan.pmk"
{
        Container *cnt = pmSeSt[pmStkP+1].cnt;
        Srcp srcp = pmSeSt[pmStkP+1].srcp;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].cnt = cnt;
	pmSeSt[pmStkP+1].srcp = srcp;
    }	break;}
    case 110: { /* <property> = <description>; */
#line 1026 "alan.pmk"
{
	Description *description = pmSeSt[pmStkP+1].description;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */

	pmSeSt[pmStkP+1].description = description;
    }	break;}
    case 115: { /* <property> = <entered>; */
#line 1035 "alan.pmk"
{
        List *entered = pmSeSt[pmStkP+1].stms;
        Srcp srcp = pmSeSt[pmStkP+1].srcp;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].entered = entered;
	pmSeSt[pmStkP+1].srcp = srcp;
    }	break;}
    case 116: { /* <property> = <mentioned>; */
#line 1045 "alan.pmk"
{
        List *ment = pmSeSt[pmStkP+1].stms;
        Srcp srcp = pmSeSt[pmStkP+1].srcp;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].mentioned = ment;
	pmSeSt[pmStkP+1].srcp = srcp;
    }	break;}
    case 111: { /* <property> = __genSym#8 <article_or_form>; */
#line 1055 "alan.pmk"
{ Article *indefinite = pmSeSt[pmStkP+2].article;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].indefinite = indefinite;
    }	break;}
    case 117: { /* <property> = 'definite' <article_or_form>; */
#line 1063 "alan.pmk"
{ Article *definite = pmSeSt[pmStkP+2].article;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].definite = definite;
    }	break;}
    case 118: { /* <property> = 'negative' <article_or_form>; */
#line 1071 "alan.pmk"
{ Article *article = pmSeSt[pmStkP+2].article;

	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].negative = article;
    }	break;}
    case 121: { /* <property> = <exit>; */
#line 1079 "alan.pmk"
{ Exit *ext = pmSeSt[pmStkP+1].ext;
	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].ext = ext;
    }	break;}
    case 122: { /* <property> = <verb>; */
#line 1085 "alan.pmk"
{ Verb *vrb = pmSeSt[pmStkP+1].vrb;
	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].vrb = vrb;
    }	break;}
    case 120: { /* <property> = <script>; */
#line 1091 "alan.pmk"
{ Script *scr = pmSeSt[pmStkP+1].scr;
	memset(&pmSeSt[pmStkP+1], 0, sizeof(pmSeSt[pmStkP+1])); /* Zero out other fields */
	pmSeSt[pmStkP+1].scr = scr;
    }	break;}
    case 127: { /* <exit> = 'exit' <id_list> 'to' ID <optional_exit_body> '.'; */
#line 1101 "alan.pmk"

	pmSeSt[pmStkP+1].ext = newExit(&pmSySt[pmStkP+1].srcp,
				pmSeSt[pmStkP+2].idList,
				pmSeSt[pmStkP+4].id,
				pmSeSt[pmStkP+5].chks,
				pmSeSt[pmStkP+5].stms);
	if (pmSeSt[pmStkP+5].id != NULL) { /* END-id given */
	    if (compareStrings(pmSeSt[pmStkP+2].str, pmSeSt[pmStkP+5].id->string) != 0)
		lmLog(&pmSeSt[pmStkP+5].id->srcp, 200, sevWAR, pmSeSt[pmStkP+2].str);
	}
    	break;}
    case 128: { /* <optional_exit_body> =; */
#line 1116 "alan.pmk"

	pmSeSt[pmStkP+1].chks = NULL;
	pmSeSt[pmStkP+1].stms = NULL;
	pmSeSt[pmStkP+1].id = NULL;
    	break;}
    case 129: { /* <optional_exit_body> = <optional_checks> <optional_does> 'end' 'exit' <optional_id>; */
#line 1123 "alan.pmk"

	pmSeSt[pmStkP+1].chks = pmSeSt[pmStkP+1].chks;
	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
	if (pmSeSt[pmStkP+2].qual != QUAL_DEFAULT)
	     lmLog(&pmSeSt[pmStkP+2].srcp, 210, sevERR, "");
	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+5].id;
    	break;}
    case 130: { /* <is> = 'is'; */
#line 1138 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 131: { /* <is> = 'are'; */
#line 1143 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 132: { /* <is> = 'has'; */
#line 1148 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 133: { /* <is> = 'can'; */
#line 1153 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 134: { /* <optional_description> =; */
#line 1160 "alan.pmk"

	pmSeSt[pmStkP+1].description = NULL;
    	break;}
    case 135: { /* <optional_description> = <description>; */
#line 1165 "alan.pmk"

	pmSeSt[pmStkP+1].description = pmSeSt[pmStkP+1].description;
    	break;}
    case 136: { /* <description> = 'description' <optional_checks> <optional_does>; */
#line 1172 "alan.pmk"

	if (pmSeSt[pmStkP+2].chks == NULL && pmSeSt[pmStkP+3].stms == NULL) {
	  /* Create a NOP-statement */
	  List *stms = newList(newStatement(&pmSySt[pmStkP+1].srcp,
					NOP_STATEMENT), STATEMENT_LIST);
	  pmSeSt[pmStkP+1].description = newDescription(nulsrcp, NULL, pmSySt[pmStkP+1].srcp, stms);
	} else {
	  Srcp checkSrcp, stmSrcp;
	  if (pmSeSt[pmStkP+2].chks != NULL)
	    checkSrcp = pmSeSt[pmStkP+2].srcp;
	  else
	    checkSrcp = nulsrcp;
	  if (pmSeSt[pmStkP+3].stms != NULL)
	    stmSrcp = pmSeSt[pmStkP+3].srcp;
	  else
	    stmSrcp = pmSySt[pmStkP+1].srcp;

	  pmSeSt[pmStkP+1].description = newDescription(checkSrcp, pmSeSt[pmStkP+2].chks, stmSrcp, pmSeSt[pmStkP+3].stms);

	  if (pmSeSt[pmStkP+3].qual != QUAL_DEFAULT)
	    lmLog(&pmSeSt[pmStkP+3].srcp, 210, sevERR, "");
	}
    	break;}
    case 137: { /* <description> = 'description' <statements>; */
#line 1197 "alan.pmk"

	pmSeSt[pmStkP+1].description = newDescription(nulsrcp, NULL,
					pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].stms);
    	break;}
    case 140: { /* <article> = 'article'; */
#line 1210 "alan.pmk"

	pmSeSt[pmStkP+1].article = newArticle(pmSySt[pmStkP+1].srcp,
					newList(newStatement(&pmSySt[pmStkP+1].srcp, NOP_STATEMENT),
						STATEMENT_LIST),
					FALSE);
    	break;}
    case 141: { /* <article> = 'article' <statements>; */
#line 1218 "alan.pmk"

	 pmSeSt[pmStkP+1].article = newArticle(pmSySt[pmStkP+1].srcp,
					pmSeSt[pmStkP+2].stms,
					FALSE);
    	break;}
    case 142: { /* <form> = 'form'; */
#line 1227 "alan.pmk"

	pmSeSt[pmStkP+1].article = newArticle(pmSySt[pmStkP+1].srcp,
					newList(newStatement(&pmSySt[pmStkP+1].srcp,
								NOP_STATEMENT),
						STATEMENT_LIST),
					TRUE);
    	break;}
    case 143: { /* <form> = 'form' <statements>; */
#line 1236 "alan.pmk"

	pmSeSt[pmStkP+1].article = newArticle(pmSySt[pmStkP+1].srcp,
					pmSeSt[pmStkP+2].stms,
					TRUE);
    	break;}
    case 144: { /* <entered> = 'entered' <statements>; */
#line 1246 "alan.pmk"

	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 145: { /* <initialize> = 'initialize' <statements>; */
#line 1255 "alan.pmk"

	pmSeSt[pmStkP+1].initialize = newInitialize(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].stms);
    	break;}
    case 146: { /* <mentioned> = 'mentioned' <statements>; */
#line 1263 "alan.pmk"

	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 147: { /* <name> = 'name' <ids> <optional_full_stop>; */
#line 1272 "alan.pmk"

	pmSeSt[pmStkP+1].nam = pmSeSt[pmStkP+2].idList;
    	break;}
    case 148: { /* <pronoun> = 'pronoun' <id_list> <optional_full_stop>; */
#line 1279 "alan.pmk"

	pmSeSt[pmStkP+1].idList = pmSeSt[pmStkP+2].idList;
	pmSeSt[pmStkP+1].pronounsSrcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 151: { /* <container_properties> = __genSym#9 <optionally_opaque> 'container' <container_body>; */
#line 1293 "alan.pmk"

	pmSeSt[pmStkP+1].cnt = newContainer(newContainerBody(pmSySt[pmStkP+3].srcp,
					pmSeSt[pmStkP+2].opaque,
					pmSeSt[pmStkP+4].id,
					pmSeSt[pmStkP+4].lims,
					pmSeSt[pmStkP+4].stms,
					pmSeSt[pmStkP+4].stms2,
					pmSeSt[pmStkP+4].chks,
					pmSeSt[pmStkP+4].stms3));
        pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+3].srcp;
    	break;}
    case 154: { /* <optionally_opaque> =; */
#line 1309 "alan.pmk"
 pmSeSt[pmStkP+1].opaque = FALSE; 	break;}
    case 155: { /* <optionally_opaque> = 'opaque'; */
#line 1311 "alan.pmk"
 pmSeSt[pmStkP+1].opaque = TRUE; 	break;}
    case 156: { /* <container_body> = <optional_taking> <optional_limits> <optional_header> <optional_empty> <optional_extract>; */
#line 1317 "alan.pmk"

	pmSeSt[pmStkP+1].id  = pmSeSt[pmStkP+1].id;
	pmSeSt[pmStkP+1].lims  = pmSeSt[pmStkP+2].lims;
	pmSeSt[pmStkP+1].stms  = pmSeSt[pmStkP+3].stms;
	pmSeSt[pmStkP+1].stms2 = pmSeSt[pmStkP+4].stms;
	pmSeSt[pmStkP+1].chks = pmSeSt[pmStkP+5].chks;
	pmSeSt[pmStkP+1].stms3 = pmSeSt[pmStkP+5].stms;
    	break;}
    case 157: { /* <container_body> = '.'; */
#line 1327 "alan.pmk"

	pmSeSt[pmStkP+1].id  = NULL;
	pmSeSt[pmStkP+1].lims  = NULL;
	pmSeSt[pmStkP+1].stms  = NULL;
	pmSeSt[pmStkP+1].stms2 = NULL;
	pmSeSt[pmStkP+1].chks = NULL;
	pmSeSt[pmStkP+1].stms3 = NULL;
    	break;}
    case 158: { /* <optional_taking> =; */
#line 1339 "alan.pmk"

	pmSeSt[pmStkP+1].id = NULL;
    	break;}
    case 159: { /* <optional_taking> = 'taking' ID '.'; */
#line 1344 "alan.pmk"

	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+2].id;
    	break;}
    case 160: { /* <optional_limits> =; */
#line 1352 "alan.pmk"

	pmSeSt[pmStkP+1].lims = NULL;
    	break;}
    case 161: { /* <optional_limits> = 'limits' <limits>; */
#line 1357 "alan.pmk"

	pmSeSt[pmStkP+1].lims = pmSeSt[pmStkP+2].lims;
    	break;}
    case 162: { /* <limits> = <limit>; */
#line 1364 "alan.pmk"

	pmSeSt[pmStkP+1].lims = newList(pmSeSt[pmStkP+1].lim, LIMIT_LIST);
    	break;}
    case 163: { /* <limits> = <limits> <limit>; */
#line 1369 "alan.pmk"

	pmSeSt[pmStkP+1].lims = concat(pmSeSt[pmStkP+1].lims, pmSeSt[pmStkP+2].lim, LIMIT_LIST);
    	break;}
    case 164: { /* <limit> = <limit_attribute> <else_or_then> <statements>; */
#line 1376 "alan.pmk"

	pmSeSt[pmStkP+1].lim = newlim(&pmSeSt[pmStkP+2].srcp,
			    pmSeSt[pmStkP+1].atr,
			    pmSeSt[pmStkP+3].stms);
    	break;}
    case 165: { /* <else_or_then> = 'else'; */
#line 1384 "alan.pmk"
 pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp; 	break;}
    case 166: { /* <else_or_then> = 'then'; */
#line 1385 "alan.pmk"
 pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp; 	break;}
    case 167: { /* <limit_attribute> = <attribute_definition>; */
#line 1390 "alan.pmk"

	pmSeSt[pmStkP+1].atr = pmSeSt[pmStkP+1].atr;
    	break;}
    case 168: { /* <limit_attribute> = 'count' Integer; */
#line 1395 "alan.pmk"

	pmSeSt[pmStkP+1].atr = newIntegerAttribute(pmSySt[pmStkP+1].srcp, newId(pmSySt[pmStkP+1].srcp, "count"), val(pmSySt[pmStkP+2].chars));
    	break;}
    case 169: { /* <optional_header> =; */
#line 1402 "alan.pmk"

	pmSeSt[pmStkP+1].stms = NULL;
    	break;}
    case 170: { /* <optional_header> = 'header' <statements>; */
#line 1407 "alan.pmk"

	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
    	break;}
    case 171: { /* <optional_empty> =; */
#line 1414 "alan.pmk"

	pmSeSt[pmStkP+1].stms = NULL;
    	break;}
    case 172: { /* <optional_empty> = 'else' <statements>; */
#line 1419 "alan.pmk"

	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
    	break;}
    case 173: { /* <optional_extract> =; */
#line 1426 "alan.pmk"

	pmSeSt[pmStkP+1].chks = NULL;
	pmSeSt[pmStkP+1].stms = NULL;
    	break;}
    case 174: { /* <optional_extract> = 'extract' <optional_checks> <optional_does>; */
#line 1432 "alan.pmk"

	pmSeSt[pmStkP+1].chks = pmSeSt[pmStkP+2].chks;
	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+3].stms;
	if (pmSeSt[pmStkP+3].qual != QUAL_DEFAULT)
	  lmLog(&pmSeSt[pmStkP+3].srcp, 210, sevERR, "");
    	break;}
    case 175: { /* <optional_extract> = 'extract' <statements>; */
#line 1440 "alan.pmk"

	pmSeSt[pmStkP+1].chk = NULL;
	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
    	break;}
    case 176: { /* <event> = <event_header> <statements> <event_tail>; */
#line 1450 "alan.pmk"

	pmSeSt[pmStkP+1].evt = newEvent(&pmSeSt[pmStkP+1].srcp,
				pmSeSt[pmStkP+1].id,
				pmSeSt[pmStkP+2].stms);
	if (pmSeSt[pmStkP+3].id != NULL) { /* END-id given */
	    if (!equalId(pmSeSt[pmStkP+1].id, pmSeSt[pmStkP+3].id))
		lmLog(&pmSeSt[pmStkP+3].id->srcp, 200, sevWAR, pmSeSt[pmStkP+1].id->string);
	}
    	break;}
    case 177: { /* <event_header> = 'event' ID; */
#line 1463 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].id  = pmSeSt[pmStkP+2].id;
    	break;}
    case 178: { /* <event_tail> = 'end' 'event' <optional_id> '.'; */
#line 1471 "alan.pmk"

	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+3].id;
    	break;}
    case 179: { /* <script> = 'script' ID __genSym#10 <optional_description> <step_list>; */
#line 1479 "alan.pmk"

	if (pmSeSt[pmStkP+4].description != NULL &&
	    pmSeSt[pmStkP+4].description->checks != NULL)
	  lmLog(&pmSeSt[pmStkP+4].description->checkSrcp,
		228, sevERR, "");
	pmSeSt[pmStkP+1].scr = newScript(&pmSySt[pmStkP+1].srcp,
			          pmSeSt[pmStkP+2].id,
			          pmSeSt[pmStkP+4].description,
			          pmSeSt[pmStkP+5].stps);
    	break;}
    case 182: { /* <step_list> = <step>; */
#line 1493 "alan.pmk"

	pmSeSt[pmStkP+1].stps = newList(pmSeSt[pmStkP+1].stp, STEP_LIST);
    	break;}
    case 183: { /* <step_list> = <step_list> <step>; */
#line 1498 "alan.pmk"

	pmSeSt[pmStkP+1].stps = concat(pmSeSt[pmStkP+1].stps, pmSeSt[pmStkP+2].stp, STEP_LIST);
    	break;}
    case 184: { /* <step> = 'step' <statements>; */
#line 1505 "alan.pmk"

	pmSeSt[pmStkP+1].stp = newStep(&pmSySt[pmStkP+1].srcp,
			   0,
			   NULL,
			   pmSeSt[pmStkP+2].stms);
    	break;}
    case 185: { /* <step> = 'step' 'after' <expression> <statements>; */
#line 1513 "alan.pmk"

	pmSeSt[pmStkP+1].stp = newStep(&pmSySt[pmStkP+1].srcp,
				pmSeSt[pmStkP+3].exp,
				NULL,
				pmSeSt[pmStkP+4].stms);
    	break;}
    case 186: { /* <step> = 'step' 'wait' 'until' <expression> <statements>; */
#line 1521 "alan.pmk"

	pmSeSt[pmStkP+1].stp = newStep(&pmSySt[pmStkP+1].srcp,
				NULL,
				pmSeSt[pmStkP+4].exp,
				pmSeSt[pmStkP+5].stms);
    	break;}
    case 187: { /* <rule> = 'when' <expression> <then> <statements> <optional_end_when>; */
#line 1532 "alan.pmk"

	pmSeSt[pmStkP+1].rul = newRule(&pmSySt[pmStkP+1].srcp,
		 		pmSeSt[pmStkP+2].exp,
				pmSeSt[pmStkP+4].stms);
    	break;}
    case 194: { /* <start> = 'start' <where> '.' <optional_statements>; */
#line 1552 "alan.pmk"

	adv.whr	 = pmSeSt[pmStkP+2].whr;
	adv.stms = pmSeSt[pmStkP+4].stms;
    	break;}
    case 195: { /* <optional_statements> =; */
#line 1561 "alan.pmk"

	pmSeSt[pmStkP+1].stms = NULL;
    	break;}
    case 196: { /* <optional_statements> = <statements>; */
#line 1566 "alan.pmk"

	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+1].stms;
    	break;}
    case 197: { /* <statements> = <statement>; */
#line 1573 "alan.pmk"

	pmSeSt[pmStkP+1].stms = newList(pmSeSt[pmStkP+1].stm, STATEMENT_LIST);
    	break;}
    case 198: { /* <statements> = <statements> <statement>; */
#line 1578 "alan.pmk"

	pmSeSt[pmStkP+1].stms = concat(pmSeSt[pmStkP+1].stms, pmSeSt[pmStkP+2].stm, STATEMENT_LIST);
    	break;}
    case 199: { /* <statement> = <output_statement>; */
#line 1585 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 201: { /* <statement> = <manipulation_statement>; */
#line 1590 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 204: { /* <statement> = <assignment_statement>; */
#line 1595 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 206: { /* <statement> = <conditional_statement>; */
#line 1600 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 205: { /* <statement> = <repetition_statement>; */
#line 1605 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 202: { /* <statement> = <actor_statement>; */
#line 1610 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 203: { /* <statement> = <event_statement>; */
#line 1615 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 200: { /* <statement> = <special_statement>; */
#line 1620 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 207: { /* <output_statement> = STRING; */
#line 1628 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, PRINT_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.print.fpos = pmSySt[pmStkP+1].fpos;
	pmSeSt[pmStkP+1].stm->fields.print.len = pmSySt[pmStkP+1].len;
    	break;}
    case 208: { /* <output_statement> = 'describe' <what> '.'; */
#line 1635 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newDescribeStatement(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].exp);
    	break;}
    case 209: { /* <output_statement> = 'say' <say_form> <expression> '.'; */
#line 1640 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, SAY_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.say.exp = pmSeSt[pmStkP+3].exp;
	pmSeSt[pmStkP+1].stm->fields.say.form = pmSeSt[pmStkP+2].sayForm;
    	break;}
    case 210: { /* <output_statement> = 'list' <primary> '.'; */
#line 1647 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newListStatement(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].exp);
    	break;}
    case 211: { /* <output_statement> = 'show' ID '.'; */
#line 1652 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newShowStatement(pmSySt[pmStkP+1].srcp, newResource(pmSeSt[pmStkP+2].id->srcp, pmSeSt[pmStkP+2].id));
    	break;}
    case 212: { /* <output_statement> = 'play' ID '.'; */
#line 1657 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newPlayStatement(pmSySt[pmStkP+1].srcp, newResource(pmSeSt[pmStkP+2].id->srcp, pmSeSt[pmStkP+2].id));
    	break;}
    case 213: { /* <output_statement> = 'style' ID '.'; */
#line 1662 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStyleStatement(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].id);
    	break;}
    case 214: { /* <say_form> =; */
#line 1669 "alan.pmk"
 pmSeSt[pmStkP+1].sayForm = SAY_SIMPLE; 	break;}
    case 215: { /* <say_form> = 'the'; */
#line 1671 "alan.pmk"
 pmSeSt[pmStkP+1].sayForm = SAY_DEFINITE; 	break;}
    case 216: { /* <say_form> = 'an'; */
#line 1673 "alan.pmk"
 pmSeSt[pmStkP+1].sayForm = SAY_INDEFINITE; 	break;}
    case 217: { /* <say_form> = 'it'; */
#line 1675 "alan.pmk"
 pmSeSt[pmStkP+1].sayForm = SAY_PRONOUN; 	break;}
    case 218: { /* <say_form> = 'no'; */
#line 1677 "alan.pmk"
 pmSeSt[pmStkP+1].sayForm = SAY_NEGATIVE; 	break;}
    case 219: { /* <manipulation_statement> = 'empty' <primary> <optional_where> '.'; */
#line 1684 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newEmptyStatement(pmSySt[pmStkP+1].srcp,
							  pmSeSt[pmStkP+2].exp,
							  pmSeSt[pmStkP+3].whr);
    	break;}
    case 220: { /* <manipulation_statement> = 'locate' <primary> <where> '.'; */
#line 1691 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newLocateStatement(pmSySt[pmStkP+1].srcp,
							   pmSeSt[pmStkP+2].exp,
							   pmSeSt[pmStkP+3].whr);
    	break;}
    case 221: { /* <manipulation_statement> = 'include' <primary> 'in' <what> '.'; */
#line 1698 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newIncludeStatement(pmSySt[pmStkP+1].srcp,
							    pmSeSt[pmStkP+2].exp,
							    pmSeSt[pmStkP+4].exp);
    	break;}
    case 222: { /* <manipulation_statement> = 'exclude' <primary> 'from' <what> '.'; */
#line 1705 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newExcludeStatement(pmSySt[pmStkP+1].srcp,
							    pmSeSt[pmStkP+2].exp,
							    pmSeSt[pmStkP+4].exp);
    	break;}
    case 224: { /* <event_statement> = 'schedule' <what> <optional_where> 'after' <expression> '.'; */
#line 1716 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newScheduleStatement(pmSySt[pmStkP+1].srcp,
						      pmSeSt[pmStkP+2].exp,
						      pmSeSt[pmStkP+3].whr,
						      pmSeSt[pmStkP+5].exp);
    	break;}
    case 223: { /* <event_statement> = 'cancel' <what> '.'; */
#line 1724 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newCancelStatement(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].exp);
    	break;}
    case 225: { /* <assignment_statement> = 'make' <primary> <something> '.'; */
#line 1733 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, MAKE_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.make.wht = pmSeSt[pmStkP+2].exp;
	pmSeSt[pmStkP+1].stm->fields.make.not = pmSeSt[pmStkP+3].present;
	pmSeSt[pmStkP+1].stm->fields.make.atr = pmSeSt[pmStkP+3].id;
    	break;}
    case 229: { /* <assignment_statement> = 'set' <attribute_reference> 'to' <expression> '.'; */
#line 1741 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, SET_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.set.wht = pmSeSt[pmStkP+2].exp;
	pmSeSt[pmStkP+1].stm->fields.set.exp = pmSeSt[pmStkP+4].exp;
    	break;}
    case 227: { /* <assignment_statement> = 'increase' <attribute_reference> <optional_by_clause> '.'; */
#line 1748 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, INCREASE_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.incr.wht = pmSeSt[pmStkP+2].exp;
	pmSeSt[pmStkP+1].stm->fields.incr.step = pmSeSt[pmStkP+3].exp;
    	break;}
    case 228: { /* <assignment_statement> = 'decrease' <attribute_reference> <optional_by_clause> '.'; */
#line 1755 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, DECREASE_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.incr.wht = pmSeSt[pmStkP+2].exp;
	pmSeSt[pmStkP+1].stm->fields.incr.step = pmSeSt[pmStkP+3].exp;
    	break;}
    case 226: { /* <assignment_statement> = 'strip' <optional_first_or_last> <optional_expression> <optional_word_or_character> 'from' <expression> <optional_into> '.'; */
#line 1762 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, STRIP_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.strip.first = pmSeSt[pmStkP+2].first;
	pmSeSt[pmStkP+1].stm->fields.strip.count = pmSeSt[pmStkP+3].exp;
	pmSeSt[pmStkP+1].stm->fields.strip.wordOrChar = pmSeSt[pmStkP+4].wordOrChar;
	pmSeSt[pmStkP+1].stm->fields.strip.from = pmSeSt[pmStkP+6].exp;
	pmSeSt[pmStkP+1].stm->fields.strip.into = pmSeSt[pmStkP+7].exp;
    	break;}
    case 230: { /* <optional_by_clause> =; */
#line 1774 "alan.pmk"

	pmSeSt[pmStkP+1].exp = NULL;
    	break;}
    case 231: { /* <optional_by_clause> = 'by' <expression>; */
#line 1779 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+2].exp;
    	break;}
    case 232: { /* <optional_first_or_last> =; */
#line 1786 "alan.pmk"
 pmSeSt[pmStkP+1].first = TRUE; 	break;}
    case 233: { /* <optional_first_or_last> = 'first'; */
#line 1788 "alan.pmk"
 pmSeSt[pmStkP+1].first = TRUE; 	break;}
    case 234: { /* <optional_first_or_last> = 'last'; */
#line 1790 "alan.pmk"
 pmSeSt[pmStkP+1].first = FALSE; 	break;}
    case 235: { /* <optional_word_or_character> =; */
#line 1795 "alan.pmk"
 pmSeSt[pmStkP+1].wordOrChar = TRUE; 	break;}
    case 236: { /* <optional_word_or_character> = 'word'; */
#line 1797 "alan.pmk"
 pmSeSt[pmStkP+1].wordOrChar = TRUE; 	break;}
    case 237: { /* <optional_word_or_character> = 'words'; */
#line 1799 "alan.pmk"
 pmSeSt[pmStkP+1].wordOrChar = TRUE; 	break;}
    case 238: { /* <optional_word_or_character> = 'character'; */
#line 1801 "alan.pmk"
 pmSeSt[pmStkP+1].wordOrChar = FALSE; 	break;}
    case 239: { /* <optional_word_or_character> = 'characters'; */
#line 1803 "alan.pmk"
 pmSeSt[pmStkP+1].wordOrChar = FALSE; 	break;}
    case 240: { /* <optional_into> =; */
#line 1808 "alan.pmk"
 pmSeSt[pmStkP+1].exp = NULL; 	break;}
    case 241: { /* <optional_into> = 'into' <expression>; */
#line 1811 "alan.pmk"
 pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+2].exp; 	break;}
    case 242: { /* <conditional_statement> = <if_statement>; */
#line 1817 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 243: { /* <conditional_statement> = <depending_statement>; */
#line 1822 "alan.pmk"

	pmSeSt[pmStkP+1].stm = pmSeSt[pmStkP+1].stm;
    	break;}
    case 244: { /* <if_statement> = 'if' <expression> 'then' <statements> <optional_elsif_list> <optional_else_part> 'end' 'if' '.'; */
#line 1830 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, IF_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.iff.exp = pmSeSt[pmStkP+2].exp;
	pmSeSt[pmStkP+1].stm->fields.iff.thn = pmSeSt[pmStkP+4].stms;
	if (pmSeSt[pmStkP+5].stms == NULL)
	    pmSeSt[pmStkP+1].stm->fields.iff.els = pmSeSt[pmStkP+6].stms;
	else {
	    /* Connect the else_part to the elsif_list */
	    (getLastListNode(pmSeSt[pmStkP+5].stms))->member.stm->fields.iff.els =
			pmSeSt[pmStkP+6].stms;
	    pmSeSt[pmStkP+5].stms->next = NULL;
	    pmSeSt[pmStkP+1].stm->fields.iff.els = pmSeSt[pmStkP+5].stms;
	}
    	break;}
    case 245: { /* <optional_elsif_list> =; */
#line 1848 "alan.pmk"

	pmSeSt[pmStkP+1].stms = NULL;
    	break;}
    case 246: { /* <optional_elsif_list> = <elsif_list>; */
#line 1853 "alan.pmk"

	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+1].stms;
    	break;}
    case 247: { /* <elsif_list> = 'elsif' <expression> 'then' <statements>; */
#line 1860 "alan.pmk"
{
	Statement *stm;

	stm = newStatement(&pmSySt[pmStkP+1].srcp, IF_STATEMENT);
	stm->fields.iff.exp = pmSeSt[pmStkP+2].exp;
	stm->fields.iff.thn = pmSeSt[pmStkP+4].stms;
	stm->fields.iff.els = NULL;

	/* Now make a list of the ELSIF */
	pmSeSt[pmStkP+1].stms = newList(stm, STATEMENT_LIST);
    }	break;}
    case 248: { /* <elsif_list> = <elsif_list> 'elsif' <expression> 'then' <statements>; */
#line 1873 "alan.pmk"
{
	Statement *stm;

	stm = newStatement(&pmSySt[pmStkP+2].srcp, IF_STATEMENT);
	stm->fields.iff.exp = pmSeSt[pmStkP+3].exp;
	stm->fields.iff.thn = pmSeSt[pmStkP+5].stms;
	stm->fields.iff.els = NULL;

	/* Now connect it to the previous ELSIFs, I.e connect the */
	/* else-part of the last element in the elsif_list to this */
	/* IF-statement and also concat this element to the list so */
	/* we'll know were the end is next time */
	(getLastListNode(pmSeSt[pmStkP+1].stms))->member.stm->fields.iff.els = newList(stm, STATEMENT_LIST);
	pmSeSt[pmStkP+1].stms = concat(pmSeSt[pmStkP+1].stms, stm, STATEMENT_LIST);
    }	break;}
    case 249: { /* <optional_else_part> =; */
#line 1892 "alan.pmk"

	pmSeSt[pmStkP+1].stms = NULL;
    	break;}
    case 250: { /* <optional_else_part> = 'else' <statements>; */
#line 1897 "alan.pmk"

	pmSeSt[pmStkP+1].stms = pmSeSt[pmStkP+2].stms;
    	break;}
    case 251: { /* <depending_statement> = 'depending' 'on' <primary> <depend_cases> 'end' __genSym#12 '.'; */
#line 1904 "alan.pmk"
{ Statement *stm;
	stm = newStatement(&pmSySt[pmStkP+1].srcp, DEPEND_STATEMENT);
	stm->fields.depend.exp = pmSeSt[pmStkP+3].exp;
	stm->fields.depend.cases = pmSeSt[pmStkP+4].cases;

	pmSeSt[pmStkP+1].stm = stm;
    }	break;}
    case 254: { /* <depend_cases> = <depend_case>; */
#line 1915 "alan.pmk"

	pmSeSt[pmStkP+1].cases = newList(pmSeSt[pmStkP+1].stm, CASE_LIST);
    	break;}
    case 255: { /* <depend_cases> = <depend_cases> <depend_case>; */
#line 1920 "alan.pmk"

	pmSeSt[pmStkP+1].cases = concat(pmSeSt[pmStkP+1].cases, pmSeSt[pmStkP+2].stm, CASE_LIST);
    	break;}
    case 257: { /* <depend_case> = <right_hand_side> 'then' <statements>; */
#line 1927 "alan.pmk"

        pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+2].srcp, DEPENDCASE_STATEMENT);
        pmSeSt[pmStkP+1].stm->fields.depcase.exp = pmSeSt[pmStkP+1].exp;
        pmSeSt[pmStkP+1].stm->fields.depcase.stms = pmSeSt[pmStkP+3].stms;
    	break;}
    case 256: { /* <depend_case> = 'else' <statements>; */
#line 1934 "alan.pmk"

        pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, DEPENDCASE_STATEMENT);
        pmSeSt[pmStkP+1].stm->fields.depcase.exp = NULL;
        pmSeSt[pmStkP+1].stm->fields.depcase.stms = pmSeSt[pmStkP+2].stms;
    	break;}
    case 258: { /* <repetition_statement> = <for_each> ID <optional_loop_filters> 'do' <statements> 'end' <for_each> __genSym#13; */
#line 1944 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newEachStatement(pmSeSt[pmStkP+1].srcp,
							pmSeSt[pmStkP+2].id,
							pmSeSt[pmStkP+3].exps,
							pmSeSt[pmStkP+5].stms);
    	break;}
    case 261: { /* <optional_loop_filters> =; */
#line 1954 "alan.pmk"

	pmSeSt[pmStkP+1].exps = NULL;
    	break;}
    case 262: { /* <optional_loop_filters> = <filters>; */
#line 1959 "alan.pmk"

	pmSeSt[pmStkP+1].exps = pmSeSt[pmStkP+1].exps;
    	break;}
    case 263: { /* <optional_loop_filters> = 'between' <arithmetic> 'and' <arithmetic>; */
#line 1964 "alan.pmk"

	pmSeSt[pmStkP+1].exps = newList(newBetweenExpression(pmSySt[pmStkP+1].srcp,
					     				NULL,
					     				FALSE,
					     				pmSeSt[pmStkP+2].exp,
					     				pmSeSt[pmStkP+4].exp),
						EXPRESSION_LIST);
    	break;}
    case 264: { /* <for_each> = 'for'; */
#line 1976 "alan.pmk"
 pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp; 	break;}
    case 265: { /* <for_each> = 'each'; */
#line 1978 "alan.pmk"
 pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp; 	break;}
    case 266: { /* <for_each> = 'for' 'each'; */
#line 1980 "alan.pmk"
 pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp; 	break;}
    case 268: { /* <actor_statement> = 'use' 'script' ID <optional_for_actor> '.'; */
#line 1986 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newUseStatement(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+3].id, pmSeSt[pmStkP+4].exp);
    	break;}
    case 267: { /* <actor_statement> = 'stop' <what> '.'; */
#line 1991 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, STOP_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.stop.actor = pmSeSt[pmStkP+2].exp;
    	break;}
    case 269: { /* <optional_for_actor> =; */
#line 1999 "alan.pmk"

	pmSeSt[pmStkP+1].exp = NULL;
    	break;}
    case 270: { /* <optional_for_actor> = 'for' <what>; */
#line 2004 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+2].exp;
    	break;}
    case 271: { /* <special_statement> = 'quit' '.'; */
#line 2012 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, QUIT_STATEMENT);
    	break;}
    case 272: { /* <special_statement> = 'look' '.'; */
#line 2017 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, LOOK_STATEMENT);
    	break;}
    case 273: { /* <special_statement> = 'save' '.'; */
#line 2022 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, SAVE_STATEMENT);
    	break;}
    case 274: { /* <special_statement> = 'restore' '.'; */
#line 2027 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, RESTORE_STATEMENT);
    	break;}
    case 275: { /* <special_statement> = 'restart' '.'; */
#line 2032 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, RESTART_STATEMENT);
    	break;}
    case 276: { /* <special_statement> = 'score' <optional_integer> '.'; */
#line 2037 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, SCORE_STATEMENT);
	if (pmSeSt[pmStkP+2].str != NULL) {
	    pmSeSt[pmStkP+1].stm->fields.score.score =
						val(pmSeSt[pmStkP+2].str);
	    pmSeSt[pmStkP+1].stm->fields.score.count = ++scoreCount;
	} else
	    pmSeSt[pmStkP+1].stm->fields.score.count = 0;
    	break;}
    case 279: { /* <special_statement> = 'visits' Integer '.'; */
#line 2048 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, VISITS_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.visits.count = val(pmSySt[pmStkP+2].chars);
    	break;}
    case 277: { /* <special_statement> = 'transcript' <on_or_off> '.'; */
#line 2054 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, TRANSCRIPT_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.transcript.on_or_off = pmSeSt[pmStkP+2].on_or_off;
    	break;}
    case 278: { /* <special_statement> = 'system' STRING '.'; */
#line 2060 "alan.pmk"

	pmSeSt[pmStkP+1].stm = newStatement(&pmSySt[pmStkP+1].srcp, SYSTEM_STATEMENT);
	pmSeSt[pmStkP+1].stm->fields.system.fpos = pmSySt[pmStkP+2].fpos;
	pmSeSt[pmStkP+1].stm->fields.system.len = pmSySt[pmStkP+2].len;
    	break;}
    case 280: { /* <on_or_off> = 'on'; */
#line 2069 "alan.pmk"
 pmSeSt[pmStkP+1].on_or_off = TRUE; 	break;}
    case 281: { /* <on_or_off> = 'off'; */
#line 2072 "alan.pmk"
 pmSeSt[pmStkP+1].on_or_off = FALSE; 	break;}
    case 282: { /* <optional_expression> =; */
#line 2079 "alan.pmk"
 pmSeSt[pmStkP+1].exp = NULL; 	break;}
    case 283: { /* <optional_expression> = <expression>; */
#line 2082 "alan.pmk"
 pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp; 	break;}
    case 284: { /* <expression> = <term>; */
#line 2087 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp;
    	break;}
    case 285: { /* <expression> = <expression> 'or' <term>; */
#line 2092 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBinaryExpression(pmSySt[pmStkP+2].srcp,
						pmSeSt[pmStkP+1].exp,
						FALSE,
						OR_OPERATOR,
						pmSeSt[pmStkP+3].exp);
    	break;}
    case 286: { /* <term> = <factor>; */
#line 2103 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp;
    	break;}
    case 287: { /* <term> = <term> 'and' <factor>; */
#line 2108 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBinaryExpression(pmSySt[pmStkP+2].srcp,
					  pmSeSt[pmStkP+1].exp,
					  FALSE,
					  AND_OPERATOR,
					  pmSeSt[pmStkP+3].exp);
    	break;}
    case 288: { /* <factor> = <arithmetic>; */
#line 2119 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp;
    	break;}
    case 290: { /* <factor> = <factor> <optional_not> <relop> <arithmetic>; */
#line 2124 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBinaryExpression(pmSeSt[pmStkP+3].srcp,
					    pmSeSt[pmStkP+1].exp,
					    pmSeSt[pmStkP+2].present,
					    pmSeSt[pmStkP+3].op,
					    pmSeSt[pmStkP+4].exp);
    	break;}
    case 289: { /* <factor> = <factor> <optional_not> <where>; */
#line 2133 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newWhereExpression(pmSeSt[pmStkP+3].srcp,
					   pmSeSt[pmStkP+1].exp,
					   pmSeSt[pmStkP+2].present,
					   pmSeSt[pmStkP+3].whr);
    	break;}
    case 292: { /* <factor> = <factor> <optional_not> 'between' <arithmetic> 'and' <arithmetic>; */
#line 2141 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBetweenExpression(pmSySt[pmStkP+3].srcp,
					     pmSeSt[pmStkP+1].exp,
					     pmSeSt[pmStkP+2].present,
					     pmSeSt[pmStkP+4].exp,
					     pmSeSt[pmStkP+6].exp);
    	break;}
    case 291: { /* <factor> = <factor> <optional_not> 'contains' <arithmetic>; */
#line 2150 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBinaryExpression(pmSySt[pmStkP+3].srcp,
					    pmSeSt[pmStkP+1].exp,
					    pmSeSt[pmStkP+2].present,
					    CONTAINS_OPERATOR,
					    pmSeSt[pmStkP+4].exp);
    	break;}
    case 293: { /* <arithmetic> = <primary>; */
#line 2162 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp;
    	break;}
    case 295: { /* <arithmetic> = <primary> 'isa' ID; */
#line 2167 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newIsaExpression(pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].exp, FALSE, pmSeSt[pmStkP+3].id);
    	break;}
    case 296: { /* <arithmetic> = <primary> <is> <something>; */
#line 2172 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newAttributeExpression(pmSeSt[pmStkP+2].srcp, pmSeSt[pmStkP+3].id,
					 pmSeSt[pmStkP+3].present, pmSeSt[pmStkP+1].exp);
    	break;}
    case 297: { /* <arithmetic> = <arithmetic> <binop> <primary>; */
#line 2178 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBinaryExpression(pmSeSt[pmStkP+2].srcp,
						pmSeSt[pmStkP+1].exp,
						FALSE,
						pmSeSt[pmStkP+2].op,
						pmSeSt[pmStkP+3].exp);
    	break;}
    case 294: { /* <arithmetic> = <aggregate> <filters>; */
#line 2187 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newAggregateExpression(pmSeSt[pmStkP+1].srcp,
							pmSeSt[pmStkP+1].agr,
							pmSeSt[pmStkP+1].id,
							pmSeSt[pmStkP+2].exps);
    	break;}
    case 298: { /* <filters> = <filter>; */
#line 2198 "alan.pmk"

        pmSeSt[pmStkP+1].exps = newList(pmSeSt[pmStkP+1].exp, EXPRESSION_LIST);
    	break;}
    case 299: { /* <filters> = <filters> ',' <filter>; */
#line 2203 "alan.pmk"

        pmSeSt[pmStkP+1].exps = concat(pmSeSt[pmStkP+1].exps, pmSeSt[pmStkP+3].exp, EXPRESSION_LIST);
    	break;}
    case 300: { /* <filter> = <optional_not> <where>; */
#line 2222 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newWhereExpression(pmSeSt[pmStkP+2].srcp,
						      NULL,
						      pmSeSt[pmStkP+1].present,
						      pmSeSt[pmStkP+2].whr);
    	break;}
    case 301: { /* <filter> = <optional_not> 'isa' ID; */
#line 2230 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newIsaExpression(pmSySt[pmStkP+2].srcp, NULL, pmSeSt[pmStkP+1].present, pmSeSt[pmStkP+3].id);
	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+3].id;
    	break;}
    case 302: { /* <filter> = <is> <something>; */
#line 2236 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newAttributeExpression(pmSeSt[pmStkP+1].srcp,
						pmSeSt[pmStkP+2].id,
						pmSeSt[pmStkP+2].present, NULL);
    	break;}
    case 304: { /* <right_hand_side> = <optional_not> <relop> <primary>; */
#line 2245 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBinaryExpression(pmSeSt[pmStkP+2].srcp,
						     NULL,
						     pmSeSt[pmStkP+1].present,
						     pmSeSt[pmStkP+2].op,
						     pmSeSt[pmStkP+3].exp);
    	break;}
    case 306: { /* <right_hand_side> = <optional_not> 'between' <arithmetic> 'and' <arithmetic>; */
#line 2254 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBetweenExpression(pmSySt[pmStkP+2].srcp,
						      NULL,
						      pmSeSt[pmStkP+1].present,
						      pmSeSt[pmStkP+3].exp,
						      pmSeSt[pmStkP+5].exp);
    	break;}
    case 305: { /* <right_hand_side> = <optional_not> 'contains' <factor>; */
#line 2263 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newBinaryExpression(pmSySt[pmStkP+2].srcp,
						     NULL,
						     pmSeSt[pmStkP+1].present,
						     CONTAINS_OPERATOR,
						     pmSeSt[pmStkP+3].exp);

    	break;}
    case 312: { /* <primary> = '(' <expression> ')'; */
#line 2278 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+2].exp;
    	break;}
    case 310: { /* <primary> = <optional_minus> Integer; */
#line 2283 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newIntegerExpression(pmSySt[pmStkP+2].srcp,
					      pmSeSt[pmStkP+1].minus?
							-val(pmSySt[pmStkP+2].chars):
							val(pmSySt[pmStkP+2].chars));
    	break;}
    case 307: { /* <primary> = STRING; */
#line 2291 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newStringExpression(pmSySt[pmStkP+1].srcp,
					     pmSySt[pmStkP+1].fpos,
					     pmSySt[pmStkP+1].len);
    	break;}
    case 308: { /* <primary> = <what>; */
#line 2298 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp;
    	break;}
    case 314: { /* <primary> = 'random' <primary> 'to' <primary>; */
#line 2303 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newRandomRangeExpression(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].exp, pmSeSt[pmStkP+4].exp);
    	break;}
    case 313: { /* <primary> = 'random' <optional_directly> 'in' <primary>; */
#line 2308 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newRandomInExpression(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+4].exp, pmSeSt[pmStkP+2].present);
    	break;}
    case 309: { /* <primary> = 'score'; */
#line 2313 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newScoreExpression(pmSySt[pmStkP+1].srcp);
    	break;}
    case 311: { /* <primary> = '{' <optional_members> '}'; */
#line 2318 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newSetExpression(pmSySt[pmStkP+1].srcp, pmSeSt[pmStkP+2].set);
    	break;}
    case 316: { /* <aggregate> = <aggregator> 'of' ID; */
#line 2326 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSeSt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].agr = pmSeSt[pmStkP+1].agr;
	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+3].id;
    	break;}
    case 315: { /* <aggregate> = 'count'; */
#line 2333 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].agr = COUNT_AGGREGATE;
	pmSeSt[pmStkP+1].id = NULL;
    	break;}
    case 317: { /* <aggregator> = 'max'; */
#line 2342 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].agr = MAX_AGGREGATE;
    	break;}
    case 318: { /* <aggregator> = 'min'; */
#line 2348 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].agr = MIN_AGGREGATE;
    	break;}
    case 319: { /* <aggregator> = 'sum'; */
#line 2354 "alan.pmk"

	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
	pmSeSt[pmStkP+1].agr = SUM_AGGREGATE;
    	break;}
    case 320: { /* <something> = <optional_not> ID; */
#line 2363 "alan.pmk"

	pmSeSt[pmStkP+1].present = pmSeSt[pmStkP+1].present;
	pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+2].id;
    	break;}
    case 321: { /* <what> = <simple_what>; */
#line 2371 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newWhatExpression(pmSeSt[pmStkP+1].srcp, pmSeSt[pmStkP+1].wht);
    	break;}
    case 322: { /* <what> = <attribute_reference>; */
#line 2376 "alan.pmk"

	pmSeSt[pmStkP+1].exp = pmSeSt[pmStkP+1].exp;
    	break;}
    case 323: { /* <simple_what> = ID; */
#line 2383 "alan.pmk"

	pmSeSt[pmStkP+1].wht = newWhatId(pmSeSt[pmStkP+1].id->srcp, pmSeSt[pmStkP+1].id);
	pmSeSt[pmStkP+1].srcp = pmSeSt[pmStkP+1].id->srcp;
    	break;}
    case 325: { /* <simple_what> = 'current' 'actor'; */
#line 2389 "alan.pmk"

	pmSeSt[pmStkP+1].wht = newWhatActor(pmSySt[pmStkP+1].srcp);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 326: { /* <simple_what> = 'current' 'location'; */
#line 2395 "alan.pmk"

	pmSeSt[pmStkP+1].wht = newWhatLocation(pmSySt[pmStkP+1].srcp);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 324: { /* <simple_what> = 'this'; */
#line 2401 "alan.pmk"

	pmSeSt[pmStkP+1].wht = newWhatThis(pmSySt[pmStkP+1].srcp);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 327: { /* <attribute_reference> = ID 'of' <what>; */
#line 2410 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newAttributeExpression(pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].id, FALSE, pmSeSt[pmStkP+3].exp);
    	break;}
    case 328: { /* <attribute_reference> = <what> ':' ID; */
#line 2415 "alan.pmk"

	pmSeSt[pmStkP+1].exp = newAttributeExpression(pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+3].id, FALSE, pmSeSt[pmStkP+1].exp);
    	break;}
    case 329: { /* <optional_where> =; */
#line 2422 "alan.pmk"

        pmSeSt[pmStkP+1].whr = newWhere(&nulsrcp, FALSE, WHERE_DEFAULT, NULL);
    	break;}
    case 330: { /* <optional_where> = <where>; */
#line 2427 "alan.pmk"

        pmSeSt[pmStkP+1].whr = pmSeSt[pmStkP+1].whr;
    	break;}
    case 331: { /* <where> = <optional_directly> 'here'; */
#line 2434 "alan.pmk"

        pmSeSt[pmStkP+1].whr = newWhere(&pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].present, WHERE_HERE, NULL);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+2].srcp;
    	break;}
    case 332: { /* <where> = <optional_directly> 'nearby'; */
#line 2440 "alan.pmk"

        pmSeSt[pmStkP+1].whr = newWhere(&pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].present, WHERE_NEARBY, NULL);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+2].srcp;
    	break;}
    case 333: { /* <where> = <optional_directly> 'at' <primary>; */
#line 2446 "alan.pmk"

        pmSeSt[pmStkP+1].whr = newWhere(&pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].present, WHERE_AT, pmSeSt[pmStkP+3].exp);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+2].srcp;
    	break;}
    case 334: { /* <where> = <optional_directly> 'in' <primary>; */
#line 2452 "alan.pmk"

        pmSeSt[pmStkP+1].whr = newWhere(&pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].present, WHERE_IN, pmSeSt[pmStkP+3].exp);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+2].srcp;
    	break;}
    case 335: { /* <where> = <optional_directly> 'near' <what>; */
#line 2458 "alan.pmk"

        pmSeSt[pmStkP+1].whr = newWhere(&pmSySt[pmStkP+2].srcp, pmSeSt[pmStkP+1].present, WHERE_NEAR, pmSeSt[pmStkP+3].exp);
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+2].srcp;
    	break;}
    case 336: { /* <binop> = '+'; */
#line 2466 "alan.pmk"

	pmSeSt[pmStkP+1].op = PLUS_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 337: { /* <binop> = '-'; */
#line 2472 "alan.pmk"

	pmSeSt[pmStkP+1].op = MINUS_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 338: { /* <binop> = '*'; */
#line 2478 "alan.pmk"

	pmSeSt[pmStkP+1].op = MULT_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 339: { /* <binop> = '/'; */
#line 2484 "alan.pmk"

	pmSeSt[pmStkP+1].op = DIV_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 340: { /* <relop> = '<>'; */
#line 2493 "alan.pmk"

        pmSeSt[pmStkP+1].op   = NE_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 341: { /* <relop> = '='; */
#line 2499 "alan.pmk"

        pmSeSt[pmStkP+1].op   = EQ_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 342: { /* <relop> = '=='; */
#line 2505 "alan.pmk"

        pmSeSt[pmStkP+1].op   = EXACT_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 343: { /* <relop> = '>='; */
#line 2511 "alan.pmk"

        pmSeSt[pmStkP+1].op   = GE_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 344: { /* <relop> = '<='; */
#line 2517 "alan.pmk"

        pmSeSt[pmStkP+1].op   = LE_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 345: { /* <relop> = '>'; */
#line 2523 "alan.pmk"

        pmSeSt[pmStkP+1].op   = GT_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 346: { /* <relop> = '<'; */
#line 2529 "alan.pmk"

        pmSeSt[pmStkP+1].op   = LT_OPERATOR;
	pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 347: { /* <optional_qual> =; */
#line 2539 "alan.pmk"

        pmSeSt[pmStkP+1].qual = QUAL_DEFAULT;
    	break;}
    case 348: { /* <optional_qual> = 'before'; */
#line 2544 "alan.pmk"

        pmSeSt[pmStkP+1].qual = QUAL_BEFORE;
        pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 349: { /* <optional_qual> = 'after'; */
#line 2550 "alan.pmk"

        pmSeSt[pmStkP+1].qual = QUAL_AFTER;
        pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 350: { /* <optional_qual> = 'only'; */
#line 2556 "alan.pmk"

        pmSeSt[pmStkP+1].qual = QUAL_ONLY;
        pmSeSt[pmStkP+1].srcp = pmSySt[pmStkP+1].srcp;
    	break;}
    case 351: { /* <optional_not> =; */
#line 2565 "alan.pmk"

        pmSeSt[pmStkP+1].present = FALSE;
    	break;}
    case 352: { /* <optional_not> = 'not'; */
#line 2570 "alan.pmk"

        pmSeSt[pmStkP+1].present = TRUE;
    	break;}
    case 353: { /* <optional_directly> =; */
#line 2577 "alan.pmk"

        pmSeSt[pmStkP+1].present = FALSE;
    	break;}
    case 354: { /* <optional_directly> = 'directly'; */
#line 2582 "alan.pmk"

        pmSeSt[pmStkP+1].present = TRUE;
    	break;}
    case 355: { /* <optional_id> =; */
#line 2589 "alan.pmk"

        pmSeSt[pmStkP+1].id = NULL;
    	break;}
    case 356: { /* <optional_id> = ID; */
#line 2594 "alan.pmk"

        pmSeSt[pmStkP+1].id = pmSeSt[pmStkP+1].id;
    	break;}
    case 357: { /* <ids> = ID; */
#line 2601 "alan.pmk"

        pmSeSt[pmStkP+1].idList = newList(pmSeSt[pmStkP+1].id, ID_LIST);
    	break;}
    case 358: { /* <ids> = <ids> ID; */
#line 2606 "alan.pmk"

        pmSeSt[pmStkP+1].idList = concat(pmSeSt[pmStkP+1].idList, pmSeSt[pmStkP+2].id, ID_LIST);
    	break;}
    case 359: { /* <id_list> = ID; */
#line 2613 "alan.pmk"

        pmSeSt[pmStkP+1].str = newString(pmSeSt[pmStkP+1].id->string);
        pmSeSt[pmStkP+1].idList = newList(pmSeSt[pmStkP+1].id, ID_LIST);
    	break;}
    case 360: { /* <id_list> = <id_list> ',' ID; */
#line 2619 "alan.pmk"

        pmSeSt[pmStkP+1].str = pmSeSt[pmStkP+1].str;
        pmSeSt[pmStkP+1].idList = concat(pmSeSt[pmStkP+1].idList, pmSeSt[pmStkP+3].id, ID_LIST);
    	break;}
    case 361: { /* <optional_integer> =; */
#line 2627 "alan.pmk"

        pmSeSt[pmStkP+1].str = NULL;
    	break;}
    case 362: { /* <optional_integer> = Integer; */
#line 2632 "alan.pmk"

        pmSeSt[pmStkP+1].str = newString(pmSySt[pmStkP+1].chars);
    	break;}
    case 363: { /* <optional_minus> =; */
#line 2639 "alan.pmk"

	pmSeSt[pmStkP+1].minus = FALSE;
    	break;}
    case 364: { /* <optional_minus> = '-'; */
#line 2644 "alan.pmk"

	pmSeSt[pmStkP+1].minus = TRUE;
    	break;}
    case 365: { /* ID = Identifier; */
#line 2651 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 366: { /* ID = 'location'; */
#line 2659 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 367: { /* ID = 'actor'; */
#line 2664 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 368: { /* ID = 'opaque'; */
#line 2669 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 369: { /* ID = 'contains'; */
#line 2674 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 370: { /* ID = 'on'; */
#line 2679 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 371: { /* ID = 'it'; */
#line 2684 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 372: { /* ID = 'of'; */
#line 2689 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 373: { /* ID = 'first'; */
#line 2694 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 374: { /* ID = 'into'; */
#line 2699 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 375: { /* ID = 'taking'; */
#line 2704 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    case 376: { /* ID = 'off'; */
#line 2709 "alan.pmk"

	pmSeSt[pmStkP+1].id = newId(pmSySt[pmStkP+1].srcp, pmSySt[pmStkP+1].chars);
    	break;}
    default: break; }
}/*pmPaSema()*/

