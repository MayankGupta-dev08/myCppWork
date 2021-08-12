//Given a sorted array, find the element in the array which has minimum difference with the given number.

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int minDifferenceOfKey_sortedArray(int arr[], int n, int key){    
    int s=0, e=n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==key)
            return 0;

        if(arr[mid]<key){
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    return min(abs(arr[e]-key), abs(key-arr[s]));
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