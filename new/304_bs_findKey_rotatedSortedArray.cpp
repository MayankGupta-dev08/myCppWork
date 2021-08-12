/*Given a rotated sorted array with unique elements, Find the index of a paticular element in the given array, if not found then print the same. */

#include <iostream>
using namespace std;

// returns the index of the key if found and -1 if not.
int binarySearch(int arr[], int start, int end, int key){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return mid;
        
        if(arr[mid]<key)
            start = mid+1;
        else
            end = mid-1;    
    }
    return -1;
}

// returns the index of the minimum element in rotated sorted array
int minElementOfRotatedSortedArray(int arr[], int start, int end){
    while(start<=end){
        int mid=start + (end-start)/2;
        
        if(mid<end && arr[mid]>arr[mid+1])
            return mid+1;

        if(start<mid && arr[mid-1]>arr[mid])
            return mid;

        if(arr[mid]>arr[start])
            start = mid+1;

        else if(arr[mid]<arr[end])
            end = mid-1;
    }
    return 0;
}

int keyInRotatedSortedArray(int arr[], int n, int key){
    int minIdx = minElementOfRotatedSortedArray(arr,0,n-1);
    int res1 = binarySearch(arr, 0, minIdx-1, key);
    int res2 = binarySearch(arr, minIdx, n-1, key);

    return ((res1>res2)? res1 : res2);
}

int main(){
    int arr[] = {11,12,15,18,2,5,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key = 6;
    int ans = keyInRotatedSortedArray(arr,n,key);
    if(ans!=-1)
        cout<<"Found at index: "<<ans<<endl;
    else
        cout<<"Not found!"<<endl;

    key = 4;
    ans = keyInRotatedSortedArray(arr,n,key);
    if(ans!=-1)
        cout<<"Found at index: "<<ans<<endl;
    else
        cout<<"Not found!"<<endl;
    return 0;
}

// Found at index: 6
// Not found!