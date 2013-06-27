/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INPUT = 258,
     BREAK = 259,
     CASE = 260,
     SWITCH = 261,
     PRINT = 262,
     IF = 263,
     WHILE = 264,
     ERROR = 265,
     IDEN = 266,
     STR = 267,
     NUM = 268,
     SEC = 269,
     MIN = 270,
     HR = 271,
     D = 272,
     W = 273,
     BOOLEAN_VALUE = 274,
     BOOLEAN = 275,
     INTEGER = 276,
     OR = 277,
     AND = 278,
     NEQ = 279,
     EQUALS = 280,
     LE = 281,
     GE = 282,
     NOT = 283,
     ELSE = 284
   };
#endif
/* Tokens.  */
#define INPUT 258
#define BREAK 259
#define CASE 260
#define SWITCH 261
#define PRINT 262
#define IF 263
#define WHILE 264
#define ERROR 265
#define IDEN 266
#define STR 267
#define NUM 268
#define SEC 269
#define MIN 270
#define HR 271
#define D 272
#define W 273
#define BOOLEAN_VALUE 274
#define BOOLEAN 275
#define INTEGER 276
#define OR 277
#define AND 278
#define NEQ 279
#define EQUALS 280
#define LE 281
#define GE 282
#define NOT 283
#define ELSE 284




