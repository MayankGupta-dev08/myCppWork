/*Question related to  binary search - Find the Rotation Count in Rotated Sorted array
    Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.
    
    Examples: 
        Input : arr[] = {14, 15, 17, 18, 2, 3, 6, 12}
        Output: 4
        Explanation : Initial array must be {2, 3, 6, 12, 14, 15, 17, 18}. 
            We get the given array after rotating the initial array four times.

        Input : arr[] = {7, 9, 11, 12, 5}
        Output: 4

        Input : arr[] = {11, 12, 2, 5, 6, 8}
        Output: 2

        Input: arr[] = {7, 9, 11, 12, 15};
        Output: 0  

    Strategy:
    -   The minimum element is the only element whose previous is greater than it. If there is no previous
        element, then there is no rotation (first element is minimum). We check this condition for middle element by comparing it with (mid-1)’th and (mid+1)’th elements.
    -   If the minimum element is not at the middle (neither mid nor mid + 1), then minimum element lies in
        either left half or right half. 
        *   If middle element is smaller than last element, then the minimum element lies in left half
        *   Else minimum element lies in right half.
*/
#include<iostream>
using namespace std;

// we could have just found the minimum element's index as in rotated sorted array, that will be the rotation count. but the time complexity of that will be O(n)
// since array was initially sorted we will use Binary search to do this is O(logN)
int rotationCount_rotatedsortedarray(int arr[], int n){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(mid<end && arr[mid]>arr[mid+1]){
            return mid+1;
        }
        if(mid>start && arr[mid]<arr[mid-1]){
            return mid;
        }
        // for deciding which way to go - 
        if(arr[mid]>arr[start])   //search in right half
            start = mid+1;

        if(arr[end]>arr[mid])   //search in left half
            end = mid-1;
    }
    return 0;
}

int main(){
    int arr[] = {14, 15, 17, 18, 2, 3, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of rotation count for the rotated sorted array: ";
    cout<<rotationCount_rotatedsortedarray(arr,n)<<endl;
    
    int arr2[] = {7, 9, 11, 12, 5};
    n = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Number of rotation count for the rotated sorted array: ";
    cout<<rotationCount_rotatedsortedarray(arr2,n)<<endl;
    
    int arr3[] = {11, 12, 2, 5, 6, 8};
    n = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"Number of rotation count for the rotated sorted array: ";
    cout<<rotationCount_rotatedsortedarray(arr3,n)<<endl;
    
    int arr4[] = {7, 9, 11, 12, 15};
    n = sizeof(arr4)/sizeof(arr4[0]);
    cout<<"Number of rotation count for the rotated sorted array: ";
    cout<<rotationCount_rotatedsortedarray(arr4,n)<<endl;

    return 0;
}

// Number of rotation count for the rotated sorted array: 4
// Number of rotation count for the rotated sorted array: 4     
// Number of rotation count for the rotated sorted array: 2     
// Number of rotation count for the rotated sorted array: 0