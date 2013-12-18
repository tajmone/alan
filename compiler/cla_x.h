#ifndef _CLA_X_H_
#define _CLA_X_H_
/*----------------------------------------------------------------------*\

			     Class Nodes Export
                                                                     
\*----------------------------------------------------------------------*/

#include "cla.h"

/* Use: */


/* Data: */
extern Class *entity, *thing, *object, *location, *actor, *string, *integer;


/* Methods: */
extern void initClasses(void);
extern Class *newClass(Srcp *srcp, Id *id, Id *parent, Properties *props);
extern void symbolizeClasses(void);
extern void analyzeAllClassAttributes(void);
extern void analyzeClasses(void);
extern void setupDefaultProperties(void);
extern Aaddr generateClasses(void);
extern void dumpClasses(void);

#endif
