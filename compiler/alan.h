#ifndef _ALAN_H_
#define _ALAN_H_

#include "sysdep.h"
#include "types.h"

/* USE other definitions */

#include "lst.h"

/* Public data */

extern int fileNo;		/* Number of last found file */
extern FILE *txtfil;		/* File for collected text */
extern FILE *datfil;		/* File for encoded text */
extern char advnam[];		/* The name of the adventure */
extern int charset;		/* Which character set the source is in */
extern List *includePaths;	/* The list of include paths to check */

/* Common procedures */

extern void compile(void);

#endif
