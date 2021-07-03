// To write a program ..maximum Subarray sum

//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

void Kadane_maxSubarraySum(int a[], int n){
// Using Kadane's Algorithm time complexity will be Big oh of n.
// if both positive and negative elements are there.
// if only positive then sum till last element and if all negative than we have to use different function.

    int currSum = 0, maxSum = 0;
    for (int i=0; i<n; i++){
        currSum += a[i];
        maxSum = max(maxSum, currSum);
        if (currSum<0){
            currSum = 0;
        }
    }
    cout<<"Max Subarray sum: "<<maxSum;
}


void Kadane_maxSubarraySum_allneg(int a[], int n){
// Using Kadane's Algorithm time complexity will be Big oh of n.
// if all negative than we have subarray of single element with value closest to 0 will give ans. 

    int maxSum = INT_MIN;
    for (int i=0; i<n; i++){
        maxSum = max(maxSum, a[i]);
    }
    cout<<"Max Subarray sum: "<<maxSum;
}

int main(){

    int n;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of your array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    // Kadane_maxSubarraySum(a,n);
    Kadane_maxSubarraySum_allneg(a,n);
    cout<<endl;
    return 0;
}