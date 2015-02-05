rm basic 
rm paslex.cpp
rm paspar.cpp
rm y.output
rm *.o
rm *.trc
rm y.tab.h

make -f pasMakeFile

./pas ../../../lab/lex/basic/p070_000.pas
#nano p070_000.trc
