#include "paspar.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

ofstream o;
ofstream pfs;											// OUTPUT FILE

// EXCEPTION STRUCTS ----------------------------------------------------------
struct BadSuffixException {
    BadSuffixException(char* fn)
    {   cout << endl;
        cout << "Input file \"" << fn << "\" does not have a .pas suffix.";
    }
};

class FileNameSuffix {
    char* prefix;
public:
    FileNameSuffix(char* fn){
       	char* p=strstr(fn,".pas");
        if (!p) throw BadSuffixException(fn);
        int n=p-fn;
        if (n+4!=strlen(fn)) throw BadSuffixException(fn);
        prefix=new char[strlen(fn)+1];
        strncpy(prefix,fn,n);
        prefix[n]=0;
    }
    ~FileNameSuffix(){if (prefix) delete[] prefix;}
    void Suffix(char* fn,const char* suffix)
    {   strcpy(fn,prefix);
        strcat(fn,suffix);
    }
};

struct CommandLineException {
    CommandLineException(int m,int a)
    {   cout << endl;
        cout << "Too many file names on the command line.";
        cout << endl;
        cout << m << " file name(s) are permitted on the command line.";
        cout << endl;
        cout << a << " file name(s) appeared on the command line.";
        cout << endl;
    }
};

struct FileException {
   FileException(const char* fn)
   {   cout << endl;
       cout << "File " << fn << " could not be opened.";
       cout << endl;
   }														
};																			 
// ----------------------------------------------------------------------------

int main (int argc,char* argv[]) {
	try {
		char ifn[255];
        switch (argc) {
            case 1:               //Prompt for the input file name
                cout << "Enter the input file name. ";
                cin >> ifn;
                break;
            case 2:               //Read the input file name
                strcpy(ifn,argv[1]);
                break;
            default:
                throw CommandLineException(1,argc-1);
                break;
    }
    FileNameSuffix F(ifn);        //Find the prefix of the input file name
    char ofn[255];
    F.Suffix(ofn,".trc");         //Create the trace file name
    FILE* i=fopen(ifn,"r");       //Open the input file
    if (!i) throw FileException(ifn);
    char pofn[255];
    F.Suffix(pofn, ".pcd");
    
    o.open(ofn); if (!o) throw FileException(ofn);
    pfs.open(pofn); if (!o) throw FileException(ofn);
    Parser P(i);
    P.Parse();
    o << endl;                 //Put a new line in the trace file
    o.close();                  //Close the trace file
    pfs << endl;
    pfs.close();
    fclose(i);                    //Close the input file
    } catch (...) {
        cout << endl;
        cout << "Program terminated!";
        cout << endl;
        cout << "I won't be back!";
        cout << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
