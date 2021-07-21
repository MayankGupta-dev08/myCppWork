/*Convert a given tree to its Sum Tree
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.
For example, the following tree 
 
                  10
               /      \
             -2        6
           /   \      /  \ 
         8     -4    7    5

should be changed to 

                 20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \ 
         0      0    0    0
*/

#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node* root){
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(node==NULL && !q.empty())
            q.push(NULL);
    }
}

int sumReplacement(Node* root){
    if(root == NULL)
        return 0;

    int old_val = root->data;

    // For changing curr node value
    root->data = sumReplacement(root->left) + sumReplacement(root->right);
    
    // For sending old and changed value
    return root->data + old_val;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    levelOrderTraversal(root);  //10 -2 6 8 4 7 5
    cout<<"\n";

    sumReplacement(root);
    levelOrderTraversal(root);  //20 4 12 0 0 0 0
    cout<<"\n";
    return 0;
}