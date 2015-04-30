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

IMPLEMENTATION MODULE ShellVars;
FROM ASCII IMPORT nul;
FROM SYSTEM IMPORT ADDRESS,TSIZE;
FROM CPROC IMPORT margc,margv,menvp;

%{
extern int m2argc;
extern char **m2argv,**m2envp;
#define margc(v) v=m2argc
#define margv(v) *(char ***)&(v)=m2argv
#define menvp(v) *(char ***)&(v)=m2envp
%}

TYPE PtrToArgs=POINTER TO POINTER TO CHAR;

 PROCEDURE GetNArg():CARDINAL;
   VAR
     argc:CARDINAL;argv,envp:PtrToArgs;
   BEGIN
     margc(argc);
     margv(argv);
     menvp(envp);
     RETURN argc;
   END GetNArg;

 PROCEDURE GetNthArgStr(n:CARDINAL;VAR str: ARRAY OF CHAR);
   VAR
     argc:CARDINAL;argv,envp:PtrToArgs;
   BEGIN
     str[0]:=nul;
     margc(argc);
     margv(argv);
     menvp(envp);
     IF n>=argc THEN RETURN END;
     argv:=PtrToArgs(CARDINAL(argv)+n*TSIZE(ADDRESS));
     GetStr(argv,str);
   END GetNthArgStr;

 PROCEDURE GetNthEnvStr(n:CARDINAL;VAR str: ARRAY OF CHAR);
   VAR
     argc:CARDINAL;argv,envp:PtrToArgs;i:CARDINAL;
   BEGIN
     str[0]:=nul;
     margc(argc);
     margv(argv);
     menvp(envp);
     i:=0;
     LOOP
       IF envp^=NIL THEN RETURN END;
       IF i=n THEN EXIT END;
       envp:=PtrToArgs(CARDINAL(envp)+TSIZE(ADDRESS));
       INC(i);
     END;
     GetStr(envp,str);
   END GetNthEnvStr;

 (*----- internal procedure:---------*)
 PROCEDURE GetStr(p:PtrToArgs;VAR str:ARRAY OF CHAR);
   TYPE PtrToChar=POINTER TO CHAR;
   VAR
     i:CARDINAL; pch: PtrToChar;
   BEGIN
     pch:=PtrToChar(p^); i:=0;
     WHILE (i<=CARDINAL(HIGH(str))) & (pch^#nul) DO
       str[i]:=pch^; pch:=PtrToChar(CARDINAL(pch)+1); INC(i);
     END;
     IF i<=CARDINAL(HIGH(str)) THEN str[i]:=nul END;
   END GetStr;

BEGIN
END ShellVars.
