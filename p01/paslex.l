
%option noyywrap
%{
extern "C" 
int yylex (void);
#include "paslex.h"
#include "y.tab.h"
;
int wordcount;
int lineNum;
string TokenMgr();
%}

%%

"{".+"}" 	return COMMENT;  // DO WE A MULILINE COMMENT

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

char* Lexer::FetchSpelling(void)
{
    return (char*)yytext;
}