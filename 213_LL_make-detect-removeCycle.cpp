/*Hare and Tortoise Problem
Cycle Detection[IMP][without map]
Floyd’s cycle detection
Also know as hare and tortoise method, and slow and fast pointer method.
Idea: Slow and pointers are initially at the start. Slow takes one step. Fast takes
two-step at a time.
Time Complexity: O(n)
*/

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

void makeCyclicList(int pos){
    Node* temp=head;
    Node* startNode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos)
            startNode=temp;
            
        temp=temp->next;
        count++;
    }//after this node we would have got our star node for cycle
    // temp node will be at end node

    // pointing temp node to start node
    temp->next=startNode;
}

bool detectCycle(){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(fast==slow)
            return true;
    }
    return false;
}

void removeCycle(){
    Node* slow=head;
    Node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);

    fast=head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
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
    insertAtEnd(8);
    insertAtEnd(9);

    cout<<"After creation of list\n";
    display();

    int pos;
    cout<<"enter the position for cycle node: ";
    cin>>pos;
    makeCyclicList(pos);
    if(detectCycle())
        cout<<"It is a cyclic list\n";
    else
        cout<<"It is not a cyclic list\n";
    
    cout<<"Removing the cyclicity from list.\n";
    removeCycle();
    if(detectCycle())
        cout<<"It is a cyclic list\n";
    else
        cout<<"Now it is not a cyclic list anymore.\n";

    display();
    return 0;
}

// After creation of list
// 1 2 3 4 5 6 7 8 9 
// enter the position for cycle node: 4
// It is a cyclic list
// Removing the cyclicity from list.       
// Now it is not a cyclic list anymore.
// 1 2 3 4 5 6 7 8 9