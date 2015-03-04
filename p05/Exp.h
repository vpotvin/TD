#ifndef Exp_h
#define Exp_h 1

//Class Exp is designed to represent 
//p-code Expressions for the Subset Pascal Compiler

//Include Files
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


#include "PCode.h"
#include "Typ.h"
#include "Sym.h"

class Exp {
   Exp* LExp;
   Exp* RExp;
   Typ* T;
   PCode* P;
public:
   Exp(Typ* t,PCode* p);
   Exp(Exp* l,Exp* r,Typ* t,PCode* p);
   void PPrint(ostream& o);             //Print the P-Code of this instance
   void TPrint(ostream& o,int depth);   //Print the type of this instance
   void Print(ostream& o);              //Print P-Codes using postorder traversal
   Typ* Type(void);
   void LeftAppend(Exp* L);             //Append L to the leftmost leaf of this
													//expression
};
#endif
