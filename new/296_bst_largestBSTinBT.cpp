/*Largest BST in a Binary Tree
    Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of the whole tree.

Examples:  
    Input: 
              5
            /  \
           2    4
         /  \
        1    3

    Output: 3 
    The following subtree is the maximum size BST subtree 
           2  
         /  \
        1    3


    Input: 
           50
         /    \
      30       60
     /  \     /  \ 
    5   20   45    70
                  /  \
                65    80

    Output: 5
    The following subtree is the maximum size BST subtree 
          60
         /  \ 
       45    70
            /  \
          65    80
*/

#include <iostream>
#include <climits>
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

struct Info{
    int sze;
    int mn;
    int mx;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root){
    // base case
    if(root==NULL)
        return {0, INT_MAX, INT_MIN, 0, true};

    // leaf node
    if(root->left==NULL && root->right==NULL)
        return {1, root->data, root->data, 1, true};

    // for node with child(s)
    Info leftSubtree = largestBSTinBT(root->left);
    Info rightSubtree = largestBSTinBT(root->right);
    
    Info curr;
    curr.sze = leftSubtree.sze + rightSubtree.sze +1;
    if(leftSubtree.isBST && rightSubtree.isBST && leftSubtree.mx < root->data && rightSubtree.mn > root->data){
        curr.mn = min(root->data, min(leftSubtree.mn, rightSubtree.mn));
        curr.mx = max(root->data, max(leftSubtree.mx, rightSubtree.mx));
        curr.ans = curr.sze;
        curr.isBST = true;
    }
    else{
        curr.ans = max(leftSubtree.ans, rightSubtree.ans);
        curr.isBST = false;
    }
    
    return curr;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Info tree = largestBSTinBT(root);
    cout<<"largest BST ans: "<<tree.ans<<endl;
    return 0;
}