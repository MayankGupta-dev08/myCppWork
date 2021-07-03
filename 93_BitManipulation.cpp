/*
Get Bit
suppose, n=5 --> n = 0101 (suppose there is a big number and we want to know whether at a specific position their is 1 or 0 so to do this we will use get bit, if ti returns 1 then it is 1 and if 0 than 0 since we will use & operator.)
and we need to find out the bit position at i=2         (5 4 3 2 1 0)
so, we will (left shift) use 1<<i, --> 0100
0101 & 0100 = 0100
if (n & (1<<i))!=0, then it is 1

Set Bit -  to set a bit as 1 fro a given number at a given position

Clear Bit - for a given number removing the 1 from binary form of that number at a given position

Update Bit - First clearing at that position that setting the value at that position.

Toggle ith bit
Mask: 1 << i
Bitwise XOR operation between n and mask toggle the ith bit

---------------------LEFT SHIFT---------------------(NUM << LEFT_SHIFTVALUE) = NUM*pow(2,LEFT_SHIFTVALUE)
4<<1  --> 0100<<1  -->  1000   -->  4*2 = 8 
4<<2  --> 0100<<2  -->  10000   -->  4*2*2 = 16 
3<<2  --> 0011<<2  -->  1100   -->  3*2*2 = 12 

1<<0 -->  0001
1<<1 -->  0010
1<<2 -->  0100
1<<3 -->  0100
1<<4 -->  1000


---------------------RIGHT SHIFT---------------------(NUM << RIGHT_SHIFTVALUE) = NUM/pow(2,RIGHT_SHIFTVALUE)
4>>1  --> 0100>>1  -->  0010    -->  4/2 = 2 
4>>2  --> 0100>>2  -->  10000   -->  4/(2*2) = 1 
9>>2  --> 1001>>2  -->  0010    -->  9/(2*2) = 2 
9>>2  --> 0011>>2  -->  0000    -->  3/(2*2) = 0 
7>>2  --> 0111>>2  -->  0001    -->  7/(2*2) = 1 

*/

// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
    // returning in terms of true and false, if (n & (1<<pos)) is not 0 than it will return 1 else 0
}

int setBit(int n, int pos){
    return (n | (1<<pos));
}

int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}

int updateBit(int n, int pos, int val){
    // clearing Bit at the position, it could be 0 or 1
    int mask = ~(1<<pos);
    n = (n & mask);

    // setting bit at pos 
    return (n | (val<<pos));
}

int toggleBit(int n, int pos){
    // xor --> same = 0
    // xor --> different = 1
    return (n xor (1<<pos));
}


int main(){

    // pos = ....3,2,1,0
    // int n, pos, val;
    // cin>>n>>pos>>val;

    cout<<getBit(5, 2)<<endl;     //n=5 and pos = 2 ---> 1
    cout<<setBit(5, 1)<<endl;     //n=5 and pos = 1 ---> 7
    cout<<clearBit(5, 2)<<endl;   //n=5 and pos = 2 ---> 1
    cout<<updateBit(5, 1,1)<<endl;   //n=5 and pos = 1 and val = 1 ---> 7
    cout<<toggleBit(5, 1)<<endl;     //n=5 and pos = 1 ---> 7
    cout<<toggleBit(5, 2)<<endl;     //n=5 and pos = 1 ---> 3
    
    return 0;
}