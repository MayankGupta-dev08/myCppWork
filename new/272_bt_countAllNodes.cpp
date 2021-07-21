/*  printing the count of all nodes in binary tree
        5                level 0    //5
      /  \                   
     6    3              level 1    //6 3  
   / \   / \
  9  1  2  1             level 2    //9 1 2 1
    /   \
   2    6                level 3    //2 6
 / \     \
3  5     7               level 4    //3 5 7

count of all nodes in binary tree = 12
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int countNodes(Node* node){
    if(node==NULL)
        return 0;
    return ( countNodes(node->left)+countNodes(node->right)+1 );
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(1);
    root->left->right->left = new Node(2);
    root->right->left->right = new Node(6);
    root->left->right->left->left = new Node(3);
    root->left->right->left->right = new Node(5);
    root->right->left->right->right = new Node(7);

    cout<<"Count of all nodes in this binary tree: "<<countNodes(root)<<endl;
    return 0;
}