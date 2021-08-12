// ****VERY IMPORTANT****

// Given two strings s and t, return the minimum window in s which will contain all the characters in t (including duplicates). If there is no such window in s that covers all characters in t, return the empty string "".
// Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
    // A substring is a contiguous sequence of characters within the string.

// Example 1:
    // Input: s = "ADOBECODEBANC", t = "ABC"
    // Output: "BANC"
    // Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Example 2:
    // Input: s = "a", t = "a"
    // Output: "a"
    // Explanation: The entire string s is the minimum window.

#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;

string minWindow(string, string);

string minimumSlidingWindow(string s, string t){
    map<char, int> mp;
    int ans=INT_MAX;    //size of min possible window
    int count, start=0;
    string str = "";

    for (int i = 0; i < t.length(); i++)
        mp[t[i]]++;
    count=mp.size();

    int i=0,j=0;
    while(j<s.length()){
        if(count>0){
            if(mp.find(s[j])!=mp.end()){    //s[j] is present in map
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            j++;
        }
        if(count==0){
            if(ans> j-i+1){
                ans = j-i+1;
                start=i;
            }   // ans = min(ans, j-i+1);
            while(count==0){    // while count is still 0
                if(mp.find(s[i])!=mp.end()){    //s[i] is present in map
                    mp[s[i]]++;
                    
                    if(mp[s[i]]==1)
                        count++;

                    if(ans> j-i+1){
                        ans = j-i+1;
                        start=i;
                    }   // ans = min(ans, j-i+1);
                    i++;
                }
                else
                    i++;
            }
        }
    }
    if(ans!=INT_MAX)
        return str.append(s.substr(start, ans));
    else
        return str;
}

int main(){
    string s = "totmtaptatghf";
    string t = "tta";
    cout<<minimumSlidingWindow(s,t)<<endl;
    // cout<<minWindow(s,t)<<endl;

    s = "ADOBECODEBANC";
    t = "ABC";
    // cout<<minimumSlidingWindow(s,t)<<endl;
    cout<<minWindow(s,t)<<endl;
    return 0;
}

/*
string minWindow(string s, string t) {
    int i=0,j=0,MinL=INT_MAX,start=0;
    map<char,int> mp;
    for(auto it:t)
        mp[it]++;
    int count=mp.size();

    if(mp.find(s[j])!=mp.end()){
        mp[s[j]]--;
        if(mp[s[j]]==0)
            count--;
    }

    while(j<s.length()){
        if(count>0){
            j++;
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                count--;
            }
        }
        else if(count==0){
            // MinL=min(MinL,j-i+1);
            if(MinL>j-i+1){
                MinL=j-i+1;
                start=i;
            }
            while(count==0){
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                        // MinL=min(MinL,j-i+1);
                            if(MinL>j-i+1){
                            MinL=j-i+1;
                            start=i;
                        } 
                    }
                    i++;
                }
                else
                    i++;
            }
        }
    }
    string str="";
    if(MinL!=INT_MAX)
        return str.append(s.substr(start,MinL));
    else
        return str;
}
*/