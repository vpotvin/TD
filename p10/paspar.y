%{
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

%}
%union {
  string* token;
  List<string>* slist;
  Typ* typ;
  List<VariableSymbol*>* varlist;
  Exp* exp;
  List<Exp*>* explist;
}
%type  <varlist> parameter_list
%type  <varlist> subprogram_parameters
%type  <typ>     type
%type  <typ>     standard_type
%type  <slist> identifier_list

%type  <exp>     factor
%type  <exp>     term
%type  <exp>     simple_expression
%type  <exp>     expression
%type  <exp>     procedure_statement
%type  <exp>     variable

%type  <explist> expression_list
%type  <explist> statement
%type  <explist> compound_statement
%type  <explist> statement_list
%type  <explist> optional_statements

%type  <token>   mulop
%type  <token>   addop
%type  <token>   relop
%type  <token>   sign

%token <token> BEGAN
%token <token> END
%token <token> ID
%token <token> PLUS
%token <token> MINUS
%token <token> STAR
%token <token> SLASH
%token <token> ASSIGN
%token <token> PERIOD
%token <token> COMMA
%token <token> SEMICOLON
%token <token> COLON
%token <token> EQU
%token <token> NEQ
%token <token> LES
%token <token> LEQ
%token <token> GRT
%token <token> GEQ
%token <token> LPAREN
%token <token> RPAREN
%token <token> LBRACKET
%token <token> RBRACKET
%token <token> RANGE
%token <token>   RESERVE_WORDS
%token <token> AND
%token <token> ARRAY
%token <token> DIV
%token <token> DO
%token <token> ELSE
%token <token> FUNCTION
%token <token> IF
%token <token> MOD
%token <token> NOT
%token <token> OF
%token <token> OR
%token <token> PROCEDURE
%token <token> PROGRAM
%token <token> THEN
%token <token> TO 
%token <token> TYPE
%token <token> VAR
%token <token> COMMENT
%token <token> CHRLIT
%token <token> REALIT
%token <token> INTLIT
%token <token> WHILE
%token <token>   REGULAR_EXPRESSIONS
%token <token>   TOKEN_END

//%type  <slist> identifier_list


%%
program: program_head program_declarations program_body
{
	o << "#001 Program->program_head program_declarations program_body" << endl;
	program(); 
}

program_head: PROGRAM ID program_parameters SEMICOLON
{
	o << "#002 program_head->PROGRAM ID program_parameters" << endl;
	program_head(*$2);
}

program_declarations: declarations subprogram_declarations
{
	o << "#003 program_declarations->declarations subprogram_declarations" << endl;
}

program_body: compound_statement PERIOD
{
	o <<"#004 program_body->compound_statement ." << endl; 
}

program_parameters:
{
	o <<"#005 program_parameters -> Empty" << endl;
}

program_parameters: LPAREN program_parameter_list RPAREN
{
	o << "#006 program_parameters->( program_parameter_list )" << endl;
}

program_parameter_list: identifier_list
{
	o << "#007 program_parameter_list -> identifier_list" << endl; //(" << (*$1) << ")
}

identifier_list: 
	ID
{
	o << "#008 identifier_list->ID(" << (*$1) << ")" << endl;
	$$=identifier_list($1);
	//$$=new List<string>;
   	//$$->Insert(*$1);
} 

identifier_list: identifier_list COMMA ID
{
	o << "#009 identifier_list -> identifier_list , ID(" << (*$3) << ")" << endl;
	$$=identifier_list($1,$3);
	//$1->Insert(*$3);
   	//$$=$1;
}

declarations:
{
	o << "#010 declarations->Empty" << endl;
}

declarations: declarations VAR identifier_list COLON type SEMICOLON
{
	o << "#011 declarations->declarations VAR identifier_list: type ;" << endl; //"<< (*$3) << "
	variable_declarations($3,$5);
}

