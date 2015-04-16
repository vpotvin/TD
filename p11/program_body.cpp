//-------------------------------------------------------------------------
//File program_body.cpp contains implementations for the following 
//productions: 
//program_body -> compound_statement . 
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
#include "Label.h"
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "ToString.h"
//-------------------------------------------------------------------------
//Function prototypes are given in file program_body.h
//-------------------------------------------------------------------------
#include "program_body.h"
//-------------------------------------------------------------------------
//Function program_body implements the rule
//program_body -> BEGIN optional_statements END
//-------------------------------------------------------------------------
List<Exp*>* Program_body(List<Exp*>* compound_statement)
{  return compound_statement;
}
