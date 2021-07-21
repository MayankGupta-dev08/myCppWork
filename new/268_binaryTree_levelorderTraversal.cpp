/*  printing level order traversal for the below binary tree
        1                level 0    //1
      /  \                   
     2    3              level 1    //2 3  
   / \   / \
  4  5  6  7             level 2    //4 5 6 7

level order traversal = [1,2,3,4,5,6,7]
*/

#include <iostream>
#include <queue>
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

void levelorder(Node* root){
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

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelorder(root);  //1 2 3 4 5 6 7
    return 0;
}    