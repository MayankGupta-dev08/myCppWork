// To write a program ..for searching in 2D matrix, given both row and columns are sorted.
// If either of row/col is sorted then we have to search using that by firstly finding that row/col by using its min and max index to get that one row/col and then applying binary search of O(n).

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m; cin>>n>>m;
    int target; cin>>target;
    bool flag = false;
    int a[n][m];
    for(int i=0; i<n; i++){    
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    }
    
    // //Using Bri=ute Force Apporach
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         if (a[i][j]==target){
    //             flag = true;
    //             break;
    //         }
    //     }
    // }
    

    // Using Optimized Approach
    int r=0, c=m-1;
    while(r<n && c>=0){
        if (a[r][c]==target){
            flag =true;
            break;
        }
        else if (a[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }
    if(flag){
        cout<<"Found!"<<endl;
    }
    else{
        cout<<"Not found!"<<endl;
    }
    return 0;
}