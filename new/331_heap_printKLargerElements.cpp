/*
Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.

For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements 
i.e., k = 3 then your program should print 50, 30 and 23.

    since largest --> we have chosen minHeap as it will only keep smaller elements on top and we will only allow k elements at a time in heap so that we can get k larger elements and smaller will than get popped.
*/

#include <iostream>
#include <queue>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> pq;

// time Complexity = O(nlogk)
void print_kLargerElements(int arr[], int n, int k){
    if(k>n)
        return;
    
    pq minHeap;
    for (int i = 0; i < n; i++){
        minHeap.push(arr[i]);
        if(minHeap.size()>k)
            minHeap.pop();
    }
    cout<<k<<" larger elements from the array are:-\n";
    while(minHeap.size()>0){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    cout<<endl;
}

int main(){
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int k = 3, n=sizeof(arr)/sizeof(arr[0]);
    
    print_kLargerElements(arr, n, k);
    return 0;
}

// 3 larger elements from the array are:-
// 23 30 50 