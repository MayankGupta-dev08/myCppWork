// To write a program ..to remove Duplicate Char From String using recurrsion
/*In this we will compare the first char of original string to the string which was created using orignal (from char 1 to last), which is already corrected from reccurrsion function if */

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string removeDupli(string s){
    if (s.length()==0)
        return "";          //returning empty string

    char ch = s[0];
    string ans = removeDupli(s.substr(1));
    if( ch == ans[0])
        return ans;
    
    else
        return (ch+ans);
}

int main(){

    cout<<removeDupli("aaaabbbccdddddeeffffgghhh");
    cout<<endl;
    return 0;
}