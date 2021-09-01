/*Deletion in Heap
    Given a Binary Heap and an element present in the given Heap.
    The task is to delete an element from this Heap.

    Time Complexity = O(1) to O(logN)

        The standard deletion operation on Heap is to delete the element present at the root node of the Heap. That is if it is a Max Heap, the standard deletion operation will delete the maximum element and if it is a Min heap, it will delete the minimum element.

    Process of Deletion: 
    Since deleting an element at any intermediary position in the heap can be costly, so we can simply replace the element to be deleted by the last element and delete the last element of the Heap. 
        * Replace the root or element to be deleted by the last element.
        * Delete the last element from the Heap.
        * Since, the last element is now placed at the position of the root node. So, it may not follow the heap property. Therefore, heapify the last node placed at the position of root.
    
    Illustration:  
        Suppose the Heap is a Max-Heap as:
              10
            /    \
           5      3
          / \
         2   4

        The element to be deleted is root, i.e. 10.

        Process:
        The last element is 4.

        Step 1: Replace the last element with root, and delete it.
              4
            /    \
           5      3
          / 
         2   

        Step 2: Heapify root.
        Final Heap:
              5
            /    \
           4      3
          / 
         2   

    In deletion of an element from maxHeap, the deleted element will finally be replaced by the next largest element in the subtree. So, if we are deleting an root element, than next largest will become the root.

    Similary for minHeap it will be next smallest from the subtree.
*/

#include <iostream>
using namespace std;

void heapify_maxHeap(int arr[], int n, int i){
    int largest = i;
    int lch = 2*i +1;
    int rch = 2*i +2;

    if(lch<n && arr[lch]>arr[largest])
        largest = lch;

    if(rch<n && arr[rch]>arr[largest])
        largest = rch;

    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify_maxHeap(arr, n, largest);
    }
}

void deleteInHeap(int arr[], int &n){
    arr[0] = arr[n-1];
    n=n-1;
    heapify_maxHeap(arr, n, 0); //heapifying from top to down
}

void printArray(int arr[], int n){
    cout<<"Array representation of Heap is:\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {10, 5, 3, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Our original heap\n";
    printArray(arr, n);
    deleteInHeap(arr, n);
    cout<<"After deleting the root element of our heap\n";
    printArray(arr, n);
    return 0;
}

// Our original heap
// Array representation of Heap is:
// 10 5 3 2 4 
// After deleting the root element of our heap
// Array representation of Heap is:
// 5 4 3 2 