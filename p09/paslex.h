#ifndef paslex_h
#define paslex_h 1

#include <cstdio>
#include <fstream>
#include <iostream>
using namespace std;

#ifdef __cplusplus
extern "C" 
#endif
int yylex (void);
class Lexer {
public:
  Lexer(FILE* i);
  int Lex(void); 
};
#endif
