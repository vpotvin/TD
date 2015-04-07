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
#include "subprogram_prolog.h"
#include "subprogram_epilog.h"
#include "program_epilog.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;          //Trace File Stream
extern ofstream pfs;          //PCode File Stream
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void program(SubprogramSymbol* S,List<Exp*>* compound_statement)
{
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

    List<Exp*>* programepilog=program_epilog(S);
    tfs << endl << "program epilog";
    programepilog->Print(tfs);
    //-----------------------------------------------------------------------
    //Now, concatenate the prolog, compound_statement, and the epilog into
    //a single list.
    //-----------------------------------------------------------------------
    List <Exp*>* L=new List<Exp*>;
    L->Append(prolog);
    L->Append(compound_statement);
    L->Append(epilog);
    L->Append(programepilog);
    //-----------------------------------------------------------------------
    //Now, print the subprogram to the PCode File
    //-----------------------------------------------------------------------
    L->Print(pfs);


    ST.Print(tfs);            //Print Locality 1
    ST.PopLocality();
    ST.Print(tfs);            //Print Locality 0
}
