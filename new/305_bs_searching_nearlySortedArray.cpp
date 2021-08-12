/*SEARCH IN A NEARLY SORTED ARRAY:

Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.

Example :
Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
Output: 2 
Output is index of 40 in given array
*/

#include <iostream>
using namespace std;

int searchInNearlySortedArray(int arr[], int n, int key){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return mid;

        if(start<mid && arr[mid-1]==key)
            return mid-1;

        if(mid<end && arr[mid+1]==key)
            return mid+1;

        if(arr[mid]>key)
            end = mid-2;

        else if(arr[mid]<key)
            start = mid+2;
    }
    return -1;
}

int main(){
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 40;
    int ans = searchInNearlySortedArray(arr, n, key);
    if(ans==-1)
        cout<<"Key not found in array\n";
    else
        cout<<key<<" in nearly sorted array is at index: "<<ans<<endl;
    
    key = 45;
    ans = searchInNearlySortedArray(arr, n, key);
    if(ans==-1)
        cout<<key<<" not found in nearly sorted array\n";
    else
        cout<<key<<" in nearly sorted array is at index: "<<ans<<endl;
    return 0;
}

// 40 in nearly sorted array is at index: 2
// 45 not found in nearly sorted array