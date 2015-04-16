//---------------------------------------------------------
//File program.cpp defines semantics for the production
//program_head->PROGRAM ID program_parameters ;
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
#include "program_head.h"
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
//Function ParameterList creates a parameter list from a list of Variables
//---------------------------------------------------------------------
static Subprogram* ParameterList(List<VariableSymbol*>* VL,Typ* RT)
{   List<Typ*>* PL=new List<Typ*>;
    for (VL->First();!VL->IsEol();VL->Next())
    {   VariableSymbol* S=VL->Member();
        Typ* T=S->Type();
        PL->Insert(T);
    }
    return new Subprogram(PL,RT);
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
SubprogramSymbol* program_head(string id)
{  List<VariableSymbol*>* VL=new List<VariableSymbol*>;
   Subprogram* PL=ParameterList(VL,ST.TVoid());
   ProcedureSymbol* P=new ProcedureSymbol(id,PL,0);

   ST.Insert(P);
   ST.NewLocality();
   return P;
}
