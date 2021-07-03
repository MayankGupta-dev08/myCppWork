// To write a program ..to print all the prime numbers from 1 till n
// Sieve Of Eratosthenes

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void primeFactorSieve(int n){
    int spf[1001] = {0};   //Initalising an int array with all as 0
    for (int i = 1; i<=n; i++){
        spf[i]=i;
    }
    
    for (int i = 2; i <= n; i++){    //with 2 as first num, we will cross out all its multiple
        if (spf[i]==i){
            for (int j= i*i; j<= n; j += i){
                if(spf[j]=j)
                    spf[j]=i;
            }
        }
    }
    
    cout<<"All prime factors of the "<<n<<" are: ";
    while(n!=1){
        cout<<spf[n]<<" ";      
        //for 10 => 2, then n=10/2 = 5 => 5, since for every number we are starting for j from i*i
        n=n/spf[n];
    }
    cout<<endl;
}

int main(){

    int n;
    cin>>n;
    primeFactorSieve(n);
    
    return 0;
}