//  Write a program to find 2 unique numbers in an array where all numbers except two, are present twice

// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

void unique2Nums(int a[], int n){
    int xorSum = 0;
    for (int i = 0; i < n; i++){
        xorSum = xorSum^a[i];
    }
    
    // now we will see that what is the pos of the rightmost set bit in xorSum
    int r_setBit_pos = log2(xorSum & (~(xorSum-1)));

    // finding which all numbers have a set bit at r_setBit_pos, so that we can do xor of all of them and result will be one of the two unique numbers.
    int xor_currSum = 0;
    for (int i = 0; i < n; i++){
        if( (a[i] & (1<<r_setBit_pos)) != 0){
            xor_currSum = xor_currSum^a[i];
        }
    }
    cout<<"Unique num1 = "<<xor_currSum<<endl;
    cout<<"Unique num2 = "<<(xor_currSum^xorSum)<<endl;    

    return;
}

int main(){

    int a[]= {2,4,6,7,4,5,6,2};
    int b[]= {1,2,3,8,4,3,2,1};
    int n = 8;
    
    unique2Nums(b, n);

    return 0;
}