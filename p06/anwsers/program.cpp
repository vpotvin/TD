//---------------------------------------------------------
//File program.cpp defines semantics for the production
//program->program_head program_declarations program_body
//---------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   February, 2012
//---------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner
//Do not reproduce without permission from Thomas R. Turner
//---------------------------------------------------------
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Application inlcude files
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "List.h"
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//Semantic include files
//---------------------------------------------------------------------
#include "program.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void program(void)
{  
   tfs << endl;
   tfs << "Before::LexicalLevel=" << ST.LexicalLevel();
   ST.Print(tfs);             //Print Locality 1
   ST.PopLocality();
   tfs << " ";
   tfs << "After::LexicalLevel=" << ST.LexicalLevel();
   tfs << endl;
   ST.Print(tfs);             //Print Locality 0
}
