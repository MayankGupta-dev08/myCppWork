/*
---------------------------------CONSTRUCTOR IN DERIVED CLASSES---------------------------------
->    We can use constructors in derived classes
->    If base class constructor does not have any arguments, then there is no additional need of any constructor in derived class
->    But if there are more than one or more arguments in the base class constructor, derived class need to pass arguments to the base clas constructor
->    If both base and derived class have constructors than base class constructor is executed first irrespective of the creation of object of derived class
->    In multiple inheritance, base classes constructors are invoked in the order in which they appear in the class decleration, 
        A-->C<--B, and Class C: public A, public B{};
            Firstly Constructor of A than B than C
        A-->C<--B, and Class C: public B, public A{};
            Firstly Constructor of B than A than C
->    In multilevel inheritance, base classes constructors are invoked in the order of inheritance, A-->B-->C, than if the object of class C is created than firstly constructor of A, than B, than C.
->   Special syntax when you want to pass the arguments of multiple base class constructor using the constructor of the derived class
                Class Base1{};
                Class Base2{};
                Class Derived : public Base1, public Base2{
                    Derived(int a, int b, int c, int d) : Base2(b), Base1(a){   //This does not dictate the order of constructor call, just specify the value to be send
                        data1 = c;
                        data2 = d;
                    }
                };
                //So Base1 constructor will be invoked firstly.
->   The constructors for the virtual base class are invoked before a non virtual base class
->   If there are multiple base classes, they are invoked in the order declared.
*/

/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/


#include<iostream>
using namespace std;

class Base1{
    int data1;
    public:
        Base1(int i){
            data1 = i;
            cout<<"Base1 class constructor called"<<endl;
        }
        void printDataBase1(void){
            cout<<"The value of data1 is "<<data1<<endl;
        }
};

class Base2{
    int data2;

    public:
        Base2(int i){
            data2 = i;
            cout << "Base2 class constructor called" << endl;
        }
        void printDataBase2(void){
            cout << "The value of data2 is " << data2 << endl;
        }
};

class Derived: public Base2, public Base1{
    int derived1, derived2;
    public:
        Derived(int a, int b, int c, int d) : Base1(b), Base2(a)
        {
            derived1 = c;
            derived2 = d;
            cout<< "Derived class constructor called"<<endl;
        }
        void printDataDerived(void)
        {
            cout << "The value of derived1 is " << derived1 << endl;
            cout << "The value of derived2 is " << derived2 << endl;
        }
};
int main(){
    Derived harry(11, 52, 73, 84);
    harry.printDataBase1();
    harry.printDataBase2();
    harry.printDataDerived();
    return 0;
}

// -------------Output-------------
// Base2 class constructor called
// Base1 class constructor called
// Derived class constructor called        
// The value of data1 is 52
// The value of data2 is 11
// The value of derived1 is 73
// The value of derived2 is 84