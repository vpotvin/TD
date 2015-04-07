%{
#include <string>
#include "List.h"
#include "pastkn.h"
#include "paslex.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

using namespace std;

int line 	= 1;
int col 	= 1;
static map<string,int> RW;
static map<int,string> NAME;  

int yyparse ( void );
int TokenMgr(int t);
void ToLower(char* o,char* i,int l);
void nameInit(void);
void reserveWordInit(void);
void printTc(int t);
void commentMgr(void);

/* EXTERNAL VARIABLES--------------------------------------------------------*/
extern ofstream o; 						// WRITES TO FILES
/*---------------------------------------------------------------------------*/
%}

%x CHARBEGIN

%%

[ \t]+								{	col+= yyleng;				}
[\n]								{	line++; col=1;				}
[a-zA-Z_][a-zA-Z0-9_]*  			{ 	return TokenMgr(ID);		}
"+"									{	return TokenMgr(PLUS);		}
"-"									{	return TokenMgr(MINUS);		}
"*"									{	return TokenMgr(STAR);		}
"/"									{	return TokenMgr(SLASH);		}
":=" 								{	return TokenMgr(ASSIGN);   	}
"." 								{	return TokenMgr(PERIOD);   	}
","									{	return TokenMgr(COMMA);    	}
";"									{	return TokenMgr(SEMICOLON);	}
":" 								{	return TokenMgr(COLON);		}
"="									{	return TokenMgr(EQU);		}
"<>" 								{	return TokenMgr(NEQ);		}
"<" 								{	return TokenMgr(LES);		}
"<=" 								{	return TokenMgr(LEQ);		}
">" 								{	return TokenMgr(GRT);		}
">=" 								{	return TokenMgr(GEQ);		}
"(" 								{	return TokenMgr(LPAREN);	}
")" 								{	return TokenMgr(RPAREN);	}
"[" 								{	return TokenMgr(LBRACKET); 	}
"]"									{	return TokenMgr(RBRACKET);	}
".."								{	return TokenMgr(RANGE);		}
['"]  								{	BEGIN(CHARBEGIN);			}
<CHARBEGIN>("''"|[^'"\n])*  		{ 	return TokenMgr(CHRLIT);    }
<CHARBEGIN>['"]             		{ 	BEGIN INITIAL;              }
[0-9]+[Ee][+|-]?[0-9]+  			{	return TokenMgr(REALIT);	}
[0-9]+\.[0-9]+([Ee][+|-]?[0-9]+)?   { 	return TokenMgr(REALIT);  	}
[0-9]+                              { 	return TokenMgr(INTLIT);    }  
"{"([^}]*)"}" 						{	commentMgr();				}


. 			; // DO NOTHING WITH EVERYTHING ELSE FOR NOW
%%

int yywrap (void){ return 1;}

int TokenMgr(int t){
	int tc = t;
	if (t==ID) {
    	char s[1024];
        ToLower(s,yytext,yyleng);
        tc=RW[s];
        if (tc==0){ 
       		tc=t;
       	}
    }

    col += yyleng;

    yylval.token = new string(yytext);

    printTc(tc);
    return tc;
}

void printTc(int tc){
	o << "Token:Code="	<< setw(3) 	<< tc 
			<< " Name= " 		<< setw(8) 	<< NAME[tc] 
			<< " Line= "  		<< setw(3)	<< line 
			<< " Col= "   		<< setw(3)	<< col - yyleng
			<< " Spelling= " 	<< setw(1)	<< "\"" << yytext << "\""
			<< endl;
}

void commentMgr(void){
	for(int j = 0; j<yyleng; j++){
		if(yytext[j] == '\n'){
			line++;
			col = 1;
		} else {
			col++;
		}
	}
}


void reserveWordInit(void){
	RW["begin"]		=BEGAN;
    RW["end"  ]		=END;
    RW["and"]		=AND;
    RW["array"]		=ARRAY;
    RW["div"]		=DIV;
    RW["do"]		=DO;
    RW["else"]		=ELSE;
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

void nameInit(void){
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

void ToLower(char* k,char* i,int l)
{       for (int a=0;a<l&&a<1024;a++) k[a]=tolower(i[a]); //To lower case
        k[l]=0; //Null termination

}

Lexer::Lexer(FILE* i){
	yyin=i;
	nameInit();
	reserveWordInit();
}

int Lexer::Lex(void){
	int tokencode=yylex();
    return tokencode;
}

