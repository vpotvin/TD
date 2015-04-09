%{
//---------------------------------------------------------------------
//Version 4: Symbol Table 
//---------------------------------------------------------------------
//File paspar.y contains a specification for Subset Pascal  
//defined by Thomas R. Turner.
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     February, 2012
//---------------------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Application inlcude files
//---------------------------------------------------------------------
#include "paslex.h"
#include "paspar.h"
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "List.h"
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//Semantic include files
//---------------------------------------------------------------------
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
#include "simple_expression.h"
//---------------------------------------------------------------------
//Semantic helper include files
//---------------------------------------------------------------------
#include "String.h"
#include "PCode.h"
#include "Exp.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
void yyerror(const char* m);
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern int line;
extern int col;
extern Label L;
extern SymbolTable ST;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
SymbolTable ST;               //The SymbolTable
//---------------------------------------------------------------------
%}
%union {
  string* token;
  List<string>* strlist;
  Typ* typ;
  List<VariableSymbol*>* varlist;
  Exp* exp;
  List<Exp*>* explist;
}
%type  <varlist> parameter_list
%type  <varlist> subprogram_parameters
%type  <typ>     type
%type  <typ>     standard_type
%type  <strlist> identifier_list

%type  <exp>     factor
%type  <exp>     term
%type  <exp>     simple_expression
%type  <exp>     expression

%type  <explist> expression_list

%type  <token>   mulop
%type  <token>   addop
%type  <token>   sign
 
%token <token>   TOKEN_BEGIN
%token <token>   PLUS
%token <token>   MINUS
%token <token>   STAR
%token <token>   SLASH
%token <token>   ASSIGN
%token <token>   PERIOD
%token <token>   COMMA
%token <token>   SEMICOLON
%token <token>   COLON
%token <token>   EQU
%token <token>   NEQ
%token <token>   LES
%token <token>   LEQ
%token <token>   GEQ
%token <token>   GRT
%token <token>   LPAREN
%token <token>   RPAREN
%token <token>   LBRACKET
%token <token>   RBRACKET
%token <token>   RANGE
%token <token>   RESERVE_WORDS
%token <token>   AND
%token <token>   ARRAY 
%token <token>   BEGiN
%token <token>   DIV
%token <token>   DO
%token <token>   ELSE
%token <token>   END
%token <token>   FUNCTION
%token <token>   IF
%token <token>   MOD
%token <token>   NOT
%token <token>   OF
%token <token>   OR
%token <token>   PROCEDURE
%token <token>   PROGRAM
%token <token>   THEN
%token <token>   TO
%token <token>   TYPE
%token <token>   VAR
%token <token>   WHILE
%token <token>   REGULAR_EXPRESSIONS
%token <token>   ID
%token <token>   INTLIT
%token <token>   REALIT
%token <token>   CHRLIT
%token <token>   TOKEN_END
%%
program:
  program_head program_declarations program_body
  {tfs << endl << "#001 program -> program_head program_declarations program_body";
   program();                 //program semantics
  }
program_head:
  PROGRAM ID program_parameters SEMICOLON
  {tfs << endl << "#002 program_head -> PROGRAM ID(" << (*$2) << ") program_parameters ;";
   program_head(*$2);
  }
program_declarations:
  variable_declarations subprogram_declarations
  {tfs << endl << "#003 program_declarations -> variable_declarations subprogram_declarations";
  }
program_body:
  compound_statement PERIOD
  {tfs << endl << "#004 program_body -> compound_statement .";
  }
program_parameters:
  {tfs << endl << "#005 program_parameters -> empty";
  }
program_parameters:
  LPAREN program_parameter_list RPAREN
  {tfs << endl << "#006 program_parameters -> (program_parameter_list)";
  }
program_parameter_list:
  identifier_list
  {tfs << endl << "#007 program_parameter_list -> identifier_list";
  }
identifier_list:
  ID
  {tfs << endl << "#008 identifier_list -> ID(" << (*$1) << ")";
   $$=identifier_list($1);
  }
identifier_list:
  identifier_list COMMA ID
  {tfs << endl << "#009 identifier_list -> identifier_list , ID(" << (*$3) << ")"; 
   $$=identifier_list($1,$3);
  } 
variable_declarations:
  {tfs << endl << "#010 variable_declarations -> empty"; 
  } 
