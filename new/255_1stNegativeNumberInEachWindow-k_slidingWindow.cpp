// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
// Input : 
    // N = 8
    // A[] = {12, -1, -7, 8, -15, 30, 16, 28}
    // K = 3
// Output :
    // -1 -1 -7 -15 -15 0 

/*Thing to remember in sliding window question -
    for window of size k and arr[n] -> total windows = n-k+1
    for window size -> j-i+1
*/

#include <iostream>
#include <list>
using namespace std;

// brute force approach - O(n*n)
void firstNegNumb_inWindowK(int arr[], int n, int k){
    for (int i = 0; i < n-k+1; i++){
        int num = 0;
        for (int j = i; j < k+i; j++){
            if(arr[j]<0){
                num=arr[j];
                break;
            }
        }
        if(num<0)
            cout<<num<<" ";
        else
            cout<<0<<" ";
    }
    cout<<"\n";
}

// optimised approach - O(n)
// Main idea - here only negative numbers will be useful and positive be be useless
void firstNegNumb_inSlidingWindowK(int arr[], int n, int k){
    int i=0,j=0;
    list<int> negNums;
    while(j<n){
        if(arr[j]<0)
            negNums.push_back(arr[j]);
        if(j-i+1 == k){
            if(negNums.empty())
                cout<<0<<" ";
            else{
                cout<<negNums.front()<<" ";
                    if(arr[i]==negNums.front())
                    negNums.pop_front();
            }
            i++;
        }
        j++;
    }
    cout<<"\n";
}

int main(){
    int n =8, k=3;
    int a[n] = {12, -1, -7, 8, -15, 30, 16, 28};
    // firstNegNumb_inWindowK(a,n,k);
    firstNegNumb_inSlidingWindowK(a,n,k);
    return 0;
}

// -1 -1 -7 -15 -15 0