/* Run-time functions for Modula-2 coroutine implementation.
 * Copyright 1993, 1994, 1995, 1996, 1997 Vladimir Makarov
 * This file is part of m2c.
 *
 * m2c is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * m2c is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with m2c. If not, see <http://www.gnu.org/licenses/>.
 */

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
