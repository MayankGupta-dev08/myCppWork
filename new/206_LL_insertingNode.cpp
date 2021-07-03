// --------------------Linked list insert node beginning or end--------------------
// We can insert a node at the beginning or at the end of the linked list.

// Beginning:
    // - Create a new Node.
    // - Make link part of the newly created node equal to head pointer & adjust the head pointer to point to the newly created node.

// End
    //-  Create a new Node.
    //-  Traverse the Linked list to reach the last Node & point the link part of the last Node to newly created Node.
    //-  Make the link part of newly created Node equal to NULL.
    //-  Special Case: If list is empty, create a new node and point head pointer to it.

#include<iostream>
using namespace std;

struct Node{
    float data;
    Node* link;
};

Node* head = NULL;

void insertBegin(float d){
    // dynamically allocating memory to ptr
    Node* ptr = new Node();
    ptr->data = d;    
    ptr->link = head;   // or we  can also write // ptr->link = head->link;
    
    head = ptr;
}

void insertEnd(float d){

    // dynamically allocating memory to ptr
    Node* ptr = new Node();
    ptr->data = d;
    ptr->link = NULL;

    // If list is empty
    if (head==NULL)
        head = ptr;
    else{
        Node* temp = head;
        while(temp->link!=NULL)
            temp = temp->link;
        
        temp->link = ptr;
    }
}

//Function to display linked list
void dispLink(){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<"\n";
}

//Main Function
int main(){
    insertBegin(2);
    insertBegin(1);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    dispLink();
    return 0;
}
