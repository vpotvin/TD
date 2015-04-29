//-------------------------------------------------------------------------
//File subprogram_epilog.cpp produces the epilog for functions and procedures. 
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
//subprogram_prolog.h
//-------------------------------------------------------------------------
#include "subprogram_epilog.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream tfs;
extern int line;
extern int col;
extern SymbolTable ST;
extern Label L;
//---------------------------------------------------------------------
//---------------------------------------------------------------------
List<Exp*>* subprogram_epilog(SubprogramSymbol* S,List<Exp*>* compound_statement)
{  List<Exp*>* L=new List<Exp*>;
   string tc=S->ReturnType()->TypeChar();
   PCode* P=new PCode("","rtn",tc,"");
   Exp* E=new Exp(ST.TVoid(),P);
   E->Print(tfs);
   tfs << endl;
   L->Insert(E);
   int spvalue =ST.Offset();
   P=new PCode("#define",S->SPLabel(),spvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(tfs);
   tfs << endl;
   L->Insert(E);
   Height H;
   //-----------------------------------------------------------------------
   //Find the maximum height of the computation stack, epvalue
   //-----------------------------------------------------------------------
   for (compound_statement->First();!compound_statement->IsEol();compound_statement->Next()) {
       Exp* E=compound_statement->Member();
       H.FindHeight(E);
   }
   tfs << endl;
   int epvalue=spvalue+H.Maximum();
   P=new PCode("#define",S->EPLabel(),epvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(tfs);
   tfs << endl;
   L->Insert(E);
   return L;
}

