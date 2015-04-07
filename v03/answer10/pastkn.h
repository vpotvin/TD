#ifndef pastkn_h
#define pastkn_h 1
//-------------------------------------------------------------------------
//File pastkn_prolog.h must be prefixed onto pastkn.h 
//Version 5 Subset Pascal Compiler
//Symbol Table
//-------------------------------------------------------------------------
#include "List.h"
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//-------------------------------------------------------------------------
//Semantic helper functions
//-------------------------------------------------------------------------
#include "ToString.h"
#include "PCode.h"
#include "Exp.h"

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
     TOKEN_BEGIN = 258,
     PLUS = 259,
     MINUS = 260,
     STAR = 261,
     SLASH = 262,
     ASSIGN = 263,
     PERIOD = 264,
     COMMA = 265,
     SEMICOLON = 266,
     COLON = 267,
     EQU = 268,
     NEQ = 269,
     LES = 270,
     LEQ = 271,
     GEQ = 272,
     GRT = 273,
     LPAREN = 274,
     RPAREN = 275,
     LBRACKET = 276,
     RBRACKET = 277,
     RANGE = 278,
     RESERVE_WORDS = 279,
     AND = 280,
     ARRAY = 281,
     BEGiN = 282,
     DIV = 283,
     DO = 284,
     ELSE = 285,
     END = 286,
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
     WHILE = 299,
     REGULAR_EXPRESSIONS = 300,
     ID = 301,
     INTLIT = 302,
     REALIT = 303,
     CHRLIT = 304,
     TOKEN_END = 305
   };
#endif
/* Tokens.  */
#define TOKEN_BEGIN 258
#define PLUS 259
#define MINUS 260
#define STAR 261
#define SLASH 262
#define ASSIGN 263
#define PERIOD 264
#define COMMA 265
#define SEMICOLON 266
#define COLON 267
#define EQU 268
#define NEQ 269
#define LES 270
#define LEQ 271
#define GEQ 272
#define GRT 273
#define LPAREN 274
#define RPAREN 275
#define LBRACKET 276
#define RBRACKET 277
#define RANGE 278
#define RESERVE_WORDS 279
#define AND 280
#define ARRAY 281
#define BEGiN 282
#define DIV 283
#define DO 284
#define ELSE 285
#define END 286
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
#define WHILE 299
#define REGULAR_EXPRESSIONS 300
#define ID 301
#define INTLIT 302
#define REALIT 303
#define CHRLIT 304
#define TOKEN_END 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 88 "paspar.y"

  string* token;
  List<string>* strlist;
  Typ* typ;
  List<VariableSymbol*>* varlist;
  Exp* exp;
  List<Exp*>* explist;



/* Line 1676 of yacc.c  */
#line 163 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


//------------------------------------------------------------------------
//File pastkn_epilog.h must be appended to file pastkn.h
//Version 3 Subset Pascal Compiler
//------------------------------------------------------------------------
#endif
