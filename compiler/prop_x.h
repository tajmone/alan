#ifndef _PROP_X_H_
#define _PROP_X_H_
/*----------------------------------------------------------------------*\

			       PROP_X.H
			Property Nodes Export
                                                                     
\*----------------------------------------------------------------------*/

#include "prop.h"

/* USE: */
#include "../interpreter/acode.h"
#include "ins.h"
#include "context.h"


/* DATA: */

/* METHODS: */

extern Properties *newEmptyProps(void);

extern Properties *newProps(List *nams,
			    Where *whr,
			    List *atrs,
			    Container *cnt,
			    Srcp descriptionCheckSrcp,
			    List *descriptionCheck,
			    Srcp descriptionSrcp,
			    List *description,
			    List *entered,
			    Srcp enteredSrcp,
			    List *mentioned,
			    Srcp mentionedSrcp,
			    List *definite,
			    Bool definiteIsForm,
			    Srcp definiteSrcp,
			    List *indefinite,
			    Bool indefiniteIsForm,
			    Srcp indefiniteSrcp,
			    List *exts,
			    List *vrbs,
			    List *scrs);

extern void symbolizeProps(Properties *props);
extern void analyzeProps(Properties *props, Context *context);
extern void generateCommonPropertiesData(Properties *props);
extern void generateInstancePropertiesData(Properties *props);
extern void generatePropertiesEntry(InstanceEntry *entry, Properties *props);
extern void dumpProps(Properties *props);


#endif
