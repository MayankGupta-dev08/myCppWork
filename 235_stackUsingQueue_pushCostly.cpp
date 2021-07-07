// To write a program ..for stack using queue, making push costly, order of n --> O(n)

//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

class Stack{
    private:
        int N;
        queue<int> q1;
        queue<int> q2;

    public:
        Stack(){N=0;}

        void push(int val){
            q2.push(val);
            N++;
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> temp = q1;
            q1=q2;
            q2=temp;
        }

        void pop(){
            q1.pop();
            N--;
        }

        int top(){
            if(N==0)
                return -1;
            return q1.front();
        }

        int size(){
            return N;
        }

};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"size of stack: "<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<"size of stack: "<<st.size()<<endl;
    return 0;
}

// size of stack: 4
// 4
// 3
// 2
// 1
// -1
// size of stack: 0