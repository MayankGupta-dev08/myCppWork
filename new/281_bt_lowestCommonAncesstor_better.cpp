/*Lowest Common Ancestor in a Binary Search Tree.
    Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). You may assume that both the values exist in the tree

            20
           / \
          8  22
        /  \
       4   12
      /   / \
    15  10  14

Input: LCA of 10 and 14
Output:  12
Explanation: 12 is the closest node to both 10 and 14 
which is a ancestor of both the nodes.

Input: LCA of 8 and 14
Output:  8
Explanation: 8 is the closest node to both 8 and 14 
which is a ancestor of both the nodes.

Input: LCA of 10 and 22
Output:  20
Explanation: 20 is the closest node to both 10 and 22 
which is a ancestor of both the nodes.
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

// This function assumes that n1 and n2 are present in Binary Tree
Node* LCA(Node* root, int n1, int n2){
    if (root==NULL)
        return NULL;

    // Note that if a key is ancestor of other, then the ancestor key becomes LCA
    if (root->data==n1 || root->data==n2)
        return root;
    
    Node* leftLCA = LCA(root->left, n1, n2);    
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA!=NULL && rightLCA!=NULL)
        return root;
    
    if(leftLCA==NULL)
        return rightLCA;
    else
        return leftLCA;
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->left->left = new Node(15);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int n1=10, n2=14;
    Node* lca=LCA(root, n1, n2);
    if(lca==NULL)
        cout<<"LCA doesn't exist.\n";
    else
        cout<<"LCA: "<<lca->data<<endl; //12

    n1=15, n2=14;
    lca=LCA(root, n1, n2);
    if(lca==NULL)
        cout<<"LCA doesn't exist.\n";
    else
        cout<<"LCA: "<<lca->data<<endl; //8

    n1=8, n2=14;
    lca=LCA(root, n1, n2);
    if(lca==NULL)
        cout<<"LCA doesn't exist.\n";
    else
        cout<<"LCA: "<<lca->data<<endl; //8

    n1=10, n2=22;
    lca=LCA(root, n1, n2);
    if(lca==NULL)
        cout<<"LCA doesn't exist.\n";
    else
        cout<<"LCA: "<<lca->data<<endl; //20
    return 0;
}