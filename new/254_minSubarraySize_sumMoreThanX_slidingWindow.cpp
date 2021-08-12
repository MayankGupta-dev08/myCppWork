/* Min Subarray size for which sum>X
    Given an array arr[] of integers of size N and X. Return the minimum sybarray size for which sum more than X.

    Input:  arr = {1, 4, 45, 7, 10, 19}, n = 6, X = 51
    Options:-
        [1, 4, 45, 7] = 57
        [4, 45, 7] = 56 > 51 and size = 3  --> ans
        [45, 7] = 52 > 51 and size = 2  --> ans
        No more subarrays whiose sum>51
        [7, 10, 19] = 36 < 51
    Output: 2
*/

#include <iostream>
#include <climits>
using namespace std;

// brute force approach - TC = O(n*n)
int minSubarraySize_moreThan_X(int arr[], int n, int x){
    int window=INT_MAX;
    for (int i = 0; i < n; i++){
        int sum=0;
        for (int j = i; j < n; j++){
            sum+=arr[j];
            if(sum>x){
                window = min(window, j-i+1);
                break;
            }
        }
    }
    return window;
}

// optimised approach - sliding window - TC = O(n)
int minSubarraySize_moreThanX(int arr[], int n, int x){
    int i=0, j=0, sum=0, ans=INT_MAX;
    while(j<n){
        sum = sum+arr[j];
        while(sum > x){
            ans=min(ans, j-i+1);
            sum-=arr[i];
            i++;
        }
        j++;
    }
    return ans;
}

int main(){
    int arr[] = {1, 4, 45, 7, 10, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=51;
    cout<<"Minimum subarray size with sum>"<<x<<": "
        <<minSubarraySize_moreThan_X(arr,n,x)<<endl;    //2
    
    cout<<"Minimum subarray size with sum>"<<x<<": "
        <<minSubarraySize_moreThanX(arr,n,x)<<endl;    //2

    return 0;
}