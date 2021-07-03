// To write a program ..

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    }
    
    int row_start=0, row_end=n-1, col_start=0, col_end=m-1;
    while(row_start<=row_end && col_start<=col_end){

        // for row start
        for (int col=col_start; col<=col_end; col++){
            cout<<a[row_start][col]<<" ";
        }
        row_start++;
        
        // for col end
        for (int row=row_start; row<=row_end; row++)
            cout<<a[row][col_end]<<" ";
        col_end--;

        // for row end
        for (int col=col_end; col>=col_start; col--)
            cout<<a[row_end][col]<<" ";
        row_end--;

        // for col start
        for (int row=row_end; row>=row_start; row--)
            cout<<a[row][col_start]<<" ";
        col_start++;
    }
    cout<<endl;
    return 0;
}

/*OUTPUT
5 6 
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
1 2 3 4 5 6 12 18 24 30 29 28 27 26 25 19 13 7 8 9 10 11 17 23 22 21 20 14 15 16 15 
*/