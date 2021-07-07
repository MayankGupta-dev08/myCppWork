// To write a program ..for queue using stack (here we will use 2 stacks)
// here deQueue function will be costly
// stack - LIFO
// queue - FIFO

//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

class que{
    private:
        stack<int> s1;
        stack<int> s2;

    public:
        void enQueue(int val){
            s1.push(val);
        }

        void deQueue(){
            if(Qempty())
                return;
        
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop();
        }

        int peek(){
            if(Qempty())
                return -1;

            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }

        bool Qempty(){
            if(s1.empty() && s2.empty()){
                cout<<"Queue is empty...\n";
                return 1;
            }
            else
                return 0;
        }
};

int main(){
    que q;
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
    cout<<q.Qempty();
    return 0;
}

// front in queue: 1
// front in queue: 2
// front in queue: 3
// front in queue: Queue is empty...
// -1
// Queue is empty...
// 1