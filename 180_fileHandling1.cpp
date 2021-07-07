// File Handling through C++ Classes

// In C++, files are mainly dealt by using three classes fstream, ifstream, ofstream available in fstream headerfile.
// ofstream: Stream class to write on files
// ifstream: Stream class to read from files
// fstream: Stream class to both read and write from/to files.

// Now the first step to open the particular file for read or write operation. We can open file by
// 1. passing file name in constructor at the time of object creation
    // Open File by using constructor
    // ifstream f1(filename, openmode) by default openmode = ios::in
    // ifstream f1(“filename”);
    // ofstream f2(filename, openmode) by default openmode = ios::out
    // ofstream f2(“filename”);

// 2. using the open method

// ----------------------Using Method 1----------------------

// To write a program ..to do file handling using constructor

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    string st;
    // cin>>st;         //consider only a word and ends it at space or new line
    getline(cin, st);   //for getting more than one word
    
    // ---------Opening files using constructor and writing it---------
    // ofstream fout("file1.txt", ios::out);
    ofstream fout("file1.txt");   //by default mode is out, fout is name of object.
    // if a file with the above name does not exist it will, otherwise write from the biginning in the file.
    fout<<st;
    fout.close();

    string content;
    // ifstream fin("file1.txt", ios::in);
    ifstream fin("file1.txt");   //by default mode is in, fin is name of object.
    // fin>>content;    //will return only one word
    getline(fin, content);
    cout<<"The content of the file:-\n"<<content;
    fin.close();

    return 0;
}

// ******************************************Output******************************************
// Hello, my name is mayank and this the the first program for file handling in cpp.
// The content of the file:-
// Hello, my name is mayank and this the the first program for file handling in cpp.