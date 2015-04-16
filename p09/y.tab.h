/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 75 "paspar.y"

  string* token;
  List<string>* slist;
  Typ* typ;
  List<VariableSymbol*>* varlist;
  Exp* exp;
  List<Exp*>* explist;



/* Line 2068 of yacc.c  */
#line 161 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


