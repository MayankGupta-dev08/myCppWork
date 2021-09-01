/*Permute a string by changing case
    Print all permutations of a string keeping the sequence but changing cases.
    Examples: 
        Input : ab
        Output : AB Ab ab aB

        Input : ABC
        Output : abc Abc aBc ABc abC AbC aBC ABC
    
    Method 1 (Naive) : Naive approach would be to traverse the whole string and for every character, consider two cases, (1) change case and recur (2) Do not change case and recur.
    Method 2 (Better) For a string of length n there exists 2n maximum combinations. We can represent this as a bitwise operation.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutationWithCaseChange(string ip_str, string op_str, vector<string> &ans){
    if(ip_str.length()==0){
        ans.push_back(op_str);
        return;
    }

    permutationWithCaseChange(ip_str.substr(1), op_str+ip_str[0], ans);   //choice1
    permutationWithCaseChange(ip_str.substr(1), op_str+char(toupper(ip_str[0])), ans);   //choice2
}

void printSequence(vector<string> v){
    for(auto i: v)
        cout<<i<<"\n";
}

int main(){
    string inp_str = "abc";
    string otp_str = "";
    vector<string> ans;
    permutationWithCaseChange(inp_str, otp_str, ans);  
    printSequence(ans);  //printing all the possible subsets of inp_str
    return 0;
}

// ABC
// ABc
// AbC
// Abc
// aBC
// aBc
// abC
// abc