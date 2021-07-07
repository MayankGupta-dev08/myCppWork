#include<bits/stdc++.h>
using namespace std;

class Node{
	
	public:
		int data;
		Node *next;
		
		// was not needed in this example 
        Node(){
			data = 0;
			next = NULL;
		}
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

class LinkedList_Test{
	Node *head;
	
	public:
		LinkedList_Test(){
			this->head = NULL;
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
		
		void reverseList(){
		    Node* prevptr = NULL;
		    Node* currptr = head;
		    Node* nextptr;
		
		    while(currptr!=NULL){
		        nextptr = currptr->next;
		        currptr->next=prevptr;
		
		        prevptr = currptr;
		        currptr = nextptr;
		    }
		    head = prevptr;
		}
		
		void display(){
		    Node* temp= head;
		    while(temp!=NULL){
		        cout<<temp->data<<" ";
		        temp = temp->next;
		    }
		    cout<<endl;
		}

};

int main(){
	
	LinkedList_Test l1;
	
	LinkedList_Test l2;
	
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.insertAtBigin(2);
    l1.insertAtBigin(1);
    l1.insertAtEnd(6);
    cout<<"After creation of list1\n";
    l1.display();

    l1.reverseList();
    cout<<"After reversing of list1\n";
    l1.display();
    
    
    l2.insertAtEnd(3);
    l2.insertAtEnd(4);
    l2.insertAtEnd(5);
    l2.insertAtBigin(2);
    l2.insertAtBigin(1);
    l2.insertAtEnd(6);
    cout<<"After creation of list2\n";
    l2.display();

    return 0;
}

// After creation of list1
// 1 2 3 4 5 6 
// After reversing of list1
// 6 5 4 3 2 1 
// After creation of list2
// 1 2 3 4 5 6