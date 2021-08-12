/*FIND AN ELEMENT IN BITONIC ARRAY:
    Given a bitonic sequence of n distinct elements, write a program to find a given element x in the bitonic sequence in O(log n) time. A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

    Examples:

    Input :  arr[] = {-3, 9, 8, 20, 17, 5, 1};
            key = 20
    Output : Found at index 3
*/

#include <iostream>
using namespace std;

int bitonicPoint(int arr[], int n){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;

        if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])  //in increasing zone
            start = mid+1;

        if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])  //in decreasing zone
            end = mid-1;
    }
    return -1;
}

int binarySearch_ascSortedArr(int arr[], int start, int end, int key){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }
        else
            end = mid-1;
    }
    return -1;
}

int binarySearch_descSortedArr(int arr[], int start, int end, int key){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return -1;
}

int searchKey_BitonicArray(int arr[], int n, int key){
    int bitonicPt = bitonicPoint(arr, n);
    if(bitonicPt==-1)
        return -1;

    return max(binarySearch_ascSortedArr(arr, 0, bitonicPt, key),
                binarySearch_descSortedArr(arr, bitonicPt+1, n-1, key));
}

int main(){
    int arr1[] = {-3, 9, 18, 20, 17, 5, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int key = 20;
    int ans = searchKey_BitonicArray(arr1, n, key);
    if(ans!=-1)
        cout<<key<<" in bitonic array found at index: "<<ans<<endl;
    else
        cout<<key<<" not present in bitonic array.\n";

    int arr2[] = {5, 6, 7, 8, 9, 10, 3, 2, 1};
    n = sizeof(arr2)/sizeof(arr2[0]);
    key = 30;
    ans = searchKey_BitonicArray(arr2, n, key);
    if(ans!=-1)
        cout<<key<<" in bitonic array found at index: "<<ans<<endl;
    else
        cout<<key<<" not present in bitonic array.\n";
    
    return 0;
}