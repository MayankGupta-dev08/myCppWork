/*Merge k Sorted Lists
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:
        Input: lists = [[1,4,5],[1,3,4],[2,6]]
        Output: [1,1,2,3,4,4,5,6]
        Explanation: The linked-lists are:
        [ 1->4->5, 1->3->4, 2->6 ]
        merging them into one sorted list:
        1->1->2->3->4->4->5->6

    Approach1: Simple Approach
        A Simple Solution is to initialize the result as the first list. Now traverse all lists starting from the second list. Insert every node of the currently traversed list into result in a sorted way.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(0), next(NULL) {}
    Node(int val) : data(val), next(NULL) {}
    Node(int val, Node* next) : data(0), next(next) {}
};

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// time complexity = O(kn)
Node* mergeKSortedLinkedLists(Node* arr[], int k){
    for(int i=1; i<=k; i++){
        while(true){
            Node *head_0=arr[0], *head_i=arr[i];
            
            if(head_i==NULL)
                break;
            
            if(head_0->data>=head_i->data){
                arr[i] = head_i->next;
                head_i->next = head_0;
                arr[0] = head_i;
            }
            else    //  (head_0->data<head_i->data)
                while(head_0->next!=NULL){
                    if(head_0->next->data>=head_i->data){
                        arr[i] = head_i->next;
                        head_i->next = head_0->next;
                        head_0->next = head_i;
                        break;
                    }
                    head_0 = head_0->next;

                    // if it is the last node of head_0
                    if(head_0->next==NULL){
                        arr[i] = head_i->next;
                        head_i->next = NULL;
                        head_0->next = head_i;
                        head_0->next->next = NULL;
                        break;
                    }
                }
            
        }
    }
    return arr[0];
}

int main(){
    int k = 3;  //number of sorted linked list
    // linked list will be in an array of node* type
    Node* arr[k];
    
    // list1
    arr[0] = new Node(1);
    arr[0]->next = new Node(4);
    arr[0]->next->next = new Node(5);
    
    // list2
    arr[1] = new Node(1);
    arr[1]->next = new Node(3);
    arr[1]->next->next = new Node(4);
    
    // list3
    arr[2] = new Node(2);
    arr[2]->next = new Node(6);

    // merging all the linked lists
    Node* head = mergeKSortedLinkedLists(arr, k-1); //k-1 as we will use 1st list as the one to make changes

    printLL(head);  
    return 0;
}