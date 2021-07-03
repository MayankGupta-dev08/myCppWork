// To write a program ..for appending last K nodes of a linked list at the start
// Time Complexity = O(n)

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
        float data;
        Node* next;

    Node(float val=0){
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

int lenghtLList(){
    int l=0;
    Node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

void appendLastKNodes(int k){
    Node* newHead;
    Node* newTail;
    Node* tail = head;
    int l = lenghtLList();
    int count = 1;

    k = k%l;  // if k>l, than it will get a new val of k%l
    while(tail->next!=NULL){
        if(count == l-k)
            newTail = tail;
        
        if(count == l-k+1)
            newHead = tail;
        
        tail = tail->next;
        count++;
    }
    tail->next = head;
    newTail->next = NULL;
    head = newHead; 
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 7; i++)    
        insertAtEnd(arr[i]);

    display();

    int k;
    cout<<"Enter the value of last K nodes: ";
    cin>>k;
    appendLastKNodes(k);
    cout<<"After appending last "<<k<<" nodes to the start:-\n";
    display();

    return 0;
}

// 1 2 3 4 5 6 7 
// Enter the value of last K nodes: 3
// After appending last 3 nodes to the start:-
// 5 6 7 1 2 3 4