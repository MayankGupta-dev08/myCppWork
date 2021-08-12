/*Question related to  binary search
    given a sorted array (ascending order) and an element which has to be searched in the array, we have to return the first occurrence of the element if present and -1 if not.
*/
#include<iostream>
using namespace std;

int firstOccurrence_key(int arr[], int n, int key){
    int start=0, end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            while(arr[mid-1]==key){
                mid--;
            }
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

int main(){
    int arr[] = {2,4,10,10,10,18,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 10;
    cout<<"First occurrence of "<<key<<" in array is at index: ";
    cout<<firstOccurrence_key(arr,n,key)<<endl;
    return 0;
}

// First occurrence of 10 in array is at index: 2