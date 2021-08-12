/*Lowest Common Ancestor in a Binary Search Tree.
    Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). You may assume that both the values exist in the tree

        20
       / \
      8  22
    /  \
   4   12
      / \
    10  14

Input: LCA of 10 and 14
Output:  12
Explanation: 12 is the closest node to both 10 and 14 
which is a ancestor of both the nodes.

Input: LCA of 8 and 14
Output:  8
Explanation: 8 is the closest node to both 8 and 14 
which is a ancestor of both the nodes.

Input: LCA of 10 and 22
Output:  20
Explanation: 20 is the closest node to both 10 and 22 
which is a ancestor of both the nodes.
*/

#include <iostream>
#include <vector>
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

bool getPath(Node* root, int key, vector<int> &path){
    if(root==NULL)
        return false;
    
    path.push_back(root->data);
    if(root->data == key)
        return true;
    
    if(getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;
    
    if(!getPath(root, n1, path1) || !getPath(root, n2, path2))
        return -1;

    int pC;   //pathChange
    for (pC = 0; pC<path1.size() && pC<path2.size(); pC++){
        if(path1[pC]!=path2[pC])
            break;
    }
    return path1[pC-1];
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int n1=10, n2=14;
    int lca=LCA(root, n1, n2);
    if(lca==-1)
        cout<<"LCA doesn't exist.\n";
    else
        cout<<"LCA: "<<lca<<endl;

    n1=8, n2=14;
    lca=LCA(root, n1, n2);
    if(lca==-1)
        cout<<"LCA doesn't exist.\n";
    else
        cout<<"LCA: "<<lca<<endl;

    n1=10, n2=22;
    lca=LCA(root, n1, n2);
    if(lca==-1)
        cout<<"LCA doesn't exist.\n";
    else
        cout<<"LCA: "<<lca<<endl;
    return 0;
}