// To write a program ..to print all the prime numbers from 1 till n
// Sieve Of Eratosthenes

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void primeSieve(int n){
    int prime[100] = {0};   //Initalising an int array with all as 0

    for (int i = 2; i <=n; i++){    //with 2 as first num, we will cross out all its multiple
        if (prime[i]==0){
            for (int j= i*i; j<= n; j += i){
                prime[j]=1;
            }
        }
    }
    
    cout<<"All prime numbers till "<<n<<" are: "<<endl;
    for (int i = 2; i <= n; i++){
        if (prime[i]==0)
            cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    int n;
    cin>>n;
    primeSieve(n);
    
    return 0;
}