/*doing push operation in heap
    Example:
        Original heap
                    8
                  /   \
                 7     5
               /  \ 
              4   3 
            heap[] = {8, 7, 5, 4, 3}, maSize = 7, currSize = 5;

        After poping from maxheap
                    7
                  /   \
                 4     5
               / 
              3  
            heap[] = {7, 4, 5, 3}, maxSize = 7, currSize = 4;

        After poping from maxheap
                    5
                  /   \
                 4     3  
            heap[] = {5, 4, 3}, maxSize = 7, currSize = 3;

        After poping from maxheap
                    4
                  /
                 3  
            heap[] = {4, 3}, maxSize = 7, currSize = 2;

        After poping from maxheap
                    3
            heap[] = {3}, maxSize = 7, currSize = 1;

        After poping from maxheap
                    .
            heap[] = {}, maxSize = 7, currSize = 0;

        After poping from maxheap
                heap underflow!!
            heap[] = {}, maxSize = 7, currSize = 0;
*/


#include <iostream>
using namespace std;

#define n 7 // for max size of heap

void maxHeap_top2down(int heap[], int size, int i){
    int largest = i;
    int lch = 2*i +1;
    int rch = 2*i +2;
    
    if(lch<size && heap[lch]>heap[largest])
        largest = lch;

    if(rch<size && heap[rch]>heap[largest])
        largest = rch;

    if(largest!=i){
        swap(heap[i], heap[largest]);
        maxHeap_top2down(heap, size, largest);
    }
}

void heapPop(int heap[], int &size){
    if(size<=0){
        cout<<"sorry, heap underflow!!\n";
        return;
    }
    cout<<"Poping "<<heap[0]<<" from heap\n";
    heap[0] = heap[size-1];
    size--;
    maxHeap_top2down(heap, size, 0);
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

    heapPop(heap, size);
    printHeap(heap, size);

    heapPop(heap, size);
    printHeap(heap, size);
    
    heapPop(heap, size);
    printHeap(heap, size);
    
    heapPop(heap, size);
    printHeap(heap, size);
    
    heapPop(heap, size);
    printHeap(heap, size);
    
    heapPop(heap, size);
    printHeap(heap, size);
    return 0;
}

// Original heap
// heap elements are:
// 8 7 5 4 3 
// Poping 8 from heap
// heap elements are:
// 7 4 5 3 
// Poping 7 from heap
// heap elements are:
// 5 4 3 
// Poping 5 from heap
// heap elements are:
// 4 3 
// Poping 4 from heap
// heap elements are:
// 3 
// Poping 3 from heap
// heap elements are:
//
// sorry, heap underflow!!
// heap elements are:
//