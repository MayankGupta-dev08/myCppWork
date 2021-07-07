#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            st.push(s[i]);

        else if((s[i]==')' || s[i]==']' || s[i]=='}') && st.empty())
            return false;

        else if(!st.empty() && s[i]==')'){
            if(st.top()=='(')
                st.pop();
            else
                return false;
        }

        else if(!st.empty() && s[i]==']'){
            if(st.top()=='[')
                st.pop();
            else
                return false;
        }

        else if(!st.empty() && s[i]=='}'){
            if(st.top()=='{')
                st.pop();
            else
                return false;
        }
    }
    if(!st.empty())
        return false;
    
    return true;
}

int main(){
    string s1="({[]})";
    string s2="({[])";
    string s3="({[]})]";
    string s4="]({[]})";
    string s5="[()]{}{[()()]()}";

    if(isValid(s1))
        cout<<"s1 - Balanced Paranthesis\n";
    else
        cout<<"s1 - Not balanced Paranthesis\n";

    if(isValid(s2))
        cout<<"s2 - Balanced Paranthesis\n";
    else
        cout<<"s2 - Not balanced Paranthesis\n";

    if(isValid(s3))
        cout<<"s3 - Balanced Paranthesis\n";
    else
        cout<<"s3 - Not balanced Paranthesis\n";

    if(isValid(s4))
        cout<<"s4 - Balanced Paranthesis\n";
    else
        cout<<"s4 - Not balanced Paranthesis\n";

    if(isValid(s5))
        cout<<"s5 - Balanced Paranthesis\n";
    else
        cout<<"s5 - Not balanced Paranthesis\n";
    return 0;
}