/* Copy the first part of user declarations.  */
#line 1 "hw4.ypp"

	#include "hw4.h"
	#include "bp.hpp"
	#include <iostream>
	#include <stdlib.h>
	#include <string>
	#include <sstream>
	#include "symbolTable.h"
	#include "output.hpp"

	#define YYERROR_VERBOSE 1 
	#define YYDEBUG 1 

	using namespace std;
	extern int yylex();
	extern int yylineno; 
	int yyerror(char * message);
	typedef enum { OP_AND, OP_OR } opType;
	SymbolTable sym;

	enum Arith {
	PLUS,MINUS,MULT,DIV};

	int whiles = 0;
	bool decScope = false;
	list<CaseCond> condList;

	void typeMis(int line);
	bool isInt(Type t);
	bool isTime(Type t);

	void errorMismatch();
	void errorBreak();
	void errorSyn();
	void errorLex();
	void errorUndef(string name);
	void errorDef(string name);


	void assertType(Type type, Type expected);
	void assertType(Type type, Type type2, Type expected);
	void assertTime(Type type);
	void assertAssignable(Type type, Type secondType);
	void assertComparable(Type type, Type secondType);
	Type calculateMultiply(Type type, Type secondType);
	Type calculateDiv(Type type, Type secondType);
	void doIO(string name);
	void addVariable(string name, Type type);
	string addTempVar(Type type);
	string addTempVar(Type type, string val);
	Type getType(string name);
	string convertInt(int number);

	void convert(Type from, string name, Type to);
	void convert(YYSTYPE var, Type type);
	string s(string i);
	string offset(string var_c);

	string emitArith(YYSTYPE first, Arith op, YYSTYPE second);
	string emitOp(YYSTYPE first, string op, YYSTYPE second);
	string emitMult(YYSTYPE first, YYSTYPE second);
	string emitDiv(YYSTYPE first, YYSTYPE second);

	YYSTYPE initListBool(YYSTYPE E,string boolVal);
	YYSTYPE reverseLists(YYSTYPE p);
	YYSTYPE emitRop(string left_c, string op_c, string right_c);
	YYSTYPE emitCompRop (string first_c, char rop, string second_c);


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 233 "hw4.tab.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    34,    32,     2,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,     3,
      28,    23,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    25,    26,
      27,    30,    31,    36,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    13,    14,    19,    23,
      29,    34,    38,    42,    46,    53,    64,    65,    75,    78,
      87,    89,    91,    92,    95,    98,   100,   111,   113,   115,
     117,   119,   121,   123,   125,   127,   131,   135,   139,   143,
     147,   149,   151,   154,   156,   159,   164,   169,   173,   177,
     181,   185,   189,   193,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    -1,    45,    46,    -1,    46,    57,    47,
      -1,    47,    -1,    -1,    39,    48,    46,    40,    -1,    55,
      12,     3,    -1,    55,    12,    23,    56,     3,    -1,    12,
      23,    56,     3,    -1,     8,    12,     3,    -1,     8,    13,
       3,    -1,     4,    12,     3,    -1,     9,    37,    56,    38,
      57,    50,    -1,     9,    37,    56,    38,    57,    50,    41,
      58,    57,    50,    -1,    -1,    57,    10,    37,    56,    38,
      49,    57,    50,    58,    -1,     5,     3,    -1,     7,    37,
      56,    38,    39,    58,    52,    40,    -1,     3,    -1,    11,
      -1,    -1,    51,    47,    -1,    53,    52,    -1,    53,    -1,
      57,     6,    14,    54,    42,    57,    50,    58,     5,     3,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    54,    -1,    22,    -1,    21,    -1,    37,    56,    38,
      -1,    56,    32,    56,    -1,    56,    33,    56,    -1,    56,
      34,    56,    -1,    56,    35,    56,    -1,    12,    -1,    14,
      -1,    14,    54,    -1,    20,    -1,    36,    56,    -1,    56,
      24,    57,    56,    -1,    56,    25,    57,    56,    -1,    56,
      28,    56,    -1,    56,    29,    56,    -1,    56,    30,    56,
      -1,    56,    31,    56,    -1,    56,    27,    56,    -1,    56,
      26,    56,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    87,    90,    91,    94,    94,    95,    96,
      98,   100,   101,   102,   103,   108,   116,   116,   122,   123,
     138,   139,   142,   142,   144,   145,   148,   153,   154,   155,
     156,   157,   160,   161,   162,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   178,   180,   181,   182,
     183,   184,   185,   189,   192
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "';'", "INPUT", "BREAK", "CASE",
  "SWITCH", "PRINT", "IF", "WHILE", "ERROR", "IDEN", "STR", "NUM", "SEC",
  "MIN", "HR", "D", "W", "BOOLEAN_VALUE", "BOOLEAN", "INTEGER", "'='",
  "OR", "AND", "NEQ", "EQUALS", "'<'", "'>'", "LE", "GE", "'+'", "'-'",
  "'*'", "'/'", "NOT", "'('", "')'", "'{'", "'}'", "ELSE", "':'",
  "$accept", "P", "@1", "Statments", "Statment", "@2", "@3", "DecStatment",
  "@4", "CasesList", "CaseStat", "TimeUnit", "Type", "Exp", "M", "N", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    59,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,    61,   277,   278,   279,   280,    60,    62,
     281,   282,    43,    45,    42,    47,   283,    40,    41,   123,
     125,   284,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    48,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    49,    47,    47,    47,
      47,    47,    51,    50,    52,    52,    53,    54,    54,    54,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     1,     0,     4,     3,     5,
       4,     3,     3,     3,     6,    10,     0,     9,     2,     8,
       1,     1,     0,     2,     2,     1,    10,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     2,     4,     4,     3,     3,     3,
       3,     3,     3,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    53,     1,    20,     0,     0,     0,     0,     0,
      21,     0,    27,    28,    29,    30,    31,    34,    33,     6,
      53,     5,    32,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    53,    53,     0,     0,    13,    40,    41,    43,
       0,     0,     0,    11,    12,     0,     0,    53,     4,     8,
       0,     0,    42,    44,     0,    53,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    10,
       7,     0,     0,    35,     0,     0,    52,    51,    47,    48,
      49,    50,    36,    37,    38,    39,    54,    22,     9,    16,
      45,    46,    53,    14,    53,    53,     0,    25,     0,    54,
      23,    22,    19,    24,     0,    53,    54,     0,    22,    17,
       0,    15,    53,    22,    54,     0,     0,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    20,    21,    32,    95,    93,    94,    96,
      97,    22,    23,    42,    24,    92
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
     -94,     4,    79,   -94,   -94,    -6,     7,   -23,     5,   -18,
     -94,    10,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
      28,   -94,   -94,    22,    27,    51,   -94,    -7,    58,    59,
      -7,    -7,    79,    79,     0,    29,   -94,   -94,    34,   -94,
      -7,    -7,   108,   -94,   -94,   123,    78,    24,   -94,   -94,
      -7,    -7,   -94,   -94,   138,   -94,   -94,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    26,   -94,   -94,
     -94,    96,   153,   -94,    -7,    -7,   185,   185,    25,    25,
      25,    25,    -9,    -9,   -94,   -94,   -94,   -94,   -94,   -94,
     167,   177,   -94,    30,    79,   -94,    33,    61,    62,   -94,
     -94,   -94,   -94,   -94,    55,   -94,   -94,    34,   -94,   -94,
      32,   -94,   -94,   -94,   -94,    71,    75,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,    47,   -31,   -94,   -94,   -93,   -94,   -17,
     -94,   -37,   -94,   -19,   -20,   -90
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -54
static const yytype_int8 yytable[] =
{
      33,    52,    48,    49,     3,    37,    25,    38,   106,   105,
      26,    45,    46,    39,    27,   111,   109,    28,    29,    30,
     114,    53,    54,    50,   115,    65,    66,    33,    -3,    40,
      41,    71,    72,    31,    34,    74,    75,    35,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    87,    12,
      13,    14,    15,    16,    36,    90,    91,    63,    64,    65,
      66,    43,    44,   100,    70,    86,    51,   -53,   104,   107,
     110,    99,    98,   102,   112,   101,   116,    98,   117,    47,
     103,    69,     4,     5,     6,   108,     7,     8,     9,     0,
      10,    11,   113,     0,    12,    13,    14,    15,    16,    88,
      17,    18,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,     0,     0,    19,     0,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,    67,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
       0,    68,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,    73,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
       0,    89,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    59,    60,    61,    62,    63,    64,    65,
      66
};

