// To write a program ..for printing n terms of fibonacci series using recurrsion.

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
    cout<<"Enter number of terms for fibonacci series: ";
    cin>>n;
    cout<<"Fibonacci Series for "<<n<<" terms."<<endl;
    for (int i = 1; i <= n; i++){
        cout<<fib_recurr(i)<<" ";
    }
    cout<<endl;
    return 0;
}

// OUTPUT
// Enter number of terms for fibonacci series: 10
// Fibonacci Series for 10 terms.
// 0 1 1 2 3 5 8 13 21 34 