/*Is Balanced Binary tree?
    A binary tree is said to be balanced if for all of its nodes, the absolute difference of height of left subtree and right subtree <=1.

Balanced Binary Tree        Unbalanced Binary Tree
        1                               1       
      /  \                            /  \      
     2   3                           2   3     
    /                               /       
   4                               4        
                                   \          
                                   5         
*/

// #include <iostream>
// #include <cstdlib>
#include <bits/stdc++.h>
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

// TC = O(n)
bool isBalancedBTree(Node* root, int* height){
    if(root==NULL){
        *height=0;
        return true;
    }
    int ltHt = 0, rtHt = 0;
    if(isBalancedBTree(root->left, &ltHt)==false)
        return false;

    if(isBalancedBTree(root->right, &rtHt)==false)
        return false;

    *height=max(ltHt, rtHt)+1;
    
    if(abs(ltHt-rtHt)<=1)
        return true;
    else
        return false;
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    int height1=0;
    if(isBalancedBTree(root1, &height1))
        cout<<"It is a balanced Binary Tree\n";
    else
        cout<<"Not a balanced Binary Tree\n";


    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->left->left = new Node(5);
    int height2=0;
    if(isBalancedBTree(root2, &height2))
        cout<<"It is a balanced Binary Tree\n";
    else
        cout<<"Not a balanced Binary Tree\n";
    return 0;
}

// It is a balanced Binary Tree
// Not a balanced Binary Tree