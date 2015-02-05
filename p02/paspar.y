%{
#include <iostream>
#include "paslex.h"
#include "paspar.h"
#include <fstream>
using namespace std;

void yyerror(const char* msg) {}
int yylex(void); 				// I CAN COMPILE WITHOUT THIS FIND OUT WHY IT IS NECCESARY;
int yywrap(){					// I CAN COMPILE WITHOUT THIS FIND OUT WHY IT SI NECCESARY;
	return 1;
}

extern int yylex (); 			// I CAN COMPILE WITHOUT THIS FIND OUT WHY IT SI NECCESARY;
extern void yyerror ( char *); 	// I CAN COMPILE WITHOUT THIS FIND OUT WHY IT SI NECCESARY;

extern ofstream o; 						// WRITES TO FILES


#ifdef __cplusplus 
extern "C" 						// I CAN COMPILE WITHOUT THIS FIND OUT WHY IT SI NECCESARY;
#endif




%}

%token BEGAN
%token END
%token ID
%token PLUS
%token MINUS
%token STAR
%token SLASH
%token ASSIGN
%token PERIOD
%token COMMA
%token SEMICOLON
%token COLON
%token EQU
%token NEQ
%token LES
%token LEQ
%token GRT
%token GEQ
%token LPAREN
%token RPAREN
%token LBRACKET
%token RBRACKET
%token RANGE
%token AND
%token ARRAY
%token DIV
%token DO
%token ELSE
%token FUNCTION
%token IF
%token MOD
%token NOT
%token OF
%token OR
%token PROCEDURE
%token PROGRAM
%token THEN
%token TO 
%token TYPE
%token VAR
%token COMMENT
%token CHRLIT
%token REALIT
%token INTLIT
%token WHILE


%%
program: program_head program_declarations program_body
{
	o << "#001 Program->program_head program_declarations program_body" << endl; 
}

program_head: PROGRAM ID program_parameters SEMICOLON
{
	o << "#002 program_head->PROGRAM ID program_parameters" << endl;
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
	o << "#007 program_parameter_list->identifier_list" << endl;
}

identifier_list: ID
{
	o << "#008 identifier_list->ID" << endl;
} 

identifier_list: identifier_list COMMA ID
{
	o << "#009 identifier_list->identifier_list, id" << endl;
}

declarations:
{
	o << "#010 declarations->Empty" << endl;
}

declarations: declarations VAR identifier_list COLON type SEMICOLON
{
	o << "#011 declarations->declarations VAR identifier_list : type ;" << endl;
}

type: standard_type
{
	o << "#012 type->standard_type" << endl;
}

type: ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
{
	o << "#013 type->ARRAY[INTLIT ... INTLIT] of standard_type" << endl;
}

standard_type: ID
{
	o << "#014 standard_type->ID" << endl;
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
}

subprogram_head: FUNCTION ID subprogram_parameters COLON standard_type
{
	o << "#018 subprogram_head->FUNCTION ID subprogram_parameters : standard_type" << endl;
}

subprogram_head: PROCEDURE ID subprogram_parameters SEMICOLON
{
	o << "#019 subprogram_head->PROCEDURE ID subprogram_parameters ;" << endl;
}

subprogram_parameters:
{
	o << "#020 subprogram_parameters->Empty" << endl;
}

subprogram_parameters: LPAREN parameter_list RPAREN
{
	o << "#021 subprogram_parameters->( parameter_list )" << endl;
}

parameter_list: identifier_list COLON type
{
	o << "#022 parameter_list->identifier_list : type" << endl;
}

parameter_list: parameter_list SEMICOLON identifier_list COLON type
{
	o << "#023 parameter_list-> parameter_list ; identifier_list : type" << endl;
}

compound_statement: BEGAN optional_statements END
{
	o << "#024 compound_statement->BEGIN optional_statements END" << endl;
}

optional_statements: 
{
	o << "#025 optional_statements->Empty" << endl;
}

optional_statements: statement_list
{
	o << "#026 optional_statements->statement_list" << endl;
}

statement_list: statement
{
	o << "#027 statement_list->statement" << endl;
}

statement_list: statement_list SEMICOLON statement 
{
	o << "#028 statement_list->statement_list ; statement" << endl;
}

statement: variable ASSIGN expression
{
	o << "#029 statement->variable := expression" << endl;
}

statement: procedure_statement
{
	o << "#030 statement->procedure_statement" << endl;
}

statement: compound_statement
{
	o << "#031 statement->compound_statement" << endl; 
}

statement: IF expression THEN statement ELSE statement
{
	o << "#032 statement->IF expression THEN statement ELSE statement" << endl; 
}

statement: WHILE expression DO statement
{
	o << "#033 statement->WHILE expression DO statement" << endl; 
}

variable: ID
{
	o << "#034 VARIABLE->ID" << endl; 
}

variable: ID LBRACKET expression RBRACKET
{
	o << "#035 VARIABLE->ID[ expression ]" << endl; 
}

procedure_statement: ID
{
	o << "#036 procedure_statement->ID" << endl; 
}

procedure_statement: ID LPAREN expression_list RPAREN
{
	o << "#037 procedure_statement->ID ( expression_list )" << endl; 
}

expression_list: expression
{
	o << "#038 expression_list->expression" << endl; 
}

expression_list: expression_list COMMA expression
{
	o << "#039 expression_list->expression_list , expression" << endl; 
}

expression: simple_expression
{
	o << "#040 expression -> simple_expression" << endl; 
}

expression: simple_expression relop simple_expression
{
	o << "#041 expression -> simple_expression relop simple_expression" << endl; 
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
	o << "#048 simple_expression -> term" << endl;
}

simple_expression: sign term
{
	o << "#049 simple_expression -> sign term" << endl;
}

simple_expression: simple_expression addop term
{
	o << "#050 simple_expression -> simple_expression addop term" << endl;
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
}

term: term mulop factor
{
	o << "#057 term -> term mulop factor" << endl;
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
	o << "#063 factor -> ID" << endl;
}

factor: ID LBRACKET expression RBRACKET
{
	o << "#064 factor -> ID [ expression ]" << endl;
}

factor: ID LPAREN expression_list RPAREN
{
	o << "#065 factor -> ID ( expression_list )" << endl;
}

factor: LPAREN expression RPAREN
{
	o << "#066 factor -> ( expression )" << endl;
}

factor: NOT factor
{
	o << "#067 factor -> NOT factor" << endl;
}

factor: INTLIT
{
	o << "#068 factor -> INTLIT" << endl;
}

factor: REALIT
{
	o << "#069 factor -> REALIT" << endl;
}

factor: CHRLIT
{
	o << "#070 factor -> CHRLIT" << endl;
}

%%

Parser::Parser(FILE* i):Lexer(i){}
int Parser::Parse(){
	return yyparse();
}
