// To write a program ..

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the number of row/colums for sq matrix: ";
    cin>>n;
    int a[n][n];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    cout<<"Matrix is: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
    cout<<endl;
    }
    
    //just printing the transpose matrix.
    cout<<"Printing the Transpose of the square Matrix is: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[j][i]<<" ";
        }
    cout<<endl;
    }

    // trab=nsposing the original array.
    cout<<"Transposing the original square Matrix is: \n";
    for(int i=0; i<n; i++){
        for (int j = i; j < n; j++){
            // swaping
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
    cout<<endl;
    }
    return 0;
}