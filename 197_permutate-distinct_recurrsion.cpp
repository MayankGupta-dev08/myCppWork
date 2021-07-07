// To write a program ..to print all the permutations of all the elements of an array given all are distinct
// Also using recurrsion
// time complxity - Big O(n!)

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// no need of this also due to buit in function swap
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void permute(vector<int> &varr, int idx, vector<vector<int>> &ans){
    if(idx==varr.size()){
        ans.push_back(varr);
        return;
    }
    for (int i = idx; i < varr.size(); i++){
        swap(varr[i], varr[idx]);
        permute(varr, idx+1, ans);
        swap(varr[i], varr[idx]);
    }
    return;
}

int main(){

    int n;
    cout<<"enter the size of vector: ";
    cin>>n;

    vector<int> varr(n);
    for(auto &iter: varr){
        cin>>iter;
    }

    vector<vector<int>> ans;

    permute(varr,0, ans);

    cout<<"All possible permutations from the given array of distinct elements"<<endl;
    for(auto i: ans){
        for(auto ii: i)
            cout<<ii<<" ";
    cout<<endl;
    }

    return 0;
}