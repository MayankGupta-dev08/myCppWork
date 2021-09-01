/*Permutations with space
    Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

    Example 1:
        Input:
        S = "ABC"
        Output: (A B C)(A BC)(AB C)(ABC)
        Explanation:
        ABC
        AB C
        A BC
        A B C
        These are the possible combination of "ABC".
        
    Example 2:
        Input:
        S = "AB"
        Output: (A B)(AB)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void addingSpace(string ip_str, string op_str, vector<string> &ans){
    if(ip_str.length()==0){
        ans.push_back(op_str);
        return;
    }

    addingSpace(ip_str.substr(1), op_str+" "+ip_str[0], ans);    //choice2 of adding space
    addingSpace(ip_str.substr(1), op_str+ip_str[0], ans);        //choice1 of not adding space
}

vector<string> permutationWithSpace(string ip_str, string op_str){
    vector<string> vec;
    addingSpace(ip_str.substr(1), op_str+ip_str[0], vec);
    return vec;
}

void printSequence(vector<string> v){
    for(auto i: v)
        cout<<i<<"\n";
}

int main(){
    string inp_str = "ABC";
    string otp_str = "";
    vector<string> ans = permutationWithSpace(inp_str, otp_str);  
    printSequence(ans);  //printing all the possible subsets of inp_str
    return 0;
}

// A B C
// A BC
// AB C
// ABC