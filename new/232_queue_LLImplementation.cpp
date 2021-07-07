// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

class Queue{
    private:
        node *front;
        node *back;

    public:
        Queue(){
            front =NULL;
            back = NULL;
        }

        void enQueue(int val){
            node *n = new node(val);
            
            if (front==NULL){
                front = n;
                back = n;
                return;
            }
            back->next=n;
            back=n;
        }

        void deQueue(){
            if (front==NULL){
                cout<<"Queue underflow\n";
                return;
            }
            node *todel;
            todel = front;
            front = front->next;
            delete todel;
        }

        int peek(){
            if (front==NULL){
                cout<<"Nothing for peeking:(\n";
                return -1;
            }
            return front->data;
        }

        bool empty(){
            if (front==NULL)
                return 1;
            
            return 0;
        }
};

int main(){

    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout<<"front in queue: "<<q.peek()<<endl;
    q.deQueue();
    cout<<"front in queue: "<<q.peek()<<endl;
    q.deQueue();
    cout<<"front in queue: "<<q.peek()<<endl;
    q.deQueue();
    cout<<"front in queue: "<<q.peek()<<endl;
    cout<<q.empty();

    return 0;
}

// front in queue: 1
// front in queue: 2
// front in queue: 3
// front in queue: Nothing for peeking:(   
// -1
// 1