type: standard_type
{
	o << "#012 type->standard_type" << endl;
        $$=type($1);
}

type: ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
{
	o << "#013 type->ARRAY[INTLIT .. INTLIT] of standard_type" << endl;
        $$=type(*$3,*$5,$8);
}

standard_type: ID
{
	o << "#014 standard_type -> ID(" << (*$1) << ")" << endl;
        $$=standard_type(*$1);
}

subprogram_declarations:
{
	o << "#015 subprogram_declarations->Empty" << endl;
}

subprogram_declarations: subprogram_declarations subprogram_declaration SEMICOLON
{
	o << "#016 subprogram_declarations->subprogram_declarations subprogram_declarations;" << endl;
}

subprogram_declaration: subprogram_head declarations compound_statement
{
	o << "#017 subprogram_declarations->subprogram_head declarations compound_statement" << endl;
	subprogram_declaration();
}

subprogram_head: FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
{
	o << "#018 subprogram_head->FUNCTION ID(" << (*$2) <<")  subprogram_parameters : standard_type" << endl;
	subprogram_head(*$2,$3,$5);
}

subprogram_head: PROCEDURE ID subprogram_parameters SEMICOLON
{
	o << "#019 subprogram_head->PROCEDURE ID(" << (*$2) << ") subprogram_parameters ;" << endl;
	subprogram_head(*$2,$3);
}

subprogram_parameters:
{
	o << "#020 subprogram_parameters->Empty" << endl;
	$$=subprogram_parameters();
}

subprogram_parameters: LPAREN parameter_list RPAREN
{
	o << "#021 subprogram_parameters->( parameter_list )" << endl;
	$$=subprogram_parameters($2);
}

parameter_list: identifier_list COLON type
{
	o << "#022 parameter_list->identifier_list: type" << endl; //" << (*$1) << " 
	$$=parameter_list($1,$3);
}

parameter_list: parameter_list SEMICOLON identifier_list COLON type
{
	o << "#023 parameter_list-> parameter_list ; identifier_list : type" << endl; //" << (*$3) << "
	$$=parameter_list($1,$3,$5);
}

compound_statement: BEGAN optional_statements END
{
	o << "#024 compound_statement->BEGIN optional_statements END" << endl;
    $$=Compound_statement($2);
}

optional_statements: 
{
	o << "#025 optional_statements->Empty" << endl;
    $$=Optional_statements();
}

optional_statements: statement_list
{
	o << "#026 optional_statements->statement_list" << endl;
    $$=Statement_list($1);
}

statement_list: statement
{
	o << "#027 statement_list->statement" << endl;
    $$=Statement_list($1);
}

statement_list: statement_list SEMICOLON statement 
{
	o << "#028 statement_list->statement_list ; statement" << endl;
    $$=Statement_list($1,$3);
}

statement: variable ASSIGN expression
{
	o << "#029 statement->variable := expression" << endl;
    $$=statement($1,$3);
}

statement: procedure_statement
{
	o << "#030 statement->procedure_statement" << endl;
    $$=statement($1);
}

statement: compound_statement
{
	o << "#031 statement->compound_statement" << endl;
    $$=statement($1);
}

statement: IF expression THEN statement ELSE statement
{
	o << "#032 statement->IF expression THEN statement ELSE statement" << endl;
    $$=statement($2,$4,$6);
}

statement: WHILE expression DO statement
{
	o << "#033 statement->WHILE expression DO statement" << endl;
    $$=statement($2,$4);
}

variable: ID
{
	o << "#034 VARIABLE->ID(" << (*$1) << ")" << endl; 
	$$=variable($1);
}

variable: ID LBRACKET expression RBRACKET
{
	o << "#035 VARIABLE->ID(" << (*$1) << ")[ expression ]" << endl; 
	$$=variable($1,$3);
}

procedure_statement: ID
{
	o << "#036 procedure_statement->ID(" << (*$1) << ")" << endl;
		$$=procedure_statement($1);
}

