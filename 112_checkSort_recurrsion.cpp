// To write a program ..for checking if an array is sorted or not using recurrsion.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int checkSort(int a[], int n, int pos){
    
    if(a[pos]>a[pos+1])
        return 0;

    else if(pos==n-1)
        return 1;
        
    else
        return ( checkSort(a, n, pos+1) );
}

int main(){

    int n, pos = 0;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    if( checkSort(a, n, pos) )
        cout<<"Yes, it's sorted!"<<endl;
    else
        cout<<"No, it's not sorted!"<<endl;
    
    return 0;
}