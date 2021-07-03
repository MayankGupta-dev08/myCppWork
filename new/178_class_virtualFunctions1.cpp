#include<iostream>
using namespace std;

class BaseClass{
    public:
        int var_base=1;
        
        // We have made this function virtual
        virtual void display(){
            cout<<"1 Displaying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived=2;
            void display(){
                cout<<"2 Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"2 Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};

int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;

    // A base class pointer pointing at the derived class object will only access base class functions unless we have made the base class function a virtual function
    base_class_pointer = &obj_derived;
    base_class_pointer->display();
    return 0;
}