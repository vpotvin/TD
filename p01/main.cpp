#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

#include "paslex.h"
#include "y.tab.h"

ofstream o;  

struct FileException {
  FileException(const char* fn)
  {  cout << endl;
     cout << "File " << fn << " cannot be opened.";
     cout << endl;
  }
};

struct CommandLineException {
  CommandLineException(int m,int a)
  {  cout << endl; 
     cout << "Too many file names on the command line.";
     cout << endl;
     cout << "A maximum of " << m << " file names can appear on the command line.";
     cout << endl;
     cout << a << " file names were entered.";
     cout << endl;
     cout << "p01 (<input file name> (<output file name>))";
  }
};


// void Title(ostream& o)
// {   o << endl;
//     o << setw(15) << "Token Code";
//     o << " ";
//     o << setw(15) << "Token Name";
//     o << " ";
//     o << "Token Spelling";
// }
//-----------------------------------------------------------------------
//Function LexMgr processes the input file, calls yylex, the scanner, and
//produces the output file.
void LexMgr(FILE* i,ostream& o) {
  static const char* TokenName[]=
           {"PLACEHOLDER" ,"PLUS"     ,"MINUS"    ,"STAR"       ,"SLASH"
            ,"ASSIGN"     ,"PERIOD"   ,"COMMA"    ,"SEMICOLON"  ,"COLON"
            ,"EQU"        , "NEQ"     ,"LES"      ,"LEQ"        ,"GRT"     ,"GEQ"
            ,"LPAREN"     , "RPAREN"  ,"LBRACKET" ,"RBRACKET"   ,"RANGE"   ,"AND"
            ,"ARRAY"      , "BEGAN"   ,"DIV"      ,"DO"         ,"ELSE"    ,"END"
            ,"FUNCTION"   , "IF"      ,"MOD"      ,"NOT"        ,"OF"      ,"OR"
            ,"PROCEDURE"  , "PROGRAM" ,"THEN"     ,"TO"         ,"TYPE"    ,"VAR"
            ,"WHILE"      , "ID"      ,"INTLIT"   ,"REALIT"     ,"CHRLIT"  ,"COMMENT"
           };
  Lexer L(i);                 //Redirect yylex to read file i instead of
//                                 //the command line
// //    Title(o);

  int col;
  int line;

  for (int t=yylex();t>0;t=yylex()){

    // col   = L.getCol();
    // line  = L.getLine();

    // o << "Token:Code=";
    // o << t; 
    // o << " Name ";
    // o << TokenName[t];
    // o << " line=";
    // o << line;
    // o << " col=";
    // o << col;
    // o << " Spelling=";
    // o << L.FetchSpelling();
    // o << endl;



//         o << " ";
//         o << setw(15) << TokenName[t];
//         o << " ";
//  //       o << L.FetchSpelling();
  }
//     o << endl;
}
//-----------------------------------------------------------------------
//Function main processes command line arguments
//-----------------------------------------------------------------------
int main(int argc, char* argv[])
{  try {
     char ifn[255],ofn[255];
     switch (argc) {
       case 1://no files on the command line
         cout << "Enter the input file name. ";
         cin >> ifn;
         cout << "Enter the output file name. ";
         cin >> ofn;
         break;
       case 2://input file on the command line/prompt for output file
        strcpy(ifn,argv[1]);
         cout << "Enter the output file name. ";
         cin >> ofn;
         break;
       case 3://Both files on the input line
         strcpy(ifn,argv[1]);
         strcpy(ofn,argv[2]);
         break;
       default:
         throw CommandLineException(2,argc-1); 
         break;
     }
     FILE* i=fopen(ifn,"r"); if (!i) throw FileException(ifn);
    o.open(ofn); if (!o) throw FileException(ofn);

      LexMgr(i,o);
     
     fclose(i);
     o.close();
   } catch ( ... ) {
     cout << endl;
     cout << "Program Terminated!";
     cout << endl;
     cout << "I won't be back!";
     cout << endl;
     exit(EXIT_FAILURE);
   }
   return 0;
}
