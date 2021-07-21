/*  building a binary tree using postorder array and inorder array
        1
      /  \    
    /     \
   2      3             
 /  \   /  \
4   5  6   7

ALGORITHM
    1.  Pick an element from postorder array [n-1,0] and create a node
        //starting from n-1, since in postrder the root is at n-1 in postorder array    
    2.  decrement postorder idx
    3.  search for the picked eleement's pos inorder array and store it in pos
    4.  call to build the right subtree from inorder's pos+1 to n
    5.  call to build the left subtree from inorder's 0 to pos-1
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

Node* buildTree(int postorder[], int inorder[], int start, int end){
    static int idx=end;   //static variable for traversing postorder
    if(start>end)       //base condition
        return NULL;

    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);
    if(start==end)      //only one element remaining in inorder array
        return node;
    
    int pos = search(inorder, start, end, curr);
    node->right = buildTree(postorder, inorder, pos+1, end);
    node->left = buildTree(postorder, inorder, start, pos-1);

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
    int postorder[] = {4,5,2,6,7,3,1};
    int inorder[]  = {4,2,5,1,6,3,7};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    // build tree
    Node* root = buildTree(postorder, inorder, 0, n-1);
    // print tree
    printTree_inorder(root);    //4 2 5 1 6 3 7
    delete root;
    return 0;
}

// FOLLOW UP QUESTION-
    // Can we construct a tree using preorder and postorder
        //No, because there are more than one possible solutions for an incomplete tree
        // But if a binary tree is complete than yes, we can do 