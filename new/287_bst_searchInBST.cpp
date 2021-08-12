/*Binary Search Tree
    Binary Search Tree is a node-based binary tree data structure which has the following properties:  
    #   The left subtree of a node contains only nodes with keys lesser than the node’s key.
    #   The right subtree of a node contains only nodes with keys greater than the node’s key.
    #   The left and right subtree each must also be a binary search tree. 
    #   There must be no duplicate nodes.

    *   Inorder sequence/traversal of a BST is always a sorted sequence of binary tree

The above properties of Binary Search Tree provides an ordering among keys so that the operations like search, minimum and maximum can be done fast. If there is no ordering, then we may have to compare every key to search for a given key.

                  8
                /  \
               3   10
              / \    \
             1  6    14
              /  \   /
             4   7  13
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

Node* searchInBST(Node* root, int key){
    if(root==NULL)
        return NULL;

    if(root->data==key)
        return root;

    if(key<root->data)
        return searchInBST(root->left, key);
    else
        return searchInBST(root->right, key);
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);
    
    int key = 6;
    if(searchInBST(root, key))
        cout<<"Key Found in BST."<<endl;
    else
        cout<<"Key doesn't exist in BST."<<endl;
    
    key = 50;
    if(searchInBST(root, key))
        cout<<"Key Found in BST."<<endl;
    else
        cout<<"Key doesn't exist in BST."<<endl;
    return 0;
}

// Key Found in BST.
// Key doesn't exist in BST.