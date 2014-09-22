/* This is common part of all config files for tunning Modula-2 translator.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */


#define Csuflong 4

/* Suffixes of implementation (main) module file and definition module file
   must be different.  Suffixes of implementation module and main module files
   can be the same. */

#define DEFINITION_MODULE_SUFFIX ".def"
#define IMPLEMENTATION_MODULE_SUFFIX ".mod"
#define MAIN_MODULE_SUFFIX ".mod"

#define MODULA_INPUT_SUFFIXES {DEFINITION_MODULE_SUFFIX,\
			       IMPLEMENTATION_MODULE_SUFFIX,\
			       MAIN_MODULE_SUFFIX}


/* The following utility is needed for the Modula-2 translator work with
   some C compilers. */

#ifndef MV
#define MV "mv"
#endif

/* The following directory is used for storing Modula-2 run time library and 
   definition, implementation standard modules and its object files. */

#ifndef STANDARD_LIBRARY_DIRECTORY
#define STANDARD_LIBRARY_DIRECTORY       "/usr/local/lib/m2lib/"
#endif

/* The following directory is used by `m2c' for storing temporary files. */

#ifndef TEMPORARY_DIRECTORY
#define TEMPORARY_DIRECTORY "/tmp/"
#endif

#define ENVIRONMENT_LIBRARY_PATHS_VARIABLE   "m2paths"

/* The name of Modula-2 run time library.  It is in
   STANDARD_LIBRARY_DIRECTORY. */

#ifndef M2_RUN_TIME_LIBRARY
#define M2_RUN_TIME_LIBRARY "m2lib.a" 
#endif

#define FALSE 0
#define TRUE 1


/* Maximum and minimum values of Modula-2 basic types. */

#ifdef MODULA_SHORT_IS_IMPLEMENTED_BY_C_CHAR
#define SHORTCARD_MAX UCHAR_MAX	/* unsigned char */
#else
#define SHORTCARD_MAX USHRT_MAX	/* unsigned short */
#endif

#define CARDINAL_MAX UINT_MAX	/* unsigned int */

#ifdef MODULA_LONG_IS_IMPLEMENTED_BY_C_LONG
#define LONGCARD_MAX ULONG_MAX	/* unsigned long */
#else
#define LONGCARD_MAX UINT_MAX	/* unsigned int */
#endif

#ifdef MODULA_SHORT_IS_IMPLEMENTED_BY_C_CHAR
#define SHORTINT_MIN SCHAR_MIN	/* char */
#else
#define SHORTINT_MIN SHRT_MIN	/* short */
#endif

#define INTEGER_MIN  INT_MIN	/* int */

#ifdef MODULA_LONG_IS_IMPLEMENTED_BY_C_LONG
#define LONGINT_MIN LONG_MIN	/* long */
#else
#define LONGINT_MIN INT_MIN	/* int */
#endif

#ifdef MODULA_SHORT_IS_IMPLEMENTED_BY_C_CHAR
#define SHORTINT_MAX SCHAR_MAX	/* char */
#else
#define SHORTINT_MAX SHRT_MAX	/* short */
#endif


#define INTEGER_MAX INT_MAX		/* int */

#ifdef MODULA_LONG_IS_IMPLEMENTED_BY_C_LONG
#define LONGINT_MAX LONG_MAX	/* long */
#else
#define LONGINT_MAX INT_MAX	/* int */
#endif

#define SHORTREAL_MAX FLT_MAX	/* float */
#define REAL_MAX FLT_MAX	/* float */
#define LONGREAL_MAX DBL_MAX	/* double */
#define SHORTREAL_MIN (-SHORTREAL_MAX)	/* float */
#define REAL_MIN (-REAL_MAX)	/* float */
#define LONGREAL_MIN (-LONGREAL_MAX)	/* double */

/* Maximum cardinal value of Modula-2 basic type CHAR. */

#define CHARACTER_MAX UCHAR_MAX

#define BITS_IN_CHARACTER CHAR_BIT

/* Number of bits in a Modula-2 set.  Modula-2 set is always implemented in C 
   by unsigned int. */

#define BITS_IN_SET (int)(CHAR_BIT*sizeof(unsigned int))		/*unsigned int*/

/* Byte is synonym of char. */

#define BYTE_SIZE sizeof(char)

#define SET_SIZE  sizeof(unsigned int)

/* Internal translator representation of Modula-2 constant value. */

#ifdef MODULA_LONG_IS_IMPLEMENTED_BY_C_LONG
typedef unsigned long Tcard;
typedef long Tint;
#else
typedef unsigned int Tcard;
typedef int Tint;
#endif

typedef double Treal;
typedef unsigned int Tset;
