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

    The task to build a Max-Heap from above array.

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
	int largest = i;        // Initialize largest as root
	int l = (2*i) + 1;      // left = 2*i + 1
	int r = (2*i) + 2;      // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void buildHeap(int arr[], int n){
	// Index of last non-leaf node = (i-1)/2
	int startIdx = (n-1 - 1)/2;

	// Perform reverse level order traversal 
    // from last non-leaf node and heapify each node
	for (int i = startIdx; i >= 0; i--)
		heapify(arr, n, i);

}

void printHeap(int arr[], int n){
	cout << "Array representation of maxHeap is:\n";
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

int main(){
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	int n = sizeof(arr) / sizeof(arr[0]);

	buildHeap(arr, n);
	printHeap(arr, n);
	return 0;
}

// Array representation of Heap is:
// 17 15 13 9 6 5 10 4 8 3 1 
/*
                     17
                  /     \
               15        13
             /    \     /  \
            9      6   5  10
           / \    / \
          4   8  3   1
*/