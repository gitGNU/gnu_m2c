/* Run-time functions for Modula-2 coroutine implementation.
   Copyright (C) 1993-1997 (see more details in file COPYING).

   This file is part of Modula-2 translator.  */

#include <stdio.h>

int *m2_nprcadr;
unsigned int m2_nprclong;
int *m2_newcor;
extern int *m2_currcor;
extern int *m2_maincor;

void
m2_newprocess (f, adr, clong, cor)
     int (*f) ();
     int *adr;
     unsigned int clong;
     int **cor;
{
  m2_nprcadr = adr;
  m2_nprclong = clong;
  (*f) (1);
  *cor = m2_newcor;
}

void
m2_transfer (cor1, cor2)
     int **cor1, **cor2;
{
  int *c;

  m2_pasivcor ();
  c = m2_currcor;
  m2_currcor = (*cor2);
  *cor1 = c;
  m2_activcor ();
}
