// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
    // nums[i] is either 0 or 1.
    // 0 <= k <= nums.length

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation : [1,1,1,0,0,1,1,1,1,1,1]
// index 5 and index 11 flipped from 0 to 1. The longest subarray is underlined.

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation : [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]

#include<iostream>
using namespace std;

/*Our idea-
    Find the longest subarray with atmost k zeroes
        ~For each a[j], try to find longest subarray
        ~if a[i] to a[j], number of zeroes<=k, we continue to increment j.
        ~if a[i] to a[j], number of zeroes>k, we will increment i as well j.
*/
int maxConsecutiveOnes_K(int nums[], int n, int k){
    int i=0, zeroCount=0, ans=0;
    for (int j = 0; j < n; j++){
        if(nums[j]==0)
            zeroCount++;
        while(zeroCount>k){
            if(nums[i]==0)
                zeroCount--;
            i++;
        }
        ans = max(ans, j-i+1);
    }
    return ans;
}

int main(){

    int arr[] = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<maxConsecutiveOnes_K(arr,11,k)<<endl;  //6

    int arr2[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    k=3;
    cout<<maxConsecutiveOnes_K(arr2,19,k)<<endl; //10
    return 0;
}