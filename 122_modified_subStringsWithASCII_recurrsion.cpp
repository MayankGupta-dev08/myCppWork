// To write a program ..to generate all the substrings of a string

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void subStrings_ASCII(string inp_s, string op_s){
    
    if (inp_s.length()==0){
        cout<<op_s<<endl;
        return;
    }
    
    // string op_s1 = op_s; no need of this also, we can directly use op_s instead for choice 1
    string op_s2 = op_s;
    string op_s3 = op_s;
    int ascii = inp_s[0];

    op_s2.push_back(inp_s[0]);
    op_s3.append(to_string(ascii));
    inp_s.erase(0,1);

    subStrings_ASCII(inp_s, op_s);      // choice 1 
    subStrings_ASCII(inp_s, op_s2);     // choice 2
    subStrings_ASCII(inp_s, op_s3);     // choice 3
}



int main(){
    string inp_s = "ABC";
    string op_s = "";
    subStrings_ASCII(inp_s, op_s);

    return 0;
}

/*-------------OUTPUT-------------
        //Empty string
C
67
B
BC
B67
66
66C
6667
A
AC
A67
AB
ABC
AB67
A66
A66C
A6667
65
65C
6567
65B
65BC
65B67
6566
6566C
656667
*/