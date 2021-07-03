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

void Base ::setData(int a, int b){     //aguments with default values 
    data1 = a;
    data2 = b;
}

int Base::getData1(){
    return data1;
}

int Base::getData2(){
    return data2;
}

class Derived : private Base{ 
    // Class is being derived privately, so all public members of base class are now it's private
    int data3;

public:
    void process(int, int);
    void display();
};

void Derived ::process(int d1=11, int d2=22){
    
    setData(d1, d2);      
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
    
    //since all the member functions of the base class were public but the visibilty was private, it got inherited as private members and we can't use them by the object of derived class, but we could use them by the public members of the derived class as they can.
    der1.process();
    der1.display();

    cout<<"-------------------------"<<endl;
    
    Derived der2;        //creating object of the derived class      
    der2.process(33,44);
    der2.display();

    return 0;
}

// ~~~~~~~~~~~~~Output~~~~~~~~~~~~~
// Value of data 1 is 11
// Value of data 2 is 22
// Value of data 3 is 242
// -------------------------
// Value of data 1 is 33
// Value of data 2 is 44
// Value of data 3 is 1452