// To write a program ..to calculate the number of combinations for a given value of n and r in nCr.

#include <iostream>
using namespace std;

long fact(int num){
    if (num<=0 || num==1)
        return 1;

    else
        return num*fact(num-1);
}

int main(){

    int n,r;
    cout<<"Enter the number of items (n): ";
    cin>>n;
    cout<<"How many items are taken at a time (r): ";
    cin>>r;
    long comb = (fact(n)/(fact(r)*fact(n-r)));
    cout<<n<<"C"<<r<<": "<<comb<<endl;
    return 0;
}