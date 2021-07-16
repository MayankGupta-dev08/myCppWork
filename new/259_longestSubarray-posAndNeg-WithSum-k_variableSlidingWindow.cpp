/*Given an array containing N integers and an integer SUM., Your task is to find the length of the longest Sub-Array with the currsum of the elements equal to the given value SUM.
Example 1:
    Input :
        A[] = {-5, 8, -14, 2, 4, 12} and SUM = -5
        Output : 5
    Explanation:
        The sub-array is {-5, 8, -14, 2, 4}.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// array has both positive and negative numbers
int longestSubarrayOfSum_K(int arr[], int n, long sum){
    // unordered_map 'um' implemented as hash table
    unordered_map<int, int> um;
    int currsum = 0, maxLen = 0;

    for (int i = 0; i < n; i++){
        currsum += arr[i];
 
        // when subarray starts from index '0'
        if (currsum == sum)
            maxLen = i + 1;
 
        // make an entry for 'currsum' if it is not present in 'um'
        if (um.find(currsum) == um.end())
            um[currsum] = i;
 
        // check if 'currsum-sum' is present in 'um' or not
        if (um.find(currsum - sum) != um.end()){
            // update maxLength
            if (maxLen < (i - um[currsum - sum]))
                maxLen = i - um[currsum - sum];
        }
    }
 
    // required maximum length
    return maxLen;
}

int main(){
    int a[] = {-5, 8, -14, 2, 4, 12};
    int n = sizeof(a)/sizeof(a[0]);
    int sum = -5;
    cout<<longestSubarrayOfSum_K(a, n, sum)<<endl;  //5
    return 0;
}