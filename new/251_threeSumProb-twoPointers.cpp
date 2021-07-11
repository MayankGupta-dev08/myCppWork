// given an array and a target value, we have to find and tell if their exists three numbers whose sum is equal to the target sum.
// we will solve by two pointer techniques. for time complexity - 
    // for sorting, t.c -> O(nlogn)
    // for iterating the array and applying two sum on rest of the array, t.c -> O(n*n)
    // So t.c of the problem = max of above two, so -> O(n*n)

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BruteForce - time complexity -> (n*n*n)
bool threeSumProb(int arr[], int n, int target){
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                if(target==arr[i]+arr[j]+arr[k]){
                    cout<<"Found at indices: ("<<i<<","<<j<<","<<k<<")\n";
                    return true;
                }
            }        
        }
    }
    return false;
}

// Optimised approach
bool threeSumProb_2ptrTech(vector<int> arr, int target){
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++){
        int start=i+1, end=arr.size()-1; 
        while(start<end){
            if(target-arr[i]==arr[start]+arr[end]){
                cout<<"Values: ("<<arr[i]<<","<<arr[start]<<","<<arr[end]<<")\n";
                return true;
            }
            else if(arr[start]+arr[end]<target-arr[i])
                start++;
            else
                end--;
        }
    }
    return false;
}

int main(){
    // int arr[] = {12,3,7,1,6,9};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int target = 24;
    // if(!threeSumProb(arr,n,target))
    //     cout<<"Not found!"<<endl;
    
    vector<int> v;
    v.push_back(12);
    v.push_back(3);
    v.push_back(7);
    v.push_back(1);
    v.push_back(6);
    v.push_back(9);
    
    int target = 24;
    if(!threeSumProb_2ptrTech(v, target)) //Found at indices: (1,4,5)
        cout<<"Not found!"<<endl;

    target = 58;
    if(!threeSumProb_2ptrTech(v, target)) //Not found!
        cout<<"Not found!"<<endl;
    return 0;
}