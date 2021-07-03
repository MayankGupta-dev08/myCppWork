// To write a program ..check if a given string is isPalindrome or not using recurrsion

//#include <bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;

bool isPalindrome(string s, int i, int j){
    if(i>=j)
        return 1;
    
    if(s[i]!=s[j])
        return 0;
    else
        return isPalindrome(s,i+1,j-1);
}

int main(){

    // string s;
    // cin>>s;    
    string s1 = "racecar", s2 = "carrace";
    cout<<isPalindrome(s1, 0, (s1.length()-1))<<endl;
    cout<<isPalindrome(s2, 0, (s2.length()-1))<<endl;
    return 0;
}