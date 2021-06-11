// To write a program ..maximum Subarray sum

//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

void subArray(int a[], int n){
// This is basic solution from brute force method, and its having time complexity of O(n3), which is very bad.

    int maxSum = INT_MIN;
    cout<<"All possible subarrays from your array\n";
    
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum += a[k];
                cout<<a[k]<<' ';
            }
            maxSum = max(maxSum, sum);
            cout<<"\t\t Sum: "<<sum<<endl;
        }
    }
    cout<<"Max Sum: "<<maxSum<<endl;
}


// void maxSubarraysum(int a[], int n){
//     // int count =1;
//     for (int i=0; i<n; i++){
//         // int curr_sum =0;
//         for (int j=i; j<n; j++){
//             // curr_sum += a[j];
//             // cout<<"Sum of SubArray"<<count<<" : "<<curr_sum<<endl;
//             // count +=1;
//             cout<<a[j]<<endl;
//         }
//     }
// }

int main(){

    int n;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of your array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    subArray(a,n);
    // maxSubarraysum(a,n);
    cout<<endl;
    return 0;
}