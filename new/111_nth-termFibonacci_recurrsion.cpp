// To write a program ..for finding the nth term of fibonacci series using recurrsion.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fib_recurr(int n){
    
    if(n<=1)
        return 0;
    
    else if(n==2)
        return 1;
    
    else
        return (fib_recurr(n-1) + fib_recurr(n-2));
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<n<<"th term of fibonacci series is: "<<fib_recurr(n)<<endl;
    return 0;
}

// 0 1 1 2 3 5 8 13 21 34 
// 10th term of fibonacci series is: 34