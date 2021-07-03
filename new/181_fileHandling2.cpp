// File Handling through C++ Classes

// 1. passing file name in constructor at the time of object creation
    // Open File by using constructor
    // fstream f1(filename, openmode) mode -> ios::in, ios::out, ios::app, ios::trunc
    // fstream fio1 ("Samplefile.txt", ios::in)
    // fstream fio1 ("Samplefile.txt", ios::out)
    // fstream fio1 ("Samplefile.txt", ios::in | ios::out)
    // fstream fio1 ("Samplefile.txt", ios::in | ios::out | ios::trunc)

// ----------------------Using Method 1----------------------

// To write a program ..to do file handling using constructor

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    cout<<"Enter a line which you want to be in file2.txt"<<endl;
    string st;
    getline(cin, st);   //for getting a line from user
    // cin>>st;         // would have taken only a word

    // for writing in the file 
    fstream fio1 ("file2.txt", ios::out); 
    fio1<<st;        //writing in the file that one line
    fio1.close();
    
    // for reading the content of the file
    fstream fio2 ("file2.txt", ios::in); 
    string data;

    // fin>>data;       // would have read only a word
    getline(fio2, data); //reading a line from the file
    cout<<"The content of the file:-\n"<<data;
    fio2.close();

    return 0;
}

// ******************************************Output******************************************
// Enter a line which you want to be in file2.txt
// Hello world and this is file. This this the second line  
// The content of the file:-
// Hello world and this is file. This this the second line