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


//-----------------------------------------------------------------------
//Function LexMgr processes the input file, calls yylex, the scanner, and
//produces the output file.
void LexMgr(FILE* i,ostream& o) {

  Lexer L(i);                 //Redirect yylex to read file i instead of

  for (int t=yylex();t>0;t=yylex()){

  }
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
