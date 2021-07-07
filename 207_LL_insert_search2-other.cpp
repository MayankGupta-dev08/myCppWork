// To write a program ..for inserting 

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

bool search(float key){
    Node* temp= head;
    while(temp!=NULL){
        if(temp->data==key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){

    insertAtBigin(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtBigin(1);
    insertAtEnd(6);

    display();

    float num;
    cout<<"Enter a number to be searched: ";
    cin>>num;
    if(search(num))
        cout<<"Found "<<num<<endl;
    else
        cout<<"Not Found "<<num<<endl;

    return 0;
}

// 1 2 3 4 5 6 
// Enter a number to be searched: 3
// Found 3