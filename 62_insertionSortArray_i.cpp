// To write a program ..Selection Sort in increasing order of an Array.
/* We consider our array to be divided into a sorted part (left side) and an unsorted part (right side).
Take an element from the unsorted array, place it in its corresponding position in the sorted part, and shift the elements accordingly.
Initially sorted part is having only one element and Starting from the element at index1 (element2) we check and insert element at its right position in sorted part if required and going till end (n). 
*/

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void insertionSort_i(int b[],int n){
    for (int i=1; i<n; i++){
        int temp = b[i];
        // temp is compared with all on its left and its position is fixed after either it has been compared by all (smallest till now) or some bigger that temp alredy there so no need to check further.
        int j = i-1;
        while (j>=0 && b[j]>temp){
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = temp;
    }
}

int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n], b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){     //Making a copy of our original array, so that both are different.
        b[i]=a[i];
    }

    insertionSort_i(b,n);    //Here we have just called the function and not took anything in return as array which will be sent will change for permanent as it works with address.
    cout<<"Our Sorted array:\n";
    for(int i=0; i<n; i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
    return 0;
}