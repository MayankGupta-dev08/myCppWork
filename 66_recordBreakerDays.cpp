// To write a program ..to return the number of record Breaker Days from an array of size N, where it represents N consecutive days with  each element representing the number of customers arrived on that day. 
// Time Complexity can't be O(n2), here it is O(n).
// GOOGLE KICKSTART

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void recordBreakerDays(int a[],int n){
    int counter = 0;
    int j=0;
    int mx = -1;        //Customers can't be negative so thi wil work.
    while (j<n){
        if(( (a[j]>a[j+1]) || (j==n-1) ) && (a[j]>mx)){
            counter++;
            mx = a[j];
            cout<<"Record Breaker Day"<<counter<<": at Day"<<j+1;
            cout<<". With a score of: "<<a[j]<<" customers."<<endl;
        }
        j++;
    }
}

int main(){

    int n;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of your array.\n";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    recordBreakerDays(a,n);
    return 0;
}

/* OUTPUT SCREEN
Enter a size of array: 8
Enter the elements of your array.
1 2 0 7 2 0 2 2
Record Breaker Day1: at Day2. With a score of: 2 customers.
Record Breaker Day2: at Day4. With a score of: 7 customers.
*/