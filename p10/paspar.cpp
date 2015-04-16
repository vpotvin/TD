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
     BEGAN = 258,
     END = 259,
     ID = 260,
     PLUS = 261,
     MINUS = 262,
     STAR = 263,
     SLASH = 264,
     ASSIGN = 265,
     PERIOD = 266,
     COMMA = 267,
     SEMICOLON = 268,
     COLON = 269,
     EQU = 270,
     NEQ = 271,
     LES = 272,
     LEQ = 273,
     GRT = 274,
     GEQ = 275,
     LPAREN = 276,
     RPAREN = 277,
     LBRACKET = 278,
     RBRACKET = 279,
     RANGE = 280,
     RESERVE_WORDS = 281,
     AND = 282,
     ARRAY = 283,
     DIV = 284,
     DO = 285,
     ELSE = 286,
     FUNCTION = 287,
     IF = 288,
     MOD = 289,
     NOT = 290,
     OF = 291,
     OR = 292,
     PROCEDURE = 293,
     PROGRAM = 294,
     THEN = 295,
     TO = 296,
     TYPE = 297,
     VAR = 298,
     COMMENT = 299,
     CHRLIT = 300,
     REALIT = 301,
     INTLIT = 302,
     WHILE = 303,
     REGULAR_EXPRESSIONS = 304,
     TOKEN_END = 305
   };
#endif
/* Tokens.  */
#define BEGAN 258
#define END 259
#define ID 260
#define PLUS 261
#define MINUS 262
#define STAR 263
#define SLASH 264
#define ASSIGN 265
#define PERIOD 266
#define COMMA 267
#define SEMICOLON 268
#define COLON 269
#define EQU 270
#define NEQ 271
#define LES 272
#define LEQ 273
#define GRT 274
#define GEQ 275
#define LPAREN 276
#define RPAREN 277
#define LBRACKET 278
#define RBRACKET 279
#define RANGE 280
#define RESERVE_WORDS 281
#define AND 282
#define ARRAY 283
#define DIV 284
#define DO 285
#define ELSE 286
#define FUNCTION 287
#define IF 288
#define MOD 289
#define NOT 290
#define OF 291
#define OR 292
#define PROCEDURE 293
#define PROGRAM 294
#define THEN 295
#define TO 296
#define TYPE 297
#define VAR 298
#define COMMENT 299
#define CHRLIT 300
#define REALIT 301
#define INTLIT 302
#define WHILE 303
#define REGULAR_EXPRESSIONS 304
#define TOKEN_END 305




/* Copy the first part of user declarations.  */
#line 1 "paspar.y"

//c++ includes
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//app inlude file
#include "paslex.h"
#include "paspar.h"

//symbol table
#include "List.h"
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"

//semantic include files
#include "program.h"
#include "program_head.h"
#include "subprogram_head.h"
#include "subprogram_declaration.h"
#include "standard_type.h"
#include "subprogram_parameters.h"
#include "variable_declarations.h"
#include "type.h"
#include "parameter_list.h"
#include "identifier_list.h"
#include "factor.h"
#include "term.h"
#include "expression.h"
#include "expression_list.h"
#include "procedure_statement.h"
#include "variable.h"
#include "compound_statement.h"
#include "statement.h"
#include "statement_list.h"
#include "optional_statements.h"
//---------------------------------------------------------------------
//Semantic helper include files
//---------------------------------------------------------------------
#include "ToString.h"
#include "String.h"
#include "PCode.h"
#include "Exp.h"

#include "simple_expression.h"




typedef string st;



//functions
void yyerror(const char* msg); 
int yylex(void);
int yywrap(){
	return 1;
}
//externals
extern int yylex ();
extern void yyerror ( char *);
extern int line;
extern int col;
extern Label L;
extern ofstream o;

