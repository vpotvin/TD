// STL LIBS --------------------------------------------------------------------
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <iomanip>
//----------------------------------------------------------------------------

// CUSTOME HEADERS ------------------------------------------------------------
#include "paslex.h"
#include "pastkn.h"
//-----------------------------------------------------------------------------

// NAMESPACING ----------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------

// USED EXTERNALLY ------------------------------------------------------------
ofstream o;  
//-----------------------------------------------------------------------------

// EXCEPTIONS -----------------------------------------------------------------
struct FileException {
  FileException(const char* fn)
  {  cout << endl;
     cout << "File " << fn << " cannot be opened.";
     cout << endl;
  }
};

struct SuffixFileException {
  SuffixFileException() {  
    cout << endl;
    cout << "File Has Incorrect Suffix, Should Be .pas";
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
//-----------------------------------------------------------------------------

/*
  THIS VERY POORLY MADE FUNCTION CHECKS THE FILE EXTENSION AN THROWS AN ERROR -
  IF THE FILE EXTENSION IS NOT '.pas' ... IN THEORY IT WORKS
*/
void checkInput(char* s){
  char* input = new char[4];
  char* correct = new char[4];
  correct[0] = '.';
  correct[1] = 'p';
  correct[2] = 'a';
  correct[3] = 's';

  int j = 0;

  for(int i = strlen(s) - 4; i < strlen(s); i++){
    input[j] = s[i];
    j++;
  }

  if(strcmp(input, correct) == 0){

  } else {
    throw SuffixFileException();
  }


}
//-----------------------------------------------------------------------------

/*
  THIS VERY POORLY MADE FUNCTION MAKES THE FILENAME FOR THE -------------------
  OUT FILE FOR THE LEXER
*/
char* makeOutput(char* s){

  char* outputFile = new char[strlen(s) + 1];

  int i;

  for(i = 0; i < strlen(s) - 3; i++){
    outputFile[i] = s[i];
  }

  outputFile[i++] = 't';
  outputFile[i++] = 'r';
  outputFile[i++] = 'c';
  outputFile[i++] = '\0';

  return outputFile;
}
// ----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//Function LexMgr processes the input file, calls yylex, the scanner, and
//produces the output file.
void LexMgr(FILE* i,ostream& o) {

  Lexer L(i);                 //Redirect yylex to read file i instead of

  for (int t=yylex();t>0;t=yylex()){

  }
}
// ----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function main processes command line arguments
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{  try {
     char ifn[255],ofn[255];
     switch (argc) {
       case 1://no files on the command line
         cout << "Enter the input file name. ";
         cin >> ifn;
         checkInput(ifn);
         break;
       case 2://input file on the command line/prompt for output file
        strcpy(ifn,argv[1]);
        checkInput(ifn);
        strcpy(ofn, makeOutput(argv[1]));
         break;
       default:
         throw CommandLineException(1,argc-1); 
         break;
     }

    FILE* i=fopen(ifn,"r"); if (!i){
      throw FileException(ifn);
    }
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
//-----------------------------------------------------------------------------
