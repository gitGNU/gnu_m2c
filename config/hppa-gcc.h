/* This file is used for tunning Modula-2 translator on 32-bit HP
   (PARISC) GCC compiler.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include "hppa.h"
#include "gcc.h"


/* If the following macros is defined than it is used for making more
   precise size of type with mode TYPE_MODE (see commentaries in m2-icode.h)
   after standard method of size calculation. */

/*#define MAKING_MORE_PRECISE_SIZE_BY_TYPE_MODE(size,type_mode) */

/* If the following macros is defined than it is used for making more
   precise size of type given as ICODE_PTR (see commentaries in m2-icode.h)
   after standard method of size calculation and after call of
   previous macros (if it is defined). */

/*#define MAKING_MORE_PRECISE_SIZE_BY_TYPE(size,icode_ptr) */

/* If the following macros is defined than it is used for making more
   precise alignment of type with mode TYPE_MODE (see commentaries in
   m2-icode.h) after standard method of alignment calculation. */

/*#define MAKING_MORE_PRECISE_ALIGN_BY_TYPE_MODE(align,type_mode) */

/* If the following macros is defined than it is used for making more
   precise alignment of type given as ICODE_PTR (see commentaries in
   m2-icode.h) after standard method of alignment calculation and after call of
   previous macros (if it is defined). */

/*#define MAKING_MORE_PRECISE_ALIGN_BY_TYPE(align,icode_ptr) */