//global varibles defined in paspar.y
SymbolTable ST;  //The SymbolTable



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
typedef union YYSTYPE
#line 81 "paspar.y"
{
  string* token;
  List<string>* slist;
  Typ* typ;
  List<VariableSymbol*>* varlist;
  Exp* exp;
  List<Exp*>* explist;
}
/* Line 193 of yacc.c.  */
#line 286 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 299 "y.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    12,    15,    18,    19,    23,    25,
      27,    31,    32,    39,    41,    50,    52,    53,    57,    61,
      67,    72,    73,    77,    81,    87,    91,    92,    94,    96,
     100,   104,   106,   108,   115,   120,   122,   127,   129,   134,
     136,   140,   142,   146,   148,   150,   152,   154,   156,   158,
     160,   163,   167,   169,   171,   173,   175,   177,   179,   183,
     185,   187,   189,   191,   193,   195,   200,   205,   209,   212,
     214,   216
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    54,    55,    -1,    39,     5,    56,
      13,    -1,    59,    62,    -1,    67,    11,    -1,    -1,    21,
      57,    22,    -1,    58,    -1,     5,    -1,    58,    12,     5,
      -1,    -1,    59,    43,    58,    14,    60,    13,    -1,    61,
      -1,    28,    23,    47,    25,    47,    24,    36,    61,    -1,
       5,    -1,    -1,    62,    63,    13,    -1,    64,    59,    67,
      -1,    32,     5,    65,    14,    61,    -1,    38,     5,    65,
      13,    -1,    -1,    21,    66,    22,    -1,    58,    14,    60,
      -1,    66,    13,    58,    14,    60,    -1,     3,    68,     4,
      -1,    -1,    69,    -1,    70,    -1,    69,    13,    70,    -1,
      71,    10,    74,    -1,    72,    -1,    67,    -1,    33,    74,
      40,    70,    31,    70,    -1,    48,    74,    30,    70,    -1,
       5,    -1,     5,    23,    74,    24,    -1,     5,    -1,     5,
      21,    73,    22,    -1,    74,    -1,    73,    12,    74,    -1,
      76,    -1,    76,    75,    76,    -1,    15,    -1,    16,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    79,    -1,
      77,    79,    -1,    76,    78,    79,    -1,     6,    -1,     7,
      -1,     6,    -1,     7,    -1,    37,    -1,    81,    -1,    79,
      80,    81,    -1,     8,    -1,     9,    -1,    29,    -1,    34,
      -1,    27,    -1,     5,    -1,     5,    23,    74,    24,    -1,
       5,    21,    73,    22,    -1,    21,    74,    22,    -1,    35,
      81,    -1,    47,    -1,    46,    -1,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   172,   178,   183,   189,   193,   198,   204,
     212,   221,   225,   231,   237,   243,   250,   254,   259,   265,
     271,   278,   283,   289,   295,   301,   308,   313,   319,   325,
     331,   337,   343,   349,   355,   361,   367,   373,   379,   385,
     391,   397,   403,   409,   414,   419,   424,   429,   434,   439,
     445,   451,   457,   462,   467,   472,   477,   482,   488,   494,
     499,   504,   509,   514,   519,   525,   531,   537,   543,   549,
     555,   561
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGAN", "END", "ID", "PLUS", "MINUS",
  "STAR", "SLASH", "ASSIGN", "PERIOD", "COMMA", "SEMICOLON", "COLON",
  "EQU", "NEQ", "LES", "LEQ", "GRT", "GEQ", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "RANGE", "RESERVE_WORDS", "AND", "ARRAY", "DIV", "DO",
  "ELSE", "FUNCTION", "IF", "MOD", "NOT", "OF", "OR", "PROCEDURE",
  "PROGRAM", "THEN", "TO", "TYPE", "VAR", "COMMENT", "CHRLIT", "REALIT",
  "INTLIT", "WHILE", "REGULAR_EXPRESSIONS", "TOKEN_END", "$accept",
  "program", "program_head", "program_declarations", "program_body",
  "program_parameters", "program_parameter_list", "identifier_list",
  "declarations", "type", "standard_type", "subprogram_declarations",
  "subprogram_declaration", "subprogram_head", "subprogram_parameters",
  "parameter_list", "compound_statement", "optional_statements",
  "statement_list", "statement", "variable", "procedure_statement",
  "expression_list", "expression", "relop", "simple_expression", "sign",
  "addop", "term", "mulop", "factor", 0
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
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     2,     2,     0,     3,     1,     1,
       3,     0,     6,     1,     8,     1,     0,     3,     3,     5,
       4,     0,     3,     3,     5,     3,     0,     1,     1,     3,
       3,     1,     1,     6,     4,     1,     4,     1,     4,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     2,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    11,     6,     1,     0,    16,     0,     0,
      26,     2,     0,     0,     4,     9,     0,     8,     3,    37,
       0,     0,    32,     0,    27,    28,     0,    31,     5,     0,
       0,     0,     0,    11,     7,     0,     0,     0,    64,    52,
      53,     0,     0,    71,    70,    69,     0,    41,     0,    49,
      57,     0,    25,     0,     0,     0,    21,    21,    17,     0,
      10,     0,    39,     0,     0,     0,     0,    68,     0,    54,
      55,    43,    44,    45,    46,    47,    48,    56,     0,     0,
      50,    59,    60,    63,    61,    62,     0,     0,    29,    30,
      15,     0,     0,    13,     0,     0,     0,    18,     0,    38,
      36,     0,     0,    67,     0,    42,    51,    58,    34,     0,
      12,     0,     0,     0,    20,    40,    66,    65,     0,     0,
       0,     0,    22,    19,    33,     0,    23,     0,     0,     0,
       0,    24,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    11,     9,    16,    17,     7,    92,
      93,    14,    32,    33,    95,   112,    22,    23,    24,    25,
      26,    27,    61,    62,    78,    47,    48,    79,    49,    86,
      50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int8 yypact[] =
{
      -2,    21,    63,   -99,    23,   -99,    64,    25,    82,    75,
       3,   -99,    66,    82,    44,   -99,    67,    78,   -99,     6,
       7,     7,   -99,    87,    80,   -99,    84,   -99,   -99,    52,
      90,    91,    85,   -99,   -99,    92,     7,     7,    57,   -99,
     -99,     7,    12,   -99,   -99,   -99,    59,    55,    12,    16,
     -99,    70,   -99,     3,     7,     2,    81,    81,   -99,    17,
     -99,     9,   -99,    77,     7,     7,    83,   -99,     3,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     7,    12,
      16,   -99,   -99,   -99,   -99,   -99,    12,     3,   -99,   -99,
     -99,    86,    93,   -99,    82,    89,    94,   -99,     7,   -99,
     -99,    43,    88,   -99,    73,     4,    16,   -99,   -99,    68,
     -99,    71,    10,   105,   -99,   -99,   -99,   -99,     3,    95,
       2,    82,   -99,   -99,   -99,    69,   -99,    72,    97,     2,
      96,   -99,   105,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -13,    98,   -81,
     -98,   -99,   -99,   -99,    54,   -99,    -3,   -99,   -99,   -49,
     -99,   -99,    49,   -19,   -99,    36,   -99,   -99,   -39,   -99,
     -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -36
static const yytype_int16 yytable[] =
{
      29,    46,    51,    12,    88,    67,    10,    90,    19,    80,
      69,    70,    38,    39,    40,   123,   -35,    38,    63,   104,
      10,    98,    66,   121,    81,    82,     4,    36,    41,    37,
      91,    99,   122,    41,   133,    89,    20,     1,   108,   126,
     106,    77,    42,    83,     8,    84,   102,    42,   131,   107,
      85,    21,    43,    44,    45,    98,    97,    43,    44,    45,
      13,    69,    70,     5,    35,   116,    55,    10,    13,   124,
      71,    72,    73,    74,    75,    76,    30,    28,    64,   115,
      65,   111,    31,    35,    35,   120,   129,    15,    18,    34,
      35,    52,    77,    53,    54,    56,    57,    60,    58,    68,
      87,   100,    94,   113,   118,   103,   110,   114,   127,   109,
      90,    96,   117,   101,   105,   119,   128,     0,     0,     0,
     125,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,   132
};

static const yytype_int16 yycheck[] =
{
      13,    20,    21,     6,    53,    42,     3,     5,     5,    48,
       6,     7,     5,     6,     7,   113,    10,     5,    37,    68,
       3,    12,    41,    13,     8,     9,     5,    21,    21,    23,
      28,    22,    22,    21,   132,    54,    33,    39,    87,   120,
      79,    37,    35,    27,    21,    29,    65,    35,   129,    86,
      34,    48,    45,    46,    47,    12,    59,    45,    46,    47,
      43,     6,     7,     0,    12,    22,    14,     3,    43,   118,
      15,    16,    17,    18,    19,    20,    32,    11,    21,    98,
      23,    94,    38,    12,    12,    14,    14,     5,    13,    22,
      12,     4,    37,    13,    10,     5,     5,     5,    13,    40,
      30,    24,    21,    14,    31,    22,    13,    13,   121,    23,
       5,    57,    24,    64,    78,    47,    47,    -1,    -1,    -1,
      25,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    52,    53,     5,     0,    54,    59,    21,    56,
       3,    55,    67,    43,    62,     5,    57,    58,    13,     5,
      33,    48,    67,    68,    69,    70,    71,    72,    11,    58,
      32,    38,    63,    64,    22,    12,    21,    23,     5,     6,
       7,    21,    35,    45,    46,    47,    74,    76,    77,    79,
      81,    74,     4,    13,    10,    14,     5,     5,    13,    59,
       5,    73,    74,    74,    21,    23,    74,    81,    40,     6,
       7,    15,    16,    17,    18,    19,    20,    37,    75,    78,
      79,     8,     9,    27,    29,    34,    80,    30,    70,    74,
       5,    28,    60,    61,    21,    65,    65,    67,    12,    22,
      24,    73,    74,    22,    70,    76,    79,    81,    70,    23,
      13,    58,    66,    14,    13,    74,    22,    24,    31,    47,
      14,    13,    22,    61,    70,    25,    60,    58,    47,    14,
      24,    60,    36,    61
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
#line 167 "paspar.y"
    {
	o << "#001 Program->program_head program_declarations program_body" << endl;
	program(); 
}
    break;

  case 3:
#line 173 "paspar.y"
    {
	o << "#002 program_head->PROGRAM ID program_parameters" << endl;
	program_head(*(yyvsp[(2) - (4)].token));
}
    break;

  case 4:
#line 179 "paspar.y"
    {
	o << "#003 program_declarations->declarations subprogram_declarations" << endl;
}
    break;

  case 5:
#line 184 "paspar.y"
    {
	o <<"#004 program_body->compound_statement ." << endl; 
}
    break;

  case 6:
#line 189 "paspar.y"
    {
	o <<"#005 program_parameters -> Empty" << endl;
}
    break;

  case 7:
#line 194 "paspar.y"
    {
	o << "#006 program_parameters->( program_parameter_list )" << endl;
}
    break;

  case 8:
#line 199 "paspar.y"
    {
	o << "#007 program_parameter_list -> identifier_list" << endl; //(" << (*$1) << ")
}
    break;

  case 9:
#line 205 "paspar.y"
    {
	o << "#008 identifier_list->ID(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl;
	(yyval.slist)=identifier_list((yyvsp[(1) - (1)].token));
	//$$=new List<string>;
   	//$$->Insert(*$1);
}
    break;

  case 10:
#line 213 "paspar.y"
    {
	o << "#009 identifier_list -> identifier_list , ID(" << (*(yyvsp[(3) - (3)].token)) << ")" << endl;
	(yyval.slist)=identifier_list((yyvsp[(1) - (3)].slist),(yyvsp[(3) - (3)].token));
	//$1->Insert(*$3);
   	//$$=$1;
}
    break;

  case 11:
#line 221 "paspar.y"
    {
	o << "#010 declarations->Empty" << endl;
}
    break;

  case 12:
#line 226 "paspar.y"
    {
	o << "#011 declarations->declarations VAR identifier_list: type ;" << endl; //"<< (*$3) << "
	variable_declarations((yyvsp[(3) - (6)].slist),(yyvsp[(5) - (6)].typ));
}
    break;

  case 13:
#line 232 "paspar.y"
    {
	o << "#012 type->standard_type" << endl;
        (yyval.typ)=type((yyvsp[(1) - (1)].typ));
}
    break;

  case 14:
#line 238 "paspar.y"
    {
	o << "#013 type->ARRAY[INTLIT .. INTLIT] of standard_type" << endl;
        (yyval.typ)=type(*(yyvsp[(3) - (8)].token),*(yyvsp[(5) - (8)].token),(yyvsp[(8) - (8)].typ));
}
    break;

  case 15:
#line 244 "paspar.y"
    {
	o << "#014 standard_type -> ID(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl;
        (yyval.typ)=standard_type(*(yyvsp[(1) - (1)].token));
}
    break;

  case 16:
#line 250 "paspar.y"
    {
	o << "#015 subprogram_declarations->Empty" << endl;
}
    break;

  case 17:
#line 255 "paspar.y"
    {
	o << "#016 subprogram_declarations->subprogram_declarations subprogram_declarations;" << endl;
}
    break;

  case 18:
#line 260 "paspar.y"
    {
	o << "#017 subprogram_declarations->subprogram_head declarations compound_statement" << endl;
	subprogram_declaration();
}
    break;

  case 19:
#line 266 "paspar.y"
    {
	o << "#018 subprogram_head->FUNCTION ID(" << (*(yyvsp[(2) - (5)].token)) <<")  subprogram_parameters : standard_type" << endl;
	subprogram_head(*(yyvsp[(2) - (5)].token),(yyvsp[(3) - (5)].varlist),(yyvsp[(5) - (5)].typ));
}
    break;

  case 20:
#line 272 "paspar.y"
    {
	o << "#019 subprogram_head->PROCEDURE ID(" << (*(yyvsp[(2) - (4)].token)) << ") subprogram_parameters ;" << endl;
	subprogram_head(*(yyvsp[(2) - (4)].token),(yyvsp[(3) - (4)].varlist));
}
    break;

  case 21:
#line 278 "paspar.y"
    {
	o << "#020 subprogram_parameters->Empty" << endl;
	(yyval.varlist)=subprogram_parameters();
}
    break;

  case 22:
#line 284 "paspar.y"
    {
	o << "#021 subprogram_parameters->( parameter_list )" << endl;
	(yyval.varlist)=subprogram_parameters((yyvsp[(2) - (3)].varlist));
}
    break;

  case 23:
#line 290 "paspar.y"
    {
	o << "#022 parameter_list->identifier_list: type" << endl; //" << (*$1) << " 
	(yyval.varlist)=parameter_list((yyvsp[(1) - (3)].slist),(yyvsp[(3) - (3)].typ));
}
    break;

  case 24:
#line 296 "paspar.y"
    {
	o << "#023 parameter_list-> parameter_list ; identifier_list : type" << endl; //" << (*$3) << "
	(yyval.varlist)=parameter_list((yyvsp[(1) - (5)].varlist),(yyvsp[(3) - (5)].slist),(yyvsp[(5) - (5)].typ));
}
    break;

  case 25:
#line 302 "paspar.y"
    {
	o << "#024 compound_statement->BEGIN optional_statements END" << endl;
    (yyval.explist)=Compound_statement((yyvsp[(2) - (3)].explist));
}
    break;

  case 26:
#line 308 "paspar.y"
    {
	o << "#025 optional_statements->Empty" << endl;
    (yyval.explist)=Optional_statements();
}
    break;

  case 27:
#line 314 "paspar.y"
    {
	o << "#026 optional_statements->statement_list" << endl;
    (yyval.explist)=Statement_list((yyvsp[(1) - (1)].explist));
}
    break;

  case 28:
#line 320 "paspar.y"
    {
	o << "#027 statement_list->statement" << endl;
    (yyval.explist)=Statement_list((yyvsp[(1) - (1)].explist));
}
    break;

  case 29:
#line 326 "paspar.y"
    {
	o << "#028 statement_list->statement_list ; statement" << endl;
    (yyval.explist)=Statement_list((yyvsp[(1) - (3)].explist),(yyvsp[(3) - (3)].explist));
}
    break;

  case 30:
#line 332 "paspar.y"
    {
	o << "#029 statement->variable := expression" << endl;
    (yyval.explist)=statement((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));
}
    break;

  case 31:
#line 338 "paspar.y"
    {
	o << "#030 statement->procedure_statement" << endl;
    (yyval.explist)=statement((yyvsp[(1) - (1)].exp));
}
    break;

  case 32:
#line 344 "paspar.y"
    {
	o << "#031 statement->compound_statement" << endl;
    (yyval.explist)=statement((yyvsp[(1) - (1)].explist));
}
    break;

  case 33:
#line 350 "paspar.y"
    {
	o << "#032 statement->IF expression THEN statement ELSE statement" << endl;
    (yyval.explist)=statement((yyvsp[(2) - (6)].exp),(yyvsp[(4) - (6)].explist),(yyvsp[(6) - (6)].explist));
}
    break;

  case 34:
#line 356 "paspar.y"
    {
	o << "#033 statement->WHILE expression DO statement" << endl;
    (yyval.explist)=statement((yyvsp[(2) - (4)].exp),(yyvsp[(4) - (4)].explist));
}
    break;

  case 35:
#line 362 "paspar.y"
    {
	o << "#034 VARIABLE->ID(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl; 
	(yyval.exp)=variable((yyvsp[(1) - (1)].token));
}
    break;

  case 36:
#line 368 "paspar.y"
    {
	o << "#035 VARIABLE->ID(" << (*(yyvsp[(1) - (4)].token)) << ")[ expression ]" << endl; 
	(yyval.exp)=variable((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].exp));
}
    break;

  case 37:
#line 374 "paspar.y"
    {
	o << "#036 procedure_statement->ID(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl;
		(yyval.exp)=procedure_statement((yyvsp[(1) - (1)].token));
}
    break;

  case 38:
#line 380 "paspar.y"
    {
	o << "#037 procedure_statement->ID(" << (*(yyvsp[(1) - (4)].token)) <<")( expression_list )" << endl;
		(yyval.exp)=procedure_statement((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].explist));
}
    break;

  case 39:
