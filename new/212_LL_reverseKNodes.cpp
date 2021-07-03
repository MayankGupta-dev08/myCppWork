// to reverse k nodes of the linked list at a time
// Given a linked list and an integer K. Reverse the nodes of a linked list k at a time
// and return its modified list.

// Idea: There are 2 cases:
    // 1. The size of the linked list is less than K. In this case, return the list as it is.
    // 2. The size of the linked list is more than K. Reverse the first K nodes and 
        // recurse for the remaining list.


#include<iostream>
using namespace std;

class Node{
    public:
        float data;
        Node *next;
        
        Node(float v=0){
            data = v;
            next = NULL;
        }
};

Node *head = NULL;

void insertAtBigin(float val){
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtEnd(float val){
    Node *n = new Node(val);
    if(head==NULL)
        head = n;
    else{
        Node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = n;
    }
}

Node* reverseKNodes(Node* head, int k){
    
    // reversing first K nodes iteratively
    Node *prevptr = NULL;
    Node* currptr = head;
    Node * nextptr;
    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        // for reversing the link
        currptr->next=prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    // After this our prevptr will be pointing to element
    // which will be our new head, but currently head will be
    // the first element of original list
    
    // linking the first element of original list to 
    // rest of the list which will get  reversed for K nodes
    if(nextptr!=NULL)
        head->next = reverseKNodes(nextptr, k);

    // Now our list if ready, just we have to fix head
    return prevptr;
}

void display(){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
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
    insertAtEnd(7);

    cout<<"After creation of list\n";
    display();

    int k;
    cout<<"What should be the value of k: ";
    cin>>k;
    head = reverseKNodes(head, k);
    cout<<"After reversing K nodes of the list at a time.\n";
    display();

    return 0;
}

// After creation of list
// 1 2 3 4 5 6
// What should be the value of k: 2
// After reversing K nodes of the list at a time.
// 2 1 4 3 6 5


// After creation of list
// 1 2 3 4 5 6
// What should be the value of k: 3
// After reversing K nodes of the list at a time.
// 3 2 1 6 5 4


// After creation of list
// 1 2 3 4 5 6 7 
// What should be the value of k: 4
// After reversing K nodes of the list at a time.
// 4 3 2 1 7 6 5 