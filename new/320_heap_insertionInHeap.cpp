/*Insertion in Heaps
    Given a Binary Heap and a new element to be added to this Heap. The task is to insert the new element to the Heap maintaining the properties of Heap. 

    Time Complexity = O(logN)
    
    Process of Insertion: The idea is to: 
        First increase the heap size by 1, so that it can store the new element.
        Insert the new element at the end of the Heap.
        This newly inserted element may distort the properties of Heap for its parents. So, in order to keep the properties of Heap, heapify this newly inserted element following a bottom-up approach.

    Illustration:  
        Suppose the Heap is a Max-Heap as:
                      10
                    /    \
                   5      3
                  / \
                 2   4

            The new element to be inserted is 15.

            Process:
            Step 1: Insert the new element at the end.
                      10
                    /    \
                   5      3
                  / \    /
                 2   4  15

            Step 2: Heapify the new element following bottom-up approach.
            -> 15 is more than its parent 3, swap them.
                       10
                    /    \
                   5      15
                  / \    /
                 2   4  3

            -> 15 is again more than its parent 10, swap them.
                       15
                    /    \
                   5      10
                  / \    /
                 2   4  3

            Therefore, the final heap after insertion is:
                       15
                    /    \
                   5      10
                  / \    /
                 2   4  3
*/

#include <iostream>
using namespace std;

# define MAX 100    // maximum size of heap

// heapifying the ith node using bottom up approach
void heapify_maxHeap(int arr[], int n, int i){
    int parent = (i-1)/2;
    if(parent>=0 && arr[i]>arr[parent]){
        swap(arr[i], arr[parent]);
        heapify_maxHeap(arr, n, parent);
    }
}

void insertNodeInHeap(int arr[], int &n, int key){
    n=n+1;
    arr[n-1] = key;
    heapify_maxHeap(arr, n, n-1);   //heapifying from bottom to up
}
 
void printArray(int arr[], int n){
    cout<<"Array representation of Heap is:\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[MAX] = {10, 5, 3, 2, 4};
    int key = 15, n = 5;
    
    cout<<"Our original heap\n";
    printArray(arr, n);
    insertNodeInHeap(arr, n, key);
    cout<<"After inserting an element: "<<key<<" in our heap\n";
    printArray(arr, n);
    return 0;
}

// Our original heap
// Array representation of Heap is:
// 10 5 3 2 4 
// After inserting an element: 15 in our heap
// Array representation of Heap is:
// 15 5 10 2 4 3 