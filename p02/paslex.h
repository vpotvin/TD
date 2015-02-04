#ifndef paslex_h
#define paslex_h 1

#include <cstdio>
using namespace std;

#ifdef __cplusplus
extern "C" 
#endif

class Lexer {
public:
  Lexer(FILE* i);
  int Lex(void); 
};
#endif