static const yytype_int8 yycheck[] =
{
      20,    38,    33,     3,     0,    12,    12,    14,   101,    99,
       3,    30,    31,    20,    37,   108,   106,    12,    13,    37,
     113,    40,    41,    23,   114,    34,    35,    47,     0,    36,
      37,    50,    51,    23,    12,    55,    56,    10,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    68,    15,
      16,    17,    18,    19,     3,    74,    75,    32,    33,    34,
      35,     3,     3,    94,    40,    39,    37,     6,     6,    14,
     107,    41,    92,    40,    42,    95,     5,    97,     3,    32,
      97,     3,     3,     4,     5,   105,     7,     8,     9,    -1,
      11,    12,   112,    -1,    15,    16,    17,    18,    19,     3,
      21,    22,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    39,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    38,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    38,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    38,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    38,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    28,    29,    30,    31,    32,    33,    34,
      35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,     3,     4,     5,     7,     8,     9,
      11,    12,    15,    16,    17,    18,    19,    21,    22,    39,
      46,    47,    54,    55,    57,    12,     3,    37,    12,    13,
      37,    23,    48,    57,    12,    10,     3,    12,    14,    20,
      36,    37,    56,     3,     3,    56,    56,    46,    47,     3,
      23,    37,    54,    56,    56,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    38,    38,     3,
      40,    56,    56,    38,    57,    57,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    39,    57,     3,    38,
      56,    56,    58,    50,    51,    49,    52,    53,    57,    41,
      47,    57,    40,    52,     6,    58,    50,    14,    57,    58,
      54,    50,    42,    57,    50,    58,     5,     3
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 87 "hw4.ypp"
    {sym.startScope();;}
    break;

  case 3:
#line 87 "hw4.ypp"
    {bp((yyvsp[(2) - (2)]).nextList, next());printBuffer(); sym.endScope();;}
    break;

  case 4:
#line 90 "hw4.ypp"
    {bp((yyvsp[(1) - (3)]).nextList,(yyvsp[(2) - (3)]).quad); (yyval)=(yyvsp[(3) - (3)]); (yyval).breakList=merge((yyvsp[(1) - (3)]).breakList,(yyvsp[(3) - (3)]).breakList);;}
    break;

  case 5:
#line 91 "hw4.ypp"
    {(yyval)=(yyvsp[(1) - (1)]); ;}
    break;

  case 6:
#line 94 "hw4.ypp"
    {sym.startScope();decScope=false;;}
    break;

  case 7:
#line 94 "hw4.ypp"
    {sym.endScope(); (yyval)=(yyvsp[(2) - (4)]);;}
    break;

  case 8:
#line 95 "hw4.ypp"
    {addVariable((yyvsp[(2) - (3)]).text, (yyvsp[(1) - (3)]).type); ;}
    break;

  case 9:
#line 96 "hw4.ypp"
    {assertAssignable((yyvsp[(1) - (5)]).type,(yyvsp[(4) - (5)]).type); addVariable((yyvsp[(2) - (5)]).text, (yyvsp[(1) - (5)]).type); 
				convert((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]).type);  emit(s((yyvsp[(2) - (5)]).text) + '=' + s((yyvsp[(4) - (5)]).text));;}
    break;

  case 10:
