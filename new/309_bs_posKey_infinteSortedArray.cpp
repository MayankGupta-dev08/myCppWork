/*Find position of an element in a sorted array of infinite numbers
    Suppose you have a sorted array of infinite numbers, how would you search an element in the array?
    Source: Amazon Interview Experience. 

    Since array is sorted, the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array. 
    If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, first we find bounds and then apply binary search algorithm.
    Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element, 
        ->if it is greater than high index element then copy high index in low index and double the high index. 
        ->if it is smaller, then apply binary search on high and low indices found. 
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){
    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==key)
            return mid;

        if(arr[mid]<key)
            start=mid+1;

        else if(arr[mid]>key)
            end=mid-1;
    }
    return -1;
}

int indexOfKey_InfinteSortedArray(int arr[], int key){
    int low=0, high=1;
    int val = arr[0];
    
    while(val<key){
        low = high;
        high *= 2;
        val = arr[high];
    }

    return binarySearch(arr, low, high, key);
}

int main(){
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int key=10;
    int ans = indexOfKey_InfinteSortedArray(arr,key);
    if(ans==-1)
        cout<<"element doesn't exist!\n";
    else
        cout<<"element is found in array at index: "<<ans<<endl;
    
    key=15;
    ans = indexOfKey_InfinteSortedArray(arr,key);
    if(ans==-1)
        cout<<"element doesn't exist!\n";
    else
        cout<<"element is found in array at index: "<<ans<<endl;
    
    return 0;
}

// element is found in array at index: 4
// element doesn't exist!