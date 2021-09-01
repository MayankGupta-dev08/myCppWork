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

    Approach1: Brute Force Solution  —  Putting all the nodes in an array and sort them.
        Traverse all the linked lists and collect the values of the nodes into an array.
        Sort and iterate over this array to get the proper value of nodes.
        Create a new sorted linked list and extend it with the new nodes.
*/

#include <iostream>
#include <vector>
#include <algorithm>
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


// time complexity = (nlogn) and space complexity = O(n)
Node* mergeKSortedLinkedLists(Node* arr[], int k){
    vector<int> store;
    
    for(int i=0; i<k; i++){
        Node* temp = arr[i];
        while(temp!=NULL){
            store.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(store.begin(), store.end());
    
    Node* node = new Node(-1);
    Node* ptr = node;
    for(int i=0; i<store.size(); i++){
        ptr->next = new Node(store[i]);
        ptr = ptr->next;
    }

    return node->next;
}

int main(){
    int k = 3;
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
    Node* head = mergeKSortedLinkedLists(arr, k);
    cout<<"Merged Sorted Linked Lists:-\n";
    printLL(head);

    return 0;
}

// Merged Sorted Linked Lists:-
// 1 1 2 3 4 4 5 6