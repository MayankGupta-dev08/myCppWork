/* Pointers whichstores the address of a variable and is a refernce of that variiable.
A pointer is associated with a type (of the value it points to), which is specified during declaration.
A pointer can only hold an address of the declared type; it cannot hold an address of a different type.

We can declare a pointer in any of the 3 ways as shown below:-
    int* aptr = &a;
    int * aptr = &a;
    int *aptr = &a;
*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int a = 10;
    bool c = true;
    cout<<"a: "<<a<<", "<<"c: "<<c<<endl;
    
    int *aptr = &a;
    bool *cptr = &c;
    cout<<"&a: "<<&a<<", "<<"aptr: "<<aptr<<", "<<"*aptr: "<<*aptr<<endl;
    cout<<"&c: "<<&c<<", "<<"cptr: "<<cptr<<", "<<"*cptr: "<<*cptr<<endl;

    
    int number = 88;
    int *pNumber = &number;
    cout << pNumber<< endl;
    cout << *pNumber << endl; // Print the value "pointed to" by the pointer, which is an int (88)
    
    *pNumber = 99; // Assign a value to where the pointer is pointed to, NOT to the pointer variable
    cout << *pNumber << endl; // Print the new value "pointed to" by the pointer (99)
    cout << number << endl;   // The value of variable number changes as well (99)
    
    number = 100; // Assign a value to where the pointer is pointed to, NOT to the pointer variable
    cout << *pNumber << endl; // Print the new value "pointed to" by the pointer (99)
    cout << number << endl;   // The value of variable number changes as well (99)
    
    int i = 88;
    double d = 55.66;
    char ch = '$';
    int * iPtr = &i;    // int pointer pointing to an int value
    char *cPtr = &ch;    // char pointer pointing to an char value
    double * dPtr = &d; // double pointer pointing to a double value
    cout<<"i: "<<i<<"\t*iPtr "<<*iPtr<<"\tiPtr: "<<iPtr<<endl;
    cout<<"ch: "<<ch<<"\t*cPtr "<<*cPtr<<"\t\tcPtr: "<<cPtr<<endl;
    cout<<"d: "<<d<<"\t*dPtr "<<*dPtr<<"\tdPtr: "<<dPtr<<endl<<endl;
    
    // iPtr = &d;   // ERROR, cannot hold address of different type
    // dPtr = &i;   // ERROR
    // iPtr = i;    // ERROR, pointer holds address of an int, NOT int value
    
    int j = 99;
    cout<<"Earlier iPtr was pointing at i"<<endl;
    iPtr = &j;  // You can change the address stored in a pointer
    cout<<"After: iPtr = &j\n"<<"j: "<<j<<" *iPtr "<<*iPtr<<endl;
    cout<<"You can change the address stored in a pointer"<<endl;

    return 0;
}