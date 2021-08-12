/*Question related to  binary search
    when order of the sorted array is not mention and u have to search for an element using binary search
*/
#include<iostream>
using namespace std;

bool binarySearch_ascSortedArr(int arr[], int n, int key){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }
        else
            end = mid-1;
    }
    return false;
}

bool binarySearch_descSortedArr(int arr[], int n, int key){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid]<key){
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return false;
}

bool agnosticBinarySearch(int arr[], int n, int key){
    if(n==1){
        if(key==arr[0])
            return true;
        else
            false;
    }
    if(arr[0]<arr[n-1])
        return binarySearch_ascSortedArr(arr, n, key);
    else
        return binarySearch_descSortedArr(arr, n, key);
}

int main(){
    int arr1[] = {1,2};
    int arr2[] = {1,2,3,4,5,6,7,8};
    int arr3[] = {8,7,6,5,4,3,2,1};

    if(agnosticBinarySearch(arr1, 2, 2))
        cout<<"Found!"<<endl;
    else
        cout<<"Not Found!"<<endl;
    return 0;
}