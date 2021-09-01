// To write a program ..to print all the subsets/powerset/subsequenses of the given string

#include <iostream>
#include <string>
using namespace std;

void str_subsets(string ip_str, string op_str){
    if(ip_str.length()==0){
        cout<<"{"<<op_str<<"}"<<endl;
        return;
    }

    str_subsets(ip_str.substr(1), op_str);              //choice1 of not taking
    str_subsets(ip_str.substr(1), op_str+ip_str[0]);    //choice2 of taking
}

int main(){
    string inp_str = "abcd";
    string otp_str = "";
    str_subsets(inp_str, otp_str);  //printing all the possible subsets of inp_str
    return 0;
}

// {}
// {d}
// {c}
// {cd}
// {b}
// {bd}
// {bc}
// {bcd}
// {a}
// {ad}
// {ac}
// {acd}
// {ab}
// {abd}
// {abc}
// {abcd}