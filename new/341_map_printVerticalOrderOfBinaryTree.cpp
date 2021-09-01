/*Print the Vertical order of a binary tree
    Given an array whose elements are in a sequence of a levelorder array. Build a binary tree from the levelorder array, and then print it vertically. The following example illustrates the vertical order traversal.
    https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/

    levelorder array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

           1
        /    \ 
       2      3
      / \   /   \
     4   5  6   7
               /  \ 
              8   9 
               
              
    The output of print this tree vertically will be:
    4
    2
    1 5 6
    3 8
    7
    9

    Strategy -
        approach for building the tree - for i=0 to i=n-1
            left child is at index = 2*i +1     , given (2*i +1)<n ;
            right child is at index = 2*i +2     , given (2*i +2)<n;
        after building the tree we will recusively define the value of horizontal distance of each node from root node (whose horiz dis = 0) and store it iin a map<int, vector<int>> (ordered) which will than store it in increasing order of the hdis and than we will print the elements.
        1.  starting from the root node
        2.  recursively call the left and the right  with (hdis-1) and (hdis+1) resp. as arguments.
            keeping the base case as if (node==null) return;
        3.  Push the value into vector and corresponding to the horizontal distance
        4.  output the map
*/

#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// recursive function to build a binary tree from a levelorder array
Node* build_BT_fromLevelorderArray(int levelOrder[], int n, int i){
    if(i>=n || i<0)
        return NULL;

    Node* root = new Node(levelOrder[i]);
    int lft = 2*i +1;
    int rgt = 2*i +2;
    root->left = build_BT_fromLevelorderArray(levelOrder, n, lft);
    root->right = build_BT_fromLevelorderArray(levelOrder, n, rgt);

    return root;
}

void printPreorderTraversal(Node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    printPreorderTraversal(root->left);
    printPreorderTraversal(root->right);
}

void getVerticalOrder(Node* root, int hdis, map<int, vector<int>> &mp){
    if(root==NULL)
        return;

    mp[hdis].push_back(root->data);

    getVerticalOrder(root->left, hdis-1, mp);
    getVerticalOrder(root->right, hdis+1, mp);
}

void printVerticalOrder(map<int, vector<int>> mp){
    cout<<"Vertical order for the given binary tree"<<endl;
    map<int, vector<int>> :: iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        for(int i=0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}

int main(){
    int lvlorder[] = {10, 7, 4, 3, 11, 14, 6};
    int n=sizeof(lvlorder)/sizeof(lvlorder[0]);
    /*
                        10
                      /    \
                     7      4
                  /    \  /   \
                 3    11 14    6
    */
    Node* root1 = build_BT_fromLevelorderArray(lvlorder, n, 0);
    // printPreorderTraversal(root1);  //10 7 3 11 4 14 6

    map<int, vector<int>> mp;
    int hdis = 0;
    getVerticalOrder(root1, hdis, mp);
    printVerticalOrder(mp);
    return 0;
}

// Vertical order for the given binary tree
// 3
// 7
// 10 11 14
// 4
// 6