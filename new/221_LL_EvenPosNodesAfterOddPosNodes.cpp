// To write a program ..Put Even Position Nodes after Odd Position Nodes

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
        float data;
        Node* next;

    Node(float val){
        data = val;
        next = NULL;
    }
};

Node* head=NULL;

void insertAtBigin(float val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtEnd(float val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
}

void display(){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void evenAfterOdd(){
    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;

    // we will exit if either odd->next==NULL or even->next==NULL
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    
    // we want even->next to be NULL as it would be our tail
    odd->next = evenStart;
    if(odd->next==NULL) //this means even->next!=NULL
        even->next=NULL;
}

int main(){

    insertAtEnd(4);
    insertAtBigin(3);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtBigin(2);
    insertAtEnd(7);
    insertAtBigin(1);
    
    cout<<"Original linked List:-\n";
    display();
    evenAfterOdd();
    cout<<"Modified linked List:-\n";
    display();

    return 0;
}

// Original linked List:-
// 1 2 3 4 5 6 7
// Modified linked List:-
// 1 3 5 7 2 4 6