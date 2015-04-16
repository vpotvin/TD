#ifndef term_h
#define term_h 1
//-------------------------------------------------------------------------
//File term.h contains prototypes for the following productions: 
//term -> factor
//term -> term mulop factor
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
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> factor
//-------------------------------------------------------------------------
Exp* term(Exp* f);
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> term mulop factor
//-------------------------------------------------------------------------
Exp* term(Exp* t,string* op,Exp* f);
#endif
