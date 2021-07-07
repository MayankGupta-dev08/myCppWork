// To write a program ..for finding the first and last ocurrence of a number given by user from an array.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int firstOccurr(int a[], int n, int pos, int val){
    if (a[pos]==val)
        return pos;

    else if (pos==n)
        return -1;

    else
        return firstOccurr(a,n,pos+1,val);
}

int lastOccurr(int a[], int n, int pos, int val){
    if (a[pos]==val)
        return pos;

    else if (pos==0)
        return -1;

    else
        return lastOccurr(a,n,pos-1,val);
}

// suppose we can't search from last and we have to start from the first index
int lastOccurr2(int a[], int n, int pos, int val){
    
    if (pos==n){
        return -1;
    }

    int restArray =  lastOccurr2(a,n,pos+1,val);
    if (restArray != -1){
        return restArray;
    }

    if (a[pos]==val){
        return pos;
    }
    return -1;
}

int main(){

    int a[] = {4,2,1,2,5,2,7};
    int n=7, fpos=0, lpos=n, val;
    cout<<"Enter a number whose first and last occurence is to be found: ";
    cin>>val;

    cout<<"First occurrence of "<<val<<" is: "<<firstOccurr(a, n, fpos, val)<<endl;
    // cout<<"Last occurrence of "<<val<<" is: "<<lastOccurr(a, n, lpos, val)<<endl;
    cout<<"Last occurrence of "<<val<<" is: "<<lastOccurr2(a, n, fpos, val)<<endl;

    return 0;
}