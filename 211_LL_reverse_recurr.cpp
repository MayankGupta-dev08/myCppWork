// to reverse the linked list using recurrsion
// Time Complexity: O(n) 
// Space Complexity: O(1)

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

Node* reverseRecurrsive(Node* head){
    if(head==NULL || head->next==NULL)
        return head;
    

    /* reverse the rest list and put
        the first element at the end */
    Node* rest = reverseRecurrsive(head->next);
    head->next->next = head;
    
    //making the first element to point Null
    head->next = NULL;

    /* fix the head pointer */
    return rest;
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

    cout<<"After creation of list\n";
    display();

    head = reverseRecurrsive(head);
    cout<<"After reversing of list\n";
    display();

    return 0;
}