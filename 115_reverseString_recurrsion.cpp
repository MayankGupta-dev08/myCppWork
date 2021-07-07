// To write a program ..reverse a string using reccurrsion

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverse_str(string s){
    if (s.length()==0)      //base case
        return;

    string rest_s = s.substr(1);
    reverse_str(rest_s);
    cout<<s[0];
}

void rev_str(string &s){
    int l =s.length();
    for (int i=0, j=l-1; i<j; j--, i++){
        char c =s[i];
        s[i]=s[j];
        s[j]=c;       
    }
}

int main(){

// By using inbuilt function of header file algorithm
    string s0 = "rishab";
    reverse(s0.begin(), s0.end());
    cout<<s0<<endl;

    string s1 = "123456";
    reverse(s1.begin()+2, s1.begin()+5);    //from index 2 to index 4
    cout<<s1<<endl;

    string st="binod";
    reverse_str(st);    //not changing the string only printing it 
    cout<<endl;
    
    rev_str(st);    //actually reversing it 
    cout<<st<<endl;

    return 0;
}