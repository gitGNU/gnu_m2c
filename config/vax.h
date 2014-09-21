/* This file is used for tunning Modula-2 translator on vax.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#ifdef __STDC__
#include <limits.h>
#include <float.h>
#else
#include "GNU_limits.h"

/* Vax does not support IEEE standard for float numbers. */

/*#include "IEEE_float.h"*/

#define FLT_MAX 1.70141173e+38                     /* float */
#define DBL_MAX 1.701411834604692293e+38           /* double */

#endif /* not __STDC__ */

/* No aim at more alignment. */

#define MAX_ALIGNMENT 4
