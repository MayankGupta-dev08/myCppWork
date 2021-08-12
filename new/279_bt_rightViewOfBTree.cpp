/*Print Right View of a Binary Tree
Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side. 

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
                  \
                   8

Right view of following tree is 1 3 7 8
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

// using level order traversal
void rightViewOfBT(Node* root){
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        for (int i = 0; i < n; i++){
            Node* node = q.front();
            q.pop();
            if(i==n-1)
                cout<<node->data<<" ";
            
            if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
        }
        
    }

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);

    // printing the right view of binary tree
    rightViewOfBT(root);    //1 3 7 8
    cout<<"\n";
    return 0;
}