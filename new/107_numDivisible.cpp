// Find the number of numbers in the interval [1,n] which are divisible by a or b.


//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int divisible(int n, int a, int b){
    int n1 = n/a;       //number of numbers which are divisible by a in [1,n]
    int n2 = n/b;       //number of numbers which are divisible by b in [1,n]
    int n3 = n/(a*b);   //number of numbers which are divisible by both a and b in [1,n]

    return (n1+n2-n3);
}

int main(){

    int n, a,b;
    cin>>n>>a>>b;           //50 3  5 -> n1=18, n2=11, n3=3
    cout<<divisible(n,a,b);     //26
    
    return 0;
}