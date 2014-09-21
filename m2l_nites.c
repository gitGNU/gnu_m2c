/* Run-time function for Modula-2 `<=' operator for sets.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include "m2-config.h"

int
m2_nites (s1, s2)
     Tset s1, s2;
{
  if ((s1 | s2) == s1)
    return TRUE;
  else
    return FALSE;
}
