/*FIND CEIL OF AN ELEMENT IN A SORTED ARRAY:
    Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume than the array is sorted in non-decreasing order. Write efficient functions to find floor and ceiling of x.
        For example - int a = 7.6
                    floor of a = 7
                    ceil of a = 8

    Example:
        For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
            For x = 0:    floor doesn't exist in array,  ceil  = 1
            For x = 1:    floor  = 1,  ceil  = 1
            For x = 5:    floor  = 2,  ceil  = 8
            For x = 20:   floor  = 19,  ceil doesn't exist in array
*/

#include <iostream>
#include <climits>
using namespace std;

int ceilOfKey_sortedArray(int arr[], int n, int key){
    int start=0, end=n-1;
    int res = INT_MAX;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return key;
        
        if(arr[mid]<key)
            start = mid+1;
        
        else if(arr[mid]>key){
            res = min(res, arr[mid]);
            end = mid-1;
        }
    }
    if(res==INT_MAX)
        return -1;
    else
        return res;
}

int main(){
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=0;
    int ans = ceilOfKey_sortedArray(arr,n,x);
    if(ans!=-1)
        cout<<"Ceil of "<<x<<" in the sorted array: "<<ans<<endl;
    else
        cout<<"Ceil for x = "<<x<<" doesn't exists.\n";
    
    x=1;
    ans = ceilOfKey_sortedArray(arr,n,x);
    if(ans!=-1)
        cout<<"Ceil of "<<x<<" in the sorted array: "<<ans<<endl;
    else
        cout<<"Ceil for x = "<<x<<" doesn't exists.\n";

    x=5;
    ans = ceilOfKey_sortedArray(arr,n,x);
    if(ans!=-1)
        cout<<"Ceil of "<<x<<" in the sorted array: "<<ans<<endl;
    else
        cout<<"Ceil for x = "<<x<<" doesn't exists.\n";

    x=20;
    ans = ceilOfKey_sortedArray(arr,n,x);
    if(ans!=-1)
        cout<<"Ceil of "<<x<<" in the sorted array: "<<ans<<endl;
    else
        cout<<"Ceil for x = "<<x<<" doesn't exists.\n";
    
    return 0;
}

// Ceil of 0 in the sorted array: 1
// Ceil of 1 in the sorted array: 1
// Ceil of 5 in the sorted array: 8
// Ceil for x = 20 doesn't exists.