// To write a program ..Selection Sort in increasing order of an Array.
/* The inner loop selects the minimum element in the unsorted array and places the elements in increasing order.
The value of j is i+1 as after every increament of i, samllest element is bring to front, starting from the least.
Array gets sorted from left to right.*/

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void selectionSort_i(int sorted_array[],int n){
    for (int i=0; i<n-1; i++){                      // i from 0 to n-2
        for (int j=i+1; j<n; j++){                      // j from i+1 to n-1
            if (sorted_array[j]<sorted_array[i]){
                int temp = sorted_array[j];
                sorted_array[j] = sorted_array[i];
                sorted_array[i] = temp;
            }

        }
        
    }
}

int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n], sorted_array[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){     //Making a copy of our original array, so that both are different.
        sorted_array[i]=a[i];
    }

    selectionSort_i(sorted_array,n);    //Here we have just called the function and not took anything in return as array which will be sent will change for permanent as it works with address.
    cout<<"Our Sorted array:\n";
    for(int i=0; i<n; i++){
        cout<<sorted_array[i]<<' ';
    }
    cout<<endl;
    return 0;
}