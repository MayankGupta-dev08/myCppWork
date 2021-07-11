// Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.
// Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool redundantParantheses(string s){
    stack<char> st;
    // bool flag = false;
    
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            st.push(s[i]);
        
        else if(s[i] == ')'){
            if(st.empty() || st.top()=='('){
                return true;
            }
            else{
                while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                    st.pop();
                }
                st.pop();   //popping the '(' which was associated with s[i]=')'
            }
        }
    }
    return false;
}

int main(){
    string s1 = "((a+b))";
    cout<<"For - "<<s1<<endl;
    if(redundantParantheses(s1))
        cout<<"Yes - Redundant Parantheses!\n";
    else
        cout<<"No  - Redundant Parantheses!\n";
    cout<<"-------------------------------\n";
    
    string s2 = "(a+(b)/c)";
    cout<<"For - "<<s2<<endl;
    if(redundantParantheses(s2))
        cout<<"Yes - Redundant Parantheses!\n";
    else
        cout<<"No  - Redundant Parantheses!\n";
    cout<<"-------------------------------\n";
    
    string s3 = "(a+b*(c-d))";
    cout<<"For - "<<s3<<endl;
    if(redundantParantheses(s3))
        cout<<"Yes - Redundant Parantheses!\n";
    else
        cout<<"Not - Redundant Parantheses!\n";
    
    return 0;
}

// For - ((a+b))
// Yes - Redundant Parantheses!
// -------------------------------
// For - (a+(b)/c)
// Yes - Redundant Parantheses!
// -------------------------------
// For - (a+b*(c-d))
// Not - Redundant Parantheses!