// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node{
    public:
        float data;
        node *next;
        node *prev;

        node(float d=0){
            data = d;
            next=NULL;
            prev=NULL;
        }
};

node *head=NULL;

void insertAtEnd(float val){
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

void insertAtBegin(float val){
    node* n = new node(val);
    if(head==NULL)
        head = n;
    else{
        n->next = head;
        head->prev = n;
        head = n;
    }
}

bool search(float key){
    node* temp= head;
    while(temp!=NULL){
        if(temp->data==key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void toDeleteVal(float val){

    if(head==NULL)
        return;
    
    if(head->data==val){
        node* todel = head;
        head = head->next;
        head->prev = NULL;

        delete todel;
    }
    else{
        node* temp= head;
        while(temp->data!=val){
            temp=temp->next;
        }
        node* todel = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        delete todel;
    }
}

void toDeletePos(int pos){

    if(head==NULL)
        return;
    
    if(pos==1){
        node* todel = head;
        head = head->next;
        head->prev = NULL;

        delete todel;
        return;
    }
    
    node* temp = head;
    int count =1;
    while(count!=pos && temp!=NULL){
        temp=temp->next;
        count++;
    }
    
    temp->prev->next = temp->next;
    if(temp->next!=NULL)        //for all except last pos
        temp->next->prev = temp->prev;
        
    delete temp;
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

    cout<<"After creation of Doubly list"<<endl;
    display();

    float num;
    cout<<"Enter a number to be searched: ";
    cin>>num;
    if(search(num))
        cout<<"Found "<<num<<endl;
    else
        cout<<"Not Found "<<num<<endl;

    float del_v;
    cout<<"Enter a number to be deleted: ";
    cin>>del_v;
    if(search(del_v)){
        toDeleteVal(del_v);
        cout<<"After deletion of "<<del_v<<" from linked list\n";
        display();
    }
    else
        cout<<"Number isn't present in the list.\n";

    int p;
    cout<<"Enter the position of the number to be deleted: ";
    cin>>p;
    toDeletePos(p);
    cout<<"After deletion of number at position "<<p<<" from linked list\n";
    display();
    
    return 0;
}