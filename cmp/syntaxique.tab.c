
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxique.y"

	#include<stdlib.h>
	#include<stdio.h>
	int nb_ligne = 1;
	int nbcol = 1;
	char temp[30];
	int cstVal;
	char sauvAffType[30] = "";
	char sauvType[20] = "";
	char *sauv;
	int sauvIf[100],sauvIfFin[100],debWhile[100],debFOR[100];
	int sauvIfP=0,sauvIfFinP=0,debWhileP=0,debFORP=0;

	void push(int* tab,int*pos,int val){

		tab[*pos]=val;
		*pos=*pos+1;
	}
	int pop(int* tab,int* pos){

		*pos=*pos-1;
		return tab[*pos];
	}

	int tmp = -1;
	int cpt = 0;
	int cptSF = 0;
	int cptIDF = 0;
	char buffer[50];
	char tabSF[30][10];
	char tabIDF[30][10];
	int activesigne = 0;
	
	extern int yylineno;
	int processToggle = 0, arrayToggle = 0, loopToggle = 0;
	
	// quad variables
	int qc=0;
	char tmpq[20];
	int deb_while;


/* Line 189 of yacc.c  */
#line 116 "syntaxique.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 44 "syntaxique.y"
 
   int entier; 
   char* str;
   float reelf;
   



