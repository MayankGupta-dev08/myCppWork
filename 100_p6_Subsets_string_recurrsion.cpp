// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void str_subsets(string ip_str, string op_str){
    if(ip_str.length()==0){
        cout<<"{"<<op_str<<"}"<<endl;
        return;
    }
    string op_str1 = op_str;    // this will remain same, 1st choice of not taking
    string op_str2 = op_str;    // we consider taking for choice 2
    
    op_str2.push_back(ip_str[0]);
    ip_str.erase(ip_str.begin()+0); //reducing the inp_str as we have already taken decision for one char

    str_subsets(ip_str, op_str1);
    str_subsets(ip_str, op_str2);
    return;
}

int main(){

    // inputing only a word, cin enough, no need of getline(cin, inp_str) 
    string inp_str;
    cin>>inp_str;
    
    // Empty string to store output at every stage
    string otp_str = "";
    
    str_subsets(inp_str, otp_str);
    
    return 0;
}