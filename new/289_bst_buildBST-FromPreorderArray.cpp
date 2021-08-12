/*Construct BST from given preorder traversal
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be the root of the following tree.

                 10
               /   \
              5    40
             / \    \
            1  7    50

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

Node* buildBST_preorder(int preorder[], int n, int* preorderIdx, int key, int min, int max){
    if(*preorderIdx>=n)
        return NULL;
    
    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        *preorderIdx = *preorderIdx +1;

        if(*preorderIdx<n){
            root->left = buildBST_preorder(preorder, n, preorderIdx, preorder[*preorderIdx], min, key);
        }

        if(*preorderIdx<n){
            root->right = buildBST_preorder(preorder, n, preorderIdx, preorder[*preorderIdx], key, max);
        }
    }
    return root;
}

void preorderTraversal(Node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int n=sizeof(preorder)/sizeof(preorder[0]);
    int preorderIdx = 0;
    
    Node* root = buildBST_preorder(preorder, n, &preorderIdx, 10, INT_MIN, INT_MAX);
    preorderTraversal(root);    //10 5 1 7 40 50
    cout<<endl;
    return 0;
}