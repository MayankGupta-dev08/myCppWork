#include <iostream>
using namespace std;

class Base
{
    int data1; // private by default and is not inheritable
public:
    int data2;
    void setData(int, int);
    int getData1();
    int getData2();
};

void Base ::setData(int a=10, int b=20){     //aguments with default values 
    data1 = a;
    data2 = b;
}

int Base::getData1(){
    return data1;
}

int Base::getData2(){
    return data2;
}

class Derived : public Base{ 
    // Class is being derived publically
    int data3;

public:
    void process();
    void display();
};

void Derived ::process(){
    
    data3 = data2 * getData1();
    // since data1 was the private member of base class and derive class can't have it directly we are trying to get its value through the public member function of the base class which was inherited by the derivedd class.
}

void Derived ::display(){
    cout << "Value of data 1 is " << getData1() << endl;
    cout << "Value of data 2 is " << data2 << endl;
    cout << "Value of data 3 is " << data3 << endl;
}

int main(){

    Derived der1;        //creating object of the derived class
    
    //since all the member functions of the base class were public it got inherited and we could use them by the object of derived class.
    der1.setData();      
    der1.process();
    der1.display();

    cout<<"-------------------------"<<endl;
    
    Derived der2;        //creating object of the derived class
    der2.setData(133,170);      
    der2.process();
    der2.display();

    return 0;
}

// ~~~~~~~~~~~~~Output~~~~~~~~~~~~~
// Value of data 1 is 10
// Value of data 2 is 20
// Value of data 3 is 200
// -------------------------
// Value of data 1 is 133
// Value of data 2 is 170
// Value of data 3 is 22610