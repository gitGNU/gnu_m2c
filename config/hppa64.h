/* This file is used for tunning Modula-2 translator on 64-bit HP
   (PARISC).  Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#ifdef __STDC__
#include <limits.h>
#include <float.h>
#else
#include "GNU_limits.h"
#include "IEEE_float.h"
#endif

/* No aim at more alignment. */

#define MAX_ALIGNMENT 8
