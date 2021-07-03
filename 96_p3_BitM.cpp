// To write a program to check if a given number is power of 2 or not.

/* For a given number n, n-1 could be written just by flipping the right most bit (1) and its subsequent bit
n = 6 = 0110    -->  n-1 = 5 = 0101   -->  (n & (n-1)) = 0100
n = 8 = 1000    -->  n-1 = 7 = 0111   -->  (n & (n-1)) = 0000

So, (n & (n-1)) will have same bits as n except the rightmost set bit. i.e. difference b/w these two will be pow(2,rightmost set bit)

So, we now that the numbers which are a power of 2 than we know that they have only one set bit which is that power so if we will do (n & (n-1)) than we will get 0.

*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool pow2(int n){
    if (n<=0)
        return false;
    
    while(n>1){
        int r = n%2;
        if(r==1)
            return false;
        n = n/2;
    }
    return true;
}

bool ispower2(int n){
    // if (n==0)
    //     return 0;
    // else if ((n & (n-1))==0)
    //     return 1;
    // else
    //     return 0;

    return (n && (!(n & (n-1))));
}


int main(){

    // cout<<pow2(8)<<endl;
    // cout<<pow2(9)<<endl;
    
    int n1=8, n2=9;
    cout<<n1<<": "<<ispower2(n1)<<endl;
    cout<<n2<<": "<<ispower2(n2)<<endl;
    return 0;
}