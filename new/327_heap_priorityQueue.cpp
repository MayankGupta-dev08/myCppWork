// using c++ stl priority_queue for implementing heaps
    // priority_queue is a queue (FIFO) but gives priority to larger numbers so stores in desc order
    // same as heaps

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    // priority_queue is maxHeap is by default
    priority_queue<int, vector<int>> maxHeap;
    cout<<"maxHeap using priority_queue\n";
    maxHeap.push(1);
    maxHeap.push(2);
    maxHeap.push(4);
    maxHeap.push(3);
    cout<<maxHeap.top()<<endl;  //4

    maxHeap.pop();
    cout<<maxHeap.top()<<endl;  //3
    maxHeap.pop();
    cout<<maxHeap.top()<<endl;  //2

    // greater<int> will reverse the priority
    priority_queue<int, vector<int>,  greater<int>> minHeap;
    cout<<"minHeap using priority_queue\n";
    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(4);
    minHeap.push(3);
    cout<<minHeap.top()<<endl;  //1

    minHeap.pop();
    cout<<minHeap.top()<<endl;  //2
    minHeap.pop();
    cout<<minHeap.top()<<endl;  //3
    
    return 0;
}

// maxHeap using priority_queue
// 4
// 3
// 2
// minHeap using priority_queue
// 1
// 2
// 3