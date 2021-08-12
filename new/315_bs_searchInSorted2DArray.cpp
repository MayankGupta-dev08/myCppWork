/*SEARCH IN A ROW WISE AND COLUMN WISE SORTED MATRIX:

Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.
Example :

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50} };
              x = 29
Output : Found at (2, 1)

Strategy - we will start from the top right element and then move in array
*/

#include <iostream>
#include <utility>
using namespace std;

pair<int, int> binarySearch2DMatrix(int arr[4][4], int m, int n, int key){
    int i=0, j=n-1;
    while(i>=0 && i<m && j>=0 && j<n){
        if(arr[i][j]==key)
            return {i,j};

        if(arr[i][j]>key)
            j--;

        else if(arr[i][j]<key)
            i++;
    }
    return {-1, -1};
}

int main(){
    const int m=4, n=4;
    int arr[m][n] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50} };
    int key = 29;
    pair<int, int> ans = binarySearch2DMatrix(arr, m, n, key);
    cout<<key<<" is at index: {"<<ans.first<<", "<<ans.second<<"}\n";

    key = 23;
    ans = binarySearch2DMatrix(arr, m, n, key);
    cout<<key<<" is at index: {"<<ans.first<<", "<<ans.second<<"}\n";
    return 0;
}