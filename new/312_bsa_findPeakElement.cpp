/*Find a peak element
    Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour.
    There can be more than one peak element. We have to return any one of them. 

    Concept - BINARY SEARCH THE ANSWER
    
    Example:
        Input: array[]= {5, 10, 20, 15}
        Output: 20
        The element 20 has neighbours 10 and 15, both of them are less than 20.

        Input: array[] = {10, 20, 15, 2, 23, 90, 67}
        Output: 20 or 90
        The element 20 has neighbours 10 and 15, both of them are less than 20, similarly 90 has neighbours 23 and 67.
    
    Following corner cases give better idea about the problem. 
        If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
        If the input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
        If all elements of input array are same, every element is a peak element.
*/

#include <iostream>
using namespace std;

int peakElement_unsortedArray(int arr[], int n){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start +(end-start)/2;
        if(mid>0 && mid<n-1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return arr[mid];
            
            else if(arr[mid]<arr[mid-1])
                end=mid-1;
            
            else
                start=mid+1;
        }
        else if(mid==0 && arr[mid]>arr[mid+1])
            return arr[mid];

        else if(mid==n-1 && arr[mid]>arr[mid-1])
            return arr[mid];
    }
}

int main(){
    int arr1[]= {5, 10, 30, 15};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"One of the Peak element from array: "
        <<peakElement_unsortedArray(arr1, n)<<endl;

    int arr2[] = {10, 20, 15, 2, 23, 90, 67};
    n = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"One of the Peak element from array: "
        <<peakElement_unsortedArray(arr2, n)<<endl;

    int arr3[] = {10, 12, 15, 20, 23, 90, 67};
    n = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"One of the Peak element from array: "
        <<peakElement_unsortedArray(arr3, n)<<endl;
    return 0;
}

// One of the Peak element from array: 30
// One of the Peak element from array: 20
// One of the Peak element from array: 90