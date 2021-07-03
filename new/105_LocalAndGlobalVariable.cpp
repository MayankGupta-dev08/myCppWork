// C++ program to show that we can access a global variable using scope resolution operator :: when there is a local variable with same name

#include<iostream>
using namespace std;

// Global x
int x = 0;
int g = 10;	


int main(){
    
    // Local x	
    int x = 10;

    cout<< "Value of global x is " << ::x<<endl;
    cout<< "Value of local x is " << x<<endl;

    x++;
    ::x = ::x+5;
    cout<< "Changed Value of global x is " << ::x<<endl;
    cout<< "Changed Value of local x is " << x<<endl;
    
    cout<< "Initial Value of global g is " << g<<endl;
    g= 15;
    cout<< "Changed Value of global g is " << g<<endl;
    return 0;
}
