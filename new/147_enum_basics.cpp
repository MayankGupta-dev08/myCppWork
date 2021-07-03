// Enums: Enums are user-defined types that consist of named integral constants.

// It helps to assign constants to a set of names to make the program easier to read, maintain and understand.
// An Enumeration is declared by using the keyword “enum“.
//enums are just to give some constant values to some words, but we can't compare these with any data type


//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

enum day {sun, mon, tue, wed, thu, fri, sat};   //naturally it starts with 0 

enum roll {ashu=1, divya, kake, mannu, mohit, puru, pulkit};    //we can change the start of the sequence

enum days_months {jan=31, feb=28, mar=31, apr=30, may=31, jun=30, jul=31, aug=31, sep=30,
                  oct=31, nov=30, dec=31};  // we can change  all or any of them to give value of our choice

int main(){

    day d = mon;
    cout<<"We will consider monday as the "<<d<<" day of our week"<<endl;

    roll r = mannu;
    cout<<"The roll number of mannu is: "<<r<<endl;

    days_months md = jun;
    cout<<"June consist "<<md<<" days"<<endl;
    
    return 0;
}