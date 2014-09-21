/* Common definitions for all GNU Modula-2 translator files.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include "m2-config.h"
#include "m2-errors.h"
#include "m2-icode.h"
#include "m2-type-size.h"
#include "m2-library.h"


#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* The following for C compilers that have not standard include files. */

#ifdef __STDC__
extern void exit (int);
extern void abort (void);
extern void *malloc ();
extern void *realloc ();
extern void free (void *);
extern char *getenv (const char *);
#else /* not __STDC__ */
extern void exit ();
extern void abort ();
extern char *malloc ();
extern char *realloc ();
extern void free ();
extern char *getenv ();
#endif /* not __STDC__ */

#define delete(v) unlink(v)


/* It is necessary when char is not unsigned char. */

#define CHAR_TO_INT(ch) ((ch)&0377)


/* The following type used for storing semantic information about language
   construction representing types and expressions. */

typedef struct
{
  /* Pointer to subgraph representing type definition
     of expressions or types. */
  ICN_pointer type;


  /* The all following members are defined only for expressions. */

  /* TRUE if the corresponding expression is a constant expression. */
  char it_is_constant;
  /* TRUE if the corresponding expression is a variable designator. */
  char it_is_designator;
  /* TRUE if the corresponding expression is an open array parameter. */
  char it_is_array_parameter;
} semantic_information;


extern int all_flag;
extern int only_upper_case_flag;
extern int test_flag;
extern int pass_of_picking_used_objects_when_all_flag;
extern int pass_of_generation_when_all_flag;
extern int testing_main_module;
extern int picking_names_of_imported_modules;
extern ICN_pointer current_compilation_unit;
extern ICN_pointer current_scope;
extern FILE *current_input_file;
extern int current_line_number;
extern int strict_flag;
extern int third_edition_flag;
extern int it_is_definition_module;
extern int it_is_main_module;
