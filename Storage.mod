/* Part of the standard library.
 * Copyright 1991, 1993 Vladimir Makarov
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

IMPLEMENTATION MODULE Storage;
FROM CPROC IMPORT malloc,free;

%{
#include <stdlib.h>
%}

 PROCEDURE ALLOCATE(VAR a:ADDRESS;size:CARDINAL);
  BEGIN
   a:=malloc(size);
   IF a=NIL THEN HALT;END;
  END ALLOCATE;

 PROCEDURE DEALLOCATE(VAR a:ADDRESS;size:CARDINAL);
  BEGIN
   free(a);
  END DEALLOCATE;

 PROCEDURE Available(size:CARDINAL):BOOLEAN;
  VAR a:ADDRESS;
  BEGIN
   a:=malloc(size);
   IF a#NIL THEN free(a); END;
   RETURN a#NIL;
  END Available;

BEGIN
END Storage.
