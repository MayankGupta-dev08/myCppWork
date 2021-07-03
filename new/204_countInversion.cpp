// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// brute force approach - Big O(n*n)
int countInversion_brute(int arr[], int n){
    int invr=0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if(i<j && arr[i]>arr[j])
                invr++;
        }
    }
    return invr;
}

// optimized approach - mergeSort approach - Big O(nlog(n))

long merge(int arr[], int l, int mid, int r){
    long inv = 0;
    int n1 = mid-l +1;
    int n2 = r-(mid+1) +1;

    int a[n1] = {0};
    for (int i = 0; i < n1; i++)
        a[i]=arr[l+i]; 
    
    int b[n2] = {0};
    for (int i = 0; i < n2; i++)
        b[i]=arr[mid+1+i];

    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            // a[i]>b[j] && i>j
            // a[i], a[i+1], a[i+2], a[i+3],....a[] >b[j]
            arr[k]=b[j];
            inv += n1-i;
            k++; j++; 
        }
    }

    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
    return inv;
}

long countInversion_opti(int arr[], int l, int r){
    long invr=0;
    if(l<r){
        int mid = (l+r)/2;
        invr += countInversion_opti(arr, l, mid);
        invr += countInversion_opti(arr, mid+1, r);
        invr += merge(arr, l, mid, r);
    }
    return invr;
}

int main(){

    int n = 8;
    int arr[] = {3,5,6,9,1,2,7,8};
    
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"Total Inversions in array: "<<countInversion_brute(arr, n)<<endl;
    cout<<"Total Inversions in array: "<<countInversion_opti(arr, 0, n-1)<<endl;
    return 0;
}