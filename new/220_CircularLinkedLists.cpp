// Write a program for circular Linked list

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

Node* head = NULL;

void insertAtBegin(float val){
    Node* n = new Node(val);

    if(head==NULL){
        n->next = n;    // imp
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next!=head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(float val){

    if(head==NULL){
        insertAtBegin(val);
    }
    else{
        Node* n = new Node(val);
        Node* temp=head;
        while(temp->next!=head)
            temp=temp->next;

        temp->next = n;
        n->next = head;
    }
}

void display(){
    
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    
    cout<<endl;
}

void deleteAtHead(){
    if(head==NULL)
        return;

    Node* temp = head;
    while(temp->next!=head)
        temp=temp->next;

    Node* todel = head;
    temp->next = temp->next->next;
    head = head->next;

    delete todel;
}

void deleteATPos(int pos){

    if(pos==1)
        deleteAtHead();

    else{
        int curr = 1;
        Node* temp = head;
        while(curr!=pos-1){
            temp=temp->next;
            curr++;
        }

        Node* todel = temp->next;
        temp->next=temp->next->next;
        
        delete todel;
    }
}

bool searching(float key){
    
    Node* temp = head;
    do{
        if(temp->data==key)
            return 1;

        temp=temp->next;
    } while (temp!=head);
    return 0;
}

int main(){

    insertAtTail(4);
    insertAtBegin(3);
    insertAtTail(5);
    insertAtTail(6);
    insertAtBegin(2);
    insertAtTail(7);

    cout<<"Circular List:-\n";
    display();
    insertAtBegin(1);
    cout<<"Modified Circular List:-\n";
    display();

    float k;
    cout<<"Enter the value to be searched: ";
    cin>>k;
    if(searching(k))
        cout<<k<<" found in the Circular list\n";
    else
        cout<<k<<" not present in the Circular list\n";

    int pos;
    cout<<"Position of the element to be deleted: ";
    cin>>pos;
    deleteATPos(pos);
    cout<<"After deletion, Circular List:-\n";
    display();

    return 0;
}

// Circular List:-
// 2 3 4 5 6 7 
// Modified Circular List:-
// 1 2 3 4 5 6 7 
// Enter the value to be searched: 5
// 5 found in the Circular list
// Position of the element to be deleted: 1
// After deletion, Circular List:-
// 2 3 4 5 6 7

// Circular List:-
// 2 3 4 5 6 7 
// Modified Circular List:-
// 1 2 3 4 5 6 7 
// Enter the value to be searched: 33
// 33 not present in the Circular list
// Position of the element to be deleted: 5
// After deletion, Circular List:-
// 1 2 3 4 6 7