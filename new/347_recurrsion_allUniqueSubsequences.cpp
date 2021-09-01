// To write a program ..to print all unique the subsets/powerset/subsequenses of the given string

#include <iostream>
#include <string>
#include <set>
#include <iterator>
using namespace std;

void str_subsets(string ip_str, string op_str, set<string> &ans){
    if(ip_str.length()==0){
        ans.insert(op_str);
        return;
    }

    str_subsets(ip_str.substr(1), op_str, ans);              //choice1 of not taking
    str_subsets(ip_str.substr(1), op_str+ip_str[0], ans);    //choice2 of taking
}

void printSet(set<string> st){
    set<string>:: iterator i;
    for(i=st.begin(); i!=st.end(); i++)
        cout<<"["<<*i<<"]"<<"\n";
}

int main(){
    string inp_str = "aab";
    string otp_str = "";
    set<string> ans;
    str_subsets(inp_str, otp_str, ans);  
    printSet(ans);  //printing all the possible subsets of inp_str
    return 0;
}

// []
// [a]
// [aa]
// [aab]
// [ab]
// [b]


// *************************************************************************************
// if instead of set we had used vectors to store each subsequence than output had been:- 
// []
// [b]
// [a]
// [ab]
// [a]
// [ab]
// [aa]
// [aab]