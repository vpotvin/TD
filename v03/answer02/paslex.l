%{
//--------------------------------------------------------------------
// File paslex.l defines a prototype scanner for the Subset Pascal language.
// The scanner definition is a lex specification.                        
//-------------------------------------------------------------------
// Author: Thomas R. Turner                                           
// E-Mail: trturner@ucok.edu                                          
// Date:   January, 2009
//--------------------------------------------------------------------
//Copyright January, 2009 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// Standard C and C++ Library Include Files                                     
//--------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>                          
#include <cstdio>
#include <map>
using namespace std;
//--------------------------------------------------------------------
// Application Includes                                               
//--------------------------------------------------------------------
#include "paslex.h"
#include "pastkn.h"
//--------------------------------------------------------------------
//Externals
//--------------------------------------------------------------------
extern ofstream tfs;
//--------------------------------------------------------------------
//Global Variables                                                    
//--------------------------------------------------------------------
static map<string,int> RW;
static int tokencode;
static string* TokenName;
int line=1;
int col =1;
//--------------------------------------------------------------------
//Functions
//--------------------------------------------------------------------
int TokenMgr(int t);                   //Token post processing
                                       //Print the token and attributes
void PrintToken(ostream& o,int tc,int l,int c);           
//--------------------------------------------------------------------
//Exceptions
//--------------------------------------------------------------------
struct StringTokenException{
    StringTokenException(char* t,int l,int c)
    {   cout << endl;
        cout << "line(" << l << ") col (" << c << ")" ;
        cout << "Lexical error: ";
        cout << "Strings cannot span lines";
        cout << endl;
        cout << "|" << t << "|";
        cout << endl;
    }
};
struct BadCharacterException{
    BadCharacterException(char p,int l,int c)
    {   cout << endl;
        cout << "line(" << l << ") col (" << c << ")" ;
        cout << "Lexical error: ";
        cout << "Illegal character |" << p << "| ASCII code=" << (int)p;
        cout << endl;
    } 
};
%}

%%
[ \t]+                               {col+=strlen(yytext);}
[\n]                                 {line++;col=1;}
[_a-zA-Z][_a-zA-Z0-9]*               return TokenMgr(ID);
[0-9]+                               return TokenMgr(INTLIT);
[0-9]+[Ee][+-]?[0-9]+                return TokenMgr(REALIT);
[0-9]+\.[0-9]+([Ee][+-]?[0-9]+)?     return TokenMgr(REALIT);
[']([^']|[']['])*[']                 return TokenMgr(CHRLIT);

[{][^}]*[}]                          { for (int a=0;a<strlen(yytext);a++) {
                                           col++;
                                           if (yytext[a]=='\n') {
                                               col=1;
                                               line++;
                                           }
                                       }
                                     }
"+"                                  return TokenMgr(PLUS);
"-"                                  return TokenMgr(MINUS);
"*"                                  return TokenMgr(STAR);
"/"                                  return TokenMgr(SLASH);
":="                                 return TokenMgr(ASSIGN);
"."                                  return TokenMgr(PERIOD);
","                                  return TokenMgr(COMMA);
";"                                  return TokenMgr(SEMICOLON);
":"                                  return TokenMgr(COLON);
"="                                  return TokenMgr(EQU);
"<>"                                 return TokenMgr(NEQ);
"<"                                  return TokenMgr(LES);
"<="                                 return TokenMgr(LEQ);
">"                                  return TokenMgr(GRT);
">="                                 return TokenMgr(GEQ);
"("                                  return TokenMgr(LPAREN);
")"                                  return TokenMgr(RPAREN);
"["                                  return TokenMgr(LBRACKET);
"]"                                  return TokenMgr(RBRACKET);
".."                                 return TokenMgr(RANGE);
.                                    {throw BadCharacterException
                                              (*yytext
                                              ,line
                                              ,col
                                              );
                                     }
