// To write a program ..to print all the permutations of a given string 
// "abc"  -  {"abc", "acb", "bac", "bca", "cab", "cba"};

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void permutation(string inp_s, string op_s){
    if(inp_s.length()==0){
        cout<<op_s<<endl;
        return;
    }

    for (int i = 0; i < inp_s.length(); i++){
        char ch = inp_s[i];
        string rest_s = inp_s.substr(0, i) + inp_s.substr(i+1);
        permutation(rest_s, op_s+ch);
    }
    
}


int main(){

    permutation("abc", "");
    return 0;
}

// abc
// acb
// bac
// bca
// cab
// cba