#line 98 "hw4.ypp"
    {assertAssignable(getType((yyvsp[(1) - (4)]).text),(yyvsp[(3) - (4)]).type); convert((yyvsp[(3) - (4)]), (yyvsp[(1) - (4)]).type); 
				emit(s((yyvsp[(1) - (4)]).text) + '=' + s((yyvsp[(3) - (4)]).text));;}
    break;

  case 11:
#line 100 "hw4.ypp"
    {doIO((yyvsp[(2) - (3)]).text); emit("print " + s((yyvsp[(2) - (3)]).text));;}
    break;

  case 12:
#line 101 "hw4.ypp"
    {emit("print " + (yyvsp[(2) - (3)]).text);;}
    break;

  case 13:
#line 102 "hw4.ypp"
    {doIO((yyvsp[(2) - (3)]).text); emit("input " + s((yyvsp[(2) - (3)]).text));;}
    break;

  case 14:
#line 103 "hw4.ypp"
    {assertType((yyvsp[(3) - (6)]).type, BOOL); 
				bp((yyvsp[(3) - (6)]).trueList, (yyvsp[(5) - (6)]).quad);
				 (yyval).nextList=merge((yyvsp[(3) - (6)]).falseList,(yyvsp[(6) - (6)]).nextList);
				 (yyval).breakList=(yyvsp[(6) - (6)]).breakList;
				;}
    break;

  case 15:
#line 109 "hw4.ypp"
    {
				assertType((yyvsp[(3) - (10)]).type, BOOL);
				bp((yyvsp[(3) - (10)]).trueList,(yyvsp[(5) - (10)]).quad); 
				bp((yyvsp[(3) - (10)]).falseList,(yyvsp[(9) - (10)]).quad); 
				(yyval).nextList=merge(merge((yyvsp[(8) - (10)]).nextList,(yyvsp[(6) - (10)]).nextList),(yyvsp[(10) - (10)]).nextList);
				(yyval).breakList=merge((yyvsp[(6) - (10)]).breakList,(yyvsp[(10) - (10)]).breakList);
			;}
    break;

  case 16:
#line 116 "hw4.ypp"
    {++whiles;  ;}
    break;

  case 17:
#line 116 "hw4.ypp"
    {
				assertType((yyvsp[(4) - (9)]).type, BOOL); --whiles; 
				(yyval).nextList=merge(merge((yyvsp[(4) - (9)]).falseList,(yyvsp[(8) - (9)]).breakList), (yyvsp[(9) - (9)]).nextList);
				bp((yyvsp[(8) - (9)]).nextList,(yyvsp[(1) - (9)]).quad);
				bp((yyvsp[(4) - (9)]).trueList,(yyvsp[(7) - (9)]).quad);
			;}
    break;

  case 18:
#line 122 "hw4.ypp"
    {if (whiles == 0) errorBreak(); (yyval).breakList=makelist(next()); emit("goto "); ;}
    break;

  case 19:
#line 123 "hw4.ypp"
    { //goto before and after
				assertTime((yyvsp[(3) - (8)]).type); 
				(yyvsp[(3) - (8)]).nextList = merge((yyvsp[(6) - (8)]).nextList, (yyvsp[(3) - (8)]).nextList);
				bp((yyvsp[(3) - (8)]).nextList, next());
				while (!condList.empty()){
					CaseCond c= condList.front();
					condList.pop_front();
					string tempVar = addTempVar(c.type, c.val);
					convert(c.type, tempVar.c_str(), (yyvsp[(3) - (8)]).type);
					emit("if " + s(tempVar.c_str()) + "==" + s((yyvsp[(3) - (8)]).text) + " goto " + convertInt(c.quad));
				}

				(yyval).nextList=merge((yyvsp[(7) - (8)]).nextList, makelist(next()));
				emit("goto ");
				;}
    break;

  case 20:
