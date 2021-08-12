/*A program to check if a binary tree is BST or not

A binary search tree (BST) is a node based binary tree data structure which has the following properties. 
    •   The left subtree of a node contains only nodes with keys less than the node’s key. 
    •   The right subtree of a node contains only nodes with keys greater than the node’s key. 
    •   Both the left and right subtrees must also be binary search trees.
    From the above properties it naturally follows that: 
    •   Each node (item in the tree) has a distinct key.

            4
          /  \
         2   5
       /  \
      1   3


// METHOD - (Simple but Wrong) 
int isBST(Node* node){
    if (node == NULL)
        return 1;
     
    // false if left is > than node 
    if (node->left != NULL && node->left->data > node->data)
        return 0;
     
    false if right is < than node
    if (node->right != NULL && node->right->data < node->data)
        return 0;
   
    // false if, recursively, the left or right is not a BST
    if (!isBST(node->left) || !isBST(node->right))
        return 0;
     
    // passing all that, it's a BST
    return 1;
}

*/

#include <iostream>
#include <climits>
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

/*METHOD 1 (Correct but not efficient) 
For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node. */

// helper function1
int maxValue(Node* root){
    if(root==NULL)
        return INT_MIN;
        
    return max(root->data, max(maxValue(root->left), maxValue(root->right)));    
}

// helper function2
int minValue(Node* root){
    if(root==NULL)
        return INT_MAX;

    return min(root->data, min(minValue(root->left), minValue(root->right)));
}

bool checkForBST(Node* root){
    if(root==NULL)
        return true;

    // if root.data is less than maxValue of its left subtree than it is not a BST
    if(root->left!=NULL && maxValue(root->left) > root->data)
        return false;

    // if root.data is more than minValue of its right subtree than it is not a BST
    if(root->right!=NULL && minValue(root->right) < root->data)
        return false;

    if(!checkForBST(root->left) || !checkForBST(root->right))
        return false;
    
    return true;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    if(checkForBST(root))
        cout<<"Yes, a BST!"<<endl;
    else
        cout<<"No, not a BST!"<<endl;

    
    Node* root2 = new Node(3);
    root2->left = new Node(2);
    root2->right = new Node(5);
    root2->left->left = new Node(1);
    root2->left->right = new Node(4);
    if(checkForBST(root2))
        cout<<"Yes, a BST!"<<endl;
    else
        cout<<"No, not a BST!"<<endl;
    return 0;
}