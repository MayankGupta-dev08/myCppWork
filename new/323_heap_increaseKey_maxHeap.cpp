/*Increase a key
    On increasing a node value in a maxHeap, node may move up the heap to maintain the heap property
    Example:
        increasing 5 to 50 in the given heap

                    9
                  /  \
                 8    7
               /  \  /  \
              6   5 4   3

        After increasing the value of 5 to 50

                   50
                  /  \
                 9    7
               /  \  /  \
              6   8 4   3         
*/

#include <iostream>
using namespace std;

void maxHeap_bottom2up(int arr[], int n, int i){
    int parent = (i-1)/2;
    if(parent>=0 && arr[parent]<arr[i]){
        swap(arr[i], arr[parent]);
        maxHeap_bottom2up(arr, n, parent);
    }
}

void increaseKey_heap(int arr[], int n, int idx, int val){
    if((idx>=n && idx<0) || arr[idx]>val)
        return;
        
    arr[idx]=val;
    maxHeap_bottom2up(arr, n, idx);
}

void printArray(int arr[], int n){
    cout<<"Elements are:\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {9, 8, 7, 6, 5, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int keyIdx = 4;
    int keyVal = 50;

    printArray(arr, n);
    increaseKey_heap(arr, n, keyIdx, keyVal);
    printArray(arr, n);
    return 0;
}

// Elements are:
// 9 8 7 6 5 4 3
// Elements are:
// 50 9 7 6 8 4 3