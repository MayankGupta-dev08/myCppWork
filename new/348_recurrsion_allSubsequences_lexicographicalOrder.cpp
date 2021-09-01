// To write a program ..to print all subsequenses of the given string in lexicographical order. 

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void str_subsets(string ip_str, string op_str, vector<string> &ans){
    if(ip_str.length()==0){
        ans.push_back(op_str);
        return;
    }

    str_subsets(ip_str.substr(1), op_str, ans);              //choice1 of not taking
    str_subsets(ip_str.substr(1), op_str+ip_str[0], ans);    //choice2 of taking
}

void printSubsequence(vector<string> st){
    vector<string>:: iterator i;
    for(i=st.begin(); i!=st.end(); i++)
        cout<<"["<<*i<<"]"<<"\n";
}

int main(){
    string inp_str = "acbd";
    string otp_str = "";
    vector<string> ans;
    str_subsets(inp_str, otp_str, ans);  
    sort(ans.begin(), ans.end());
    printSubsequence(ans);  //printing all the possible subsets of inp_str
    return 0;
}

// []
// [a]
// [ab]
// [abd]
// [ac]
// [acb]
// [acbd]
// [acd]
// [ad]
// [b]
// [bd]
// [c]
// [cb]
// [cbd]
// [cd]
// [d]