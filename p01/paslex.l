
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
"+"			return TokenMgr(PLUS);
"-"			return TokenMgr(MINUS);
"*" 		return TokenMgr(STAR);
"/"			return TokenMgr(SLASH);
":=" 		return TokenMgr(ASSIGN);
"." 		return TokenMgr(PERIOD);

[0-9]+ 		return TokenMgr(INTLIT);   // INT
"{".*"}" 	return TokenMgr(COMMENT);  // DO WE A MULILINE COMMENT

int 		return 1;

atest 		return 2;

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