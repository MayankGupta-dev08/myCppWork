/*Print N-bit binary numbers having more 1s than 0s
    Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

    Example 1:
        Input:  N = 2
        Output: 11 10
        Explanation: 11 and 10 have more than or equal 1's than 0's
    
    Example 2:
        Input:  N = 3
        Output: 111 110 101
        Explanation: 111, 110 and 101 have more than or equal 1's than 0's
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int one, int zro, int n, string op, vector<string> &v){
    if((one+zro)==n){
        v.push_back(op);
        return;
    }

    if (one<n)
        solve(one+1, zro, n, op+'1', v);

    if(zro<one && (zro+one<n)) //makes sure that number of 1s are >= 0s in any prefix for N bit binary number
        solve(one, zro+1, n, op+'0', v);

}

vector<string> NBitBinaryWith1sMoreThan0sForAnyPrefixNumber(int n){
    int one=0;     // total no. of opening brackets possible
    int zero=0;    // total no. of closing brackets possible
    vector<string> v;
    string op = "";
    solve(one, zero, n, op, v);
    return v;
}

void printVector(vector<string> ans){
    for(auto i : ans)
        cout<<i<<"\n";
}

int main(){
    int n=3;
    vector<string> ans = NBitBinaryWith1sMoreThan0sForAnyPrefixNumber(n);
    cout<<"**for n=3**"<<endl;
    printVector(ans);

    cout<<"------------"<<endl;
    
    n=5;
    vector<string> ans2 = NBitBinaryWith1sMoreThan0sForAnyPrefixNumber(n);
    cout<<"**for n=5**"<<endl;
    printVector(ans2);
    return 0;
}

// **for n=3**
// 111
// 110
// 101
// ------------
// **for n=5**
// 11111
// 11110
// 11101
// 11100
// 11011
// 11010
// 11001
// 10111
// 10110
// 10101