/* Line 214 of yacc.c  */
#line 234 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 246 "syntaxique.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    14,    19,    22,    27,    31,    35,
      38,    43,    46,    48,    49,    57,    58,    69,    71,    73,
      75,    77,    79,    83,    85,    86,    94,    95,    99,   102,
     107,   110,   111,   113,   115,   116,   117,   126,   128,   130,
     132,   134,   136,   138,   140,   141,   149,   153,   155,   158,
     162,   166,   170,   174,   178,   182,   185,   186,   192,   194,
     199,   201,   203,   205,   209,   213,   217,   221,   225,   232,
     239,   241,   246,   248,   250,   252,   257,   259,   261,   263,
     265,   267,   268,   280,   281,   293,   295,   297,   299,   301,
     303,   305,   307,   309,   310,   311,   323,   330,   331,   339,
     340,   345,   349,   351,   355,   359
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    77,    76,   104,   103,    78,    -1,     3,
       9,    79,    76,    -1,     3,     9,    90,    76,    -1,     3,
     102,    -1,     3,     7,    62,     4,    -1,     5,     8,     4,
      -1,    80,    82,    81,    -1,    10,     4,    -1,     5,     9,
      10,     4,    -1,    83,    82,    -1,    83,    -1,    -1,     3,
      87,    19,    86,    84,     6,    35,    -1,    -1,     3,    13,
      19,    86,     4,    88,    85,     5,    13,     4,    -1,    14,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    62,
      40,    87,    -1,    62,    -1,    -1,     3,    62,    20,    63,
       6,    89,    88,    -1,    -1,    91,    93,    92,    -1,    11,
       4,    -1,     5,     9,    11,     4,    -1,    94,    93,    -1,
      -1,    95,    -1,    99,    -1,    -1,    -1,     3,    62,    69,
      96,    98,    97,     6,    35,    -1,    65,    -1,    63,    -1,
      64,    -1,    66,    -1,    67,    -1,    60,    -1,    61,    -1,
      -1,     3,   101,    19,    86,   100,     6,    35,    -1,    62,
      40,   101,    -1,    62,    -1,    12,     4,    -1,     5,    12,
       4,    -1,    26,   105,   104,    -1,    32,   123,   104,    -1,
      33,   124,   104,    -1,    31,   112,   104,    -1,    30,   114,
     104,    -1,   117,   104,    -1,    -1,    20,   106,    22,   107,
       6,    -1,    62,    -1,    62,    36,    63,    37,    -1,   108,
      -1,   109,    -1,   111,    -1,   108,    71,   108,    -1,   108,
      70,   108,    -1,   108,    73,   108,    -1,   108,    72,   108,
      -1,    38,   108,    39,    -1,   116,    38,   110,    22,   110,
      39,    -1,   116,    38,   110,    22,   110,    39,    -1,   108,
      -1,    51,    38,   110,    39,    -1,    62,    -1,    63,    -1,
      64,    -1,    62,    36,    63,    37,    -1,    67,    -1,    66,
      -1,    65,    -1,    60,    -1,    61,    -1,    -1,   113,     4,
     104,     3,    59,    20,   110,     6,     5,    23,     4,    -1,
      -1,   106,    69,   111,    25,   111,   115,     4,   104,     5,
      24,     4,    -1,    55,    -1,    57,    -1,    53,    -1,    58,
      -1,    56,    -1,    54,    -1,    47,    -1,    48,    -1,    -1,
      -1,    27,    20,   110,   118,     4,   120,   119,   121,     5,
      49,     4,    -1,    28,     4,   104,     5,    52,     4,    -1,
      -1,   122,    29,     4,   104,     5,    50,     4,    -1,    -1,
      20,   106,    67,     6,    -1,    20,   125,     6,    -1,    67,
      -1,    67,    71,   106,    -1,    67,    71,   125,    -1,    67,
      71,   106,    71,   125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    81,    82,    83,    85,    88,    92,    94,
      96,    99,   100,   103,   103,   104,   104,   107,   108,   109,
     110,   111,   115,   116,   119,   119,   120,   124,   127,   130,
     133,   134,   137,   138,   142,   142,   142,   145,   146,   147,
     148,   149,   150,   151,   155,   155,   158,   159,   163,   166,
     169,   170,   171,   172,   173,   174,   175,   180,   183,   184,
     190,   191,   194,   195,   196,   197,   198,   199,   202,   205,
     206,   207,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   223,   223,   229,   228,   235,   236,   237,   238,   239,
     240,   241,   242,   246,   247,   246,   250,   253,   253,   257,
     264,   267,   270,   271,   272,   273
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "op_tag", "close_tag", "strt_tag",
  "end_tag", "op_doc", "end_doc", "sb", "mc_var", "mc_cnst", "body",
  "mc_array", "tint", "treel", "tchar", "tstring", "tbool", "as", "dp",
  "mc_aff", "vg", "my_do", "my_for", "my_until", "mc_affstrt", "my_ifstrt",
  "my_thenstrt", "my_elsestrt", "my_forstrt", "my_dostrt", "readstrt",
  "writestrt", "tcst", "pvg", "cros", "croe", "prnts", "prnte", "pipe",
  "repint", "repreal", "repstr", "repchar", "repbool", "qot", "my_and",
  "my_or", "my_if", "my_else", "my_not", "my_then", "egal", "inf", "sup",
  "infe", "supe", "diff", "my_while", "true", "false", "idf", "cst",
  "entierr", "reelr", "charr", "stringr", "msg", "egg", "dec", "add",
  "divi", "mult", "$accept", "S", "partie_declaration", "debutprogramme",
  "finprogramme", "list_var", "start_partie_var", "end_partie_var",
  "list_dec", "dec_var", "$@1", "$@2", "TYPE", "LISTE_IDF", "LIST_ARRAY",
  "$@3", "DEC_CSTS", "START_CST_PART", "END_CST_PART", "CSTS",
  "CST_DEC_TYPE", "VAL_CST", "$@4", "$@5", "CST_VALEUR", "TYPE_CST", "$@6",
  "LISTE_CST", "debut_body", "fin_body", "partie_instruction",
  "AFFECTATION", "IDF_SWITCH", "LIST_EXP", "LIST_EXP_ARITHM", "COND_STRT",
  "COND", "COND_ARG", "WHILE", "$@7", "FOR", "$@8", "COND_CMP_LOG",
  "CONDITION", "$@9", "$@10", "THEN", "ELSE", "$@11", "INPUT", "OUTPUT",
  "MSG", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    78,    79,    80,
      81,    82,    82,    84,    83,    85,    83,    86,    86,    86,
      86,    86,    87,    87,    89,    88,    88,    90,    91,    92,
      93,    93,    94,    94,    96,    97,    95,    98,    98,    98,
      98,    98,    98,    98,   100,    99,   101,   101,   102,   103,
     104,   104,   104,   104,   104,   104,   104,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   109,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   113,   112,   115,   114,   116,   116,   116,   116,   116,
     116,   116,   116,   118,   119,   117,   120,   122,   121,   121,
     123,   124,   125,   125,   125,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     2,     4,     3,     3,     2,
       4,     2,     1,     0,     7,     0,    10,     1,     1,     1,
       1,     1,     3,     1,     0,     7,     0,     3,     2,     4,
       2,     0,     1,     1,     0,     0,     8,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     3,     1,     2,     3,
       3,     3,     3,     3,     3,     2,     0,     5,     1,     4,
       1,     1,     1,     3,     3,     3,     3,     3,     6,     6,
       1,     4,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     0,    11,     0,    11,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,    11,     6,     0,     7,     0,
       4,     3,     1,     3,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,    56,     0,     0,
       0,     5,     0,     0,     0,    81,     0,     0,     0,    56,
       6,     0,     0,     0,     0,     0,    31,    48,     0,    56,
       0,    58,     0,    56,    56,     0,     0,    56,     0,    56,
       0,     0,    55,     9,    28,     3,     0,     0,    12,     4,
       0,     0,    31,    32,    33,     0,    50,     0,    91,    92,
       0,    87,    90,    85,    89,    86,    88,    79,    80,    72,
      73,    74,    78,    77,    76,    70,    93,    62,     0,     0,
       0,    54,    53,    56,     0,    51,   102,     0,    52,     0,
       0,     2,     0,    23,     0,     0,     8,    11,    47,     0,
       0,    27,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,    49,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
      60,    61,     0,    67,     0,     0,    64,    63,    66,    65,
       0,     0,    59,     0,     0,   100,   103,   104,     7,    17,
      18,    19,    20,    21,     0,    22,    13,     0,    47,    46,
       0,    44,     0,    57,     0,    71,    75,     0,    94,     0,
      83,     0,     0,    26,     0,    10,    42,    43,    38,    39,
      37,    40,    41,    35,     0,    29,     0,    56,    97,     0,
       0,     0,   105,     0,    15,     0,     0,     0,     0,     0,
       0,     0,    69,    56,     0,     0,     0,    14,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    68,
       0,     0,    56,     0,     0,     0,     0,    96,    95,     0,
       0,     0,    24,    16,     0,    84,    82,    26,     0,    25,
      98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     3,    91,    23,    24,    96,    47,    48,
     174,   206,   154,    94,   194,   237,    25,    26,   101,    51,
      52,    53,   160,   196,   183,    54,   184,    99,    11,    41,
      18,    29,    32,   129,    75,   131,    76,    77,    34,    35,
      33,   190,    78,    19,   111,   188,   168,   200,   201,    37,
      39,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
      25,    49,    59,    60,     4,  -116,    46,   105,    67,    51,
      72,  -116,    57,    66,    26,  -116,    71,    92,   108,   105,
    -116,   110,   111,    60,   119,    60,   130,  -116,    26,   105,
      42,    98,    70,   105,   105,   136,    26,   105,    74,   105,
     131,   137,  -116,  -116,  -116,  -116,    -8,   139,   119,  -116,
      83,   141,   130,  -116,  -116,   125,  -116,   -31,  -116,  -116,
     112,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   113,
    -116,  -116,  -116,  -116,  -116,   -20,  -116,  -116,   114,    85,
     -18,  -116,  -116,   105,    84,  -116,    82,   148,  -116,   151,
     149,  -116,   140,   116,   142,   153,  -116,  -116,   -28,   144,
     155,  -116,  -116,    63,   -33,    42,    95,   -31,   -31,   -31,
     -31,   156,    42,   128,   145,   163,   161,   -46,  -116,  -116,
     165,     9,   109,     9,   162,   115,  -116,     9,   164,   167,
     -20,  -116,   138,  -116,   135,   143,    -3,    -3,  -116,  -116,
     150,   157,  -116,   -18,   122,  -116,   117,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,   178,  -116,  -116,   179,   146,  -116,
      18,  -116,   181,  -116,    42,  -116,  -116,   183,  -116,    42,
    -116,   169,    74,   187,   185,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,   186,  -116,   171,   105,   189,   158,
     191,    42,  -116,   134,  -116,   166,   192,   170,    42,   194,
     195,   173,  -116,   105,   198,   188,   201,  -116,   172,  -116,
     174,   159,   160,   206,   207,   209,   152,   203,  -116,  -116,
     213,   214,   105,   196,   199,   215,   219,  -116,  -116,   220,
     222,   223,  -116,  -116,   180,  -116,  -116,   187,   224,  -116,
    -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,    -6,  -116,  -116,  -116,  -116,  -116,   176,  -116,
    -116,  -116,  -114,    97,    -5,  -116,  -116,  -116,  -116,   177,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,   106,  -116,  -116,
     -19,  -116,   -25,  -116,   -35,  -116,  -104,   -76,  -116,  -116,
    -116,  -116,   132,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -115
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -100
static const yytype_int16 yytable[] =
{
      42,   134,   147,    55,   114,    92,   133,    57,   141,   156,
      56,    84,   125,   161,    81,    82,    31,    45,    85,    49,
      88,    86,   104,   149,   150,   151,   152,   153,     1,    67,
      68,    69,    70,    71,    72,    73,    74,   107,   108,   109,
     110,   126,    67,    68,    69,    70,    71,    72,    73,    74,
     107,   108,   109,   110,    93,     9,     4,   192,    10,     5,
     186,    21,    22,     6,   115,   189,     8,   170,   130,   109,
     110,    20,   136,   137,   138,   139,    27,    28,   176,   177,
      57,   178,   179,   180,   181,   182,    30,   204,    31,    58,
      59,    36,   146,    60,   210,    61,    62,    63,    64,    65,
      66,    57,    67,    68,    69,    70,    71,    72,    73,    74,
      58,    59,    38,    40,    43,    44,    61,    62,    63,    64,
      65,    66,    46,    67,    68,    69,    70,    71,    72,    73,
      74,    12,    13,    50,    79,    14,    15,    16,    17,    80,
      83,    86,    90,    89,    95,    98,   100,   103,   113,   106,
     105,   116,   112,   117,   118,   119,   122,   120,   135,   121,
     140,   123,   124,   127,   128,   142,   144,   145,   199,   148,
     143,    93,   157,   163,   165,   162,   164,   158,   167,   169,
     166,   171,   173,   175,   214,   185,   125,   187,   172,   191,
     193,   195,   197,   198,   -99,   203,   205,   202,   208,   211,
     212,   207,   213,   229,   215,   209,   217,   218,   216,   221,
     222,   220,   223,   219,   224,   225,   226,   227,   228,   155,
     230,   232,   231,   233,    97,   234,   235,   236,   240,   102,
     238,   159,   239,     0,     0,   132
};

