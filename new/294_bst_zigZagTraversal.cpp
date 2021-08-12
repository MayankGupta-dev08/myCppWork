/*Zig Zag Traversal of BST
            1
          /  \
         2   3
         \   \
         4   5
       /  \
      6   7

level order = [1,2,3,4,5,6,7]
zigzag order = [1,3,2,4,5,7,6]
*/

#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data=val;
        left = NULL;
        right = NULL;
    }
};

void zigZagTraversal(Node* root){
    if(root==NULL)
        return;
    
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;
    
    currLevel.push(root);
    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            else{
                if(temp->right)
                    nextLevel.push(temp->right);
                if(temp->left)
                    nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->right = new Node(4); 
    root->right->right = new Node(5); 
    root->left->right->left = new Node(6); 
    root->left->right->right = new Node(7);

    zigZagTraversal(root);  //1 3 2 4 5 7 6 
    cout<<endl;
    return 0;
}