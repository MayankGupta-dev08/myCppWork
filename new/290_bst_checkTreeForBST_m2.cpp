/*A program to check if a binary tree is BST or not

A binary search tree (BST) is a node based binary tree data structure which has the following properties. 
    •   The left subtree of a node contains only nodes with keys less than the node’s key. 
    •   The right subtree of a node contains only nodes with keys greater than the node’s key. 
    •   Both the left and right subtrees must also be binary search trees.
    From the above properties it naturally follows that: 
    •   Each node (item in the tree) has a distinct key.

            4
          /  \
         2   5
       /  \
      1   3

Method 1 above runs slowly since it traverses over some parts of the tree many times. A better solution looks at each node only once. The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there. 

Note: This method is not applicable if there are duplicate elements with value INT_MIN or INT_MAX.
*/

#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// METHOD 2 (Correct and Efficient)
bool checkForBST(Node* root, Node* mn, Node* mx){
    if(root==NULL)
        return true;

    if(mn!=NULL && root->data <= mn->data)
        return false;
    
    if(mx!=NULL && root->data >= mx->data)
        return false;

    if(!checkForBST(root->left, mn, root) || !checkForBST(root->right, root, mx))
        return false;

    return true;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    if(checkForBST(root, NULL, NULL))   // Valid BST!
        cout<<"Valid BST!"<<endl;
    else
        cout<<"Invalid BST!"<<endl;

    
    Node* root2 = new Node(3);
    root2->left = new Node(2);
    root2->right = new Node(5);
    root2->left->left = new Node(1);
    root2->left->right = new Node(4);
    if(checkForBST(root2, NULL, NULL))  // Invalid BST!
        cout<<"Valid BST!"<<endl;
    else
        cout<<"Invalid BST!"<<endl;
    return 0;
}
