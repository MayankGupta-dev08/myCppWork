/*Find the index of first 1 in an infinite sorted array of 0s and 1s
    Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.
        Examples: 
            Input : arr[] = {0, 0, 1, 1, 1, 1} 
            Output : 2

            Input : arr[] = {1, 1, 1, 1,, 1, 1}
            Output : 0
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){
    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid]==key){
            while(arr[mid-1]==1)
                mid--;
            return mid;
        }
        if(arr[mid]<key)
            start=mid+1;

        else if(arr[mid]>key)
            end=mid-1;
    }
    return -1;
}

int indexOfFisrt1_InfinteSortedBinaryArray(int arr[]){
    int low=0, high=1;
    int val = arr[0];

    while(val==0){
        low=high;
        high*=2;
        val=arr[high];
    }

    return binarySearch(arr, low, high, 1);
}

int main(){
    int arr1[] = {0, 0, 1, 1, 1, 1};
    cout<<"index of first 1 in infinteSortedBinary array: "
        <<indexOfFisrt1_InfinteSortedBinaryArray(arr1)<<endl;
    
    int arr2[] = {1, 1, 1, 1, 1, 1};
    cout<<"index of first 1 in infinteSortedBinary array: "
        <<indexOfFisrt1_InfinteSortedBinaryArray(arr2)<<endl;
    return 0;
}

// index of first 1 in infinteSortedBinary array: 2
// index of first 1 in infinteSortedBinary array: 0