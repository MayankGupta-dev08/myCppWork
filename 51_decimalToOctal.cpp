// To write a program to conert Decimal (0,1,2,3,4,5,6,7,8,9) to Octal (0,1,2,3,4,5,6,7)

#include <iostream>
using namespace std;

int decimalToOctal(int n){
    int  x = 1;
    int result = 0;
    while(x<=n){
        x *= 8;
    }
    x /= 8; //Finding the max value of x which is some power of 8, such that it is less than n but closest to it.
    while(x>0){
        int lastDigit = n/x;
        n -= lastDigit*x;
        x /= 8;
        result = result*10 + lastDigit;
    }
    return result;
}

int main(){
    int n;
    cin>>n;

    cout<<decimalToOctal(n)<<endl;
    return 0;
}