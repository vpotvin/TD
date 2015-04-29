#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "List.h"

List::List()
{ 
        size = 100;
        num = 0;
        pointer = 0;
        myList = new string[size];
}
void List::Insert(string temp)
{   
        myList[num++] = temp;
}
void List::Scan(istream& i)
{   
        while(true){
                string temp;
                i >> temp;
                if (i.eof()) break;
                Insert(temp);
        }
}
void List::Print(ostream& o)
{   
        o << "{";
        for (int x = 0; x < num; x++) 
        {
                if (x > 0) 
                        o << ",";
                o << myList[x];
        }
        o << "}";
}
void List::First(void)
{
        pointer = 0;
}
void List::Next(void)
{
        if(pointer < num) 
                pointer++;
}

ostream& operator<<(ostream& o, const List& myList)
{   o << "{";
    for (int x = 0; x < myList.num; x++) {
        if (x > 0) o << ",";
        o << myList.myList[x];
    }
    o << "}";
    return o;
}