#line 386 "paspar.y"
    {
	o << "#038 expression_list->expression" << endl;
		(yyval.explist)=expression_list((yyvsp[(1) - (1)].exp));
}
    break;

  case 40:
#line 392 "paspar.y"
    {
	o << "#039 expression_list->expression_list , expression" << endl; 
		(yyval.explist)=expression_list((yyvsp[(1) - (3)].explist),(yyvsp[(3) - (3)].exp));
}
    break;

  case 41:
#line 398 "paspar.y"
    {
	o << "#040 expression -> simple_expression" << endl; 
	(yyval.exp)=expression((yyvsp[(1) - (1)].exp));
}
    break;

  case 42:
#line 404 "paspar.y"
    {
	o << "#041 expression -> simple_expression relop simple_expression" << endl; 
	(yyval.exp)=expression((yyvsp[(1) - (3)].exp),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].exp));
}
    break;

  case 43:
#line 410 "paspar.y"
    {
	o << "#042 relop -> =" << endl; 
}
    break;

  case 44:
#line 415 "paspar.y"
    {
	o << "#043 relop -> <>" << endl; 
}
    break;

  case 45:
#line 420 "paspar.y"
    {
	o << "#044 relop -> <" << endl; 
}
    break;

  case 46:
#line 425 "paspar.y"
    {
	o << "#045 relop -> <=" << endl;
}
    break;

  case 47:
