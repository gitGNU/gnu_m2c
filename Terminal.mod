(* Part of the standard library.
 * Copyright 1991, 1993 Vladimir Makarov
 * Copyright 2014 David Egan Evans
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
 *)

IMPLEMENTATION MODULE Terminal;
IMPORT ASCII;
FROM SYSTEM IMPORT ADR;
FROM CPROC IMPORT read,write,unblock,block;

%{
#include <fcntl.h>

static int attr;

static unblock(){
 attr=fcntl(0,F_GETFL,0);
 fcntl(0,F_SETFL,attr |
#ifdef FNDELAY
       FNDELAY
#else
       O_NDELAY
#endif
      );
}

static block(){fcntl(0,F_SETFL,attr);}

%}

 CONST
  stdin=0;
  stdout=1;

 VAR
  lastch: CHAR; (* last character read *)
  reread: BOOLEAN; (* TRUE if the last character should be reread *)


 PROCEDURE Read(VAR ch:CHAR);
  BEGIN
   IF reread THEN ch:=lastch; Done:=TRUE
   ELSE
    Done:=read(stdin, ADR(ch), 1)=1;
   END;
   reread:=FALSE; lastch:=ch;
  END Read;

 PROCEDURE BusyRead(VAR ch:CHAR);
  VAR attr:INTEGER;
  BEGIN
   unblock();
   IF read(stdin, ADR(ch), 1)<=0 THEN ch:=0C; END;
   block();
  END BusyRead;

 PROCEDURE ReadAgain;
  BEGIN
   reread:=TRUE;
  END ReadAgain;

 PROCEDURE Write(ch:CHAR);
  BEGIN
    write(stdout, ADR(ch), 1);
  END Write;

 PROCEDURE WriteLn;
  BEGIN
    Write(ASCII.lf);
  END WriteLn;

 PROCEDURE WriteString(s:ARRAY OF CHAR);
  VAR i:CARDINAL;
  BEGIN
   i:=0;
   WHILE (i<=CARDINAL(HIGH(s))) & (s[i] # ASCII.nul) DO
    Write(s[i]);
    INC(i);
   END;
  END WriteString;

BEGIN
 reread:=FALSE; lastch:=" ";
END Terminal.

