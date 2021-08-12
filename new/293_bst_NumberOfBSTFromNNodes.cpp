

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }

    for (int i=start; i<=end; i++){
        vector<Node*> leftSubtree = constructTrees(start, i-1);
        vector<Node*> rightSubtree = constructTrees(i+1, end);

        for (int j = 0; j < leftSubtree.size(); j++){
            Node* lft = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++){
                Node* rgt = rightSubtree[k];
                Node* node = new Node(i);
                node->left = lft;
                node->right = rgt;
                trees.push_back(node); 
            }
        }
    }
    return trees;
}

void preorder(Node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n =3;
    vector<Node*> totalTrees = constructTrees(1, n);
    for (int i = 0; i < totalTrees.size(); i++){
        cout<<i+1<<" : "; 
        preorder(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}

// 1 : 1 2 3
// 2 : 1 3 2
// 3 : 2 1 3
// 4 : 3 1 2
// 5 : 3 2 1