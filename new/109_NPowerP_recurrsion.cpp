// To write a program ..for finding n power of p using recurrsion.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int NpowerP(int n, int p){
    if(p==0)
        return 1;

    return (n * NpowerP(n,p-1));
}

int main(){

    int n,p;
    cout<<"Enter a number and its power: ";
    cin>>n>>p;
    cout<<n<<" raise to power "<<p<<" is: "<<NpowerP(n,p)<<endl;
    return 0;
}
// 2*2*2*2*2*1