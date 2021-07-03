// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// void swap(int a, int b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int a,b;
    cin>>a>>b;
    cout<<"a: "<<a<<"\n"<<"b: "<<b<<endl;

    // this will only swap the values of a and b in function and if we will return or print them than for that statement it will show swaped values but actual values of a and b will remain as it is if it is used again here
    // swap(a,b);   // call by value

    int *p1 = &a;
    int *p2 = &b;

    // We can either send pointers or their addresses, since the function parameters at that end is pointer.
    swap(p1,p2);   // call by reference
    // or
    // swap(&a,&b);   // call by reference
    cout<<"a: "<<a<<"\n"<<"b: "<<b<<endl;
    return 0;
}