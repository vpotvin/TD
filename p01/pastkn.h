#ifndef pastkn_h
#define pastkn_h 1
//--------------------------------------------------------------------
// File pastkn.h defines class Lexer.  
//--------------------------------------------------------------------
// Author: Thomas R. Turner                                           
// E-Mail: trturner.ucok.edu                                          
// Date:   March, 2003                                              
//--------------------------------------------------------------------
//includes                                        
//--------------------------------------------------------------------
//#include <cstdio>
//#include <fstream>
//#include <iostream>
//using namespace std;
//--------------------------------------------------------------------

#ifdef __cplusplus
extern "C" 
#endif
int yylex (void);
//--------------------------------------------------------------------
//Token definitions
//--------------------------------------------------------------------
#define PLUS 		1
#define MINUS 		2
#define STAR 		3
#define SLASH 		4
#define ASSIGN 		5
#define PERIOD 		6
#define COMMA 		7
#define SEMICOLON 	8
#define COLON 		9
#define EQU 		10
#define NEQ 		11
#define LES 		12
#define LEQ 		13
#define GRT 		14
#define GEQ 		15
#define LPAREN 		16
#define RPAREN 		17
#define LBRACKET 	18
#define RBRACKET 	19
#define RANGE 		20
#define AND 		21
#define ARRAY 		22
#define BEGIN 		23
#define DIV 		24
#define DO 			25
#define ELSE 		26
#define END 		27
#define FUNCTION 	28
#define IF 			29
#define MOD 		30
#define NOT 		31
#define OF 			32
#define OR 			33
#define PROCEDURE 	34
#define PROGRAM 	35
#define THEN 		36
#define TO 			37
#define TYPE 		38
#define VAR 		39
#define WHILE 		40

//--------------------------------------------------------------------
//Class Lexer defines the attributes of a Scanner
//--------------------------------------------------------------------
// class Lexer {
//   int tokencode;                 //Code for the most recent token found
// public:
//   Lexer(FILE* i);                //Constructor used to redirect the keyboard
//                                  //(stdin) to file i.
//   int Lex(void);                 //Call the scanner yylex and return the code
//                                  //found by yylex
//   int FetchTokenCode(void);      //Return the code of the most recent token
//   void StoreTokenCode(int T);    //Store the token code.
//   char* FetchSpelling(void);     //Return the spelling of the most recent
//                                  //token
// };
#endif
