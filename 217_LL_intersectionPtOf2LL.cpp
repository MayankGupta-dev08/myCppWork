// To write a program ..for finding the interssection pt of two linked lists
// Time Complexity = O(l1) if l1>l2 and O(l2) if l2>l1

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

        int lenghtLList(){
            int l=0;
            Node* temp=head;
            while(temp!=NULL){
                l++;
                temp=temp->next;
            }
            return l;
        }

        void intersectingLL(LList &lst2, int pos){
            Node* temp1 = this->head;
            Node* temp2 = lst2.getHead();
            pos--;
            
            while(pos--){
                temp1 = temp1->next;
            }   //for reaching the pos
            
            while(temp2->next!=NULL){
                temp2 = temp2->next;
            }   //for reching last node of lst2

            temp2->next = temp1;
        }

        int intersectionPt(LList &lst2){
            int l1 = this->lenghtLList();
            int l2 = lst2.lenghtLList();

            int diff;
            Node *ptr1, *ptr2;

            // to assign ptr1 to bigger lst
            if(l1>l2){
                diff=l1-l2;
                ptr1 = this->head;
                ptr2 = lst2.getHead();
            }
            else{
                diff=l2-l1;
                ptr1 = lst2.getHead();
                ptr2 = this->head;
            }

            // for reaching at point from where both have equal
            // nodes to be traversed for reaching intersection.
            while(diff){
                ptr1 = ptr1->next;                
                diff--;
            }
            
            while(ptr1!=NULL && ptr2!=NULL){
                if(ptr1==ptr2)
                    return ptr1->data;

                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            return -1;
        }
};


int main(){

    LList lst1;
    int arr1[] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 7; i++)    
        lst1.insertAtEnd(arr1[i]);

    cout<<"Linked List1:-\n";
    lst1.display();

    LList lst2;
    int arr2[] = {9,10};
    for (int i = 0; i < 2; i++)    
        lst2.insertAtEnd(arr2[i]);

    cout<<"Linked List2:-\n";
    lst2.display();

    lst1.intersectingLL(lst2, 5);
    cout<<" After instercting List1 and List2:-\n";
    lst2.display();

    cout<<"Intersecting at: "<<lst1.intersectionPt(lst2)<<endl;

    return 0;
}

// Linked List1:-
// 1 2 3 4 5 6 7
// Linked List2:-
// 9 10
//  After instercting List1 and List2:-
// 9 10 5 6 7
// Intersecting at: 5