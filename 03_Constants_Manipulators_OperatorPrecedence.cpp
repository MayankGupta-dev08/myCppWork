#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    // int a = 34; 
    // cout<<"The value of a was: "<<a;
    // a = 45; 
    // cout<<"The value of a is: "<<a;
    
    // ******************************Constants in C++ ******************************
    const int x = 3;
    cout<<"The value of x was: "<<x<<endl;
    // x = 45; // You will get an error because a is a constant
    // cout<<"The value of x is: "<<x<<endl;

    // ******************************Manipulators in C++ ******************************
    // endl - iostream
    // setw() - iomanip
    int a =3, b=78, c=1233;
    cout<<"The value of a without setw is: "<<a<<endl;
    cout<<"The value of b without setw is: "<<b<<endl;
    cout<<"The value of c without setw is: "<<c<<endl;

    cout<<"The value of a is: "<<setw(4)<<a<<endl;
    cout<<"The value of b is: "<<setw(4)<<b<<endl;
    cout<<"The value of c is: "<<setw(4)<<c<<endl;

    // The value of a without setw is: 3   
    // The value of b without setw is: 78  
    // The value of c without setw is: 1233
    // The value of a is:    3
    // The value of b is:   78
    // The value of c is: 1233

    // ******************************Operator Precedence******************************
    int p =3, q=4;
    int r = p*5+q-45+87;                //61
    // int r = ((((p*5)+q)-45)+87);     //61
    cout<<r;

    return 0;
}
