#!/bin/bash
# My first script

rm out.txt

rm main

rm paslex.cpp

make -f makePas

rm main.o
rm paslex.o

./main in.txt out.txt
