/*C++ program for building maxHeap from Array
    Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
    Corresponding Complete Binary Tree is:
                     1
                  /     \
                3         5
             /    \     /  \
            4      6   13  10
           / \    / \
          9   8  15 17

    The task to build a Min-Heap from above array.

    Note:
        Root is at index 0 in array.
        Left child of i-th node is at (2*i + 1)th index.
        Right child of i-th node is at (2*i + 2)th index.
        Parent of i-th node is at (i-1)/2 index.

    Last non-leaf node = parent of last-node.
    or, Last non-leaf node = parent of node at (n-1)th index.
    or, Last non-leaf node = Node at index ((n-1) - 1)/2.    
*/

#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is an index in arr[]. 
void heapify(int arr[], int n, int i){
    int smallest = i;
    int lchild = (2*i) +1;
    int rchild = (2*i) +2;

    if(lchild<n && arr[lchild]<arr[smallest])
        smallest = lchild;

    if(rchild<n && arr[rchild]<arr[smallest])
        smallest = rchild;

    if(smallest!=i){
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n){
    int startIdx = ((n-1) -1)/2;
    for (int i = startIdx; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int arr[], int n){
    cout<<"Array representation of Heap is:\n";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	int n = sizeof(arr) / sizeof(arr[0]);

	buildHeap(arr, n);
	printHeap(arr, n);
    return 0;
}

// Array representation of minHeap is:
// 1 3 5 4 6 13 10 9 8 15 17 
/*
                      1
                  /     \
                3        5
             /    \    /  \
            4      6  13  10
           / \    / \
          9   8 15  17
*/