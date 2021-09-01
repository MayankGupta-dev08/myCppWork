/* Max Sum Subarray of size k and sum<X
Given an array of integers of size N and a number K and X. Return the maximum sum of a subarray of size K and it should be less than X.

    Input:  arr = {7,5,4,6,8,9}, n = 6, K = 3, X = 20
    Options:-
        [7,5,4] = 16
        [5,4,6] = 15
        [4,6,8] = 18 <20 --> ans
        [6,8,9] = 23 >20
    Output: 18
*/

#include <iostream>
using namespace std;

// brute force approach - TC = O(n*k)
int maxSumSubarray_K_X(int arr[], int n, int k, int x){
    int maxSum=0;
    for (int i = 0; i < n-k+1; i++){
        int sum=0;
        for (int j = i; j < i+k; j++){
            sum+=arr[j];
        }
        if(sum<x)
            maxSum=max(maxSum, sum);
    }
    return maxSum;
}

// optimised approach - sliding window - TC = O(n)
int maxSumSubarray_k_x(int arr[], int n, int k, int x){
    int i=0, j=0, sum=0, maxSum=0;
    while(j<n){
        sum = sum+arr[j];
        if(j-i+1 == k){
            if(sum<x)
                maxSum = max(sum, maxSum);
            sum = sum - arr[i];
            i++;
        }
        j++;
    }
    return maxSum;
}

int main(){
    int a[] = {7, 5, 4, 6, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);
    int k=3, x=20;
    cout<<maxSumSubarray_K_X(a,n,k,x)<<endl;    //18
    cout<<maxSumSubarray_k_x(a,n,k,x)<<endl;    //18
    return 0;
}