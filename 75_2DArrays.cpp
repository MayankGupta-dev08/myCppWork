// To write a program ..to ask elements of a @D matrix and print them Matrix.

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[2][3] = {{1,2,3}, {4,5,6}};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    cout<<"Matrix a is: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
    cout<<endl;
    }
    cout<<"Matrix b is: \n";
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout<<b[i][j]<<" ";
        }
    cout<<endl;
    }
    return 0;
}