// INHERITANCE IN OOPS IN C++

// Single Inheritance - A derived class with only one base class
// Multiple Inheritance - A derived class with more than one base class 
// Hierarchical Inheritance - Several derived class from one base class 
// Multilevel Inheritance - Deriving a class from an already derived class
// Hybrid Inheritance - A combination of multiple and multilevel inheritance

// Derived Class syntax
/*
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc...
}

Note:
    1. Default visibility mode is private
    2. Public Visibility Mode: Public members of the base class becomes Public members of the derived class
    3. Private Visibility Mode: Public members of the base class becomes Private members of the derived class
    4. Private members are never inherited to derived class
*/


#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    Employee() {}       //this constructor is necessary for the working of the derived class constructor as it will firstly call the base class constructor the one without any argument as we have already made one with the argument.
    // If that one was not present than this one was also not necessary.  
};


// Creating a Programmer class derived from Employee Base class
class Programmer : public Employee{

public:
    int languageCode;
    
    Programmer(int inpId){        
        id = inpId;
        languageCode = 9;
    }
    
    void getData(){
        cout<<id<<endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    harry.salary = 55;
    cout << harry.salary << endl;
    
    Programmer skillF(10);
    cout << skillF.languageCode<<endl;
    cout << skillF.id<<endl;
    skillF.getData();
    return 0;
}