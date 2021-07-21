/*  building a binary tree using preorder array and inorder array
        1
      /  \    
    /     \
   2      3             
 /  \   /  \
4   5  6   7

ALGORITHM
    1.  Pick an element from preorder array [0,n) and create a node
        //starting from 0, since in prorder the root is at 0 in preorder array
    2.  increment preorder idx
    3.  search for the picked eleement's pos inorder array and store it in pos
    4.  call to build the left subtree from inorder's 0 to pos-1
    5.  call to build the right subtree from inorder's pos+1 to n
    6.  return to node
*/

#include <iostream>
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

int search(int inorder[], int start, int end, int curr){
    for (int i = start; i <=end; i++){
        if(curr==inorder[i])
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx=0;   //static variable for traversing preorder
    if(start>end)       //base condition
        return NULL;

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if(start==end)      //only one element remaining in inorder array
        return node;
    
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);

    return node;
}

void printTree_inorder(Node* root){
    if(root==NULL)
        return;

    printTree_inorder(root->left);
    cout<<root->data<<" ";
    printTree_inorder(root->right);    
}

int main(){
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[]  = {4,2,5,1,6,3,7};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    Node* root = buildTree(preorder, inorder, 0, n-1);
    printTree_inorder(root);    //4 2 5 1 6 3 7
    delete root;
    return 0;
}    