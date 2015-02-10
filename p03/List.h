// Author: Daniel Avery
// Student ID: *20053160
// Email:  daniel-avery@cox.net
// Course:  CMSC 4173, Translator Design
// CRN:  24414, Spring, 2011
// Project:  p03
// Due:  February 9, 2011
// Account:  tt022


#ifndef List_h
#define List_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class List {
    int size, num, pointer;
    string* myList;
public:
    List();
    void Insert(string temp);
    void Scan(istream& i);
    void Print(ostream& o);
    void First(void);
    void Next(void);
    friend ostream& operator<<(ostream& o,const List& myList);
};
#endif