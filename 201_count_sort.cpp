// To write a program ..for count sort
// 1.   Find the count of every distinct element of the array
// 2.   Calculate the position of each element in the sorted array

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int arr[] = {1,3,2,3,4,1,6,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int max_ele = arr[0];
    for(int i=0; i<n; i++)
        max_ele = max(max_ele, arr[i]);

    // creating an array of size = max_ele+1
    // coz at size-1 index we will store the count of max_ele of arr[]
    int count_arr[max_ele+1] = {0};   //every element 0
    
    // creating the count array
    for(int i=0; i<n; i++)
        count_arr[arr[i]] +=1;

    // // for printing count array
    // for (int i = 0; i < max_ele+1; i++)
    //     cout<<count_arr[i]<<" ";
    // cout<<endl;

    // creating position array for arr elements
    // by converting count array
    for (int i = 1; i < max_ele+1; i++)
        count_arr[i] += count_arr[i-1];
            
    // // for printing count array
    // for (int i = 0; i < max_ele+1; i++)
    //     cout<<count_arr[i]<<" ";
    // cout<<endl;

    int ans[n];
    for (int i = n-1; i >= 0; i--){
        count_arr[arr[i]]--;
        ans[(count_arr[arr[i]])] = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
    

    cout<<"New sorted array by count_sort\n";          
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

// output
// New sorted array by count_sort
// 1 1 2 3 3 3 4 4 6