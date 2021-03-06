#ifndef variable_h
#define variable_h 1
//-------------------------------------------------------------------------
//File variable.h defines function that implement rules for variable
//variable -> ID
//variable -> ID [ expression ]
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     March, 2012
//---------------------------------------------------------------------
//Copyright March, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
#include "List.h"
//---------------------------------------------------------------------
//lex and yacc support
//---------------------------------------------------------------------
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
#include "ToString.h"
#include "PCode.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//Function variable implements the rule
//variable -> ID
//-------------------------------------------------------------------------
Exp* variable(string* id);
//--------------------------------------------------------------------
//Function variable implements the rule
//variable -> ID [ expression ]
//1.  Find id - id must be an array
//2.  load the address of id
//3.  load the value of the expression
//4.  load the value of the smallest possible index value
//5.  subtract the index from the expression
//6.  add the difference to the address of id
//
//                    ixa stride  
//                    / 
//                   -   
//                  / \
//  index expression   index lobound
//                /
//           adr(array)
//--------------------------------------------------------------------
Exp* variable(string* id,Exp* e);
#endif
