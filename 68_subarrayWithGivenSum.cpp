/*To write a program ..Subarray With Given Sum
Given an unsorted array A of size N of non-negative integers, find a continuous subarray which adds to a given number S.
GOOGLE, FB, VISA, AMAZON.
*/

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

// brute force approach
// O(n*n)
void subArraySum(int arr[], int n, int sum){
    int curr_sum, i, j;
 
    // Pick a starting point
    for (i = 0; i < n; i++) {
        curr_sum = arr[i];
 
        // try all subarrays starting with 'i'
        for (j = i + 1; j <= n; j++){
        // we are checking curr sum of j at j+1
            if (curr_sum == sum) {
                cout << "Sum found between indexes "
                     << i << " and " << j - 1<<endl;
                return;
            }
            if (curr_sum > sum || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }
    cout << "No subarray found"<<endl;
}


// Optimised approach
// time complexity - O(n)
void subarrayWithGivenSum(int arr[], int n, int s){
    int first_idx=0, last_idx=0, sum=0;
    
    for(int  i=0; i<=n; i++){
        if(sum<s){
            sum=sum + arr[i];
            last_idx++;
        }
        else if(sum==s){
            cout<<"Subarry with sum="<<s<<" found from: ";
            cout<<first_idx<<" to "<<last_idx-1<<endl;
                return;
        }
        else{
            sum=sum-arr[first_idx];
            first_idx++;
            i--; // for checking again for that same value of i.
        }
    }
    cout<<"No subarray with sum="<<s<<" found."<<endl;
}


int main(){

    int n, s;
    cout<<"Enter a size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of your array.\n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter a sum value for which you want subarray: ";
    cin>>s;
    // subArraySum(a,n, s);
    subarrayWithGivenSum(arr,n, s);
    return 0;
}

// Enter a size of array: 8
// Enter the elements of your array.
// 15 2 4 8 9 5 10 23
// Enter a sum value for which you want subarray: 23
// Subarry with sum=23 found from: 1 to 4