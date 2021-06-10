// To write a program to conert Decimal (0,1,2,3,4,5,6,7,8,9) to Binary (0,1)

#include <iostream>
using namespace std;

int decimalToBinary(int n){
    int  x = 1;
    int result = 0;
    while(x<=n){
        x *= 2;
    }
    x /= 2;
    while(x>0){
        int lastDigit = n/x;
        n -= lastDigit*x;
        x /= 2;
        result = result*10 + lastDigit;
    }
    return result;
}

int main(){
    int n;
    cin>>n;

    cout<<decimalToBinary(n)<<endl;
    return 0;
}