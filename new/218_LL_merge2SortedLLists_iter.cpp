// To write a program ..for merging two sorted linked lists
// Time Complexity = O(N), where N= max(n1,n2)
// n1 and n2 are the length of the two lists

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
    
    private: 
        Node* head;

    public:
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

        void mergeLL_iter(LList l1, LList l2){
            Node *p1= l1.getHead();
            Node *p2= l2.getHead();
            Node* dummyNode = new Node(-1);
            Node *p3= dummyNode;


            while(p1!=NULL && p2!=NULL){
                if(p1->data<p2->data){
                    p3->next = p1;
                    p1=p1->next;
                }
                else{
                    p3->next = p2;
                    p2=p2->next;
                }
                p3=p3->next;
            }

            while(p1!=NULL){
                p3->next = p1;
                p1=p1->next;
                p3=p3->next;
            }
            while(p2!=NULL){
                p3->next = p2;
                p2=p2->next;
                p3=p3->next;
            }

            head = dummyNode->next;
            delete dummyNode;
        }
};


int main(){

    LList l1;
    int arr1[] = {1,3,5,7,9,10};
    for (int i = 0; i < 6; i++)    
        l1.insertAtEnd(arr1[i]);

    cout<<"Linked List1:-\n";
    l1.display();

    LList l2;
    int arr2[] = {2,4,6,8};
    for (int i = 0; i < 4; i++)    
        l2.insertAtEnd(arr2[i]);

    cout<<"Linked List2:-\n";
    l2.display();

    LList l3;
    l3.mergeLL_iter(l1, l2);
    cout<<"Merged Linked List:-\n";
    l3.display();

    return 0;
}

// Linked List1:-
// 1 3 5 7 9 10
// Linked List2:-
// 2 4 6 8 
// Merged Linked List:-
// 1 2 3 4 5 6 7 8 9 10