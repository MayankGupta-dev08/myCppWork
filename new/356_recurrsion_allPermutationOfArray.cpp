//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void printPermutation(int arr[], int l, int r, vector<vector<int>> &res){
    if(l==r){
        vector<int> newR;
        for(int i=0; i<=r; i++) //since we are not changing value of r anywhere
            newR.emplace_back(arr[i]);
        res.emplace_back(newR);
        return;
    }
    else{
        for(int i=l; i<=r; i++){
            swap(arr[i], arr[l]);
            printPermutation(arr, l+1, r, res);
            swap(arr[i], arr[l]);
        }
    }
}

int main(){
    int arr[] = {1, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0, r=n-1;
    vector<vector<int>> res; 
    printPermutation(arr, l, r, res);

    for(auto v: res){
        for(auto a: v){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 2 1 3
// 2 3 1
// 1 2 3
// 1 3 2
// 3 1 2
// 3 2 1