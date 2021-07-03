// To write a program ..numberOfOnes or Count Set Bits

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int countSetBits(int n){
    int count = 0;
    while(n>0){
        count++;
        n = (n & (n-1));
    }
    return count;
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Count of set bits in "<<n<<": "<<countSetBits(n)<<endl;
    return 0;
}