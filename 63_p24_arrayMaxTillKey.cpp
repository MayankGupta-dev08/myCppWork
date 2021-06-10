// To write a program ..to find the maximum from the elements from the array till an index number given by the user.

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void maxTillkey(int a[], int n, int key){
    int mx = a[0];
    for (int i=0; i<=key; i++){
        mx = max(a[i], mx);
        cout<<mx<<' ';
    }
}

int main(){

    int n;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n], key, ans;
    cout<<"Enter the elements of your array.\n";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter the index number till which you want to find max.\n";
    cin>>key;
    cout<<"Max till index "<<key<<endl;
    maxTillkey(a, n, key);
    cout<<endl;
    return 0;
}