#line 430 "paspar.y"
    {
	o << "#046 relop -> >" << endl;
}
    break;

  case 48:
#line 435 "paspar.y"
    {
	o << "#047 relop -> >=" << endl;
}
    break;

  case 49:
#line 440 "paspar.y"
    {
    o << endl << "#048 simple_expression -> term" << endl;
    (yyval.exp)=simple_expression((yyvsp[(1) - (1)].exp));
}
    break;

  case 50:
#line 446 "paspar.y"
    {
    o << endl << "#049 simple_expression -> sign term" << endl;
    (yyval.exp)=simple_expression((yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].exp));
}
    break;

  case 51:
#line 452 "paspar.y"
    {
    o << endl << "#050 simple_expression -> simple_expression addop term" << endl;
    (yyval.exp)=simple_expression((yyvsp[(1) - (3)].exp),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].exp));
}
    break;

  case 52:
#line 458 "paspar.y"
    {
	o << "#051 sign -> +" << endl;
}
    break;

  case 53:
#line 463 "paspar.y"
    {
	o << "#052 sign -> -" << endl;
}
    break;

  case 54:
#line 468 "paspar.y"
    {
	o << "#053 addop -> +" << endl;
}
    break;

  case 55:
#line 473 "paspar.y"
    {
	o << "#054 addop -> -" << endl;
}
    break;

  case 56:
