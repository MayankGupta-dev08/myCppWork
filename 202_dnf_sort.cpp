// To write a program ..Dutch National Flag (DNF) sort
// aka - 0,1,2 sort
// to sort an array cosisting of 0,1,2
// time complexity Big O(n)

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// we mill mainly traverse arr thru mid
// using mid we will swap and move high-- or low++
void dnfSort(int arr[], int n){
    int low=0, mid=0, high=n-1;
    
    while(mid<=high){    
        if(arr[mid]==0){
            swap(arr,low, mid);
            low++; 
            mid++;
        }
        else if(arr[mid]==1)
            mid++;
        else if(arr[mid]==2){
            swap(arr,mid,high);
            high--;
        }
    }
    return;
}

int main(){

    int n = 10;
    int arr[n] = {1,1,2,0,0,1,2,2,1,0};
    
    dnfSort(arr,n);

    cout<<"sorted array by DNF_sort\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

// sorted array by DNF_sort
// 0 0 0 1 1 1 1 2 2 2