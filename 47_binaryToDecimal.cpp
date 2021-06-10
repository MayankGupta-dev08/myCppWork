// To write a program ..

#include <iostream>
using namespace std;

int binaryToDecimal(int n){
    int result = 0, two = 1;
    int x;
    while(n>0){
        x = n%10;
        result += two*x;
        two *= 2;   // two = two*2;
        n /=10;    // n = n/10;
    }
    return result;
}

int main(){
    int n;
    cin>>n;

    cout<<binaryToDecimal(n)<<endl;
    return 0;
}