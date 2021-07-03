// To write a program ..maximum Circular Subarray sum

//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

int Kadane_maxSubarraySum(int a[], int n){

    int currSum = 0, maxSum = 0;
    for (int i=0; i<n; i++){
        currSum += a[i];
        maxSum = max(maxSum, currSum);
        if (currSum<0){
            currSum = 0;
        }
    }
    return maxSum;
}

int main(){
// Maximum Circular subarray sum = total sum of the array - sum of non contributing element.
// To get the sum of non contributing element we multiply the array by -1 and get the maximum sum subarray.

    int n;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of your array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int wrapsum;
    // When our array is not circular.
    wrapsum = Kadane_maxSubarraySum(a,n);

    int nonwrapsum;
    int totalSum = 0;
    for (int i = 0; i < n; i++){
        totalSum += a[i]; //finding totalsum of original array.
        a[i]=-a[i];
    }
    nonwrapsum = totalSum + Kadane_maxSubarraySum(a,n);
    // for the above call, it will use array whose sign is changed (+to- and -to+).
    // as total sum contains sum of contributing and noncontributing which reduces it. so just by adding sum of non contributing to it we will get our nonwrap sum.

    // cout<<"Max Subarray sum: "<<wrapsum<<endl;
    cout<<"Max Circular Subarray sum: "<<nonwrapsum<<endl;
    
    return 0;
}