variable_declarations:
  variable_declarations VAR identifier_list COLON type SEMICOLON
  {tfs << endl << "#011 variable_declarations -> variable_declarations VAR identifier_list:type;"; 
   variable_declarations($3,$5);
  } 
type:
  standard_type
  {tfs << endl << "#012 type -> standard_type"; 
   $$=type($1);
  } 
type:
  ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
  {tfs << endl << "#013 type -> ARRAY[INTLIT .. INTLIT] OF standard_type"; 
   $$=type(*$3,*$5,$8);
  } 
standard_type:
  ID
  {tfs << endl << "#014 standard_type -> ID(" << (*$1) << ")"; 
   $$=standard_type(*$1);
  } 
subprogram_declarations:
  {tfs << endl << "#015 subprogram_declarations -> empty"; 
  } 
subprogram_declarations:
  subprogram_declarations subprogram_declaration SEMICOLON
  {tfs << endl << "#016 subprogram_declarations -> subprogram_declarations subprogram_declaration ;"; 
  } 
subprogram_declaration:
  subprogram_head variable_declarations compound_statement
  {tfs << endl << "#017 subprogram_declaration -> subprogram_head variable_declarations compound_statement"; 
   subprogram_declaration();
  } 
subprogram_head:
  FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
  {tfs << endl << "#018 subprogram_head -> FUNCTION ID(" << (*$2) << ") subprogram_parameters : standard_type ;"; 
   subprogram_head(*$2,$3,$5);
  } 
subprogram_head:
  PROCEDURE ID subprogram_parameters SEMICOLON
  {tfs << endl << "#019 subprogram_head -> PROCDURE ID(" << (*$2) << ") subprogram_parameters ;";
   subprogram_head(*$2,$3);
  } 
subprogram_parameters:
  {tfs << endl << "#020 subprogram_parameters -> empty"; 
   $$=subprogram_parameters();
  } 
subprogram_parameters:
  LPAREN parameter_list RPAREN
  {tfs << endl << "#021 subprogram_parameters -> ( parameter_list )"; 
   $$=subprogram_parameters($2);
  } 
parameter_list:
  identifier_list COLON type
  {tfs << endl << "#022 parameter_list -> identifier_list : type" ; 
   $$=parameter_list($1,$3);
  } 
parameter_list:
  parameter_list SEMICOLON identifier_list COLON type
  {tfs << endl << "#023 parameter_list -> parameter_list ; identifier_list : type" ; 
   $$=parameter_list($1,$3,$5);
  } 
compound_statement:
  BEGiN optional_statements END
  {tfs << endl << "#024 compound_statement -> BEGIN optional_statement END"; 
  } 
optional_statements:
  {tfs << endl << "#025 optional_statements -> empty"; 
  } 
optional_statements:
  statement_list
  {tfs << endl << "#026 optional_statements -> statement_list"; 
  } 
statement_list:
  statement
  {tfs << endl << "#027 statement_list -> statement"; 
  } 
statement_list:
  statement_list SEMICOLON statement
  {tfs << endl << "#028 statement_list -> statement_list ; statement"; 
  } 
statement:
  variable ASSIGN expression   
  {tfs << endl << "#029 statement -> variable := expression"; 
  } 
statement:
  procedure_statement
  {tfs << endl << "#030 statement -> procedure_statement"; 
  } 
statement:
  compound_statement
  {tfs << endl << "#031 statement -> compound_statement"; 
  } 
statement:
  IF expression THEN statement ELSE statement
  {tfs << endl << "#032 statement -> IF expression THEN statement ELSE statement "; 
  } 
statement:
  WHILE expression DO statement
  {tfs << endl << "#033 statement -> WHILE expression DO statement "; 
  } 
variable:
  ID 
  {tfs << endl << "#034 variable -> ID(" << (*$1) << ")"; 
  } 
variable:
  ID LBRACKET expression RBRACKET
  {tfs << endl << "#035 variable -> ID [ expression ]"; 
  } 
procedure_statement:
  ID 
  {tfs << endl << "#036 procedure_statement -> ID(" << (*$1) << ")"; 
  } 
procedure_statement:
  ID LPAREN expression_list RPAREN
  {tfs << endl << "#037 procedure_statement -> ID(" << (*$1) << ") ( expression_list )"; 
  } 