%%
//--------------------------------------------------------------------
//Class Lexer implementation
//--------------------------------------------------------------------
//Function TokenMgr processes the token after it has been recognized
//--------------------------------------------------------------------
int TokenMgr(int t)
{   int tc=t;
    if (t==ID) {
        char s[1024];
        for (int a=0;a<strlen(yytext)&&a<1024;a++) s[a]=tolower(yytext[a]);
        s[strlen(yytext)]=0;
        tc=RW[s];
        if (tc==0) tc=t;
    }
    PrintToken(tfs,tc,line,col);
    col+=yyleng;
    return tc; 
}
//--------------------------------------------------------------------
//Constructor Lexer is used to redirect the input file stream from the
//keyboard to input file stream i.
//--------------------------------------------------------------------
Lexer::Lexer(FILE* i) 
{   yyin=i; 
    const int MAXSY=48;
    static string sy[]=
    { "TOKEN_BEGIN"
    , "PLUS"
    , "MINUS"
    , "STAR"
    , "SLASH"
    , "ASSIGN"
    , "PERIOD"
    , "COMMA"
    , "SEMICOLON"
    , "COLON"
    , "EQU"
    , "NEQ"
    , "LES"
    , "LEQ"
    , "GEQ"
    , "GRT"
    , "LPAREN"
    , "RPAREN"
    , "LBRACKET"
    , "RBRACKET"
    , "RANGE"
    , "RESERVE_WORDS"
    , "AND"
    , "ARRAY"
    , "BEGIN"
    , "DIV"
    , "DO"
    , "ELSE"
    , "END"
    , "FUNCTION"
    , "IF"
    , "MOD"
    , "NOT"
    , "OF"
    , "OR"
    , "PROCEDURE"
    , "PROGRAM"
    , "THEN"
    , "TO"
    , "TYPE"
    , "VAR"
    , "WHILE"
    , "REGULAR_EXPRESSIONS"
    , "ID"
    , "INTLIT"
    , "REALIT"
    , "CHRLIT"
    , "TOKEN_END"
    };
    TokenName=new string[MAXSY];
    for (int a=0;a<MAXSY;a++) TokenName[a]=sy[a];
    static string rw[]=
    {
     "and"       
    ,"array"      
    ,"begin"      
    ,"div"
    ,"do"         
    ,"else"  
    ,"end"        
    ,"function"
    ,"if"         
    ,"mod"  
    ,"not"        
    ,"of"         
    ,"or"
    ,"procedure"
    ,"program"    
    ,"then"       
    ,"to"         
    ,"type"
    ,"var"        
    ,"while"
    };
    static int    tc[]=
    {
      AND        
    , ARRAY      
    , BEGiN      
    , DIV        
    , DO         
    , ELSE       
    , END        
    , FUNCTION   
    , IF  
    , MOD        
    , NOT        
    , OF         
    , OR         
    , PROCEDURE  
    , PROGRAM    
    , THEN       
    , TO 
    , TYPE        
    , VAR        
    , WHILE
    };
    for (int a=0;a<20;a++) RW[rw[a]]=tc[a];
}
//--------------------------------------------------------------------
//Function Lex calls yylex
//--------------------------------------------------------------------
int Lexer::Lex(void)
{   tokencode=yylex();
    return tokencode;
}
//--------------------------------------------------------------------
//Function PrintToken prints the token code name and the spelling of the 
//token.
//--------------------------------------------------------------------
void PrintToken(ostream& o,int tc,int l,int c)
{   o << endl;
    o << "Token";
    o << ":Code="     << setw( 3) << tc;
    o << " Name="     << setw(10) << TokenName[tc-TOKEN_BEGIN];
    o << " line="     << setw( 3) << l;
    o << " col="      << setw( 3) << c;
    o << " Spelling=\"" << (char*)yytext << "\"";
}

//-----------------------End of Lex Definition------------------------
     