#line 138 "hw4.ypp"
    {errorSyn();;}
    break;

  case 21:
#line 139 "hw4.ypp"
    {errorLex(); ;}
    break;

  case 22:
#line 142 "hw4.ypp"
    { decScope=true;;}
    break;

  case 23:
#line 142 "hw4.ypp"
    { decScope=false; (yyval)=(yyvsp[(1) - (2)]);;}
    break;

  case 24:
#line 144 "hw4.ypp"
    {(yyval).nextList= merge((yyvsp[(1) - (2)]).nextList,(yyvsp[(2) - (2)]).nextList);;}
    break;

  case 25:
#line 145 "hw4.ypp"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 26:
#line 148 "hw4.ypp"
    {
				condList.push_back(CaseCond((yyvsp[(3) - (10)]).text,(yyvsp[(4) - (10)]).type, (yyvsp[(6) - (10)]).quad)); (yyval).nextList = merge((yyvsp[(7) - (10)]).nextList, (yyvsp[(8) - (10)]).nextList);
			;}
    break;

  case 27:
#line 153 "hw4.ypp"
    {(yyval).type = SECOND;;}
    break;

  case 28:
#line 154 "hw4.ypp"
    {(yyval).type = MINUTE;;}
    break;

  case 29:
#line 155 "hw4.ypp"
    {(yyval).type = HOUR;;}
    break;

  case 30:
#line 156 "hw4.ypp"
    {(yyval).type = DAY;;}
    break;

  case 31:
#line 157 "hw4.ypp"
    {(yyval).type = WEEK;;}
    break;

  case 32:
#line 160 "hw4.ypp"
    {(yyval).type = (yyvsp[(1) - (1)]).type;;}
    break;

  case 33:
#line 161 "hw4.ypp"
    {(yyval).type = INT;;}
    break;

  case 34:
#line 162 "hw4.ypp"
    {(yyval).type = BOOL;;}
    break;

  case 35:
#line 166 "hw4.ypp"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 36:
#line 167 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).text = emitArith((yyvsp[(1) - (3)]),PLUS,(yyvsp[(3) - (3)])); (yyval).type=getType((yyval).text);;}
    break;

  case 37:
#line 168 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).text = emitArith((yyvsp[(1) - (3)]),MINUS,(yyvsp[(3) - (3)])); (yyval).type=getType((yyval).text);;}
    break;

  case 38:
#line 169 "hw4.ypp"
    {(yyval).text = emitArith((yyvsp[(1) - (3)]),MULT,(yyvsp[(3) - (3)])); (yyval).type=getType((yyval).text);;}
    break;

  case 39:
#line 170 "hw4.ypp"
    {(yyval).text = emitArith((yyvsp[(1) - (3)]),DIV,(yyvsp[(3) - (3)])); (yyval).type=getType((yyval).text);;}
    break;

  case 40:
#line 171 "hw4.ypp"
    {(yyval).type = getType((yyvsp[(1) - (1)]).text); (yyval).text=(yyvsp[(1) - (1)]).text;;}
    break;

  case 41:
#line 172 "hw4.ypp"
    {(yyval).type = INT; (yyval).text = addTempVar(INT, (yyvsp[(1) - (1)]).text);;}
    break;

  case 42:
#line 173 "hw4.ypp"
    {(yyval).type = (yyvsp[(2) - (2)]).type; (yyval).text = addTempVar((yyvsp[(2) - (2)]).type, (yyvsp[(1) - (2)]).text);;}
    break;

  case 43:
#line 174 "hw4.ypp"
    {(yyval).type = BOOL; (yyval).text = addTempVar(BOOL, (yyvsp[(1) - (1)]).text); (yyval)=initListBool((yyval),(yyvsp[(1) - (1)]).text); ;}
    break;

  case 44:
#line 175 "hw4.ypp"
    {assertType((yyvsp[(2) - (2)]).type, BOOL); (yyval) = (yyvsp[(2) - (2)]); (yyval)=reverseLists((yyval));;}
    break;

  case 45:
