/*Binary Search Tree
    Binary Search Tree is a node-based binary tree data structure which has the following properties:  
    #   The left subtree of a node contains only nodes with keys lesser than the node’s key.
    #   The right subtree of a node contains only nodes with keys greater than the node’s key.
    #   The left and right subtree each must also be a binary search tree. 
    #   There must be no duplicate nodes.

    *   Inorder sequence/traversal of a BST is always a sorted sequence of binary tree

The above properties of Binary Search Tree provides an ordering among keys so that the operations like search, minimum and maximum can be done fast. If there is no ordering, then we may have to compare every key to search for a given key.

                  8
                /  \
               3   10
              / \    \
             1  6    14
              /  \   /
             4   7  13


    STRATEGY
        Firstly searching for the key in the BST and then deleting it if it exists.
        For deletion we ha ve to handle the following 3 cases:
            1.  it is a leaf node - delete without any problem
            2.  it is a node with only one child - storing that node in temp
                                                   swapping that node with its child
                                                   deleing that node which was stored in temp
            3.  it is a node with both the child - 
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

Node* inorderSuccessor(Node* root){
    Node* curr = root;
    while(curr && curr->left!=NULL)
        curr = curr->left;

    return curr;
}

Node* deleteInBST(Node* root, int key){
    if(root==NULL)
        return NULL;

    if(key<root->data)
        root->left = deleteInBST(root->left, key);
    
    else if(key>root->data)
        root->right = deleteInBST(root->right, key);

    else{   //key==root->data
        if(root->left==NULL){   //for case 1 and 2
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){   //for case 1 and 2
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{    //for case 3
            Node* temp = inorderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteInBST(root->right, temp->data);
        }
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root==NULL)
        return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);
    
    int key = 6;
    inorderTraversal(root);
    cout<<"\n";
    
    if(deleteInBST(root, key))
        cout<<"Key Found in BST & deleted."<<endl;
    else
        cout<<"Key doesn't exist in BST."<<endl;
    
    inorderTraversal(root);
    cout<<"\n";
    return 0;
}
// 1 3 4 6 7 8 10 13 14 
// Key Found in BST & deleted.
// 1 3 4 7 8 10 13 14