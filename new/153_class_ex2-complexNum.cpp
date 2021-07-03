// To write a program ..to print the addition and multiplication of two complex umbers

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Complex{

private:
    int real, imag;

public:
    void setNum(int a, int b){
        real = a;
        imag = b;
    }

    void printNum(){
    cout<<"Complex Number is: "<<real<<'+'<<imag<<'i'<<endl;
    }

    void complexSum(Complex cn1, Complex cn2){
        cout<<"Doing the sum of two complex Numbers"<<endl;
        cout<<"Complex Number1: "<<cn1.real<<'+'<<cn1.imag<<'i'<<endl;
        cout<<"Complex Number2: "<<cn2.real<<'+'<<cn2.imag<<'i'<<endl;
        real = (cn1.real+cn2.real);      //real for c3
        imag = (cn1.imag+cn2.imag);      //imag for c3
        // cout<<"Sum of the two complex numbers are: "<<real<<'+'<<imag<<'i'<<endl;
    }

    void complexMultiplication(Complex cn1, Complex cn2){
        cout<<"Doing the multiplication of two complex Numbers"<<endl;
        cout<<"Complex Number1: "<<cn1.real<<'+'<<cn1.imag<<'i'<<endl;
        cout<<"Complex Number2: "<<cn2.real<<'+'<<cn2.imag<<'i'<<endl;
        
        real = ((cn1.real*cn2.real) - (cn1.imag*cn2.imag));    //real for c4
        imag = ((cn1.real*cn2.imag) + (cn1.imag*cn2.real));    //imag for c4
        // cout<<"Sum of the two complex numbers are: "<<real<<'+'<<imag<<'i'<<endl;
    }
};

int main(){

    Complex c1, c2, c3, c4;
    c1.setNum(1,2);
    c1.printNum();
    c2.setNum(3,5);
    c2.printNum();

    c3.complexSum(c1,c2);
    c3.printNum();
    c4.complexMultiplication(c1,c2);
    c4.printNum();
    return 0;
}

// -----------------Output-----------------
// Complex Number is: 1+2i
// Complex Number is: 3+5i
// Doing the sum of two complex Numbers
// Complex Number1: 1+2i
// Complex Number2: 3+5i
// Complex Number is: 4+7i
// Doing the multiplication of two complex Numbers
// Complex Number1: 1+2i
// Complex Number2: 3+5i
// Complex Number is: -7+11i