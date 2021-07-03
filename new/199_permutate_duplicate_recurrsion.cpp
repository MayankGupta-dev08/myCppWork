// To write a program ..to print all the permutations of all the elements of an array given elements can br repeating

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(vector<int> &va,int idx, vector<vector<int>> &ans){
    if(idx==va.size()){
        ans.push_back(va);
        return;
    }

    for (int i = idx; i < va.size(); i++){
        // agar i and idx alag hai or un dono mein values same hai to 
        // uske liye continue kar lo loop
        if(i!=idx && va[i]==va[idx])
            continue;
        else{
            swap(va[i], va[idx]);
            permute(va, idx+1, ans);
            swap(va[i], va[idx]);
        }
    }
    return;
}

int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> va(n);
    cout<<"Enter elements: ";
    for(auto &itr: va)
        cin>>itr;

    vector<vector<int>> ans;
    permute(va, 0, ans);
    
    cout<<"All permutations:-\n";
    for (auto i: ans){
        for(auto ii: i)
            cout<<ii;
        
        cout<<endl;
    }
    
    return 0;
}