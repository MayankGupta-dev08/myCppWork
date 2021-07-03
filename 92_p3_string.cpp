// To write a program ..find the char and frequency of max occuring char from a given string.

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string s = "abcacbadefacgeahb";
    int frq[26];
    for (int i=0;i<26;i++)
        frq[i] = 0;

    for (int i = 0; i < s.size(); i++){
        frq[(s[i]-'a')]++;
    }
    
    int maxfreq=0;
    char ans = 'a';
    for (int i = 0; i < 26; i++){
        if(frq[i]>maxfreq){
            maxfreq = frq[i];
            ans = 'a'+i;
        }
    }
    
    cout<<ans<<" occurred max number of times: "<<maxfreq<<endl;

    return 0;
}