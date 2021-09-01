/*
Find k closest numbers in an unsorted array
    Given an unsorted array and two numbers x and k, find k closest values to x.
    
    Examples: 
        Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3 
        Output : 4 6 7
        Three closest values of x are 4, 6 and 7.

        Input : arr[] = {-10, -50, 20, 17, 80}, x = 20, k = 2
        Output : 17, 20
*/

#include <iostream>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

void kClosestNumbers(int arr[], int n, int k, int x){
    if(k>n)
        return;

    priority_queue<pair<int, int>> maxHeap;
    for(int i=0; i<n; i++){
        maxHeap.push({fabs(arr[i]-x), arr[i]});
        if(maxHeap.size()>k)
            maxHeap.pop();
    }
    cout<<k<<" closest values to "<<x<<" in array: \n";
    while(!maxHeap.empty()){
        cout<<maxHeap.top().second<<" ";
        maxHeap.pop();
    }
    cout<<endl;
}

int main(){
    int arr[] = {10, 2, 14, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5, k = 3; 
    kClosestNumbers(arr, n, k, x);
    return 0;
}