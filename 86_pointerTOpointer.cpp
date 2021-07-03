// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int a = 89;
    int *p1 = &a;       //p1 is a pointer pointing at variable a
    int **p2 = &p1;     //p2 is a pointer pointing at pointer p1
    int *p3 = p1;       //p3 will also point to vaiable a
    
    cout<<&a<<endl;     //0x61ff04 - address of a
    cout<<a<<endl;      //89 - value of a
    
    cout<<p1<<endl;     //0x61ff04 - address of a - p1 is pointing at a
    cout<<*p1<<endl;    //89 - value of a

    cout<<p3<<endl;     //0x61ff04 - address of a - contained by p2
    cout<<*p3<<endl;    //89 - value of a

// ----------------------------For pointer pointing at pointer----------------------------
    cout<<p2<<endl;     //0x61ff04 - address of p1 - contained by p2
    cout<<*p2<<endl;    //0x61ff08 - value of p2 - contained by p1 - address of a 
    cout<<**p2<<endl;   //89 - value of a - directly accessing the value of variable
    
    
// Modifying the value of variable using pointers
    *p1 = 90;
    cout<<a<<endl;
    *p3 = 95;
    cout<<a<<endl;
    **p2 = 99;
    cout<<a<<endl;
    
    return 0;
}

// 0x61ff04
// 89
// 0x61ff04
// 89
// 0x61ff04
// 89
// 0x61ff00
// 0x61ff04
// 89
// 90
// 95
// 99