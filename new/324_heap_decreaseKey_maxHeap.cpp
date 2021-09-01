/*Decrease a key
    On decreasing a node value in a maxHeap, node may remain at its position or move down the heap to maintain the heap property
    Example:
        decreasing 8 to 0 in the given heap

                    9
                  /  \
                 8    7
               /  \  /  \
              6   5 4   3
            /  \
           1    2

        After increasing the value of 5 to 50

                    9
                  /  \
                 6    7
               /  \  /  \
              2   5 4   3         
            /  \
           1    0
*/

#include <iostream>
using namespace std;

void maxHeap_top2down(int arr[], int n, int i){
    int largest = i;
    int lch = 2*i +1;
    int rch = 2*i +2;
    
    if(lch<n && arr[lch]>arr[largest])
        largest = lch;

    if(rch<n && arr[rch]>arr[largest])
        largest = rch;

    if(largest!=i){
        swap(arr[i], arr[largest]);
        maxHeap_top2down(arr, n, largest);
    }
}

void decreaseKey_heap(int arr[], int n, int idx, int val){
    if((idx>=n && idx<0) || arr[idx]<val)
        return;
        
    arr[idx]=val;
    maxHeap_top2down(arr, n, idx);
}

void printArray(int arr[], int n){
    cout<<"Elements are:\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int keyIdx = 1;
    int keyVal = 0;

    printArray(arr, n);
    decreaseKey_heap(arr, n, keyIdx, keyVal);
    printArray(arr, n);
    return 0;
}

// Elements are:
// 9 8 7 6 5 4 3 1 2 
// Elements are:
// 9 6 7 2 5 4 3 1 0