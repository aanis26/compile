
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     divfini = 258,
     mc_entier = 259,
     mc_reel = 260,
     mc_bool = 261,
     mc_car = 262,
     mc_str = 263,
     bool = 264,
     tabb = 265,
     ttype = 266,
     cst = 267,
     et = 268,
     ou = 269,
     no = 270,
     sup = 271,
     supe = 272,
     inf = 273,
     infe = 274,
     ega = 275,
     dif = 276,
     aff = 277,
     entre = 278,
     sorti = 279,
     decv = 280,
     decvar = 281,
     body = 282,
     as = 283,
     aprdeb = 284,
     start = 285,
     finish = 286,
     si = 287,
     alors = 288,
     sinon = 289,
     doo = 290,
     pour = 291,
     tantque = 292,
     jusqua = 293,
     debut = 294,
     ID = 295,
     sep = 296,
     entier_pos = 297,
     entier_neg = 298,
     reel = 299,
     car = 300,
     str = 301,
     plus = 302,
     moins = 303,
     mul = 304,
     parouv = 305,
     parfer = 306,
     croch1 = 307,
     croch2 = 308,
     deuxpoint = 309,
     formabol = 310,
     formachr = 311,
     formaflt = 312,
     formaint = 313,
     formastr = 314,
     fin = 315,
     egale = 316,
     virgule = 317,
     doublecot = 318,
     msg = 319,
     noteq = 320,
     doubleegale = 321
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "syntasem.y"

	char* nom;
	int integer;
    struct{
		int type;
        char* res;
    }NT;



/* Line 1676 of yacc.c  */
#line 129 "syntasem.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


