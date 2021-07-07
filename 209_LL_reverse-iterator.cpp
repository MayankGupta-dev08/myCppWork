// To write a program ..for reversing a linked list using iteraotr method
// Time Complexity: O(n) 
// Space Complexity: O(1)

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

void reverseList(){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        // for reversing
        currptr->next=prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    head = prevptr;
}

void display(){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){

    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtBigin(2);
    insertAtBigin(1);
    insertAtEnd(6);

    cout<<"After creation of list\n";
    display();

    reverseList();
    cout<<"After reversing of list\n";
    display();

    return 0;
}