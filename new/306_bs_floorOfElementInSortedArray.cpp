/*FIND FLOOR OF AN ELEMENT IN A SORTED ARRAY:
    Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.
        For example - int a = 7.6
                    floor of a = 7
                    ceil of a = 8

    Example:
        Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
        Output : 2
        2 is the largest element in arr[] smaller than 5.

        Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20
        Output : 19
        19 is the largest element in arr[] smaller than 20.

        Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 0
        Output : -1
        Since floor doesn't exist, output is -1.
*/

#include <iostream>
#include <climits>
using namespace std;

int floorOfKey_sortedArray(int arr[], int n, int key){
    int start=0, end=n-1;
    int res = INT_MIN;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return key;
        
        if(arr[mid]<key){
            res = max(res, arr[mid]);
            start = mid+1;
        }
        else if(arr[mid]>key)
            end = mid-1;
    }
    if(res==INT_MIN)
        return -1;
    else
        return res;
}

int main(){
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=5;
    int ans = floorOfKey_sortedArray(arr,n,x);
    if(ans!=-1)
        cout<<"Floor of "<<x<<" in the sorted array: "<<ans<<endl;
    else
        cout<<"Floor for x = "<<x<<" doesn't exists.\n";
    
    x=20;
    ans = floorOfKey_sortedArray(arr,n,x);
    if(ans!=-1)
        cout<<"Floor of "<<x<<" in the sorted array: "<<ans<<endl;
    else
        cout<<"Floor for x = "<<x<<" doesn't exists.\n";

    x=0;
    ans = floorOfKey_sortedArray(arr,n,x);
    if(ans!=-1)
        cout<<"Floor of "<<x<<" in the sorted array: "<<ans<<endl;
    else
        cout<<"Floor for x = "<<x<<" doesn't exists.\n";
    
    return 0;
}

// Floor of 5 in the sorted array: 2
// Floor of 20 in the sorted array: 19
// Floor for x = 0 doesn't exists.