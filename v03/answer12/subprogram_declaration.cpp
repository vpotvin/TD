//---------------------------------------------------------
//File subprogram_declaration.cpp defines semantics for the production
//subprogram_declaration->subprogram_head declarations compound_statement
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
#include "subprogram_declaration.h"
#include "subprogram_prolog.h"
#include "subprogram_epilog.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern ofstream pfs;
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void subprogram_declaration(SubprogramSymbol* S,List<Exp*>* compound_statement)
{   //-----------------------------------------------------------------------
    //Create a list of expressions containing the subprogram prolog, the 
    //compound statement of the subprogram itself, and the subprogram epilog 
    //making the entire subprogram.
    //-----------------------------------------------------------------------
    //First, verify that all is well in the trace file for the prolog,
    //compound_statement, and the epilog.
    //-----------------------------------------------------------------------
    List<Exp*>* prolog=subprogram_prolog(S);
    tfs << endl << "prolog";
    prolog->Print(tfs);
    tfs << endl << "compound_statement";
    compound_statement->Print(tfs);
    List<Exp*>* epilog=subprogram_epilog(S,compound_statement);
    tfs << endl << "epilog";
    epilog->Print(tfs);
    //-----------------------------------------------------------------------
    //Now, concatenate the prolog, compound_statement, and the epilog into
    //a single list.
    //-----------------------------------------------------------------------
    List <Exp*>* L=new List<Exp*>;
    L->Append(prolog);
    L->Append(compound_statement);
    L->Append(epilog);
    //-----------------------------------------------------------------------
    //Now, print the subprogram to the PCode File
    //-----------------------------------------------------------------------
    L->Print(pfs);

    ST.Print(tfs);            //Print the symbol table at this lexical level
    ST.PopLocality();         //Pop the current locality
}
