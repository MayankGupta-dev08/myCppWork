/*Next Permutation
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
    If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
    The replacement must be in place and use only constant extra memory.

        Example 1:
            Input: nums = [1,2,3]
            Output: [1,3,2]

        Example 2:
            Input: nums = [3,2,1]
            Output: [1,2,3]
            
        Example 3:
            Input: nums = [1,1,5]
            Output: [1,5,1]

        Example 4:
            Input: nums = [1]
            Output: [1]
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void swapp(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse_arr(int arr[], int i, int j){
    while(i<j){
        swapp(arr, i, j);
        i++, j--;
    }
}

void nextPermutation(int arr[], int n){
    if(n<=1)
        return;

    int idx1, idx2;
    for (idx1 = n - 2; idx1 >= 0; idx1--){
        if(arr[idx1]<arr[idx1+1])
            break;
    }
    if(idx1<0){
        reverse_arr(arr, 0, n-1);
        return;
    }
    else{
        for (idx2 = n - 1; idx2>idx1; idx2--){
            if(arr[idx2]>arr[idx1])
                break;
        }
        swapp(arr, idx1, idx2);
        reverse_arr(arr, idx1+1, n-1);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {1, 3, 5, 4, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    nextPermutation(arr, n);
    printArray(arr, n);

    cout<<"-----------------\n";

    int arr2[] = {3, 2, 1};
    n=sizeof(arr2)/sizeof(arr2[0]);
    printArray(arr2, n);
    nextPermutation(arr2, n);
    printArray(arr2, n); 
    return 0;
}

// 1 3 5 4 2 
// 1 4 2 3 5
// -----------------
// 3 2 1 
// 1 2 3