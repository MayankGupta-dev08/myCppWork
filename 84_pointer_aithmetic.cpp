// To write a program ..
// We can apply only ++,--,+ and - operators on pointers.
// using ++ or -- it jumps to the next address using the sixof of the variable type.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int a = 55;
    int *ptr1 = &a;
    cout<<"*ptr1: "<<*ptr1<<endl;   //55
    cout<<"ptr1: "<<ptr1<<endl;     //address of a
    ++ptr1;
    cout<<"(++ptr1): "<<ptr1<<endl;
    cout<<"*(++ptr1): "<<*ptr1<<" - Garbage value"<<endl;
    --ptr1;
    cout<<"(--ptr1): "<<ptr1<<endl;
    cout<<"*(--ptr1): "<<*ptr1<<endl;
    ptr1 + 1;                               //this will lead to no change as its not modifying pointer 
    cout<<"ptr1: "<<ptr1<<" - No change"<<endl;
    cout<<"(ptr1+1): "<<(ptr1+1)<<endl;      //Value of pointer is not changed but just final value    
    cout<<"(ptr1-1): "<<(ptr1-1)<<endl<<endl;//Value of pointer is not changed but just final value 

    double b = 66.85;
    double *ptr2 = &b;
    cout<<"*ptr2: "<<*ptr2<<endl;
    cout<<"ptr2: "<<ptr2<<endl;
    ++ptr2;
    cout<<"ptr2: "<<ptr2<<endl;
    --ptr2;
    cout<<"ptr2: "<<ptr2<<endl;
    ptr2 + 1;
    cout<<"ptr2: "<<ptr2<<endl;
    ptr2 - 1;
    cout<<"ptr2: "<<ptr2<<endl<<endl;

    char c = 'C';
    char *ptr3 = &c;
    cout<<"*ptr3: "<<*ptr3<<endl;
    cout<<"ptr3: "<<ptr3<<endl;
    ++ptr3;
    cout<<"ptr3: "<<ptr3<<endl;
    --ptr3;
    cout<<"ptr3: "<<ptr3<<endl;
    ptr3 + 1;
    cout<<"ptr3: "<<ptr3<<endl;
    ptr3 - 1;
    cout<<"ptr3: "<<ptr3<<endl;
    
    return 0;
}

/*
*ptr1: 55
ptr1: 0x61ff00
(++ptr1): 0x61ff04
*(++ptr1): 4202128 - Garbage value
(--ptr1): 0x61ff00
*(--ptr1): 55
ptr1: 0x61ff00 - No change        
(ptr1+1): 0x61ff04
(ptr1-1): 0x61fefc

*ptr2: 66.85
ptr2: 0x61fef8
ptr2: 0x61ff00
ptr2: 0x61fef8
ptr2: 0x61fef8
ptr2: 0x61fef8

*ptr3: C
ptr3: Cfffff╢P@7
ptr3: fffff╢P@7
ptr3: Cfffff╢P@7
ptr3: Cfffff╢P@7
ptr3: Cfffff╢P@7
*/