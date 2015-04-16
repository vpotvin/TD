//-------------------------------------------------------------------------
//File program_epilog.cpp produces the epilog for a program 
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     April, 2012
//---------------------------------------------------------------------
//Copyright April, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
#include "List.h"
#include "yyerror.h"
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
#include "Label.h"
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "ToString.h"
#include "Height.h"
//-------------------------------------------------------------------------
//program_prolog.h
//-------------------------------------------------------------------------
#include "program_epilog.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream o;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;
//---------------------------------------------------------------------
//---------------------------------------------------------------------
List<Exp*>* program_epilog(SubprogramSymbol* S)
{   //-----------------------------------------------------------------
    //Create a List of expression for the program epilog
    //-----------------------------------------------------------------
    List<Exp*>* L=new List<Exp*>;

    //-----------------------------------------------------------------
    //Create and insert the mark stack pcode that creates the 
    //stack mark for the program
    //-----------------------------------------------------------------
    PCode* P=new PCode("","mst","0","");
    Exp* E=new Exp(ST.TVoid(),P);
    L->Insert(E);
   
    //-----------------------------------------------------------------
    //Create and insert the call to the program body
    //-----------------------------------------------------------------
    P=new PCode("","cup","0",S->ELabel());
    E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    //-----------------------------------------------------------------
    //Create and insert the stop instruction to halt the p-code 
    //interpreter
    //-----------------------------------------------------------------
    P=new PCode("","stp","","");
    E=new Exp(ST.TVoid(),P);
    L->Insert(E);

    return L;
}

