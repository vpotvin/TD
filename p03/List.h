
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