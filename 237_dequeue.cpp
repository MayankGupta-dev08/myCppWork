/*Deque or Double Ended Queue is a generalized version of Queue data structure that allows insert and delete at both ends.

Operations on Deque:
Mainly the following four basic operations are performed on queue:

insertFront(): Adds an item at the front of Deque.
insertLast(): Adds an item at the rear of Deque.
deleteFront(): Deletes an item from front of Deque.
deleteLast(): Deletes an item from rear of Deque.

In addition to above operations, following operations are also supported
getFront(): Gets the front item from queue.
getRear(): Gets the last item from queue.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.

Applications of Deque:
Since Deque supports both stack and queue operations, it can be used as both. The Deque data structure supports clockwise and anticlockwise rotations in O(1) time which can be useful in certain applications.
Also, the problems where elements need to be removed and or added both ends can be efficiently solved using Deque. For example see Maximum of all subarrays of size k problem., 0-1 BFS and Find the first circular tour that visits all petrol pumps.*/

#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_front(1);   //1
    dq.push_front(2);   //2 1
    dq.push_back(3);   //2 1 3
    dq.push_back(4);   //2 1 3 4
    for(auto i: dq)
        cout<<i<<" ";
    cout<<"\n";
    dq.pop_back();   //2 1 3
    dq.pop_front();   //1 3
    for(auto i: dq)
        cout<<i<<" ";
    cout<<"\n";

    cout<<"size of dequeue: "<<dq.size()<<endl; //2
}