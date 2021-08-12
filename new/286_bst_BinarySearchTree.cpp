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

Node* insertBST(Node* root, int val){
    if(root==NULL)
        return new Node(val);
    
    if(val<root->data)
        root->left = insertBST(root->left, val);

    // No duplicates nodes so no need of equality condition
    else    //val>root->data
        root->right = insertBST(root->right, val);
    
    return root;
}

void inorderSeq(Node* root){
    if(root==NULL)
        return;

    inorderSeq(root->left);
    cout<<root->data<<" ";
    inorderSeq(root->right);
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 8);
    insertBST(root, 10);
    insertBST(root, 3);
    insertBST(root, 6);
    insertBST(root, 14);
    insertBST(root, 1);
    insertBST(root, 7);
    insertBST(root, 13);
    insertBST(root, 4);

    // print inorder of BST
    inorderSeq(root);   //1 3 4 6 7 8 10 13 14
    cout<<endl;
    return 0;
}