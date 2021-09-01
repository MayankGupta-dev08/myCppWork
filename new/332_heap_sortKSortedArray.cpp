/*
Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

    Example:
        Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
        k = 3 
        Output : arr[] = {2, 3, 5, 6, 8, 9, 10}
*/

#include <iostream>
#include <queue>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> pq;

// time comlexity = O(nlogk)
void sorts_KSortedArray(int arr[], int n, int k){
    pq minHeap;
    int idx=0;
    for (int i = 0; i < n; i++){
        minHeap.push(arr[i]);
        if(minHeap.size()>k){
            arr[idx++]=minHeap.top();
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        arr[idx++] = minHeap.top();
        minHeap.pop();
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3, n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original "<<k<<" sorted array:\n";
    printArray(arr, n);
    
    sorts_KSortedArray(arr,n,k);
    cout<<"After sorting using minHeap\n";
    printArray(arr, n);
    return 0;
}

// Original 3 sorted array:
// 6 5 3 2 8 10 9 
// After sorting using minHeap
// 2 3 5 6 8 9 10