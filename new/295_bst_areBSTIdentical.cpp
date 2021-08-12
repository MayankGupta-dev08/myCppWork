/*Are the given two BSTs identical?
    For given root nodes of two binary search trees , print if the BSTs are identical or not.
    Identical BSTs are structually identical and have equal values for the nodes in the structure.

    Strategy:
        1.  if both the BSTs are empty return true
        2.  if both non empty
                check that the data at nodes are equal
                check that the left subtrees are equal
                check that the right subtrees are equal
*/

#include <iostream>
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

bool areBSTsIdentical(Node* root1, Node* root2){
    if (root1==NULL && root2==NULL)
        return true;
    
    // if either of them is null but, not both are not same
    if (root1==NULL || root2==NULL)
        return false;
    
    else{
        if(root1->data!=root2->data)
            return false;

        if(!areBSTsIdentical(root1->left, root2->left))
            return false;

        if(!areBSTsIdentical(root1->right, root2->right))
            return false;
    }
    return true;
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2); 
    root1->right = new Node(3); 
    root1->left->right = new Node(4); 
    root1->right->right = new Node(5); 
 
    Node* root2 = new Node(8);
    root2->left = new Node(2); 
    root2->right = new Node(3); 
    root2->left->right = new Node(4); 
    root2->right->right = new Node(5); 
    
    if(areBSTsIdentical(root1, root1))  //BSTs are identical
        cout<<"BSTs are identical\n";
    else
        cout<<"BSTs aren't identical\n";
    
    if(areBSTsIdentical(root1, root2))  //BSTs aren't identical
        cout<<"BSTs are identical\n";
    else
        cout<<"BSTs aren't identical\n";
    
    return 0;
}