// To write a program .. to print the sum of each subarray of a given array.

/*Subarray is a continuous part of the array. Number of subarrays of an array with n elements = n
C2 + n = n*(n+1) / 2.
A subsequence is a sequence that can be derived from an array by selecting zero or more elements, without changing the order of the remaining elements. Note: Number of subsequences of an array with n elements = 2 power n.
*/


//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

void subArray(int a[], int n){
    int maxSum = INT_MIN;
    int count =0;
    for (int i=0; i<n; i++){
        int curr_sum =0;
        for (int j=i; j<n; j++){
            curr_sum += a[j];
            count +=1;
            cout<<"Sum of SubArray"<<count<<" : "<<curr_sum<<endl;
            maxSum = max(maxSum, curr_sum);
        }
    }
    cout<<"Max Subarray sum: "<<maxSum;
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
    subArray(a,n);
    cout<<endl;
    return 0;
}