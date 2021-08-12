/*Sorted Array to Balanced BST
Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.
Examples: 
    Input:  Array {1, 2, 3}
    Output: A Balanced BST
                 2
               /  \
              1    3 

    Input: Array {1, 2, 3, 4, 5}
    Output: A Balanced BST
                  3
                /  \
               1    4
               \    \
               2    5

    STRATEGY
    1) Get the Middle of the array and make it root.
    2) Recursively do same for left half and right half.
        a) Get the middle of left half and make it left child of the root
            created in step 1.
        b) Get the middle of right half and make it right child of the
            root created in step 1.
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* sortedArrayToBST(int arr[], int start, int end){
    if(start>end)
        return NULL;

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

void preorder(Node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int start=0, end=sizeof(arr)/sizeof(arr[0]);

    Node* root = sortedArrayToBST(arr, start, end-1);
    preorder(root); //3 1 2 4 5
    cout<<endl;
    return 0;
}