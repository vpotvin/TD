/* UNKNOWN OPTION TO MAKE COMPILE -------------------------------------------*/
%option noyywrap
/*---------------------------------------------------------------------------*/
%{
/* ? ------------------------------------------------------------------------*/
extern "C" 
int yylex (void);
/*--------------------------------------------------------------------------*/

/* INCLUDES -----------------------------------------------------------------*/
#include "paslex.h"
#include "pastkn.h"
#include <map>
#include <iomanip>
/*---------------------------------------------------------------------------*/

/* FUNCTION DECLARATIONS ----------------------------------------------------*/
int TokenMgr(int i);
void ToLower(char* d,char* s);
int ReserveWord(char* s);
int cmtMng(int i); 
void cmtPrinter(int tc);
void nameMapInit(void);
void reserveWordMapInit(void);
/*---------------------------------------------------------------------------*/

/* GLOBALS ------------------------------------------------------------------*/
static map<string,int> RW;              //MAP FROM TOKEN SPELLING TO TOKE CODE
static map<int,string> NAME;            //MAP FROM TOKEN INT TO TOKEN SPELLING
int line 	= 1;						// KEEPS TRACK OF LINE #
int col 	= 1;						// KEEPS TRACK OF COLLUMN #
/*---------------------------------------------------------------------------*/

/* EXTERNAL VARIABLES--------------------------------------------------------*/
extern ofstream o; 						// WRITES TO FILES
/*---------------------------------------------------------------------------*/
%}

