#ifndef expression_list_h
#define expression_list_h 1
//-------------------------------------------------------------------------
//File expression_list.h contains prototypes for the following productions: 
//expression_list_1: expression_list -> expression
//expression_list_2: expression_list -> expression_list , expression
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
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "ToString.h"
//-------------------------------------------------------------------------
//Function Expression implements the rule
//expression_list -> expression 
//-------------------------------------------------------------------------
List<Exp*>* expression_list(Exp* expression);
//--------------------------------------------------------------------
//Expression_2: expression_list -> expression_list , expression 
//--------------------------------------------------------------------
List<Exp*>* expression_list(List<Exp*>* expression_list,Exp* expression);
#endif
