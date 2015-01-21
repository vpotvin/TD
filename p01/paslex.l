
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
"{".*|\n*"}" 	return TokenMgr(COMMENT);  // DO WE A MULILINE COMMENT



[0-9]+ 		return TokenMgr(INTLIT);   // INT
[0-9]+"."[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? return TokenMgr(REALIT); 
[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? return TokenMgr(REALIT); 




. 			;

%%



int TokenMgr(int i){
	int tc = i;

	if (i == ID){
		char* s=new char[yyleng];     
  		ToLower(s,yytext);
  		tc = ReserveWord(s);
	}
	col += yyleng;

	o << "Token:Code=";
	o << tc;
	o << " Name= ";
	o << NAME[tc];
	o << " Spelling=";
	o << yytext;
	o << endl;
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

	RW["begin"]=AND;
    RW["end"  ]=ARRAY;
    RW["read" ]=BEGAN;
    RW["div"]=DIV;
    RW["do"]=DO;
    RW["else"]=ELSE;
    RW["end"]=END;
    RW["function"]=FUNCTION;
    RW["if"]=IF;
    RW["mod"]=MOD;
    RW["not"]=NOT;
    RW["of"]=OF;
    RW["or"]=OR;
    RW["procedure"]=PROCEDURE;
    RW["program"]=PROGRAM;
    RW["then"]=THEN;
    RW["to"]=TO;
    RW["type"]=TYPE;
    RW["var"]=VAR;
    RW["while"]=WHILE;

    NAME[PLUS] = "PLUS";
    NAME[MINUS] = "MINUS";
    NAME[STAR] = "STAR";
    NAME[SLASH] = "SLASH";
    NAME[ASSIGN] = "ASSIGN";
    NAME[PERIOD] = "PERIOD";
    NAME[COMMA] = "COMMA";
    NAME[SEMICOLON] = "SEMICOLON";
    NAME[COLON] = "COLON";
    NAME[EQU] = "EQU";
    NAME[NEQ] = "NEQ";
    NAME[LES] = "LES";
    NAME[LEQ] = "LEQ";
    NAME[GRT] = "GRT";
    NAME[GEQ] = "GEQ";
    NAME[LPAREN] = "LPAREN";
    NAME[RPAREN] = "RPAREN";
    NAME[LBRACKET] = "LBRACKET";
    NAME[RBRACKET] = "RBRACKET";
    NAME[RANGE] = "RANGE";
    NAME[AND] = "AND";
    NAME[ARRAY] = "ARRAY";
    NAME[BEGAN] = "BEGIN";
    NAME[DIV] = "DIV";
    NAME[DO] = "DO";
	NAME[ELSE] = "ELSE"; 
	NAME[END] = "END"; 
	NAME[FUNCTION] = "FUNCTION"; 
	NAME[IF] = "IF";
	NAME[MOD] = "MOD"; 
	NAME[NOT] = "NOT"; 
	NAME[OF] = "OF"; 
	NAME[OR] = "OR"; 
	NAME[PROCEDURE] = "PROCEDURE"; 
	NAME[PROGRAM] = "PROGRAM";
	NAME[THEN] = "THEN";
	NAME[TO] = "TO";
	NAME[TYPE] = "TYPE"; 
	NAME[VAR] = "VAR"; 
	NAME[WHILE] = "PLUS"; 
	NAME[ID] = "ID"; 
	NAME[INTLIT] = "INTLIT"; 
	NAME[REALIT] = "REALIT";
	NAME[CHRLIT] = "CHRLIT";
	NAME[COMMENT] = "COMMENT";
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