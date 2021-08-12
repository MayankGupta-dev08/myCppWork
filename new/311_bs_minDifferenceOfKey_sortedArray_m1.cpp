//Given a sorted array, find the element in the array which has minimum difference with the given number.

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int ceilOFkey_sortedArray(int arr[], int n, int key){
    int s=0, e=n-1, ceil=INT_MAX;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==key)
            return key;

        if(arr[mid]<key){
            s=mid+1;
        }
        else {
            ceil=min(ceil, arr[mid]);
            e=mid-1;
        }
    }
    if(ceil==INT_MAX)
        return -1;
    return ceil;
}

int floorOFkey_sortedArray(int arr[], int n, int key){
    int s=0, e=n-1, floor=INT_MIN;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==key)
            return key;

        if(arr[mid]<key){
            floor=max(floor, arr[mid]);
            s=mid+1;
        }
        else
            e=mid-1;
    }
    if(floor==INT_MIN)
        return -1;
    return floor;
}

int minDifferenceOfKey_sortedArray(int arr[], int n, int key){    
    int ceil  = ceilOFkey_sortedArray(arr, n, key);
    int floor = floorOFkey_sortedArray(arr, n, key);
    if(floor!=-1 && ceil!=-1)
        return min(ceil-key, key-floor);
    else if(floor!=-1)
        return (key-floor);
    else
        return (ceil-floor);
}

int main(){
    int arr[] = {1,3,5,7,9,13,15,17,19};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=9;
    cout<<"min difference of "<<key<<" in sorted array: "
        <<minDifferenceOfKey_sortedArray(arr, n, key)<<endl;
    
    key=10;
    cout<<"min difference of "<<key<<" in sorted array: "
        <<minDifferenceOfKey_sortedArray(arr, n, key)<<endl;
    return 0;
}

// min difference of 9 in sorted array: 0
// min difference of 10 in sorted array: 1