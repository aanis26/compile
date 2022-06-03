
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
     op_tag = 258,
     close_tag = 259,
     strt_tag = 260,
     end_tag = 261,
     op_doc = 262,
     end_doc = 263,
     sb = 264,
     mc_var = 265,
     mc_cnst = 266,
     body = 267,
     mc_array = 268,
     tint = 269,
     treel = 270,
     tchar = 271,
     tstring = 272,
     tbool = 273,
     as = 274,
     dp = 275,
     mc_aff = 276,
     vg = 277,
     my_do = 278,
     my_for = 279,
     my_until = 280,
     mc_affstrt = 281,
     my_ifstrt = 282,
     my_thenstrt = 283,
     my_elsestrt = 284,
     my_forstrt = 285,
     my_dostrt = 286,
     readstrt = 287,
     writestrt = 288,
     tcst = 289,
     pvg = 290,
     cros = 291,
     croe = 292,
     prnts = 293,
     prnte = 294,
     pipe = 295,
     repint = 296,
     repreal = 297,
     repstr = 298,
     repchar = 299,
     repbool = 300,
     qot = 301,
     my_and = 302,
     my_or = 303,
     my_if = 304,
     my_else = 305,
     my_not = 306,
     my_then = 307,
     egal = 308,
     inf = 309,
     sup = 310,
     infe = 311,
     supe = 312,
     diff = 313,
     my_while = 314,
     true = 315,
     false = 316,
     idf = 317,
     cst = 318,
     entierr = 319,
     reelr = 320,
     charr = 321,
     stringr = 322,
     msg = 323,
     egg = 324,
     dec = 325,
     add = 326,
     divi = 327,
     mult = 328
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 44 "syntaxique.y"
 
   int entier; 
   char* str;
   float reelf;
   



/* Line 1676 of yacc.c  */
#line 134 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


