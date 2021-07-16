// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
// Example 1:
//     Input:
//         S = "aabacbebebe", K = 3
//     Output: 7
//     Explanation: "cbebebe" is the longest substring with K distinct characters.

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <climits>
#include <map>
#include <set>
using namespace std;

int longestSubstring_kUniqueChars(string s, int k){
    set<int> check_set;
    for (int i = 0; i < s.size(); i++)
        check_set.insert(s[i]);
    if(check_set.size()<k)
        return -1;
    
    map<char, int> mp;
    int i=0, j=0, ans = INT_MIN;
    while(j<s.length()){
        mp[s[j]]++;
        if(mp.size()>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) //if count of that char==0
                    mp.erase(s[i]);
                i++;
            }
        }
        else if(mp.size()==k){
            ans = max(ans, j-i+1);
        }
        j++;
    }
    return ans;
}

int main(){
    string s = "aabacbebebe";
    int k=3;
    cout<<longestSubstring_kUniqueChars(s,k)<<endl; //7
    string s2 = "aaaaa";
    int k2=2;
    cout<<longestSubstring_kUniqueChars(s2,k2)<<endl; //-1
    return 0;
}