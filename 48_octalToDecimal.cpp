// To write a program to print Decimal (0,1,2,3,4,5,6,7,8,9) from Octal (0,1,2,3,4,5,6,7)

#include <iostream>
using namespace std;

int octalToDecimal(int n){
    int result = 0, eight = 1;
    int x;
    while(n>0){
        x = n%10;
        result += eight*x;
        eight *= 8;   // eight = eight*2;
        n /=10;    // n = n/10;
    }
    return result;
}

int main(){
    int n;
    cin>>n;

    cout<<octalToDecimal(n)<<endl;
    return 0;
}