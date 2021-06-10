// Print whether a prime numbers is prime or not.

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, flag;
    cout<<"Enter a number for check of prime: ";
    cin>>n;
    flag = 0;
    // for (int i =2; i<n; i++)
    for (int i =2; i<sqrt(n); i++){
        if (n<1){
            cout<<"Not prime!\n";
            break;
        }
        else if (n%i==0){
            flag +=1;
            cout<<"Not prime!\n";
            break;
        }
    }
    
    if (flag==0){
        cout<<"Number is prime!\n";
    }
    
    return 0;
}