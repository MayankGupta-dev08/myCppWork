// binary tree is composed of branch, node, and leaf.
    // end node is known as leaf (can be one or more)
    // start node is known as root (only one in a tree)
    // only two child nodes at max for a node

// properties of binary trees
    // 1.   maximum nodes at a level L [0,n] = 2^L
    // 2.   maximum nodes in a tree of height H [1,n] = 2^H - 1
    // 3.   For N nodes, minimum possible height or minimum numbers of levels = log2(N+1)
    // 4.   A Binary tree with L leaves has at least log2(N+1)+1 numbers of levels

//#include <bits/stdc++.h>
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

/*
        1
      /  \
    /     \
   2      3
 /  \   /  \
4   5  6   7
*/

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return 0;
}    