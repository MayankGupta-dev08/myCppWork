/*  printing preorder traversal for the below binary tree
        5                level 0    //5
      /  \                   
     6    3              level 1    //6 3  
   / \   / \
  9  1  2  1             level 2    //9 1 2 1
    /   \
   2    6                level 3    //2 6
 / \     \
3  5     7               level 4    //3 5 7

level order traversal = [5,6,3,9,1,2,1,2,6,3,5,7]
Sum at kth level (k=3) = 2+6 = 8
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

// using level order traversal
int sumAtKthLevel(Node* root, int k){
    if(root==NULL)
        return -1;
    
    int level=0, sum=0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(node==NULL && !q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
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

    int k=3;
    cout<<"Sum of nodes at level "<<k<<": "<<sumAtKthLevel(root,k)<<endl;   //8
    k=2;
    cout<<"Sum of nodes at level "<<k<<": "<<sumAtKthLevel(root,k)<<endl;   //13
    return 0;
}    