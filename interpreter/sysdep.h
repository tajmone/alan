/*----------------------------------------------------------------------*\

  sysdep.h				Date: 1992-07-16/thoni@rabbit

  System dependencies file for Alan Adventure Language system 

\*----------------------------------------------------------------------*/
#ifndef _SYSDEP_H_
#define _SYSDEP_H_


/* Place definitions of OS and compiler here if necessary */
#ifdef AZTEC_C
#define __amiga__
#endif

#ifdef sun
#define __sun__
#endif

#ifdef unix
#define __unix__
#endif

#ifdef vax
#define __vms__
#endif

#ifdef THINK_C
#define __mac__
#endif

#ifdef DOS
#define __dos__
#endif


/*----------------------------------------------------------------------

  Below follows OS and compiler dependent settings. They should not be
  changed except for introducing new sections when porting to new
  environments.

 */

/* ISO character sets? */
#if defined __dos__ || defined __mac__
#define ISO 0
#else
#define ISO 1
#endif

/* General settings and includes, which work for all environments */
#include <stdio.h>
#include <ctype.h>

/* Strings for file modes */
#define READ_MODE "r"
#define WRITE_MODE "w"



/* Special cases and definition overrides */

#ifdef __STDC__
#define _PROTOTYPES_
#include <stdlib.h>
#include <string.h>
#endif

#ifdef __unix__
#define MULTI
#endif


#ifdef __vms__
/* Our VAXC doesn't define __STDC__ */
#define _PROTOTYPES_
#define REVERSED		/* Byte order in strings */
#include <stdlib.h>
#include <string.h>

#define MULTI

extern char *strdup(char str[]);

/* Cheat implementation of strftime */
extern size_t strftime (char *, size_t, const char *, const struct tm *);

#endif


#ifdef AZTEC_C
/* Define some library routines needed for the Aztec C compiler */
/* <memory.h> */
extern void *malloc();

/* <string.h> */
extern char *strcpy();
extern char *strncpy();
extern char *strcat();
extern char *strncat();
extern char *strchr();
extern char *strrchr();
extern char *strpbrk();
extern int strcmp();
extern int strncmp();
extern int strlen();
extern int strspn();
extern int strcspn();


/* These where necessary to implement in SYSDEP.C although they should exist */
extern void memcpy();
extern void memset();
extern char *strdup();
#endif


#ifdef __amiga__
/* Return codes */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE  1
#endif


#ifdef __dos__

/* File open mode (binary) */
#undef READ_MODE
#define READ_MODE "rb"
#undef WRITE_MODE
#define WRITE_MODE "wb"

/* Byte ordering */
#define REVERSED

/* Return codes */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE  1
#endif



#ifdef _PROTOTYPES_

extern int isSpace(int c);	/* IN - Character to test */
extern int isLower(int c);	/* IN - Character to test */
extern int isUpper(int c);	/* IN - Character to test */
extern int isLetter(int c);	/* IN - Character to test */
extern char lowerCase(int c);	/* IN - Character to convert */
extern char upperCase(int c);	/* IN - Character to convert */
extern char *strlow(char str[]); /* INOUT - String to convert */
extern char *strupp(char str[]); /* INOUT - String to convert */
extern void toIso(char copy[],	/* OUT - Mapped string */
		  char original[]); /* IN - string to convert */
extern void fromIso(char copy[], /* OUT - Mapped string */
		    char original[]); /* IN - string to convert */
#else
extern int isSpace();
extern int isLower();
extern int isUpper();
extern int isLetter();
extern char lowerCase();
extern char upperCase();
extern char *strlow();
extern char *strupp();
extern void toIso();
extern void fromIso();
#endif

#endif				/* -- sysdep.h -- */

