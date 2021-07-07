// Destructor never takes an argument nor does it return any value 
// It has same name as that of class prefixed with '~' titlt symbol
// It's purpose is to destroy the object or free up the memory when object goes out of scope

#include<iostream>
using namespace std;

int count=0;

class num{
    public:
        num(){
            count++;
            cout<<"This is the time when constructor is called for object number"<<count<<endl;
        }

        ~num(){
            cout<<"This is the time when my destructor is called for object number"<<count<<endl;
            count--;
        }
};

int main(){
    
    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object"<<endl;
    num n1;
    
    {                                             //Block
        cout<<"Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num n2, n3;
        cout<<"Exiting this block"<<endl;
    }                                            //Defines scope of the things inside it
    
    cout<<"Back to main"<<endl;

    return 0;
}

// --------------------------------------Output--------------------------------------
// We are inside our main function
// Creating first object
// This is the time when constructor is called for object number1       
// Entering this block
// Creating two more objects
// This is the time when constructor is called for object number2       
// This is the time when constructor is called for object number3       
// Exiting this block
// This is the time when my destructor is called for object number3     
// This is the time when my destructor is called for object number2     
// Back to main
// This is the time when my destructor is called for object number1