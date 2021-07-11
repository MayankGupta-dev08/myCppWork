// Given an array arr[] of size, N, the task is to find the length of the longest subarray that forms an Arithmetic Progression.
// To write a program ..to return the length of longest airthmetic subarray, where airthmetic in the problem is given as elements that have same difference when subtracted with adjacent elements.
// Time Complexity can't be O(n2), here it is O(n).
// GOOGLE KICKSTART

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void longestAirthmeticSubarray(int a[],int n){
    int max_streak =2; 
    int curr_streak = 2;//becoz at least two will have a diff
    int pd = a[1] - a[0];
    int j=2;
    while (j<n)
    {
        if(pd == a[j]-a[j-1]){
            curr_streak++;
        }
        else{
            pd = a[j]-a[j-1];
            curr_streak = 2;
        }
        max_streak = max(max_streak, curr_streak);
        j++;
    }
    cout<<"Length of longest Airthmetic Subarray: "<<max_streak<<endl;
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
    longestAirthmeticSubarray(a,n);
    return 0;
}

// Enter a size of array: 3
// Enter the elements of your array.
// 3 4 5
// Length of longest Airthmetic Subarray: 3

// Enter a size of array: 7
// Enter the elements of your array.
// 10 7 4 6 8 10 12
// Length of longest Airthmetic Subarray: 5