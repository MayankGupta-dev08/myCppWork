// To write a program ..numberOfOnes or Count Set Bits

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int countSetBits_brute(int n){
    int count = 0;
    while(n>0){
        if(n&1==1)
            count++;
        n = n>>1;   //rightshifting n by 1 ie. dividing by 2
    }
    return count;
}


// time complexity of both will be O(number of set bits)
int countSetBits(int n){
    int count = 0;
    while(n>0){
        count++;
        n = (n & (n-1));    //removing the rightmost set bit 
    }
    return count;
}

int main(){

    int n = 14;
    cout<<"Count of set bits in "<<n<<": "<<countSetBits_brute(n)<<endl;
    cout<<"Count of set bits in "<<n<<": "<<countSetBits(n)<<endl;
    
    n=8;
    cout<<"Count of set bits in "<<n<<": "<<countSetBits_brute(n)<<endl;
    cout<<"Count of set bits in "<<n<<": "<<countSetBits(n)<<endl;
    return 0;
}