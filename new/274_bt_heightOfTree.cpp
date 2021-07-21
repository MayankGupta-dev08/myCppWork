/* Write a Program to Find the Maximum Depth or Height of a Tree 
        1                level 0    //1
      /  \                   
     2    3              level 1    //2 3  
    /\   /\              
   4 5  6 7              level 2    //4 5 6 7
          \
          8
height of the above binary tree = 4
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

// Since we are going on each node once - TC = O(n)
    // n - total number of nodes
int heightOfTree(Node* node){
    if(node==NULL)
        return 0;

    //+1 for taking current node into consideration also
    return (max(heightOfTree(node->left), heightOfTree(node->right)) + 1);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);

    cout<<"Height of binary tree: "<<heightOfTree(root)<<endl;   //4
    delete root;
    return 0;
}