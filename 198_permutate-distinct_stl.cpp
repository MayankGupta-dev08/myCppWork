// To write a program ..to print all the permutations of all the elements of an array given all are distinct
// time complxity - Big O(n!)

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cout<<"enter the size: ";
    cin>>n;
    vector<int> a(n);
    
    for(auto &i: a)
        cin>>i;

    vector <vector<int>> ans;

    // we require sorting in this becoz next_permutation gives
    // dictionary permutations, so if we don't sort we won't get all
    // possible permutations
    sort(a.begin(), a.end());
    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(), a.end()));   //gives dictionary permutations
    
    cout<<"All Permutations\n";
    for(auto i: ans){
        for(auto ii: i)
            cout<<ii<<" ";
    cout<<endl;
    }

    return 0;
}

// enter the size: 3
// 1 2 3
// All Permutations
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1