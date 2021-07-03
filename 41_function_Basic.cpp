// To write a program ..

#include<iostream>
using namespace std;

// -----------------------Function prototype-----------------------
// type function-name (arguments);
// int sum(int a, int b); //--> Acceptable
// int sum(int a, b); //--> Not Acceptable 
int sum(int, int); //--> Acceptable 
// void g(void); //--> Acceptable 
void thanks(); //--> Acceptable 



void g(){   //No need for function prototype as it is above main()

    cout<<"Hello, This is a program for adding two numbers"<<endl;
}

int main(){         // Main function
    
    g();
    int num1, num2;
    cout<<"Enter first number"<<endl;
    cin>>num1;
    cout<<"Enter second number"<<endl;
    cin>>num2;
    // num1 and num2 are actual parameters
    cout<<"The sum is "<<sum(num1, num2);
    thanks();
    return 0;
}

int sum(int a, int b){  //need for function decleration/prototype
    
    // Formal Parameters a and b will be taking values from actual parameters num1 and num2.
    int c = a+b;
    return c;
}

void thanks(){      //need for function decleration/prototype

    cout<<"\nThanks for using the program";
}
