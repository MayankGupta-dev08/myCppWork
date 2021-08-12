/*Find distance between two nodes of a Binary Tree
    The distance between two nodes in a Binary Tree is the minimum number of edges to be traversed to reach one node from another.

                1
              /  \
             2   3
           / \  / \
          4  5 6  7
              /
             8

    Strategy
        1.  Find the LCA for n1 and n2
        2.  Find the finddist of n1 (d1) and n2 (d2) from LCA.
        3.  return d1+d2
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

Node* LCA(Node* root, int n1, int n2){
    if(root==NULL)
        return NULL;

    if(root->data==n1 || root->data==n2)
        return root;

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA && rightLCA)
        return root;

    if(leftLCA==NULL)
        return rightLCA;
    else
        return leftLCA;
}

int findDist(Node* root, int key, int dist){
    if(root==NULL)
        return -1;
    
    if(root->data==key)
        return dist;
    
    int left=findDist(root->left, key, dist+1);
    if(left!=-1)
        return left;
    return findDist(root->right, key, dist+1);
}

int findDistance(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);
    
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    
    return d1+d2;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    cout<<"Dist(4, 5) = "<<findDistance(root, 4, 5)<<"\n";  //2
    cout<<"Dist(4, 6) = "<<findDistance(root, 4, 6)<<"\n";  //4
    cout<<"Dist(3, 4) = "<<findDistance(root, 3, 4)<<"\n";  //3
    cout<<"Dist(2, 4) = "<<findDistance(root, 2, 4)<<"\n";  //1
    cout<<"Dist(8, 5) = "<<findDistance(root, 8, 5)<<"\n";  //5
    return 0;
}