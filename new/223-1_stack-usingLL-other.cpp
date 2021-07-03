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

// To write a program ..for showing implementation of a stack using linked list
// For stack using linked list, we always add or delete at the biginning to get order
// of O(1) because for adding or deleting at end we get O(n) 

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class Stack{

    private:
        Node* top;
        
    public:
        Stack(){
            top= NULL;
        }

        void Push(int v){
            Node* n = new Node(v);
            n->next = top;
            top = n;
        }

        int isEmpty(){
            if(top==NULL){
                cout<<"Stack is Empty!\n";
                return -1;
            }
            return 0;
        }

        void Pop(){
            if(isEmpty()==-1)
                return;

            Node* todel = top;
            top = top->next;
            delete todel;
        }

        int Top(){
            if(isEmpty()==-1)
                return -1;
            
            return (top->data);
        }
};

int main(){

    Stack st;
    st.Push(1);
    cout<<st.Top()<<endl;   //1
    st.Push(2);
    cout<<st.Top()<<endl;   //2
    st.Push(3);
    cout<<st.Top()<<endl;   //3
    st.Pop();
    cout<<st.Top()<<endl;   //2
    st.Pop();
    cout<<st.Top()<<endl;   //1
    st.Pop();               //Stack is Empty!
    cout<<st.Top()<<endl;   //-1
    cout<<st.isEmpty()<<endl;//Stack is Empty!
                            //-1
    return 0;
}