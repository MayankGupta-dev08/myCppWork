// To write a program ..for deleting a node

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

// if we want to delete n'th node than,
// we have to break the link of (n-1)'th node
// and than link it to (n+1)'th node
void toDelete(float val){

    if(head==NULL)
        return;
    
    if(head->data==val){
        Node* todel = head;
        head = head->next;

        delete todel;
    }
    else{
        Node* temp= head;
        while(temp->next->data!=val){
            temp=temp->next;
        }
        Node* todel = temp->next;
        temp->next = temp->next->next;
        
        delete todel;
    }
}

int main(){

    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtBigin(2);
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

    float del;
    cout<<"Enter a number to be deleted: ";
    cin>>del;
    toDelete(del);
    
    cout<<"After deletion of "<<del<<" from linked list\n";
    display();

    return 0;
}

// 1 2 3 4 5 6 
// Enter a number to be searched: 5
// Found 5
// Enter a number to be deleted: 5
// After deletion of 5 from linked list    
// 1 2 3 4 6

// 1 2 3 4 5 6
// Enter a number to be searched: 6
// Found 6
// Enter a number to be deleted: 1
// After deletion of 1 from linked list
// 2 3 4 5 6

// 3 
// Enter a number to be searched: 3
// Found 3
// Enter a number to be deleted: 3
// After deletion of 3 from linked list
//  
