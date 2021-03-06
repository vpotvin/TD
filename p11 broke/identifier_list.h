#ifndef identifier_list_1
#define identifier_list_1 1
//---------------------------------------------------------------------
//File identifier_list.h defines semantics for an identifier_list
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   January, 2012
//---------------------------------------------------------------------
//Copyright: January, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//C and C++ include files
//---------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
//---------------------------------------------------------------------
//Application include files
//---------------------------------------------------------------------
#include "List.h"
//---------------------------------------------------------------------
//Function identifier_list creates a list of identifiers and appends
//the first identifier on the list.
//---------------------------------------------------------------------
List<string>* identifier_list
    (string* i
    );
//---------------------------------------------------------------------
//Function identifier_list appends an identifier onto an existing list.
//---------------------------------------------------------------------
List<string>* identifier_list
    (List<string>* L
    ,string* i
    );
#endif
