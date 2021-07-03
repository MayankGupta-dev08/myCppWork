// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getmaxIndex(int a[], int n){
    
    int maxv=a[0], maxIndex = 0;
    for (int i = 1; i < n; i++){
        if(maxv<a[i]){
            maxv = a[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void sort(int a[], int n){
    if (n==0)       //base condition
        return;
    
    int maxIndex = getmaxIndex(a, n);
    int temp = a[n-1];
    a[n-1] = a[maxIndex];
    a[maxIndex] = temp;
    sort(a, n-1);
}

int main(){
    int a[] = {1,5,0,2};
    cout<<"Array before sort: ";
    for (int i = 0; i < 4; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    sort(a,4);
    cout<<"Array after sort:  ";
    for (int i = 0; i < 4; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}