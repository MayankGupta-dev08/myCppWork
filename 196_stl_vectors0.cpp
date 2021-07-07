// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){

    int n;
    cout<<"enter the size of vector: ";
    cin>>n;

    vector<int> va(n);

    // // one way to ask
    // vector<int>::iterator it;
    // for ( it = va.begin(); it != va.end(); it++){
    //     cin>>(*it);
    // }
    
    // // 2nd way to ask
    // for (int i = 0; i < va.size(); i++){
    //     cin>>va[i];
    // }
    
    // 3rd way to ask
    for(auto &iter: va){
        cin>>iter;
    }

    // // 1st way to print
    // for (auto it = va.begin(); it != va.end(); it++){
    //     cout<<(*it)<<" ";
    // }
    // cout<<endl;
    
    // // 2nd way to print
    // for (int i = 0; i < va.size(); i++){
    //     cout<<va[i]<<" ";
    // }
    // cout<<endl;
    
    // 3rd way to print
    for(auto iter: va){
        cout<<iter<<" ";
    }
    cout<<endl;

    return 0;
}