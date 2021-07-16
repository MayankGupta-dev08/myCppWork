// Given a string s, find the length of the longest substring without repeating characters.
    // Input: s = "abcabcbb"
    // Output: 3
    // Explanation: The answer is "abc", with the length of 3

    // Input: s = "pwwkew"
    // Output: 3
    // Explanation: The answer is "wke", with the length of 3.
    // Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


#include <iostream>
#include <string>
#include <map>
using namespace std;

int longestSubstr_withoutRepeatingChars(string s){
    map<char, int> mp;
    int i=0, j=0, ans=0;
    while(j<s.length()){
        mp[s[j]]++;
        if(j-i+1 > mp.size()){
            while(j-i+1 > mp.size()){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
        }
        if(mp.size()==j-i+1){
            ans=max(ans, j-i+1);
        }
        j++;
    }
    return ans;
}

int main(){
    string s = "pwwkew";
    cout<<longestSubstr_withoutRepeatingChars(s)<<endl;
    return 0;
}