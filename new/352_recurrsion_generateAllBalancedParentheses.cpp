/*Generate all Balanced Parentheses
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

    For example, given n = 3, a solution set is:
    "((()))", "(()())", "(())()", "()(())", "()()()"

    Assumption - only single type of brackets are used - '(' and ')' or '[' and ']' or '{' and '}'.
    Solved using decision tree - key observations are:-
        we have a choice of pushing the '(' in output string in every recurrsion till its count>0 but we can't do the same with  ')' bracket.
        closing bracket will only be pushed in string if its count is grater than the count of opening bracket.
        if count of both have become 0 than we ha ve got one of the answers.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int o, int c, string op, vector<string> &v){
    if(o==0 && c==0){
        v.push_back(op);
        return;
    }

    if (o>0)
        solve(o-1, c, op+'(', v);

    if(c>o) // makes sure that it is balanced parentheses
        solve(o, c-1, op+')', v);

}

vector<string> genBalancedParentheses(int n){
    int open=n;     // total no. of opening brackets possible
    int close=n;    // total no. of closing brackets possible
    vector<string> v;
    string op = "";
    solve(open, close, op, v);
    return v;
}

void printVector(vector<string> ans){
    for(auto i : ans)
        cout<<i<<"\n";
}

int main(){
    int n=3;
    vector<string> ans = genBalancedParentheses(n);
    printVector(ans);
    return 0;
}

// ((()))
// (()())
// (())()
// ()(())
// ()()()