#line 478 "paspar.y"
    {
	o << "#055 addop -> or" << endl;
}
    break;

  case 57:
#line 483 "paspar.y"
    {
	o << "#056 term -> factor" << endl;
	(yyval.exp)=term((yyvsp[(1) - (1)].exp));
}
    break;

  case 58:
#line 489 "paspar.y"
    {
	o << "#057 term -> term mulop factor" << endl;
	(yyval.exp)=term((yyvsp[(1) - (3)].exp),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].exp));
}
    break;

  case 59:
#line 495 "paspar.y"
    {
	o << "#058 mulup -> *" << endl;
}
    break;

  case 60:
#line 500 "paspar.y"
    {
	o << "#059 mulup -> /" << endl;
}
    break;

  case 61:
#line 505 "paspar.y"
    {
	o << "#060 mulup -> /" << endl;
}
    break;

  case 62:
#line 510 "paspar.y"
    {
	o << "#061 mulup -> MOD" << endl;
}
    break;

  case 63:
#line 515 "paspar.y"
    {
	o << "#062 mulup -> AND" << endl;
}
    break;

  case 64:
#line 520 "paspar.y"
    {
	o << "#063 factor -> ID(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl;
	(yyval.exp)=factor_1((yyvsp[(1) - (1)].token));
}
    break;

  case 65:
