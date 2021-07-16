// To write a program ..Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

/*Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// brute force
int maxSumSubarr(int arr[], int n, int k){
    int maxSum = 0;
    for (int i = 0; i < n-k+1; i++){
        int sum=0;
        for (int j = i; j < k+i; j++){
            sum=sum+arr[j];
        }
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

// optimised approach
int maxSumSubarray(int arr[], int n, int k){
    int i=0, j=0, sum=0, maxSum=0;
    while(j<n){
        sum = sum+arr[j];
        if(j-i+1 == k){
            maxSum = max(sum, maxSum);
            sum = sum - arr[i];
            i++;
        }
        j++;
    }
    return maxSum;
}

int main(){
    int a[]={100, 200, 300, 400};
    int k=2, n=4;
    cout<<maxSumSubarr(a,n,k)<<endl;    //700
    cout<<maxSumSubarray(a,n,k)<<endl;  //700
    return 0;
}