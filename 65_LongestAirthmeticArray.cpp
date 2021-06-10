// To write a program ..to return the length of longest airthmetic subarray, where airthmetich in the problem is given as elements have have same difference when subtracted with adjacent elements.
// Time Complexity can't be O(n2), here it is O(n).
// GOOGLE KICKSTART

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void longestAirthmeticSubarray(int a[],int n){
    int ans =2;
    int streak = 2;
    int pd = a[1] - a[0];
    int j=2;
    while (j<n)
    {
        if(pd == a[j]-a[j-1]){
            streak++;
        }
        else{
            pd = a[j]-a[j-1];
            streak = 2;
        }
        ans = max(ans, streak);
        j++;
    }
    cout<<"Length of longest Airthmetic Subarray: "<<ans<<endl;
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