#line 526 "paspar.y"
    {
	o << "#064 factor -> ID(" << (*(yyvsp[(1) - (4)].token)) << ") [ expression ]" << endl;
	(yyval.exp)=factor_2((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].exp));
}
    break;

  case 66:
#line 532 "paspar.y"
    {
	o << "#065 factor -> ID(" << (*(yyvsp[(1) - (4)].token)) << ") ( expression_list )" << endl;
	(yyval.exp)=factor_3((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].explist));
}
    break;

  case 67:
#line 538 "paspar.y"
    {
	o << "#066 factor -> ( expression )" << endl;
	(yyval.exp)=factor_4((yyvsp[(2) - (3)].exp));
}
    break;

  case 68:
#line 544 "paspar.y"
    {
	o << "#067 factor -> NOT factor" << endl;
	(yyval.exp)=factor_5((yyvsp[(2) - (2)].exp));
}
    break;

  case 69:
#line 550 "paspar.y"
    {
	o << "#068 factor -> INTLIT(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl;
	(yyval.exp)=factor_6((yyvsp[(1) - (1)].token));
}
    break;

  case 70:
#line 556 "paspar.y"
    {
	o << "#069 factor -> REALIT(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl;
	(yyval.exp)=factor_7((yyvsp[(1) - (1)].token));
}
    break;

  case 71:
#line 562 "paspar.y"
    {
	o << "#070 factor -> CHRLIT(" << (*(yyvsp[(1) - (1)].token)) << ")" << endl;
	(yyval.exp)=factor_8((yyvsp[(1) - (1)].token));
}
    break;


/* Line 1267 of yacc.c.  */
#line 2161 "y.tab.c"
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


#line 567 "paspar.y"


//-----------------------------------------------------------------------
//User function section
//-----------------------------------------------------------------------
void yyerror(const char* m)
{   cout << endl
         << "line(" << line << ") col(" << col << ") " << m;
    cout << endl;
}

