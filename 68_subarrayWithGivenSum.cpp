/*To write a program ..Subarray With Given Sum
Given an unsorted array A of size N of non-negative integers, find a continuous subarray which adds to a given number S.
GOOGLE, FB, VISA, AMAZON.
*/

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;


void subarrayWithGivenSum(int arr[], int n, int s){
    int first_idx=0, last_idx=0, sum=0;
    
    for(int  i=0; i<=n; i++){
        if(sum<s){
            sum=sum + arr[i];
            last_idx++;
        }
        else if(sum==s){
            cout<<first_idx+1<<" "<<last_idx<<endl;
                break;
        }
        else{
            sum=sum-arr[first_idx];
            first_idx++;
            i--; // for checking again for that same value of i.
        }
    }
    if(i>n){
        cout<<"Not found"<<endl;
    }
}


int main(){

    int n, s;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of your array.\n";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter a sum value for which you want subarray: ";
    cin>>s;
    subarrayWithGivenSum(a,n, s);
    return 0;
}