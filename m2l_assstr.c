/* Run-time function for Modula-2 string assignment.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */


/* This function is used only for the 3rd edition of Wirth's book. */

void
m2_assstr (var, str, vlong, strlong)
     register char *var, *str;
     register unsigned int vlong, strlong;
{
  while (vlong--, strlong-- != 0)
    *var++ = (*str++);
  while (vlong-- != 0)
    *var++ = '\0';
}
