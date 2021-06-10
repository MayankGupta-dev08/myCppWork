// To write a program ..

#include <iostream>
using namespace std;

double nCr(int n, int r){     // n=100, r=95
    if (n-r<r){
        r = n-r;                // r=5
    }
    double nmr = n;        // 100,99,98,97,96
    double denr = r;       // 5,4,3,2,1
    double result = 1;
    while(nmr>n-r){
        result *= (nmr/denr);
        nmr--;
        denr--;
    }
    return result;
}

int main(){

    int n,r;
    cout<<"Enter the number of items (n): ";
    cin>>n;
    cout<<"How many items are taken at a time (r): ";
    cin>>r;
    double comb = nCr(n,r);
    cout<<n<<"C"<<r<<": "<<comb<<endl;
    return 0;
}