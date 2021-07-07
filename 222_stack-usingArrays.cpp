/*STACKS
A stack is a list with the restriction thta insertion and deletion can be done only from one end called the top.
It works on LIFO
Operations:     
            Push
            Pop
            Top
            isEmpty
All operations take constant time i.e. O(1)
*/

// To write a program ..for showing implementation of a stack using array

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define n 100

class Stack{
    private:
        int *arr;
        int top;
    
    public:
        Stack(){
            arr = new int[n];
            top = -1;
        }

        void push(int val){
            if (top==n-1){
                cout<<"Stack overflow...\n";
                return;
            }
            top++;
            arr[top] = val;
        }

        bool empty(){
            if(top==-1){
                cout<<"Stack is already empty!\n";
                return 1;
            }
            return 0;
        }

        void pop(){
            if(empty()){
                return;
            }
            cout<<"Done popping an element\n";
            top--;
        }

        int Top(){
            if(empty())
                return -1;
            
            return arr[top]; 
        }
};

int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}

// 3
// Done popping an element
// 2
// Done popping an element
// 1
// Done popping an element
// Stack is already empty!
// Stack is already empty!
// 1