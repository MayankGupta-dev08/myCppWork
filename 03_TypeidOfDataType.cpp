#include<iostream>
// #include<bits/stdc++.h> #one header file which includes all others
#include<string.h>
#include<typeinfo>

using namespace std;

int main(){
    int a = 3;
    float b = 4.5;
    char c = 'c';
    string d = "Hello World";
    bool e = true;
    double f = 4.8;
    cout<<"Identifying the different data types in c++\n";
    
    cout<<"value of a is: "<<a<<endl;
    cout<<"type of a is: "<<typeid(a).name()<<endl;
    
    cout<<"value of b is: "<<b<<endl;
    cout<<"type of b is: "<<typeid(b).name()<<endl;
    
    cout<<"value of c is: "<<c<<endl;
    cout<<"type of c is: "<<typeid(c).name()<<endl;
    
    cout<<"value of d is: "<<d<<endl;
    cout<<"type of d is: "<<typeid(d).name()<<endl;
    
    cout<<"value of e is: "<<e<<endl;
    cout<<"type of e is: "<<typeid(e).name()<<endl;
    
    cout<<"value of f is: "<<f<<endl;
    cout<<"type of f is: "<<typeid(f).name()<<endl;

    return 0;
}