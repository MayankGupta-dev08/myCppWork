// To write a program ..to geneate all possible subsets of a given set, where set is a coollection of distinct elements, so no duplicates.
// For an array of n elements, we will have 2 ki power n. 
// 2 ki power n -->  1<<n, for n =4  --> 1<<4 = 10000 = 16 

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// using Bit manipulation
void subsets(int arr[], int n){
    for (int i = 0; i < (1<<n); i++){
        cout<<"{ ";
        for (int j = 0; j < n; j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"}"<<endl;
    }
}


int main(){

    int arr[] = {1,2,3,4};
    subsets(arr, 4);
    return 0;
}