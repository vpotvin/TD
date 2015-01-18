
%option noyywrap
%{
extern "C" 
int yylex (void);
#include "paslex.h"
;
int wordcount;
int lineNum;
string TokenMgr();
%}

%%

int 		return 1;

atest 		return 2;

. 			;

%%

string TokenMgr(){
	return (string)yytext;
}





Lexer::Lexer(FILE* i)
{   
	yyin=i;
}
