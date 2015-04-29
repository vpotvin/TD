#ifndef simple_expression_h
#define simple_expression_h 1
//-------------------------------------------------------------------------
//File simple_expression.h contains prototypes for the following productions: 
//simple_expression -> term 
//simple_expression -> sign term 
//simple_expression -> simple_expression addop term 
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
//Symbol Table
//---------------------------------------------------------------------
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//P-Code and expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//Function simple_expression_1 implements the rule
//simple_expression -> term
//-------------------------------------------------------------------------
Exp* simple_expression(Exp* term);
//--------------------------------------------------------------------
//Function simple_expression -> sign term
//--------------------------------------------------------------------
Exp* simple_expression(string* sign, Exp* term);
//--------------------------------------------------------------------
//Function simple_expression -> simple_expression addop term
//--------------------------------------------------------------------
Exp* simple_expression(Exp* simpleexpression, string* addop, Exp* term);
#endif
