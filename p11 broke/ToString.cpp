//-------------------------------------------------------------------------
//File ToString.cpp contains utility ToString that converts an integer to an
//equivalent string 
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
#include <sstream>
#include <string>
using namespace std;
//-------------------------------------------------------------------------
//Application include files
//-------------------------------------------------------------------------
#include "ToString.h"
//-------------------------------------------------------------------------
//Function ToString is a utility that converts integers to strings.
//-------------------------------------------------------------------------
string ToString(int i)
{  ostringstream o;
   o << i;
   return o.str();
}

