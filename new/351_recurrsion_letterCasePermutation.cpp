/*Letter Case Permutation
    Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

    Examples:
    Input: S = "a1b2"
    Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

    Input: S = "3z4"
    Output: ["3z4", "3Z4"]

    Input: S = "12345"
    Output: ["12345"]
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
    if(isalpha(ip_str[0])){
        permutationWithCaseChange(ip_str.substr(1), op_str+char(tolower(ip_str[0])), ans);   //choice1
        permutationWithCaseChange(ip_str.substr(1), op_str+char(toupper(ip_str[0])), ans);   //choice2
    }
    else
        permutationWithCaseChange(ip_str.substr(1), op_str+ip_str[0], ans);
}

void printSequence(vector<string> v){
    for(auto i: v)
        cout<<i<<"\n";
}

int main(){
    string inp_str = "a1b2";
    string otp_str = "";
    vector<string> ans;
    permutationWithCaseChange(inp_str, otp_str, ans);  
    printSequence(ans);  //printing all the possible subsets of inp_str
    return 0;
}

// a1b2
// a1B2
// A1b2
// A1B2