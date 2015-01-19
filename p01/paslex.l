
%option noyywrap
%{
extern "C" 
int yylex (void);
#include "paslex.h"
#include "y.tab.h"

int TokenMgr(int i);
int getCol();
int getLine();


int line 	= 1;
int col 	= 1;
%}

%%


[\n]		{line++; col = 1;}
[\t]+        {col += yyleng;}
[_a-zA-Z][_a-zA-Z0-9]*                  return TokenMgr(ID);
"+"			return TokenMgr(PLUS);
"-"			return TokenMgr(MINUS);
"*" 		return TokenMgr(STAR);
"/"			return TokenMgr(SLASH);
":=" 		return TokenMgr(ASSIGN);
"." 		return TokenMgr(PERIOD);
","			return TokenMgr(COMMA);
";"			return TokenMgr(SEMICOLON);
":" 		return TokenMgr(COLON);
"="			return TokenMgr(EQU);
"<>" 		return TokenMgr(NEQ);
"<" 		return TokenMgr(LES);
"<=" 		return TokenMgr(LEQ);
">" 		return TokenMgr(GRT);
">=" 		return TokenMgr(GEQ);
"(" 		return TokenMgr(LPAREN);
")" 		return TokenMgr(RPAREN);
"[" 		return TokenMgr(LBRACKET);
"]"			return TokenMgr(RBRACKET);
".."		return TokenMgr(RANGE);
"and" 		return TokenMgr(AND);
"array" 	return TokenMgr(ARRAY);
"begin" 	return TokenMgr(BEGAN);
"div" 		return TokenMgr(DIV);
"do" 		return TokenMgr(DO);
"else" 		return TokenMgr(ELSE);
"end" 		return TokenMgr(END);
"function"	return TokenMgr(FUNCTION);
"if" 		return TokenMgr(IF);
"mod" 		return TokenMgr(MOD);
"not" 		return TokenMgr(NOT);
"of" 		return TokenMgr(OF);
"or" 		return TokenMgr(OR);
"procedure" return TokenMgr(PROCEDURE);
"program" 	return TokenMgr(PROGRAM);
"then" 		return TokenMgr(THEN);
"to" 		return TokenMgr(TO);
"type" 		return TokenMgr(TYPE);
"var"		return TokenMgr(VAR);
"while"		return TokenMgr(WHILE);


[0-9]+ 		return TokenMgr(INTLIT);   // INT
[0-9]+"."[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? return TokenMgr(REALIT); 
[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? return TokenMgr(REALIT); 
"{".*"}" 	return TokenMgr(COMMENT);  // DO WE A MULILINE COMMENT



. 			;

%%



int TokenMgr(int i){
	col += yyleng;
	return i;
}

int getCol(){
	return col;
}

int getLine(){
	return line;
}





Lexer::Lexer(FILE* i)
{   
	yyin=i;
}

char* Lexer::FetchSpelling(void)
{
    return (char*)yytext;
}

int Lexer::getLine(void)
{
    return line;
}

int Lexer::getCol(void)
{
    return col;
}