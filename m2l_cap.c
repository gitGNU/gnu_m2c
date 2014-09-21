/* Run-time function for Modula-2 CAP implementation.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */


int
m2_cap (ch)
     register unsigned int ch;
{				/*ASCII*/
  if ('a' <= ch && ch <= 'z')
    return ch + ('A' - 'a');
  return ch;
}
