
%option noyywrap
%{
extern "C" 
int yylex (void);
#include "paslex.h"
#include "y.tab.h"
#include <map>

int TokenMgr(int i);
void ToLower(char* d,char* s);
int ReserveWord(char* s); 

static map<string,int> RW;              //RW - Reserve Words
static map<int,string> NAME;            //NAME OF TOKEN

extern ofstream o; 


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



[0-9]+ 		return TokenMgr(INTLIT);   // INT
[0-9]+"."[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? return TokenMgr(REALIT); 
[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? return TokenMgr(REALIT); 
(['][a-zA-Z0-9]['])|([']['"][']) return TokenMgr(CHRLIT);
"{".*"}" 	return TokenMgr(COMMENT);  // DO WE A MULILINE COMMENT



. 			;

%%



int TokenMgr(int i){
	int tc = i;

	o << "Token:Code=";

	if (i == ID){
		char* s=new char[yyleng];     
  		ToLower(s,yytext);
  		tc = ReserveWord(s);
	}
	col += yyleng;
	return i;
}

int ReserveWord(char* s)
{
    int t=RW[(string)s];
    if (t>0) return t; else return ID;
}

void ToLower(char* d,char* s)
{   strcpy(d,s);
    for (int a=0;a<strlen(d);a++) d[a]=tolower(d[a]);
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