#line 176 "hw4.ypp"
    {assertType((yyvsp[(1) - (4)]).type, (yyvsp[(3) - (4)]).type, BOOL); (yyval).type = BOOL; 
				bp((yyvsp[(1) - (4)]).falseList, (yyvsp[(3) - (4)]).quad);(yyval).trueList=merge((yyvsp[(1) - (4)]).trueList,(yyvsp[(4) - (4)]).trueList);(yyval).falseList=(yyvsp[(4) - (4)]).falseList;;}
    break;

  case 46:
#line 178 "hw4.ypp"
    {assertType((yyvsp[(1) - (4)]).type, (yyvsp[(3) - (4)]).type, BOOL); (yyval).type = BOOL;
				 (yyval).falseList=merge((yyvsp[(1) - (4)]).falseList,(yyvsp[(4) - (4)]).falseList); (yyval).trueList=(yyvsp[(4) - (4)]).trueList; bp((yyvsp[(1) - (4)]).trueList,(yyvsp[(3) - (4)]).quad);;}
    break;

  case 47:
#line 180 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).type = BOOL; (yyval)=emitRop((yyvsp[(1) - (3)]).text, "<", (yyvsp[(3) - (3)]).text);;}
    break;

  case 48:
#line 181 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).type = BOOL; (yyval)=emitRop((yyvsp[(1) - (3)]).text, ">", (yyvsp[(3) - (3)]).text);;}
    break;

  case 49:
#line 182 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).type = BOOL; (yyval)=emitCompRop((yyvsp[(1) - (3)]).text, '<' , (yyvsp[(3) - (3)]).text); ;}
    break;

  case 50:
#line 183 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).type = BOOL; (yyval)=emitCompRop((yyvsp[(1) - (3)]).text, '>' , (yyvsp[(3) - (3)]).text);;}
    break;

  case 51:
#line 184 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).type = BOOL; (yyval)=emitRop((yyvsp[(1) - (3)]).text, "==", (yyvsp[(3) - (3)]).text);;}
    break;

  case 52:
