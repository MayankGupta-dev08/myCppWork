// To write a program ..for queue using stack (here we will define one stack and for other we will use the inbuilt stack frame which is the call function)
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

    public:
        void enQueue(int val){
            s1.push(val);
        }

        bool Qempty(){
            if(s1.empty()){
                cout<<"Queue is empty...\n";
                return 1;
            }
            else
                return 0;
        }

        int deQueue(){
            if(Qempty())
                return -1;
        
            int x = s1.top();
            s1.pop();
            if(s1.empty())
                return x;
            
            int item = deQueue();
            s1.push(x);
            return item;
        }
};

int main(){
    que q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout<<"front in queue: "<<q.deQueue()<<endl;
    cout<<"front in queue: "<<q.deQueue()<<endl;
    cout<<"front in queue: "<<q.deQueue()<<endl;
    cout<<"front in queue: "<<q.deQueue()<<endl;
    return 0;
}

// front in queue: 1
// front in queue: 2
// front in queue: 3
// front in queue: Queue is empty...       
// -1