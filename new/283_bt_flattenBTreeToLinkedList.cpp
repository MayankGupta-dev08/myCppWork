/*Flatten a binary tree into linked list
    Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.
Examples:  
Input : 
          1
        /  \
       2    5
      / \    \
     3   4    6

Output :
    1       
     \      
      2     
       \        
        3       
         \      
          4     
           \        
            5       
             \      
              6     

Input :
        1
       / \
      3   4
         /
        2
         \
          5
Output :
     1
      \
       3
        \
         4
          \
           2
            \ 
             5

    APPROACH
        1.  Recursively flatten the left and right subtrees
        2.  Store the left tail and right tail.
        3.  Store the right subtree as temp and make the left subtree as the right subtree.
        4.  Join the left tail with the right subtree.
        5.  return the right tail
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

void flattenBT(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    
    if(root->left!=NULL){
        flattenBT(root->left);
        
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        Node* leftTail = root->right;   //root.left is now root.right
        // for reaching at the tail of now right part
        while(leftTail->right!=NULL)
            leftTail=leftTail->right;

        leftTail->right=temp;
    }
    flattenBT(root->right);
}

void inorder(Node* root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    
    inorder(root);      //3 2 4 1 5 6 
    cout<<"\n";
    flattenBT(root);    //1 2 3 4 5 6
    inorder(root);
    cout<<"\n";
    return 0;
}