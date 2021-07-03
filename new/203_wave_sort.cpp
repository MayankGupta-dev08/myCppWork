// To write a program ..wave sort
// a[0]>=a[1]<=a[2]>=a[3]<=a[4]>=a[5]<=a[6].................
// time complexity Big O(n/2) = Big O(n)

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
void waveSort(int arr[], int n){
    
    int i=1;
    while(i<n){    
        if(arr[i-1]<arr[i])
            swap(arr, i-1, i);
        
        if(arr[i]>arr[i+1] && i<n-1)
            swap(arr, i, i+1);
        
        i += 2;
    }
    return;
}

int main(){

    int n = 7;
    int arr[n] = {1,3,4,7,5,6,2};
    
    waveSort(arr,n);

    cout<<"sorted array by wave_sort\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

// sorted array by wave_sort
// 3 1 7 4 6 2 5