static const yytype_int16 yycheck[] =
{
      19,   105,   117,    28,    80,    13,    39,    38,   112,   123,
      29,    36,    40,   127,    33,    34,    62,    23,    37,    25,
      39,    67,    57,    14,    15,    16,    17,    18,     3,    60,
      61,    62,    63,    64,    65,    66,    67,    70,    71,    72,
      73,    69,    60,    61,    62,    63,    64,    65,    66,    67,
      70,    71,    72,    73,    62,     9,     7,   172,    12,     0,
     164,    10,    11,     3,    83,   169,    62,   143,   103,    72,
      73,     4,   107,   108,   109,   110,     4,    20,    60,    61,
      38,    63,    64,    65,    66,    67,    20,   191,    62,    47,
      48,    20,   117,    51,   198,    53,    54,    55,    56,    57,
      58,    38,    60,    61,    62,    63,    64,    65,    66,    67,
      47,    48,    20,     5,     4,     4,    53,    54,    55,    56,
      57,    58,     3,    60,    61,    62,    63,    64,    65,    66,
      67,    26,    27,     3,    36,    30,    31,    32,    33,    69,
       4,    67,     5,    12,     5,    62,     5,    22,    63,    36,
      38,    67,    38,    71,     6,     4,    40,     8,    63,    19,
       4,    19,     9,    19,     9,    37,     3,     6,   187,     4,
      25,    62,    10,     6,    39,    11,    38,    62,    28,    22,
      37,    59,     4,     4,   203,     4,    40,     4,    71,    20,
       3,     6,     6,    22,     5,     4,    62,    39,     6,     5,
       5,    35,    29,   222,     6,    35,     5,    35,    20,    49,
       4,    52,     5,    39,     5,    63,    13,     4,     4,   122,
      24,     6,    23,     4,    48,     5,     4,     4,     4,    52,
      50,   125,   237,    -1,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    75,    77,     7,     0,     3,    76,    62,     9,
      12,   102,    26,    27,    30,    31,    32,    33,   104,   117,
       4,    10,    11,    79,    80,    90,    91,     4,    20,   105,
      20,    62,   106,   114,   112,   113,    20,   123,    20,   124,
       5,   103,   104,     4,     4,    76,     3,    82,    83,    76,
       3,    93,    94,    95,    99,   106,   104,    38,    47,    48,
      51,    53,    54,    55,    56,    57,    58,    60,    61,    62,
      63,    64,    65,    66,    67,   108,   110,   111,   116,    36,
      69,   104,   104,     4,   106,   104,    67,   125,   104,    12,
       5,    78,    13,    62,    87,     5,    81,    82,    62,   101,
       5,    92,    93,    22,   108,    38,    36,    70,    71,    72,
      73,   118,    38,    63,   111,   104,    67,    71,     6,     4,
       8,    19,    40,    19,     9,    40,    69,    19,     9,   107,
     108,   109,   116,    39,   110,    63,   108,   108,   108,   108,
       4,   110,    37,    25,     3,     6,   106,   125,     4,    14,
      15,    16,    17,    18,    86,    87,    86,    10,    62,   101,
      96,    86,    11,     6,    38,    39,    37,    28,   120,    22,
     111,    59,    71,     4,    84,     4,    60,    61,    63,    64,
      65,    66,    67,    98,   100,     4,   110,     4,   119,   110,
     115,    20,   125,     3,    88,     6,    97,     6,    22,   104,
     121,   122,    39,     4,   110,    62,    85,    35,     6,    35,
     110,     5,     5,    29,   104,     6,    20,     5,    35,    39,
      52,    49,     4,     5,     5,    63,    13,     4,     4,   104,
      24,    23,     6,     4,     5,     4,     4,    89,    50,    88,
       4
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 77 "syntaxique.y"
    {printf("\n\t ___ La Syntaxe Est Correcte ! ___ \n\n");
        YYACCEPT;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 103 "syntaxique.y"
    {insererType(temp);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 104 "syntaxique.y"
    {insererType(temp);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 107 "syntaxique.y"
    { strcpy(temp,"ENTIER");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 108 "syntaxique.y"
    { strcpy(temp,"REEL");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 109 "syntaxique.y"
    { strcpy(temp,"CHAR");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 110 "syntaxique.y"
    { strcpy(temp,"STRING");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 111 "syntaxique.y"
    { strcpy(temp,"BOOL");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 115 "syntaxique.y"
    {inserer((yyvsp[(1) - (3)].str),"idf");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 116 "syntaxique.y"
    {inserer((yyvsp[(1) - (1)].str),"idf");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 119 "syntaxique.y"
    { inserer((yyvsp[(2) - (5)].str),"idf"); insertTable((yyvsp[(2) - (5)].str),"Table",(yyvsp[(4) - (5)].str));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 142 "syntaxique.y"
    {inserer((yyvsp[(2) - (3)].str),"CST");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 142 "syntaxique.y"
    {insererType(temp);insererVal((yyvsp[(2) - (5)].str),(yyvsp[(5) - (5)].str));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 145 "syntaxique.y"
    {strcpy(temp,"REEL"); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 146 "syntaxique.y"
    {strcpy(temp,"ENTIER"); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 147 "syntaxique.y"
    {strcpy(temp,"ENTIER"); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 148 "syntaxique.y"
    {strcpy(temp,"CHAR"); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 149 "syntaxique.y"
    {strcpy(temp,"STRING"); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 150 "syntaxique.y"
    {strcpy(temp,"BOOL"); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 151 "syntaxique.y"
    {strcpy(temp,"BOOL"); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 155 "syntaxique.y"
    {insererType(temp);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 158 "syntaxique.y"
    {inserer((yyvsp[(1) - (3)].str),"CST");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 159 "syntaxique.y"
    {inserer((yyvsp[(1) - (1)].str),"CST");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 180 "syntaxique.y"
    {TypeCheck("AFF",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));checkCST((yyvsp[(2) - (5)].str));quadr("AFF",(yyvsp[(4) - (5)].str),"",(yyvsp[(2) - (5)].str));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 183 "syntaxique.y"
    {checkDeclaration((yyvsp[(1) - (1)].str));  (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 184 "syntaxique.y"
    {
			 checkDeclaration((yyvsp[(1) - (4)].str)); checkOverFlowTab((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));
			 if(atoi((yyvsp[(3) - (4)].str))>tabTaille((yyvsp[(1) - (4)].str))){printf("Erreur semantique : vous avez depassé la taille du tableau !\n");}
	        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 190 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 191 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 194 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 195 "syntaxique.y"
    {TypeCheck("ADD",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));sauv=(char*) generateNameNUM();(yyval.str)=sauv;quadr("ADD",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),sauv);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 196 "syntaxique.y"
    {TypeCheck("DEC",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));sauv=(char*) generateNameNUM();(yyval.str)=sauv;quadr("DEC",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),sauv);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 197 "syntaxique.y"
    {TypeCheck("MUL",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));sauv=(char*) generateNameNUM();(yyval.str)=sauv;quadr("MUL",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),sauv);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 198 "syntaxique.y"
    {TypeCheck("DIV",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));sauv=(char*) generateNameNUM();(yyval.str)=sauv;quadr("DIV",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),sauv);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 199 "syntaxique.y"
    {(yyval.str)=(yyvsp[(2) - (3)].str);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 202 "syntaxique.y"
    {sauv=(char*) generateNameBOOL(); (yyval.str)=sauv;TypeCheck((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));quadr((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str),sauv);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 205 "syntaxique.y"
    {sauv=(char*) generateNameBOOL();(yyval.str)=sauv;TypeCheck((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));quadr((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str),sauv);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 206 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 207 "syntaxique.y"
    {sauv=(char*) generateNameBOOL();(yyval.str)=sauv;quadr("NOT",(yyvsp[(3) - (4)].str),"",sauv);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 210 "syntaxique.y"
    {checkDeclaration((yyvsp[(1) - (1)].str)); (yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 211 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 212 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 213 "syntaxique.y"
    {checkDeclaration((yyvsp[(1) - (4)].str)); (yyval.str)=(yyvsp[(1) - (4)].str); checkOverFlowTab((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 214 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 215 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 216 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 217 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 218 "syntaxique.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 223 "syntaxique.y"
    {push(debWhile,&debWhileP,qc);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 225 "syntaxique.y"
    {quadr("BNZ",itoa(pop(debWhile,&debWhileP),buffer,10),(yyvsp[(7) - (11)].str),"");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 229 "syntaxique.y"
    {quadr("AFF",(yyvsp[(3) - (5)].str),"",(yyvsp[(1) - (5)].str));sauv=(char*) generateNameBOOL(); push(debFOR,&debFORP,qc); quadr("EGG",(yyvsp[(1) - (5)].str),(yyvsp[(5) - (5)].str),sauv);quadr("BNZ","ENDFOR",sauv,"");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 231 "syntaxique.y"
    {quadr("INC","","",(yyvsp[(1) - (11)].str)); quadr("BR",itoa(pop(debFOR,&debFORP),buffer,10),"","");ajour_quad(debFOR[debFORP]+1,1,itoa(qc,buffer,10));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 235 "syntaxique.y"
    {(yyval.str)=strdup("SUP");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 236 "syntaxique.y"
    {(yyval.str)=strdup("SUPE");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 237 "syntaxique.y"
    {strdup("EGG");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 238 "syntaxique.y"
    {(yyval.str)=strdup("DIF");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 239 "syntaxique.y"
    {(yyval.str)=strdup("INFE");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 240 "syntaxique.y"
    {(yyval.str)=strdup("INF");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 241 "syntaxique.y"
    {(yyval.str)=strdup("AND");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 242 "syntaxique.y"
    {(yyval.str)=strdup("OR");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 246 "syntaxique.y"
    {push(sauvIf,&sauvIfP,qc);quadr("BZ","ELSE",(yyvsp[(3) - (3)].str),"");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 247 "syntaxique.y"
    {push(sauvIfFin,&sauvIfFinP,qc);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 253 "syntaxique.y"
    {quadr("BR","FIN","","");ajour_quad(pop(sauvIf,&sauvIfP),1,itoa(qc,buffer,10));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 255 "syntaxique.y"
    {ajour_quad(pop(sauvIfFin,&sauvIfFinP),1,itoa(qc,buffer,10));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 257 "syntaxique.y"
    {ajour_quad(pop(sauvIf,&sauvIfP),1,itoa(qc,buffer,10));;}
    break;



/* Line 1455 of yacc.c  */
#line 2111 "syntaxique.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 278 "syntaxique.y"

main () 
{
	/* initialisation(); */
	yyparse();
	/* afficher(); */
	afficher_qdr();
	optimisation(); 
	afficher();
	afficher_qdr(); 
}
yywrap()
{}
yyerror (char* msg)
{
	printf("\nErreur Syntaxique a la ligne %d et a la colonne %d \n\n",nb_ligne,nbcol);
}