#line 185 "hw4.ypp"
    {assertComparable((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type); (yyval).type = BOOL; (yyval)=emitRop((yyvsp[(1) - (3)]).text, "!=", (yyvsp[(3) - (3)]).text);;}
    break;

  case 53:
#line 189 "hw4.ypp"
    {(yyval).quad = next();;}
    break;

  case 54:
#line 192 "hw4.ypp"
    {(yyval).quad = next(); emit("goto "); (yyval).nextList=makelist((yyval).quad);;}
    break;


/* Line 1267 of yacc.c.  */
#line 1842 "hw4.tab.cpp"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 195 "hw4.ypp"


main() { 
	yydebug = 0; 
	 yyparse(); 
}

int yyerror(char * s) { 
 	output::errorSyn(yylineno);
 	exit(1); 
 	return 0; 
} 

void typeCheck(Type t1, Type t2){
	if (t1!=t2){
	   output::errorMismatch(yylineno);
	   exit(1);
	}

}

bool isInt(Type t){
	return t==INT;
}

bool isTime(Type t){
	switch (t){
		case(MINUTE):
		case(SECOND):
		case(HOUR):
		case(DAY):
		case(WEEK): return true;
	}
	return false;
}

void assertTime(Type type){
	if (!isTime(type)) errorMismatch();
}

void assertType(Type type, Type expected){
	if (type != expected) errorMismatch();
}

void assertType(Type type, Type type2, Type expected){
	assertType(type, expected);
	assertType(type2, expected);
}


void assertAssignable(Type type, Type secondType){
	if (type == secondType) return;
	assertComparable(type,secondType);
}

void assertComparable(Type type, Type secondType){
	if (isInt(type)){
		if(!isInt(secondType)) errorMismatch();
		return;
	}
	if (isTime(type)){
		if (!isTime(secondType)) errorMismatch();
		return;
	}
	errorMismatch(); //TODO is this really a mismatch?
}

Type calculateMultiply(Type type, Type secondType){
	if (isTime(type)){
		if (isInt(secondType))
			return type;
		errorMismatch();
	}
	if (isInt(type)){
		if (isTime(secondType))
			return secondType;
		if (isInt(secondType))
			return INT;
	}
	errorMismatch();
	return INT;
}

Type calculateDiv(Type type, Type secondType){
	if (isInt(secondType)) 
		if (isInt(type) || isTime(type)) return type;
	if (isTime(type) && isTime(secondType)) return INT;
	errorMismatch();
	return INT;
}

string emitArith(YYSTYPE first, Arith op, YYSTYPE second){
	switch (op){
		case(PLUS): return emitOp(first,"+", second); 
		case(MINUS): return emitOp(first,"-", second); 
		case(MULT): return emitMult(first, second); 
		case(DIV): return emitDiv(first, second); 
	}
}

string emitOp(YYSTYPE first, string op, YYSTYPE second){
	string res = addTempVar(first.type);
	convert(second, first.type);
	emit(s(res) + "=" + s(first.text) + op + s(second.text));
	return res;
}

string emitMult(YYSTYPE first, YYSTYPE second){
	string res = addTempVar(calculateMultiply(first.type,second.type));
	emit(s(res) + '=' + s(first.text) + '*' + s(second.text));
	return res;
}

string emitDiv(YYSTYPE first, YYSTYPE second) {
	string res = addTempVar(calculateDiv(first.type, second.type));
	if (isTime(first.type) && isTime(second.type)) convert (second, first.type);
	emit(s(res) + '=' + s(first.text) + '/' + s(second.text));
	return res;

	
}

void convert(Type from, string name, Type to){
	if(from==to) return;
	if (from>to) 
		emit(s(name)+ "=" + s(name) + "*" + convertInt(from/to));

	else 
		emit(s(name)+ "=" + s(name) + "/" + convertInt(to/from));

}

void convert(YYSTYPE var, Type type){
	convert(var.type, var.text, type);
}



string s(string i){
	return "s[" + offset(i) + "]";
}

string offset(string var){
	return convertInt(sym.getOffset(var));
}

void doIO(string name){
	if (!sym.isDefined(name)) errorUndef(name);
	Type type = sym.getType(name);
	if(!isInt(type) && !isTime(type)) errorMismatch();
}

void addVariable(string name, Type type){
	if (decScope==true) sym.startScope();
	if (sym.addVariable(name, type) == false)
	errorDef(name);
	if (decScope==true) sym.endScope();
}

string addTempVar(Type type, string val){
				 string name = newTemp();
				 sym.addVariable(name, type); 
				 emit(s(name)+"="+val);
				 return name;
}

string addTempVar(Type type){
				 string name = newTemp();
				 sym.addVariable(name, type); 
				 return name;
}

Type getType(string name){
	if (!sym.isDefined(name)) errorUndef(name);
	return sym.getType(name);
}


string convertInt(int number){
   stringstream ss;
   ss << number;
   return ss.str();
}


void errorMismatch(){
	output::errorMismatch(yylineno);
	exit(1);
}

void errorBreak(){
	output::errorUnexpectedBreak(yylineno);
	exit(1);
}

void errorUndef(string name){
	output::errorUndef(yylineno, name.c_str());
	exit(1);
}

void errorDef(string name){
	output::errorDef(yylineno, name.c_str());
	exit(1);
}

void errorLex(){
	output::errorLex(yylineno);
	exit(1);
}

void errorSyn(){
	output::errorSyn(yylineno);
	exit(1);
}



YYSTYPE initListBool(YYSTYPE E,string boolVal){
	if (boolVal.compare("1") == 0) E.trueList=makelist(next());
	else E.falseList=makelist(next());
	emit("goto ");
	return E;
}

YYSTYPE reverseLists(YYSTYPE p){
	list<int> tempList = p.trueList;
	p.trueList=p.falseList;
	p.falseList=tempList;
	return p;
}

YYSTYPE emitRop(string left, string op, string right){
	YYSTYPE retVal;
	retVal.type = BOOL;
	retVal.trueList = makelist(next());
	emit("if " + s(left) + " " + op + " " + s(right) + " goto ");
	retVal.falseList = makelist(next());
	emit("goto ");
	return retVal;
}


YYSTYPE emitCompRop (string left, char rop, string right){
	YYSTYPE retVal;
	retVal.type = BOOL;
	retVal.trueList=makelist(next());
	emit("if " + s(left) + " "+ rop + " " + s(right) + " goto ");
	list<int> tempList = makelist(next());
	emit("if " + s(left) + " "+ "==" + " " + s(right) + " goto ");
	retVal.trueList=merge(retVal.trueList,tempList);
	retVal.falseList=makelist(next());
	emit("goto ");
	return retVal;
}

