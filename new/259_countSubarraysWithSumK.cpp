/*Number of subarrays having sum exactly equal to k
    Given an unsorted array of integers, find the number of subarrays having sum exactly equal to a given number k.

    Examples: 

        Input : arr[] = {10, 2, -2, -20, 10}, 
                k = -10
        Output : 3
        Subarrays: arr[0...3], arr[1...4], arr[3..4]
        have sum exactly equal to -10.

        Input : arr[] = {9, 4, 20, 3, 10, 5},
                    k = 33
        Output : 2
        Subarrays : arr[0...2], arr[2...4] have sum
        exactly equal to 33.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarrayWithSum_K(int nums[], int n, int k){
    if(n==0)
        return 0;
    
    unordered_map<int, int> hashMap;    //key=prefixSum, value=count of prefixSum
    int count=0, prefixSum=0;
    for (int i = 0; i < n; i++){
        prefixSum += nums[i];
        
        if(prefixSum==k)
            count++;
        
        if(hashMap.find(prefixSum-k)!=hashMap.end())  //if prefixSum-k is in hashmap
            count += hashMap[prefixSum-k];
        
        hashMap[prefixSum]++;
    }
    return count;
}

int main(){
    int a[] = {3, 4, 7, 2, -3, 1, 4, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int sum = 7;
    cout<<countSubarrayWithSum_K(a, n, sum)<<endl;  //4
    return 0;
}