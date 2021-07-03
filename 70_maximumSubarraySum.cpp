// To write a program ..maximum Subarray sum

//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

void subArray(int a[], int n){
// This is basic solution from brute force approach, and its having time complexity of O(n3), which is not at all good.

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

/*Enter a size of array: 4
Enter the elements of your array: -1 4 7 2
All possible subarrays from your array
-1               Sum: -1
-1 4             Sum: 3
-1 4 7           Sum: 10
-1 4 7 2                 Sum: 12    
4                Sum: 4
4 7              Sum: 11
4 7 2            Sum: 13
7                Sum: 7
7 2              Sum: 9
2                Sum: 2
Max Sum: 13
*/

void maxSubarraySum(int a[], int n){
// In this function we are using Cummulative approach, which is better than the above brute froce appreach of time complexity Big-oh of n cube.

//Creating an array haing cummulative sum and using that to find max. Since subarray is continuous so this will work as we don't have to check other combinations, just cummulative will be enough.
// Now time complexity will be Big oh of n square.

    int cummSumarr[n+1];
    cummSumarr[0] = 0;
    for (int i=1; i<n+1; i++){
        cummSumarr[i] = cummSumarr[i-1] + a[i-1];
    } // Cummulative sum array in just one loop.

    int maxSum = INT_MIN;
    for (int i=1; i<n+1; i++){
        int sum =0;
        for (int j=0; j<i; j++){
            sum = cummSumarr[i] - cummSumarr[j];
            // Fnding sum using cummSumarr as diff of adj terms gives it
            maxSum = max(sum, maxSum);
        }
    }
    cout<<maxSum<<endl;
}

int main(){

    int n;
    cout<<"Enter a size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of your array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    // int b[] = {1,2,3,4};
    // subArray(b,4);
    maxSubarraySum(a,n);
    cout<<endl;
    return 0;
}