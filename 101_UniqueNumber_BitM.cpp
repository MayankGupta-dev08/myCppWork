// Write a program to find a unique number in an array where all numbers except one number, are present twice
/*
for(int i = 0; i < n; i++){
    xorsum = xorsum ^ arr[i];
}

Let's dry run this for arr[] = {1, 2, 3, 4, 1, 2, 3}:
we can write as:
xorsum = 0 ^ 1;
xorsum = 0 ^ 1 ^ 2;
.
.
.
xorsum = 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 1 ^ 2 ^ 3;
By Commutative Property -
xorsum = 0 ^ (1 ^ 1) ^ (2 ^ 2) ^ (3 ^ 3) ^ 4;
xorsum = 0 ^ 0 ^ 0 ^ 0 ^ 4;
xorsum = 4;
*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int uniqueNum(int a[], int n){
    int xorSum = 0;
    for (int i = 0; i < n; i++){
        xorSum = xorSum^a[i];
    }
    return xorSum;
}

int main(){

    int a[] = {1,2,3,4,3,1,2};
    int n = 7;
    cout<<uniqueNum(a, n)<<endl;
    return 0;
}