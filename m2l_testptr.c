/* Modula-2 run-time function for processing null pointer.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include <stdio.h>

char *
m2_testptr (ptr)
     char *ptr;
{
  if (ptr != 0)
    return ptr;
  fputs ("\n\rpointer overange", stderr);
  m2_halt ();
}