%%
[\n]										{line++; col = 1;}
[ \t]+        								{col += yyleng;}
[_a-zA-Z][_a-zA-Z0-9]*						return TokenMgr(ID);
"+"											return TokenMgr(PLUS);
"-"											return TokenMgr(MINUS);
"*" 										return TokenMgr(STAR);
"/"											return TokenMgr(SLASH);
":=" 										return TokenMgr(ASSIGN);
"." 										return TokenMgr(PERIOD);
","											return TokenMgr(COMMA);
";"											return TokenMgr(SEMICOLON);
":" 										return TokenMgr(COLON);
"="											return TokenMgr(EQU);
"<>" 										return TokenMgr(NEQ);
"<" 										return TokenMgr(LES);
"<=" 										return TokenMgr(LEQ);
">" 										return TokenMgr(GRT);
">=" 										return TokenMgr(GEQ);
"(" 										return TokenMgr(LPAREN);
")" 										return TokenMgr(RPAREN);
"[" 										return TokenMgr(LBRACKET);
"]"											return TokenMgr(RBRACKET);
".."										return TokenMgr(RANGE);
"{"([^}]*)"}" 								return cmtMng(COMMENT);
[0-9]+ 										return TokenMgr(INTLIT);
[0-9]+"."[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? return TokenMgr(REALIT); 
[0-9]+(("e"|"E")("-"|"+")?[0-9]+)? 			return TokenMgr(REALIT); 
 (['][a-zA-Z0-9]['])|([']['"][']) 			return TokenMgr(CHRLIT);
. 											; /* TEST FOR UNCAUGHT CATCHES */
%%

/* ----------------------------------------------------------------------------
	FUNCTION FOR HANDLING COMMENTS
-----------------------------------------------------------------------------*/
int cmtMng(int i){
	cmtPrinter(i);
	for(int j = 0; j<yyleng; j++){
		if(yytext[j] == '\n'){
			line++;
			col = 1;
			o << endl;
			cmtPrinter(i);
		} else {
			col++;
			o << yytext[j];
		}
	}
	o << endl;
	return 1;
}
//-----------------------------------------------------------------------------

/* ----------------------------------------------------------------------------
	FUNCTION USED BY COMMENT MANAGER FOR PRINTING EACH LINE
-----------------------------------------------------------------------------*/
void cmtPrinter(int tc){
	o << "Token:Code=";
	o << setw(4) << tc;
	o << " Name= ";
	o << setw(10) << NAME[tc];
	o << " line= ";
	o << setw(3) << line;
	o << " col= ";
	o << setw(3) << col;
	o << " Spelling=";
}
/*---------------------------------------------------------------------------*/

/* FUNCTION USED FOR ALL OTHER TOKENS ---------------------------------------*/
int TokenMgr(int i){
	int tc = i;

	if (i == ID){
		char* s=new char[yyleng];     
  		ToLower(s,yytext);
  		tc = ReserveWord(s);
	}
	col += yyleng;

	o << "Token:Code=";
	o << setw(4) << tc;
	o << " Name= ";
	o << setw(10) << NAME[tc];
	o << " line= ";
	o << setw(3) << line;
	o << " col= ";
	o << setw(3) << col - yyleng;
	o << " Spelling=";
	o << setw(10) << yytext;
	o << endl;
	return i;
}
/*---------------------------------------------------------------------------*/

/* CHECK IF AN ID IS A RESERVER WORK ----------------------------------------*/
int ReserveWord(char* s)
{
    int t=RW[(string)s];
    if (t>0) return t; else return ID;
}
/*---------------------------------------------------------------------------*/

/* FORCE TO LOWER CASE, SO ID AND RESERVE WORDS ARE CASE INSENSITIVE --------*/
void ToLower(char* d,char* s)
{   strcpy(d,s);
    for (int a=0;a<strlen(d);a++) d[a]=tolower(d[a]);
}
/*---------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------
	MAKES MAP THE TAKES STRING TYPE OF TOKEN AND RETURNS IT'S INTETEGER VALUE
-----------------------------------------------------------------------------*/
void reserveWordMapInit(void){
	RW["begin"]		=BEGAN;
    RW["end"  ]		=END;
    RW["div"]		=DIV;
    RW["do"]		=DO;
    RW["else"]		=ELSE;
    RW["end"]		=END;
    RW["function"]	=FUNCTION;
    RW["if"]		=IF;
    RW["mod"]		=MOD;
    RW["not"]		=NOT;
    RW["of"]		=OF;
    RW["or"]		=OR;
    RW["procedure"]	=PROCEDURE;
    RW["program"]	=PROGRAM;
    RW["then"]		=THEN;
    RW["to"]		=TO;
    RW["type"]		=TYPE;
    RW["var"]		=VAR;
    RW["while"]		=WHILE;
}
/*---------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------
	MAKES MAP THE TAKES INTEGER VALUE OF TOKEN AND RETURNS IT'S STRING,
	SPELLING VALUE.
-----------------------------------------------------------------------------*/
void nameMapInit(void){
	NAME[PLUS] 			= "PLUS";
    NAME[MINUS] 		= "MINUS";
    NAME[STAR] 			= "STAR";
    NAME[SLASH] 		= "SLASH";
    NAME[ASSIGN] 		= "ASSIGN";
    NAME[PERIOD] 		= "PERIOD";
    NAME[COMMA] 		= "COMMA";
    NAME[SEMICOLON] 	= "SEMICOLON";
    NAME[COLON] 		= "COLON";
    NAME[EQU] 			= "EQU";
    NAME[NEQ] 			= "NEQ";
    NAME[LES] 			= "LES";
    NAME[LEQ] 			= "LEQ";
    NAME[GRT] 			= "GRT";
    NAME[GEQ] 			= "GEQ";
    NAME[LPAREN] 		= "LPAREN";
    NAME[RPAREN] 		= "RPAREN";
    NAME[LBRACKET] 		= "LBRACKET";
    NAME[RBRACKET] 		= "RBRACKET";
    NAME[RANGE] 		= "RANGE";
    NAME[AND] 			= "AND";
    NAME[ARRAY] 		= "ARRAY";
    NAME[BEGAN] 		= "BEGIN";
    NAME[DIV] 			= "DIV";
    NAME[DO] 			= "DO";
	NAME[ELSE] 			= "ELSE"; 
	NAME[END] 			= "END"; 
	NAME[FUNCTION] 		= "FUNCTION"; 
	NAME[IF] 			= "IF";
	NAME[MOD] 			= "MOD"; 
	NAME[NOT] 			= "NOT"; 
	NAME[OF] 			= "OF"; 
	NAME[OR] 			= "OR"; 
	NAME[PROCEDURE] 	= "PROCEDURE"; 
	NAME[PROGRAM] 		= "PROGRAM";
	NAME[THEN] 			= "THEN";
	NAME[TO] 			= "TO";
	NAME[TYPE] 			= "TYPE"; 
	NAME[VAR] 			= "VAR"; 
	NAME[WHILE] 		= "PLUS"; 
	NAME[ID] 			= "ID"; 
	NAME[INTLIT] 		= "INTLIT"; 
	NAME[REALIT] 		= "REALIT";
	NAME[CHRLIT] 		= "CHRLIT";
	NAME[COMMENT] 		= "COMMENT";
}
/*----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------
	CHANGES STANDARD INPUT AND POPULATES THE RESERVE WORK MAP AND THE NAMING
	MAP
-----------------------------------------------------------------------------*/
Lexer::Lexer(FILE* i)
{   
	yyin=i;
	reserveWordMapInit();
	nameMapInit();
}
/*---------------------------------------------------------------------------*/

/* FETCH SPELLING FOR USE IN PAS.CPP ----------------------------------------*/
char* Lexer::FetchSpelling(void)
{
    return (char*)yytext;
}
/*---------------------------------------------------------------------------*/