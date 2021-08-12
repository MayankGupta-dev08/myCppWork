/*FIND MAXIMUM ELEMENT IN AN BITONIC ARRAY:
    Problem statement:
    Given a bitonic array (firstly strictly increasing till max element and than strictly decrasing. No duplicates present) find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.

    Example:
        Input:
        1 4 8 3 2
        Output:
        8
*/

#include <iostream>
using namespace std;

int maxElement_BitonicArray(int arr[], int n){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return arr[mid];

        if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])  //in increasing zone
            start = mid+1;

        if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])  //in decreasing zone
            end = mid-1;
    }
    return -1;
}

int main(){
    int arr1[] = {1, 4, 8, 3, 2};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Max element from bitonic array: "
        <<maxElement_BitonicArray(arr1,n)<<endl;

    int arr2[] = {6, 8, 20, 12, 11, 9, 7, 5, 0, -4};
    n = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Max element from bitonic array: "
        <<maxElement_BitonicArray(arr2,n)<<endl;
    return 0;
}

// Max element from bitonic array: 8
// Max element from bitonic array: 20