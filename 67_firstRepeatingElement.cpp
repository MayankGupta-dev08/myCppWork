/*Given an array arr[] of size N. The task is to find the first repeating element in an array of integers, i.e., an element that occurs more than once and whose index of first occurrence is smallest.
AMAZON, ORACLE*/

//#include <bits/stdc++.h>
#include <iostream>
#include <climits>             // for INT_MAX and INT_MIN
using namespace std;

void firstRepeatingElement(int a[],int n){
    const int N = 1e5 + 2;
    int indx[N];    //for storing index of all unique numbers
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
    if (minindx==INT_MAX){
        cout<<"No repeating element in array."<<endl;
    }
    else{
        cout<<"First repeating Element: "<<a[minindx]<<" at index: "<<minindx<<endl;
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

// Enter a size of array: 7
// Enter the elements of your array.
// 10 5 3 4 3 5 6       
// First repeating Element: 5 at index: 1


// Enter a size of array: 4
// Enter the elements of your array.
// 1 2 3 4
// No repeating element in array.