expression_list:
  expression
  {tfs << endl << "#038 expression_list -> expression"; 
  } 
expression_list:
  expression_list COMMA expression
  {tfs << endl << "#039 expression_list -> expression_list , expression"; 
  } 
expression:
  simple_expression
  {tfs << endl << "#040 expression -> simple_expression"; 
  } 
expression:
  simple_expression relop simple_expression
  {tfs << endl << "#041 expression -> simple_expression relop simple_expression"; 
  } 
relop:
  EQU
  {tfs << endl << "#042 relop -> ="; 
  } 
relop:
  NEQ
  {tfs << endl << "#043 relop -> <>"; 
  } 
relop:
  LES
  {tfs << endl << "#044 relop -> <"; 
  } 
relop:
  LEQ
  {tfs << endl << "#045 relop -> <="; 
  } 
relop:
  GRT
  {tfs << endl << "#046 relop -> >"; 
  } 
relop:
  GEQ
  {tfs << endl << "#047 relop -> >="; 
  } 
simple_expression:
  term
  {tfs << endl << "#048 simple_expression -> term"; 
   $$=simple_expression($1);
  } 
simple_expression:
  sign term
  {tfs << endl << "#049 simple_expression -> sign term"; 
   $$=simple_expression($1,$2);
  } 
simple_expression:
  simple_expression addop term
  {tfs << endl << "#050 simple_expression -> simple_expression addop term"; 
   $$=simple_expression($1,$2,$3);
  } 
sign:
  PLUS
  {tfs << endl << "#051 sign -> +"; 
  } 
sign:
  MINUS
  {tfs << endl << "#052 sign -> -"; 
  } 
addop:
  PLUS
  {tfs << endl << "#053 addop -> +"; 
  } 
addop:
  MINUS
  {tfs << endl << "#054 addop -> -"; 
  } 
addop:
  OR
  {tfs << endl << "#055 addop -> OR"; 
  } 
term:
  factor
  {tfs << endl << "#056 term -> factor"; 
   $$=term($1);
  } 
term:
  term mulop factor
  {tfs << endl << "#057 term -> term mulop factor"; 
  $$=term($1,$2,$3);
  } 
mulop:
  STAR
  {tfs << endl << "#058 mulop -> *"; 
  } 
mulop:
  SLASH
  {tfs << endl << "#059 mulop -> /"; 
  } 
mulop:
  DIV
  {tfs << endl << "#060 mulop -> DIV"; 
  } 
mulop:
  MOD
  {tfs << endl << "#061 mulop -> MOD"; 
  } 
mulop:
  AND
  {tfs << endl << "#062 mulop -> AND"; 
  } 
factor:
  ID
  {tfs << endl << "#063 factor -> ID(" << (*$1) << ")"; 
   $$=factor_1($1);
  } 
factor:
  ID LBRACKET expression RBRACKET
  {tfs << endl << "#064 factor -> ID(" << (*$1) << ") [ expression ]"; 
   $$=factor_2($1,$3);
  } 
factor:
  ID LPAREN expression_list RPAREN
  {tfs << endl << "#065 factor -> ID(" << (*$1) << ") ( expression_list )"; 
   $$=factor_3($1,$3);
  } 
factor:
  LPAREN expression RPAREN
  {tfs << endl << "#066 factor -> ( expression )"; 
   $$=factor_4($2);
  } 
factor:
  NOT factor
  {tfs << endl << "#067 factor -> NOT factor"; 
   $$=factor_5($2);
  } 
factor:
  INTLIT
  {tfs << endl << "#068 factor -> INTLIT(" << (*$1) << ")"; 
   $$=factor_6($1);
  } 
factor:
  REALIT
  {tfs << endl << "#069 factor -> REALIT(" << (*$1) << ")"; 
   $$=factor_7($1);
  } 
factor:
  CHRLIT
  {tfs << endl << "#070 factor -> CHRLIT(" << (*$1) << ")"; 
   $$=factor_8($1);
  } 
%%
//-----------------------------------------------------------------------
//User function section
//-----------------------------------------------------------------------
void yyerror(const char* m)
{   cout << endl 
         << "line(" << line << ") col(" << col << ") " << m;
    cout << endl;
}

