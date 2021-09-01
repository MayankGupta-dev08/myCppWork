/*Merge k Sorted Lists
    You are given an array of k linked-list list, each linked-list is sorted in ascending order.
    Merge all the linked-list into one sorted linked-list and return it.

    Example 1:
        Input: list = [[1,4,5],[1,3,4],[2,6]]
        Output: [1,1,2,3,4,4,5,6]
        Explanation: The linked-list are:
        [ 1->4->5, 1->3->4, 2->6 ]
        merging them into one sorted list:
        1->1->2->3->4->4->5->6

    Approach: Using minHeap
        We can easily solve this problem in O(n.log(k)) time by using a min-heap. The idea is to construct a min-heap of size k and insert each list’s first node into it. Then pop the root node (having minimum value) from the heap and insert the next node from the “same” list as the popped node. We repeat this process until the heap is exhausted.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(0), next(NULL) {}
    Node(int val) : data(val), next(NULL) {}
    Node(int val, Node* next) : data(0), next(next) {}
};

struct cmp{
    bool operator() (Node* lsh, Node* rsh){
        return (lsh->data > rsh->data);
    }
};

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"nullptr"<<endl;
}

Node* mergeKSortedLinkedLists(Node* list[], int k){
    priority_queue<Node*, vector<Node*>, cmp> minHeap;
    for(int i=0; i<k; i++)
        minHeap.push(list[i]);
    
    // head points to the first node of the ans and tail points to the last node
    Node *head=NULL, *tail=NULL;    // for the resultant
    while(!minHeap.empty()){
        Node* mn = minHeap.top();
        minHeap.pop();

        // adding the min node
        if(head==NULL)
            head = tail = mn;
        else{
            tail->next = mn;
            tail = mn;
        }

        // taking the next node from the same list and inserting into the minHeap
        if(mn->next!=NULL)
            minHeap.push(mn->next);
    }
    return head;
}

int main(){
    int k = 3;  //number of sorted linked list
    Node* list[k]; // an array to store the head nodes of linked list
    
    // list1
    list[0] = new Node(1);
    list[0]->next = new Node(4);
    list[0]->next->next = new Node(5);
    
    // list2
    list[1] = new Node(1);
    list[1]->next = new Node(3);
    list[1]->next->next = new Node(4);
    
    // list3
    list[2] = new Node(2);
    list[2]->next = new Node(6);

    // merging all linked list into one
    Node* head = mergeKSortedLinkedLists(list, k);
    printLL(head);  
    return 0;
}

// 1->1->2->3->4->4->5->6->nullptr