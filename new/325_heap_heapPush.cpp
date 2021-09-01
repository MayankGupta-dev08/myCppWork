/*doing push operation in heap
    Example:
        Original heap
                    8
                  /   \
                 7     5
               /  \ 
              4   3 
            heap[] = {8, 7, 5, 4, 3}, maxSize = 7, currSize = 5;

        After pushing 6 in heap
                    8
                  /   \
                 7     6
               /  \  /
              4   3 5
            heap[] = {8, 7, 6, 5, 4, 3}, maxSize = 7, currSize = 6;

        After pushing 9 in heap
                    9
                  /   \
                 7     8
               /  \  /  \
              4   3 5    6
            heap[] = {9, 7, 8, 5, 4, 3, 6}, maxSize = 7, currSize = 7;

        After pushing 2 in heap
            heap overflow!!
            heap[] = {9, 7, 8, 5, 4, 3, 6}, maxSize = 7, currSize = 7;
*/


#include <iostream>
using namespace std;

#define n 7 // for max size of heap

void maxHeap_bottom2up(int heap[], int i){
    int parent = (i-1)/2;
    if(parent>=0 && heap[parent]<heap[i]){
        swap(heap[i], heap[parent]);
        maxHeap_bottom2up(heap, parent);
    }
}

void heapPush(int heap[], int key, int &size){
    if(size>=n){
        cout<<"sorry, heap overflow!!\n";
        return;
    }
    cout<<"Pushing "<<key<<" in heap\n";
    heap[size] = key;
    size++;
    maxHeap_bottom2up(heap, size-1);
}

void printHeap(int heap[], int size){
    cout<<"heap elements are:\n";
    for (int i = 0; i < size; i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}

int main(){
    int heap[n] = {8, 7, 5, 4, 3};
    int size = 5;
    cout<<"Original heap\n";
    printHeap(heap, size);


    heapPush(heap, 6, size);
    printHeap(heap, size);

    heapPush(heap, 9, size);
    printHeap(heap, size);
    
    heapPush(heap, 2, size);
    printHeap(heap, size);
    return 0;
}

// Original heap
// heap elements are:
// 8 7 5 4 3 
// Pushing 6 in heap
// heap elements are:
// 8 7 6 4 3 5 
// Pushing 9 in heap
// heap elements are:
// 9 7 8 4 3 5 6 
// sorry, heap overflow!!
// heap elements are:
// 9 7 8 4 3 5 6 