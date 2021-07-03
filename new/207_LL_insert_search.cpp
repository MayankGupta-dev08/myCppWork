// To write a program ..for inserting 

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

void insertAtBigin(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtEnd(Node* &head, int val){
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

void display(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool search(Node* head, int key){
    Node* temp= head;
    while(temp!=NULL){
        if(temp->data==key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){

    // since we are initialsing head in main and not globally,
    // we have to send it evry time.
    Node* head=NULL;

    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtBigin(head, 2);
    insertAtBigin(head, 1);
    insertAtEnd(head, 6);

    display(head);

    if(search(head, 3))
        cout<<"Found 3\n";
    else
        cout<<"Not Found 3\n";

    if(search(head, 7))
        cout<<"Found 7\n";
    else
        cout<<"Not Found 7\n";
        
    return 0;
}