procedure_statement: ID LPAREN expression_list RPAREN
{
	o << "#037 procedure_statement->ID(" << (*$1) <<")( expression_list )" << endl;
		$$=procedure_statement($1,$3);
}

expression_list: expression
{
	o << "#038 expression_list->expression" << endl;
		$$=expression_list($1);
}

expression_list: expression_list COMMA expression
{
	o << "#039 expression_list->expression_list , expression" << endl; 
		$$=expression_list($1,$3);
}

expression: simple_expression
{
	o << "#040 expression -> simple_expression" << endl; 
	$$=expression($1);
}

expression: simple_expression relop simple_expression
{
	o << "#041 expression -> simple_expression relop simple_expression" << endl; 
	$$=expression($1,$2,$3);
}

relop: EQU
{
	o << "#042 relop -> =" << endl; 
}

relop: NEQ
{
	o << "#043 relop -> <>" << endl; 
}

relop: LES
{
	o << "#044 relop -> <" << endl; 
}

relop: LEQ
{
	o << "#045 relop -> <=" << endl;
}

relop: GRT
{
	o << "#046 relop -> >" << endl;
}

relop: GEQ
{
	o << "#047 relop -> >=" << endl;
}

simple_expression: term
{
    o << endl << "#048 simple_expression -> term" << endl;
    $$=simple_expression($1);
}

simple_expression: sign term
{
    o << endl << "#049 simple_expression -> sign term" << endl;
    $$=simple_expression($1,$2);
}

simple_expression: simple_expression addop term
{
    o << endl << "#050 simple_expression -> simple_expression addop term" << endl;
    $$=simple_expression($1,$2,$3);
}

sign: PLUS
{
	o << "#051 sign -> +" << endl;
}

sign: MINUS
{
	o << "#052 sign -> -" << endl;
}

addop: PLUS
{
	o << "#053 addop -> +" << endl;
}

addop: MINUS
{
	o << "#054 addop -> -" << endl;
}

addop: OR
{
	o << "#055 addop -> or" << endl;
}

term: factor
{
	o << "#056 term -> factor" << endl;
	$$=term($1);
}

term: term mulop factor
{
	o << "#057 term -> term mulop factor" << endl;
	$$=term($1,$2,$3);
}

mulop: STAR
{
	o << "#058 mulup -> *" << endl;
}

mulop: SLASH
{
	o << "#059 mulup -> /" << endl;
}

mulop: DIV
{
	o << "#060 mulup -> /" << endl;
}

mulop: MOD
{
	o << "#061 mulup -> MOD" << endl;
}

mulop: AND
{
	o << "#062 mulup -> AND" << endl;
}

factor: ID 
{
	o << "#063 factor -> ID(" << (*$1) << ")" << endl;
	$$=factor_1($1);
}

factor: ID LBRACKET expression RBRACKET
{
	o << "#064 factor -> ID(" << (*$1) << ") [ expression ]" << endl;
	$$=factor_2($1,$3);
}

factor: ID LPAREN expression_list RPAREN
{
	o << "#065 factor -> ID(" << (*$1) << ") ( expression_list )" << endl;
	$$=factor_3($1,$3);
}

factor: LPAREN expression RPAREN
{
	o << "#066 factor -> ( expression )" << endl;
	$$=factor_4($2);
}

factor: NOT factor
{
	o << "#067 factor -> NOT factor" << endl;
	$$=factor_5($2);
}

factor: INTLIT
{
	o << "#068 factor -> INTLIT(" << (*$1) << ")" << endl;
	$$=factor_6($1);
}

factor: REALIT
{
	o << "#069 factor -> REALIT(" << (*$1) << ")" << endl;
	$$=factor_7($1);
}

factor: CHRLIT
{
	o << "#070 factor -> CHRLIT(" << (*$1) << ")" << endl;
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
