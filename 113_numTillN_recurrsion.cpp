// To write a program ..for printing numbers till n in increasing order using recurrsion.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void numTillN_inc(int n, int i){
    if (i>n)                        //base condition
        return;
    
    cout<<i<<" ";                   //induction
    numTillN_inc(n, i+1);           //hypothesis
}

void numTillN_in(int n){
    if (n==1){
        cout<<n<<" ";
        return;
    }
    
    numTillN_in(n-1);
    cout<<n<<" ";
}

void numTillN_dec(int n){
    if (n<1)
        return;
    
    cout<<n<<" ";
    numTillN_dec(n-1);
}


int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Series in incresing order till "<<n<<endl;
    // numTillN_inc(n,1);
    numTillN_in(n);
    cout<<endl;
    cout<<"Series in decresing order from "<<n<<" till 1\n";
    numTillN_dec(n);
    cout<<endl;
    return 0;
}