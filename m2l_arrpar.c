/* Run-time function for Modula-2 value array parameter allocation.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include <stdio.h>

#ifdef __STDC__
extern void *malloc ();
#else
extern char *malloc ();
#endif

void
m2_arrpar (adr, high, elong)
     char **adr;
     unsigned int high, elong;
{
  register char *var, *val;
  register unsigned int valong;

  val = (*adr);
  valong = (high + 1) * elong;
  var = (*adr) = malloc (valong);
  if (var == NULL)
    {
      fputs ("\n\r no memory for array parameter", stderr);
      m2_halt ();
    }
  while (valong-- != 0)
    *var++ = (*val++);
}
