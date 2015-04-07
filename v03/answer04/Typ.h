#ifndef Typ_h 
#define Typ_h 1
//-----------------------------------------------------------------------------
//File Typ.h defines the attributes of types for the Subset Pascal
//symbol table 
//-----------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//January, 2012
//-----------------------------------------------------------------------------
//Copyright January, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
//C++ include files and namespace std
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
//-----------------------------------------------------------------------------
//Application include files
//-----------------------------------------------------------------------------
#include "List.h"
//-----------------------------------------------------------------------------
//Forward declarations
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//type classification - kinds of types
//-----------------------------------------------------------------------------
enum typekind
  {tk_void                    //type void
  ,tk_address                 //type address
  ,tk_boolean                 //type Boolean
  ,tk_character               //type character
  ,tk_integer                 //type integer
  ,tk_real                    //type real
  ,tk_range                   //type range
  ,tk_array                   //type array
  ,tk_subprogram              //programs, functions, and procedures
  };
//-----------------------------------------------------------------------------
//Define the attributes base class typ
//-----------------------------------------------------------------------------
class Typ {
    typekind tk;                                  //type classification
public:
    Typ();
    Typ(typekind t);                              
    string TypekindSymbol(typekind tk);
    virtual void Print(ostream& o,int indent);
    virtual int Size();
    virtual int Alignment();
    bool IsRange(void);
    bool IsVoid(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Scalar: public Typ {
    int size;                 //Number of bits required to store an entity of
                              //this type
    int alignment;            //Alignment specification for this type
public:
    
    Scalar(typekind tk);
    Scalar(typekind tk,int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
   
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Boolean:public Scalar {
public:
    Boolean();
    Boolean(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Character:public Scalar {
public:
    Character();
    Character(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Integer:public Scalar {
public:
    Integer();
    Integer(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Real:public Scalar {
public:
    Real();
    Real(int sz,int al);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Void:public Scalar {
public:
    Void();
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Constant {
    Typ* t;                   //Constant type
    string v;                 //Constant value
public:
    Constant(Typ* T,string V);
    void Print(ostream& o,int indent);
    Typ* Type(void);
    int IntegerValue(void);
    int Size(void);
    int Alignment(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Range :public Typ{
    Constant *lo;
    Constant *hi;
public:
    Range(Typ* t,const char* l,const char* h);
    Range(Typ* t,string l,string h);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
    int Cardinality(void);
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class Array: public Typ {
    Typ* index;
    Typ* element;
public:
    Array(Typ* i,Typ* e);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};
//-----------------------------------------------------------------------------
//class Subprogram characterizes both user and standard subprograms
//The first parameter is the return type.
//If the first parameter has type tk_void then the subprogram is a procedure.
//If the first parameter does not have type tk_void then the subprogram is a function.
//-----------------------------------------------------------------------------
class Subprogram: public Typ {
    List<Typ*>* parameters;                       //Parameters
    Typ* returntype;                              //Return type
public:
    Subprogram(List<Typ*>* p,Typ* rt);
    void Print(ostream& o,int indent);
    int Size(void);
    int Alignment(void);
};
#endif

