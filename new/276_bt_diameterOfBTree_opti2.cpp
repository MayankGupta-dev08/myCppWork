/*Diameter of a Binary Tree - The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.

The diameter of a tree T is the largest of the following quantities:
    the diameter of T’s left subtree.
    the diameter of T’s right subtree.
    the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

Diameter thru root node      Diameter not thru root node 
        1                               1                     
      /  \                             / \  
     2    3                           2  3
    /\    \                          /\ 
   4 5    7                         4 5  
          \                        /  \           
          8                       6   7
                                 /    \
                                8     9
Diameter = 6                    Diameter = 7

// Here we will use the optimised approach for calc the dia
    // For traversing each node in bt for diameter and height simultaneously - O(n)
*/


#include <iostream>
#include <utility>
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

// Optimised approach  = O(n)
// pair<dia,ht>
pair<int, int> calcDiameterHeight(Node* root){
    if(root==NULL){
        return {0,0};
    }
    pair<int,int> ltSubtree = calcDiameterHeight(root->left);
    pair<int,int> rtSubtree = calcDiameterHeight(root->right);

    int currNodeHt = max(ltSubtree.second, rtSubtree.second)+1;
    int currNodeDia = ltSubtree.second + rtSubtree.second +1;
    int ltSubtreeDia = ltSubtree.first;
    int rtSubtreeDia = rtSubtree.first;

    return {max(currNodeDia, max(ltSubtreeDia, rtSubtreeDia)), currNodeHt};
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(7);
    root1->right->right->right = new Node(8);
    cout<<"Diameter of Binary tree1: "<<calcDiameterHeight(root1).first<<endl;  //6
    cout<<"Height of Binary tree1: "<<calcDiameterHeight(root1).second<<endl;  //4

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->left->left->left = new Node(6);
    root2->left->right->right = new Node(7);
    root2->left->left->left->left = new Node(8);
    root2->left->right->right->right = new Node(9);
    cout<<"Diameter of Binary tree2: "<<calcDiameterHeight(root2).first<<endl;  //6
    cout<<"Height of Binary tree2: "<<calcDiameterHeight(root2).second<<endl;  //5
    return 0;
}