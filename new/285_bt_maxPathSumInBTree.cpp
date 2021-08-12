/*MAXIMUM PATH SUM
    Maximum possible sum of a path in the binary tree starting and ending at any node, but it should be always continuous.
    Path may or may not go through root.
    It should have at least one node.

            1
          /  \
        -12  3
        /  /  \
       4  5   -6

    In the above binary tree maximum path sum = 9
        1->3->5

    STRATEGY
        Recurrsively for each node we will compute:
            1.  Node val
            2.  Max path through left child + node val
            3.  Max path through right child + node val
            4.  Max path thhrough left child + Max path throughh right child + node val

        Using recurrsion frame we will firstly check for left and right subtrees and then for current node.
        So by this we will check for the last node firstly.
        
        We have 3 Cases:
            1.  Max straight path sum: when the current node is in the path of maxSumPath
            2.  when the current node is the root of the max sum path
            3.  when the current node is not in the max sum path
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

int maxPathSumUtil(Node* root, int &ans){
    if(root==NULL)
        return 0;

    int lft = maxPathSumUtil(root->left, ans);
    int rgt = maxPathSumUtil(root->right, ans);

    //maxStraightPath - case1 - only case which will include ancesstors of current node
    int case1 = max(root->data, max(lft, rgt)+root->data);  
    int case2 = max(case1, lft+root->data+rgt);
    ans = max(ans, case2);  //case3

    return case1;
}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(-12);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    int mps = maxPathSum(root); //9
    cout<<mps<<endl;
    return 0;
}