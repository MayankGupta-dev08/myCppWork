/*Heap Sort
    Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning. We repeat the same process for the remaining elements.

    What is Binary Heap? 
        Let us first define a Complete Binary Tree. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible (Source Wikipedia)
        A Binary Heap is a Complete Binary Tree where items are stored in a special order such that the value in a parent node is greater(or smaller) than the values in its two children nodes. The former is called max heap and the latter is called min-heap. The heap can be represented by a binary tree or array.

    Why array based representation for Binary Heap? 
        Since a Binary Heap is a Complete Binary Tree, it can be easily represented as an array and the array-based representation is space-efficient. If the parent node is stored at index I, the left child can be calculated by 2 * I + 1 and the right child by 2 * I + 2 (assuming the indexing starts at 0).

    Heap Sort Algorithm for sorting in increasing order: 
        1. Build a max heap from the input data. 
        2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree. 
        3. Repeat step 2 while the size of the heap is greater than 1.

    How to build the heap? 
        Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom-up order.
        
        Lets understand with the help of an example:
            Input data: 12, 11, 13, 5, 6, 7
            The numbers in bracket represent the indices in the array representation of data.
                
                Original array representation of binary tree
                             12(0)
                            /   \
                         11(1)   13(2)
                        /   \       /
                     5(3)    6(4)  7(5)
                
                After building a maxHeap binary tree from the given array
                             13(0)
                            /   \
                         11(1)   12(2)
                        /   \       /
                     5(3)    6(4)  7(5)

            Now, its time to delete the root element of heap one by one until the last element 
            On deleting the element we will swap the then root element with (n-1-i)th index element
            and than apply heapify on the reduced sized heap

            [13, 11, 12, 5, 6, 7]
            On iteration 1 of delete process -> swapping 13 with 7 
            and applying maxheap to [7, 11, 12, 5, 6] [13] with index 0 ---> [12, 11, 7, 5, 6] [13]
            
            On iteration 2 of delete process -> swapping 12 with 6 
            and applying maxheap to [6, 11, 7, 5] [12, 13] with index 0 ---> [11, 6, 7, 5] [12, 13]
            
            On iteration 2 of delete process -> swapping 11 with 5 
            and applying maxheap to [5, 6, 7] [11, 12, 13] with index 0 ---> [7, 6, 5] [11, 12, 13]
            
            On iteration 2 of delete process -> swapping 7 with 5 
            and applying maxheap to [6, 5] [7, 11, 12, 13] with index 0 ---> [6, 5] [7, 11, 12, 13]
            
            On iteration 2 of delete process -> swapping 6 with 5 
            and applying maxheap to [5] [6, 7, 11, 12, 13] with index 0 ---> [5] [6, 7, 11, 12, 13]
            
            Finally after full heap sort --> [5, 6, 7, 11, 12, 13]
                             5(0)
                            /   \
                         6(1)    7(2)
                        /   \      /
                     11(3) 12(4)  13(5)

*/

//time complexity = O(nlogn)
#include <iostream>
using namespace std;

void printArray(int [], int);

void maxHeap(int arr[], int n, int i){
    int largest = i;
    int lc = 2*i +1;
    int rc = 2*i +2;

    if(lc<n && arr[lc]>arr[largest])
        largest = lc;

    if(rc<n && arr[rc]>arr[largest])
        largest = rc;

    if(largest!=i){
        swap(arr[i], arr[largest]);
        maxHeap(arr, n, largest);        
    }
}

void heapSort(int arr[], int n){
    
    // building a max heap form a givens array
    int startIdx = (n/2) -1;
    for (int i = startIdx; i >= 0; i--)
        maxHeap(arr, n, i);

    // printArray(arr, n);  //for checking build maxHeap
    
    for (int i = 0; i < n-1; i++){
        swap(arr[0], arr[n-1-i]);
        maxHeap(arr, n-1-i, 0);
    }
}

void printArray(int arr[], int n){
    // cout<<"Array elements are:\n";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout<<"Orignal array\n";
    printArray(arr, n);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}

// Orignal array
// 12 11 13 5 6 7 
// Sorted array is 
// 5 6 7 11 12 13