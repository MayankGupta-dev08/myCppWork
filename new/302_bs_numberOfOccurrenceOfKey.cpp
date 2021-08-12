/*Question related to  binary search
    given a sorted array (ascending order) and an element which has to be searched in the array, we have to return the number of occurrences of that element if present and -1 if not present.
*/
#include<iostream>
using namespace std;

int numberOfOccurrence_key(int arr[], int n, int key){
    int start=0, end=n-1, num=1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key){
            while(arr[mid-1]==key){
                mid--;
            }
            while(arr[mid+1]==key){
                mid++;
                num++;
            }
            return num;
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
    int arr[] = {2,4,10,10,10,10,10,18,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 10;
    cout<<"Number of occurrences of "<<key<<" in array: ";
    cout<<numberOfOccurrence_key(arr,n,key)<<endl;
    return 0;
}

// Number of occurrences of 10 in array: 5