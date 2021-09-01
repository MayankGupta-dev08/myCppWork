/*Given an array containing N integers and an integer SUM., Your task is to find the length of the longest Sub-Array with the prefixSum of the elements equal to the given value SUM.
Example 1:
    Input :
        A[] = {-5, 8, -14, 2, 4, 12} and SUM = -5
        Output : 5
    Explanation:
        The sub-array is {-5, 8, -14, 2, 4}.

    Approach: The idea is to store the sum of elements of every prefix of the array in a hashmap, i.e, every index stores the sum of elements up to that index hashmap. So to check if there is a subarray with a sum equal to s, check for every index i, and sum up to that index as x. If there is a prefix with a sum equal to x – s, then the subarray with the given sum is found. 
 
    Algorithm:  
        *   Create a Hashmap (hm) to store a key-value pair, i.e, key = prefix sum and value = its index, and a variable to store the current sum (sum = 0) and the sum of the subarray as s
        *   Traverse through the array from start to end.
        *   For every element update the sum, i.e sum = sum + array[i]
        *   If the sum is equal to s then print that the subarray with the given sum is from 0 to i
        *   If there is any key in the HashMap which is equal to sum – s then print that the subarray with the given sum is from hm[sum – s] to i
        *   Put the sum and index in the hashmap as a key-value pair.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// array has both positive and negative numbers
int longestSubarrayOfSum_K(int arr[], int n, int k){
    unordered_map<int, int> um;
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < n; i++){
        prefixSum += arr[i];
        if (prefixSum == k)
            maxLen = i + 1;
 
        if (um.find(prefixSum) == um.end())
            um[prefixSum] = i;
        
        if (um.find(prefixSum-k) != um.end())
            maxLen = max(maxLen, (i - um[prefixSum-k]));
    }
    return maxLen;
}

int main(){
    int a[] = {3, 4, 7, 2, -3, 1, 4, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int sum = 7;
    cout<<longestSubarrayOfSum_K(a, n, sum)<<endl;  //4 from i=2 to i=5
    
    // longest subarray with sum=0
    int b[] = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    int n2 = sizeof(b)/sizeof(b[0]);
    sum = 0;
    cout<<longestSubarrayOfSum_K(b, n2, sum)<<endl; //5 from i=3 to i=7
    return 0;
}