/*IMPORTANT

Print all nodes at distance k from a given node
    Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available.

    Examples:  
                  1
                /  \
               5   2
              /   / \
             6   3  4
             \
             7
            / \
           8  9
        
        Input : 
            Target Node=5, k=3
        Output : 
            8,9,3,4
*/

#include <iostream>
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

void printNodesKDistDown(Node* root, int k){
    if(root==NULL || k<0)
        return;
    
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    // Recurr for left and right subtrees
    printNodesKDistDown(root->left, k-1);
    printNodesKDistDown(root->right, k-1);
}

// Prints all nodes at a distance k from the given target node
// the nodes at k dist can be upward or downward
// this function returns ther distance of a root from a target node
int printNodesAtKDistance(Node* root, Node* target, int k){
    if(root==NULL)
        return -1;      //if target node is not found we will send an invalid dist

    if(root==target){
        printNodesKDistDown(target, k);
        return 0;   // returning dist 0 to ancesstor as we have found the target
    }
    
    // firstly checking the target node in the left subtree
    int dl = printNodesAtKDistance(root->left, target, k);
    if(dl!=-1){ 
        //we have found our target somewhere in left subtree
        if(dl+1==k)
            cout<<root->data<<" ";
        else
            // since the right child is two edges away from the left child
            printNodesKDistDown(root->right, k-dl-2);
        
        return dl+1;
    }

    // for checking the target node in the right subtree only if it is not found in left subtree
    // similar to the code for left subtree
    int dr = printNodesAtKDistance(root->right, target, k);
    if(dr!=-1){ 
        //we have found our target somewhere in left subtree
        if(dr+1==k)
            cout<<root->data<<" ";
        else
            printNodesKDistDown(root->left, k-dr-2);
        
        return dr+1;
    }
    return -1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(2);
    root->left->left = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(8);
    root->left->left->right->right = new Node(9);

    Node* target = root->left;
    int k=3;
    printNodesAtKDistance(root, target, k);
    return 0;
}