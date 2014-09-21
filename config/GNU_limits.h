/* This file is used for tunning Modula-2 translator on GNU (32- or 64-bit)
   machines when file `limits.h' is absent.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#define CHAR_BIT    8                      /* number of bits in char (byte) */
#define UCHAR_MAX   0377                   /* unsigned char */

#if sizeof (unsigned short) == 2
#define USHRT_MAX   0177777                /* unsigned short */
#elif sizeof (unsigned short) == 4
#define USHRT_MAX   037777777777           /* unsigned short */
#else
error Sorry, What's the strange machine
#endif

#if sizeof (unsigned int) == 4
#define UINT_MAX    037777777777           /* unsigned int */
#elif sizeof (unsigned int) == 8
#define UINT_MAX    01777777777777777777777  /* unsigned int */
#else
error Sorry, What's the strange machine
#endif

#if sizeof (unsigned long) == 4
#define ULONG_MAX   037777777777           /* unsigned long */
#elif sizeof (unsigned long) == 8
#define ULONG_MAX   01777777777777777777777  /* unsigned long */
#else
error Sorry, What's the strange machine
#endif

#define SCHAR_MAX   ((int)0177)            /* char */

#if sizeof (short) == 2
#define SHRT_MAX    ((int)077777)          /* short */
#elif sizeof (short) == 4
#define SHRT_MAX    ((int)017777777777)    /* short */
#else
error Sorry, What's the strange machine
#endif

#if sizeof (int) == 4
#define INT_MAX     ((int)017777777777)    /* int */
#elif sizeof (int) == 8
#define INT_MAX     ((int)0777777777777777777777)    /* int */
#else
error Sorry, What's the strange machine
#endif

#if sizeof (long int) == 4
#define LONG_MAX    ((int)017777777777)    /* long */
#elif sizeof (long int) == 8
#define LONG_MAX    ((int)0777777777777777777777)    /* long */
#else
error Sorry, What's the strange machine
#endif

#define SCHAR_MIN   (-SCHAR_MAX-1)         /* char */
#define SHRT_MIN    (-SHRT_MAX-1)          /* short */
#define INT_MIN	    (-INT_MAX-1)           /* int */
#define LONG_MIN    (-LONG_MAX-1)          /* long */
