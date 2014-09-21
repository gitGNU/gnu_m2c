/* Run-time function for Modula-2 HALT implementation.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include <stdio.h>

void
m2_halt ()
{
  fputs ("\n\rhalt\n\r", stderr);
  exit (1);
}
