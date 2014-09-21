/* Run-time function for Modula-2 array assignment.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */


void
m2_assarr (var, expr, l)
     register char *var, *expr;
     register unsigned int l;
{
  while (l-- != 0)
    *var++ = (*expr++);
}
