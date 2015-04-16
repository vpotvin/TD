#ifndef usersubprogram_h
#define usersubprogram_h 1
//---------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   March, 2012
//---------------------------------------------------------
//Copyright March, 2012 by Thomas R. Turner
//Do not reproduce without permission from Thomas R. Turner
//---------------------------------------------------------
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
#include "ToString.h"
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

//-------------------------------------------------------------------------
//Function UserSubprogram implements the rule
//procedure_statement -> ID ( expression_list )
//procedure_statement -> ID
//factor -> ID ( expression_list )
//factor -> ID *where ID is a function*
//when ID is the name of a user procedure.
//-------------------------------------------------------------------------
Exp* UserSubprogram(SubprogramSymbol* S,List<Exp*>* e);
#endif
