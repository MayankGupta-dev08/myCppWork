#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 5;
    int b = 7;
    
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"Swapping using Bit Manipulation\n";
// Swap two numbers without using any third variable
    
    a = a^b;    //Step1: a = a XOR b
    b = a^b;    //Step2: b = a XOR b XOR b = a  //since n^n = 0 and 0^n = n
    a = a^b;    //Step3: a = a XOR b XOR a = b
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    return 0;
}


/* 
a: 5
b: 7
Swapping using Bit Manipulation
a: 7
b: 5 
*/