/*Convert a given tree to its Sum Tree
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the itself, left and right sub trees in the original tree. The values of leaf nodes are not changed at all.
For example, the following tree  

                  10
               /      \
             -2        6
           /   \      /  \ 
         8     -4    7    5

should be changed to 

               30(10+18+2)
               /      \
         2(-2+8-4)    18(6+7+5)
           /   \      /  \ 
          8   -4     7   5
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

void sumReplacement(Node* root){
    if(root==NULL)
        return;

    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left!=NULL)
        root->data += root->left->data;

    if(root->right!=NULL)
        root->data += root->right->data;
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
    levelOrderTraversal(root);  //30 2 18 8 -4 7 5
    cout<<"\n";
    return 0;
}