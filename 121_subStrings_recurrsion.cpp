// To write a program ..to generate all the substrings of a string
// To write a program ..to print all the subsequences aka Powerset or Superset of a given string 
// "abc"  -  {"",'a','b','c', "ab", "bc", "ac", "abc"};

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void AllsubStrings(string inp_s, string op_s){
    
    if (inp_s.length()==0){
        cout<<op_s<<endl;
        return;
    }
    
    string op_s1 = op_s;
    string op_s2 = op_s;

    op_s2.push_back(inp_s[0]);
    inp_s.erase(0,1);

    AllsubStrings(inp_s, op_s1);
    AllsubStrings(inp_s, op_s2);
}



int main(){
    string inp_s = "abc";
    string op_s = "";
    AllsubStrings(inp_s, op_s);
    return 0;
}

//
// c
// b
// bc
// a
// ac
// ab
// abc