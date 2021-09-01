/*
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array.
It is given that all array elements are distinct.

    Example:
        Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 3
        Output: 7

    since smallest --> we have chosen maxHeap as it will only keep larger elements on top and we will only allow k elemets at a time in heap so that we can get kth smallest element and all larger than that will get popped.
*/

#include <iostream>
#include <queue>
using namespace std;

// time Complexity = O(nlogk)
int KthSmallestElement(int arr[], int n, int k){
    if(k>n)
        return -1;
    
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size()>k)
            maxHeap.pop();
    }
    return maxHeap.top();
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3, n=sizeof(arr)/sizeof(arr[0]);
    cout<<k<<"th smallest element in array: "
        <<KthSmallestElement(arr, n, k)<<endl;
    return 0;
}

// 3th smallest element in array: 7