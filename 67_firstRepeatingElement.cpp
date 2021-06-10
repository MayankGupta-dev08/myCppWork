/*Given an array arr[] of size N. The task is to find the first repeating element in an array of integers, i.e., an element that occurs more than once and whose index of first occurrence is smallest.
AMAZON, ORACLE*/

#include <iostream>
#include <limits.h>             // for INT_MAX and INT_MIN
//#include <bits/stdc++.h>
using namespace std;

void firstRepeatingElement(int a[],int n){
    const int N = 1e5 + 2;
    int indx[N];
    int minindx = INT_MAX;
    for(int i=0; i<N; i++){
        indx[i]= -1;
    }
    for (int i =0; i<n; i++){
        if (indx[a[i]] != -1){
            minindx = min(minindx,indx[a[i]]);
        }
        else{
            indx[a[i]] = i;
        }
    }
    if (minindx==-1){
        cout<<"-1"<<endl;
    }
    else{
        cout<<"First repeating Element: "<<a[minindx]<<" at: "<<minindx+1<<endl;
    }

}

int main(){

    int n;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of your array.\n";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    firstRepeatingElement(a,n);
    return 0;
}