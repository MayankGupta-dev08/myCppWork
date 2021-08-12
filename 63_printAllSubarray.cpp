// print all the subarray of the array

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printSubarrays(int arr[], int n){
    for (int s = 0; s < n; s++){
        for (int e = s; e < n; e++){
            for (int i = s; i <= e; i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";    
        }
        cout<<"\n";    
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    printSubarrays(arr, 5);
    return 0;
}

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 

// 2 
// 2 3 
// 2 3 4 
// 2 3 4 5 

// 3 
// 3 4 
// 3 4 5 

// 4 
// 4 5 

// 5 
