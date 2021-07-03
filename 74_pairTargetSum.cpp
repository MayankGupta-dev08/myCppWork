// To write a program ..to pair elements from an array to get target sum.
// Find whether there exist 2 numbers that sum to targetSum.

//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

bool pairTargetSum1(int a[], int n, int targetsum){
// by using brute force apporach

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if(a[i]+a[j]==targetsum){
                cout<<"element: "<<i+1<<", element: "<<j+1<<endl;
                return true;
            }
        }
        
    }    
    return false;
}

bool pairTargetSum2(int a[], int n, int targetsum){
// better apporach

    int start = 0, end = n-1;
    while(start<end){
        if(a[start]+a[end] == targetsum){
            cout<<"element: "<<start+1<<", element: "<<end+1<<endl;
            return true;
        }
        else if(a[start]+a[end] < targetsum){
            start++;
        }
        else{
            end--;
        }
    }
    cout<<"Pair of elements not found for the given target sum"<<endl;
    return false;
}

int main(){

    int a[] = {2,4,7,11,14,16,20,21};
    int n = sizeof(a)/sizeof(a[0]);
    int targetSum = 25;
    cout<<pairTargetSum2(a, n, targetSum)<<endl;
    targetSum = 8;
    cout<<pairTargetSum2(a, n, targetSum)<<endl;
    return 0;
}