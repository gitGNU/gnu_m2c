/* Run-time function for Modula-2 comparing long memory values on equality.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */


int
m2_eq (str1, str2, l)
     register char *str1, *str2;
     register unsigned int l;
{
  while (l-- != 0)
    if (*str1++ != *str2++)
      return 0;
  return 1;
}
