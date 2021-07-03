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
void toDelete(int val){

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

    int n; float nums; char ch;
    cout<<"How many numbers do you want to insert in linked list: ";
    cin>>n;
    cout<<"For inserting @ bigin -> y & For end -> any other\n";
    for (int i = 1; i <= n; i++){
        cout<<"Enter numb"<<i<<": ";
        cin>>nums;
        cin>>ch;
        if(ch=='y')
            insertAtBigin(nums);
        else
            insertAtEnd(nums);
    }
    

    display();

    
    float del;
    cout<<"Enter a number to be deleted: ";
    cin>>del;
    if(search(del)){
        cout<<"Found "<<del<<endl;
        toDelete(del);
        cout<<"After deletion of "<<del<<" from linked list\n";
        display();
    }
    else{
        cout<<"Not Found "<<del<<endl;
        cout<<"After deletion of "<<del<<" from linked list\n";
        display();
    }

    return 0;
}

// How many numbers do you want to insert in linked list: 3
// For inserting @ bigin -> y & For end -> any other
// Enter numb1: 2 m
// Enter numb2: 3 m
// Enter numb3: 1 y
// 1 2 3 
// Enter a number to be deleted: 1
// Found 1
// After deletion of 1 from linked list
// 2 3
