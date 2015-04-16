#ifndef subprogram_prolog_h
#define subprogram_prolog_h 1
//-------------------------------------------------------------------------
//File subprogram_prolog.cpp produces the prolog for programs, functions,
//and procedures. 
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
//---------------------------------------------------------------------
//---------------------------------------------------------------------
List<Exp*>* subprogram_prolog(SubprogramSymbol* S);
#endif
