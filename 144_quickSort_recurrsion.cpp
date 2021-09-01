// To write a program ..for quick sort

//time complexity = O(nlogn)
#include <iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r){
// pivot element could be any for this program but it has to be related to a fix position for the whole program.
// here we have decided it to be the last one.
// here we are using pivot element to place it at a position such that before it all elements are lesser than it (not all sorted) and after it all are bigger than it.

    int pivot = arr[r];
    int i = l-1;
    for (int j = l; j < r; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr, i, j);
        }        
    }
    swap(arr, i+1, r);
    return (i+1);

}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pivotIndex = partition(arr, l, r);
        
        quickSort(arr, l, pivotIndex-1);
        quickSort(arr, pivotIndex+1, r);
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
    quickSort(arr, 0, n-1);
    cout<<"Sorted array"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// Output
// Enter the size of array: 7
// Enter the elements of the array
// 6 3 9 8 2 5 7
// Sorted array  
// 2 3 5 6 7 8 9 