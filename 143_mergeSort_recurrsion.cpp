// To write a program ..for merge sort

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int n1 = mid-l +1;
    int n2 = r-(mid+1) +1;

    int a[n1], b[n2];       //temp arrays

    for (int i = 0; i < n1; i++)
        a[i]=arr[l+i];
    
    for (int j = 0; j < n2; j++)
        b[j]=arr[mid+1+j];
    
    int i=0, j=0, k=l;      //i for a, j for b, k for arr
    while (i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }
    
    while (i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    
    while (j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void mergerSort(int arr[], int l, int r){
// l is the index of leftmost element and r is the index of rightmost element

    if(l<r){
        int mid = (l+r)/2;
        mergerSort(arr, l, mid);
        mergerSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergerSort(arr, 0, n-1);
    cout<<"Sorted array"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// Output
// Enter the size of array: 5
// Enter the elements of the array
// 5 4 3 1 2
// Sorted array
// 1 2 3 4 5