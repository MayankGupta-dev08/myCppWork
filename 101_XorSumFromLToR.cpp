// Find the Xor sum from l to r, eg.- 2 to 6 = 2^3^4^5^6 =  

#include <bits/stdc++.h>
using namespace std;

int XorSumTillN(int n){
    if(n%4==0)
        return n;

    if(n%4==1)
        return 1;

    if(n%4==2)
        return n+1;

    else    // if(n%4==3)
        return 0;
}

int xorSumLToR(int l, int r){
    int ansR = XorSumTillN(r);
    int ansLMinus1 = XorSumTillN(l-1);
    return (ansLMinus1^ansR);
}

int main(){
    int l, r;
    cout<<"enter lower limit number: ";
    cin>>l;
    cout<<"enter upper limit number: ";
    cin>>r;
    cout<<"Xor sum from "<<l<<" till "<<r<<": ";
    cout<<xorSumLToR(l,r)<<endl;
    return 0;
}

/* 
enter lower limit number: 4
enter upper limit number: 8
Xor sum from 4 till 8: 8

enter lower limit number: 3
enter upper limit number: 7
Xor sum from 3 till 7: 3

 */