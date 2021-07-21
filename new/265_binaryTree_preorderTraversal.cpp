/*  printing preorder traversal for the below binary tree
        1               
      /  \                  root
    /     \             left subtree
   2      3             right subtree
 /  \   /  \             
4   5  6   7             
preorder traversal = [1,2,4,5,3,6,7]
*/

#include <iostream>
using namespace std;

struct Node{
    
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(Node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder(root); //1 2 4 5 3 6 7
    return 0;
}    