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

Node* top= NULL;

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

int main(){

    Push(1);
    cout<<Top()<<endl;
    Push(2);
    cout<<Top()<<endl;
    Push(3);
    cout<<Top()<<endl;
    Pop();
    cout<<Top()<<endl;
    Pop();
    cout<<Top()<<endl;
    Pop();
    Pop();
    cout<<isEmpty()<<endl;
    return 0;
}

// 1
// 2
// 3
// 2
// 1
// Stack is Empty!
// Stack is Empty!
// -1