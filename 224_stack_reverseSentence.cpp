// / To write a program ..for showing implementation of a stack using array

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverseSentance(string s){
    stack<string> st;

    for (int i = 0; i < s.length(); i++){
        string word = "";
        while(s[i]!=' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){

    string s = "Hey, how are you doing?";
    cout<<s<<endl;          //Hey, how are you doing?
    reverseSentance(s);     //doing? you are how Hey,
    return 0;
}