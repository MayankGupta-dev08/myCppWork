// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <class T1, class T2>
class Sample{
    private:
        T1 a;
        T2 b;

    public:
        Sample(T1 x, T2 y){
            a= x;
            b= y;
        }
        void display();
};

// At times of later definition of member function this is the way 
template <class T1, class T2>
void Sample<T1, T2> :: display(){
    cout<<"Value of a: "<<a<<endl;
    cout<<"Value of b: "<<b<<endl;
    cout<<"***********************\n";
}

// Now Showing in case of function overloading

void func(int x){
    cout<<"From function with exact parameter match\n";
    cout<<"vaue of x: "<<x<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

template <class t>
void func(t x){
    cout<<"From template function\n";
    cout<<"vaue of x: "<<x<<endl;
    cout<<"------------------\n";
}

int main(){

    Sample<int, float> obj1(3, 3.8);
    obj1.display();

    Sample<char, float> obj2('@', 5.9);
    obj2.display();

    func(3);  //in case of function overloading it will go to function with exact parameter match 
    func(3.4);
    func('X');
    return 0;
}

// Output
// Value of a: 3
// Value of b: 3.8        
// ***********************
// Value of a: @
// Value of b: 5.9
// ***********************
// From function with exact parameter match
// vaue of x: 3
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// From template function
// vaue of x: 3.4
// ------------------
// From template function
// vaue of x: X
// ------------------