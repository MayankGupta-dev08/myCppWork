// Basic Concepts in Object-Oriented Programming
    // Classes - Basic template for creating objects
    // Objects – Basic run-time entities
    // Data Abstraction & Encapsulation – Wrapping data and functions into a single unit
    // Inheritance – Properties of one class can be inherited into others
    // Polymorphism – Ability to take more than one forms
    // Dynamic Binding – Code which will execute is not known until the program runs
    // Message Passing – message (Information) call format

// Benefits of Object-Oriented Programming
    // Better code reusability using objects and inheritance
    // Principle of data hiding helps build secure systems
    // Multiple Objects can co-exist without any interference
    // Software complexity can be easily managed

#include<iostream>
using namespace std;

class Employee
{
    private:
        int a, b, c;
    public:
        int d, e;
        void setData(int, int, int); // Declaration
        void getData(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};

void Employee :: setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Employee harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1,2,4);
    harry.getData();
    return 0;
}
