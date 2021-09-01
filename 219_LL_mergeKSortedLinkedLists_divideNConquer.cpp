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

    Approach1: Divide and Conquer
        Pairing up K lists and merging each pair
        After the first pairing, k lists are merged into k/2.
        Repeat this process till we get the final sorted list
            In case of odd numbers of list, we leave that one list to be paired next time till only one list is left as the result.

        time complexity  = O(nlogk) without an extra space
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

// recurrsive way of merging two linked lists
Node* sortedMerged(Node* lA, Node* lB){
    if(lA==NULL)
        return lB;
    else if(lB==NULL)
        return lA;

    Node* result;
    if(lA->data<=lB->data){
        result = lA;
        result->next = sortedMerged(lA->next, lB);
    }
    else{
        result = lB;
        result->next = sortedMerged(lA, lB->next);
    }

    return result;
}

// time complexity = O(kn)
Node* mergeKSortedLinkedLists(Node* arr[], int k){
    int last = k-1;
    while(last!=0){
        int i=0, j=last;
        while(i<j){
            arr[i] = sortedMerged(arr[i], arr[j]);
            i++, j--;
            if(i>=j)
                last=j; //updating last after list grouped once and halved
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
    Node* head = mergeKSortedLinkedLists(arr, k);
    cout<<"Sorted Merged Linked List\n";
    printLL(head);
    return 0;
}

// Sorted Merged Linked List
// 1 1 2 3 4 4 5 6