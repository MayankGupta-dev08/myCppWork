// To write a program ..to remove Duplicate Char From String using recurrsion
/*In this we will compare the first char of original string to the string which was created using orignal (from char 1 to last), which is already corrected from reccurrsion function if */

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

// brute force approach, tc=O(n*n), sc=O(1)
string removeDuplicates_brute(string s){
    string ans;
    for(int i=0; i<s.length(); i++){
        int j=0;
        while(j < i){    //checking for s[i] from 0 to i-1
            if(s[i]==s[j])
                break;
            j++;
        }
        if(j==i)    //if for s[i] we don't have any duplicates till i-1
            ans.push_back(s[i]);
    }
    return ans;
}

// using set - which implements self balancing bst
// tc=O(nlogn), sc=O(n)
string removeDuplicates_set(string s){
    unordered_set<char> st(begin(s), end(s));
    string ans;
    for(auto i: st)
        ans.push_back(i);
    
    reverse(ans.begin(), ans.end());
    return ans;
}

//using an array - best approach
// tc=O(n), sc=O(1)
string removeDupli(string s){
    if(s.length()<=1)
        return s;
    
    string ans;
    bool arr[128] = {0};
    for (int i = 0; i < s.length(); i++){
        if(arr[s[i]]==0){
            ans.push_back(s[i]);
            arr[s[i]]=1;
        }
    }
    return ans;
}

int main(){
    string s = "acbaacbd";
    cout<<removeDuplicates_brute(s)<<endl;
    cout<<removeDuplicates_set(s)<<endl;
    cout<<removeDupli(s)<<endl;
    return 0;
}