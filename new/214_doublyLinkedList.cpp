// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;

        node(int d=0){
            data = d;
            next=NULL;
            prev=NULL;
        }
};

node *head=NULL;

void insertAtEnd(int val){
    node* n = new node(val);
    if(head==NULL)
        head=n;
    else{
        node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void insertAtBegin(int val){
    node* n = new node(val);
    if(head==NULL)
        head = n;
    else{
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void display(){
    node *temp = head;
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
    insertAtBegin(2);
    insertAtBegin(1);
    insertAtEnd(6);
    cout<<"After creation of Doubly list\n";
    display();

    return 0;
}