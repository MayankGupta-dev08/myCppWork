/*Merge k sorted arrays
    Given k sorted arrays of size n each, merge them and print the sorted output.
    Input: k = 3, n = 4 
        arr[][] = { {1, 3, 5, 7}, 
        {2, 4, 6, 8}, 
        {0, 9, 10, 11}} ;
    Output: 0 1 2 3 4 5 6 7 8 9 10 11 
    
    Approach1: The very naive method is to create an output array of size n * k and then copy all the elements into the output array followed by sorting. 
        Time complexity = O(mlogm), m=n*k as, n->number of elements in each array and k arrays
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define n 4

// Approach1 - simplest, time complexity = O(n*k*log(n*k))
// space complexity = O(n*k)
void mergeKSortedArrays_simplest(int arr[][n], int k, int res[]){
    int i=0;
    for(int r=0; r<k; r++){
        for(int c=0; c<n; c++)\
            res[i++] = arr[r][c];
    }

    sort(res, res+(n*k));
}

void printArray(int a[], int sz){
    for (int i = 0; i < sz; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int k=3; // n=4 and k=3 --> 3 arrays of size 4 each
    int arr[k][n] = {{2, 6, 12, 19},
                     {1, 9, 20, 95},
                     {23, 5, 27, 8}};

    int res[n*k];
    cout<<"Merged array:-\n";
    mergeKSortedArrays_simplest(arr, k, res);
    printArray(res, n*k);
    return 0;
}

// 1 2 5 6 8 9 12 19 20 23 27 95 