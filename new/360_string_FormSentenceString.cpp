/* You are given a string cstr, written in camel case(every word starts with an uppercase letter and there is no space or punctuation between two conssecutive words). The task is to put one space after every word and covert every uppercase letter to lowercase 

    Input-
        cstr = "ThisIsAnAutomationEra"
    Output
        this is an automation era
*/ 

#include <bits/stdc++.h>
using namespace std;

string formSentenceString(string cstr){
    string ans = "";
    ans.push_back(tolower(cstr[0]));
    for (int i = 1; i < cstr.length(); i++){
        if(isupper(cstr[i])){
            ans.push_back(' ');
            ans.push_back(tolower(cstr[i]));
        }
        else{
            ans.push_back(cstr[i]);
        }
    }
    return ans;
}

void changeSentenceString(string &cstr){
    cstr[0] = tolower(cstr[0]);
    for (int i = 1; i < cstr.length(); i++){
        if(isupper(cstr[i])){
            cstr.insert(i, " ");
            i++;
            cstr[i] = tolower(cstr[i]);
        }
    }
}

int main(){
    string cstr = "ThisIsAnAutomationEra";
    cout<<"Original string-\n";
    cout<<cstr<<endl;
    cout<<"Changed string-\n";
    // cout<<formSentenceString(cstr)<<endl;
    changeSentenceString(cstr);
    cout<<cstr<<endl;
    return 0;
}


/* 
Original string-
ThisIsAnAutomationEra
Changed string-
this is an automation era 
*/