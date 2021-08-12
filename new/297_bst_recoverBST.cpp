/*Recover Binary Search Tree -IMPORTANT
    You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
        Input Tree:
        
                10
              /   \
             5    8
            / \
           2  20

        In the above tree, nodes 20 and 8 must be swapped to fix the tree.  
        Following is the output tree
        
                10
              /  \
            5    20
           / \
          2   8

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

    Main idea - we will use the property of bst that the inorder sequence of the bst is a sorted array
    2 cases to be handeled
        1.  swapped elements are not adjacent to each other inorder sequence
             given = {1,8,3,4,5,6,7,2}

        2.  swapped elements are adjacent to each other inorder sequence
             given = {1,2,4,3,5,6,7,8}

    Strategy: 
        We will use 3 pointers: first, mid, last
        for case1 - 
            first = will point at previous node where 1st time a number < prev number [8]
            mid = will point at node where 1st time a number < prev number [3]
            last = will point at node where 2nd time a number < prev number [2]
            we will swap first with last
        
        for case2 - 
            first = will point at previous node where 1st time a number < prev number [4]
            mid = will point at node where 1st time a number < prev number [3]
            last = [NULL]
            we will swap first with mid
    
    correct inorder sequence should be after correcting bst = {1,2,3,4,5,6,7,8}
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void swapp(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(root==NULL)
        return;

    calcPointers(root->left, first, mid, last, prev);

    // for very first node below if will not work as prev will be NULL
    if(*prev && (root->data < (*prev)->data)){
        if(!(*first)){
            *first = *prev;
            *mid = root;
        }
        else
            *last = root;
    }

    *prev = root;   //for moving ahead in seq

    calcPointers(root->right, first, mid, last, prev);
}

void recoverBST(Node* root){
    Node* first = NULL;
    Node* mid = NULL;
    Node* last = NULL;
    Node* prev = NULL;  //just as temp pointer for manipulating fist, mid and last

    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last){   //if both first and last are not null so -> case1
        swapp(&(first->data), &(last->data));
    }
    else if(first && mid){   //if both first and mid are not null, but last is null so -> case2
        swapp(&(first->data), &(mid->data));
    }
}

void inorder(Node* root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    /*
                6
              /  \
             9   3
           /  \   \
          1   4   13
    */

    Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root);  //1 9 4 6 3 13 
    cout<<endl;

    recoverBST(root);
    inorder(root);  //1 3 4 6 9 13
    cout<<endl;
    return 0;
}