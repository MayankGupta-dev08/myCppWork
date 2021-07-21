/*  printing Sum of all nodes in a binary tree
        1                level 0    //1
      /  \                   
     2    3              level 1    //2 3  
    /\   /\              
   4 5  6 7              level 2    //4 5 6 7

Sum of all nodes in binary tree = 28
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

int sumOfAllNodes(Node* node){
    if(node==NULL)
        return 0;

    return ( node->data+sumOfAllNodes(node->left)+sumOfAllNodes(node->right) );
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Sum of all nodes in binary tree: "<<sumOfAllNodes(root)<<endl;   //28
    delete root;
    return 0;
}