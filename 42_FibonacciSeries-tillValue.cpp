// To write a program ..for finding the nth term of fibonacci series using recurrsion.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int val;
    cout<<"Enter max value for fibonacci series: ";
    cin>>val;
    cout<<"Fibonacci Series till "<<val<<" is:"<<endl;
    int t1 = 0, t2 = 1, t3;
    t3 = t1+t2;
    cout<<t1<<" "<<t2<<" ";
    while (t3<=val){
        cout<<t3<<" ";
        t1 = t2;
        t2 = t3;
        t3 = t1+t2;
    }
    cout<<endl;
    return 0;
}

// OUTPUT
// Enter max value for fibonacci series: 150
// Fibonacci Series till 150 is:
// 0 1 1 2 3 5 8 13 21 34 55 89 144