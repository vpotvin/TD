#ifndef paspar_h
#define paspar_h 1

#include "paslex.h"

#ifdef __cplusplus
extern "C" 
#endif

int yyparse (void);

#endif


class Parser : public Lexer {
public:
	Parser(FILE* i);
	int Parse(void);
};