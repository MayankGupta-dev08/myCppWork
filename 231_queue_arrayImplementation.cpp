// To write a program for array implementation of queue

#include<iostream>
using namespace std;

#define n 20

class Queue{
    private:
        int* arr;
        int front;
        int back;

    public:
        Queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        void enQueue(int val){
            if(back==n-1){
                cout<<"Queue overflow...\n";
                return;
            }
            back++;
            arr[back] = val;

            if(front==-1)
                front++;
        }

        void deQueue(){
            if(front>back || front==-1){
                cout<<"Nothing in queue\n";
                return;
            }
            front++;
        }

        int peek(){
            if(front>back || front==-1){
                cout<<"Nothing in queue\n";
                return -1;
            }
            return arr[front];
        }

        bool empty(){
            if(front>back || front==-1)
                return 1;
            
            else
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
// front in queue: Nothing in queue        
// -1
// 1