// To write a program ..for finding n power of p using recurrsion.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fact_recurr(int n){
    if (n==1)
        return 1;
    
    return ( n * fact_recurr(n-1) );
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<n<<" Factorial is: "<<fact_recurr(n)<<endl;
    return 0;
}