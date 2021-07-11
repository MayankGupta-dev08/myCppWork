// To write a program ..to return the number of record Breaker Days from an array of size N, where it represents N consecutive days with  each element representing the number of customers arrived on that day. 
// A day is record breaking if it satisfies both of the following conditions: 1) The number of visitors on the day is strictly larger than the number of visitors on each of the previous days. and 2) Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day. Note that the very first day could be a record breaking day!
// Time Complexity can't be O(n2), here it is O(n).
// GOOGLE KICKSTART

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void recordBreakerDays(int a[],int n){
    int counter = 0;
    int mx = -1;        //Customers can't be negative so this will work.
    for (int j=0; j<n; j++){
        if(( (a[j]>a[j+1]) || (j==n-1) ) && (a[j]>mx)){
            counter++;
            mx = a[j];
            cout<<"Record Breaker Day"<<counter<<": at Day"<<j+1;
            cout<<". With a score of: "<<a[j]<<" customers."<<endl;
        }
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