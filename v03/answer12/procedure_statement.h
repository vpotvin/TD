#ifndef procedure_statement_h
#define procedure_statement_h 1
//-------------------------------------------------------------------------
//File procedure_statement.h contains prototytpes for the 
//following productions: 
//procedure_statement: procedure_statement -> ID
//procedure_statement: procedure_statement -> ID ( expression_list )
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     February, 2012
//---------------------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner.
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
//---------------------------------------------------------------------
//lex and yacc support
//---------------------------------------------------------------------
#include "paslex.h"
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
//P-Code and Statement Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "ToString.h"
//-------------------------------------------------------------------------
//Function procedure_statement implements the rule
//procedure_statement: procedure_statement -> ID
//-------------------------------------------------------------------------
Exp* procedure_statement(string* id);
//-------------------------------------------------------------------------
//Function procedure_statement implements the rule
//procedure_statement: procedure_statement -> ID ( expression_list )
//-------------------------------------------------------------------------
Exp* procedure_statement(string* id, List<Exp*>* EL);
#endif
