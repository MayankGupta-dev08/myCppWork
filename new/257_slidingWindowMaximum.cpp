// Given an array nums[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
// Example:
//     Input 1:
//         A = [1, 3, -1, -3, 5, 3, 6, 7]
//         B = 3
//     Output 1:
//         C = [3, 3, 5, 5, 6, 7]

#include <iostream>
#include <vector>
#include <set>  //for multi_set - storing in decr order
#include <climits>    //for INT_MIN
#include <algorithm>    //for *max_element
using namespace std;

vector<int> maxOfSlidingWindow(vector<int> nums, int k){
    vector<int> ans;
    if(k>=nums.size()){
        ans.push_back(*max_element(nums.begin(),nums.end()));
        return ans;
    }
    int i=0, j=0; 
    multiset<int, greater<int>> mx;
    while(j<nums.size()){
        mx.insert(nums[j]);
        if(j-i+1==k){
            ans.push_back(*mx.begin());
            mx.erase(mx.find(nums[i]));//only one element at a time of that value will be erased
            i++;
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k=3;
    vector<int> v = maxOfSlidingWindow(nums, k);
    for(auto i: v)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}
