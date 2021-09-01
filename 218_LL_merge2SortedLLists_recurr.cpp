// To write a program ..for merging two sorted linked lists
// Time Complexity = 

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

class LList{ 

    public:
        Node* head;
        LList(){
            head = NULL;
        }

        Node* getHead(){
            return head;
        }

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

        Node* mergeLL_recurr(Node* &head1, Node* &head2){

            if(head1 == NULL)
                return head2;

            if(head2 == NULL)
                return head1;

            Node* result;
            if(head1->data<head2->data){
                result = head1;
                result->next = mergeLL_recurr(head1->next, head2);
            }
            else{
                result = head2;
                result->next = mergeLL_recurr(head1, head2->next);
            }

            return result;
        }
};


int main(){

    LList l1;
    int arr1[] = {1,3,5,7,9};
    for (int i = 0; i < 5; i++)    
        l1.insertAtEnd(arr1[i]);

    cout<<"Linked List1:-\n";
    l1.display();

    LList l2;
    int arr2[] = {2,4,6,8};
    for (int i = 0; i < 4; i++)    
        l2.insertAtEnd(arr2[i]);

    cout<<"Linked List2:-\n";
    l2.display();

    l1.head = l1.mergeLL_recurr(l1.head, l2.head);
    cout<<"Merged Linked List:-\n";
    l1.display();

    return 0;
}

// Linked List1:-
// 1 3 5 7 9 
// Linked List2:-
// 2 4 6 8 
// Merged Linked List:-
// 1 2 3 4 5 6 7 8 9 