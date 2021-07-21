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

int calcHeight(Node* root){
    if(root==NULL)
        return 0;
    
    return max(calcHeight(root->left), calcHeight(root->right))+1;
}

// TC = O(n)
bool isBalancedBTree(Node* root){
    if(root==NULL)
        return true;

    if(isBalancedBTree(root->left)==false)
        return false;

    if(isBalancedBTree(root->right)==false)
        return false;
    
    int ltHt = calcHeight(root->left);
    int rtHt = calcHeight(root->right);
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
    if(isBalancedBTree(root1))
        cout<<"It is a balanced Binary Tree\n";
    else
        cout<<"Not a balanced Binary Tree\n";


    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->left->left = new Node(5);
    if(isBalancedBTree(root2))
        cout<<"It is a balanced Binary Tree\n";
    else
        cout<<"Not a balanced Binary Tree\n";
    return 0;
}

// It is a balanced Binary Tree
// Not a balanced Binary Tree