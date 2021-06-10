// To write a program ..Bubble Sort in increasing order of an Array.
/* Repeatedly swap two adjacent elements if they are in wrong order.
If we have an array of n elements then after n-1 iterations we will get our soted array.
Array gets sorted from right to left.*/

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void bubbleSort_i(int sorted_array[],int n){
    for (int i=0; i<n-1; i++){                  
        // since we are checking an element with its next element so till n-2 or <n-1 as last element is n-1 and we can't check it with anyother.
        for (int j=0; j<n-1-i; j++){
            // Since after every iteration, one less element to be checked as bigger ones gets pushed at back.
            if (sorted_array[j]>sorted_array[j+1]){
            //Agar right wala chhota hai to swap, aise biggest will be send to end.
                int temp = sorted_array[j];
                sorted_array[j] = sorted_array[j+1];
                sorted_array[j+1] = temp;
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

    bubbleSort_i(sorted_array,n);    //Here we have just called the function and not took anything in return as array which will be sent will change for permanent as it works with address.
    cout<<"Our Sorted array:\n";
    for(int i=0; i<n; i++){
        cout<<sorted_array[i]<<' ';
    }
    cout<<endl;
    return 0;
}