/* Modula-2 run-time function for processing range overange.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include <stdio.h>

void
m2_rngovf ()
{
  fputs ("\n\rrange overange", stderr);
  m2_halt ();
}
