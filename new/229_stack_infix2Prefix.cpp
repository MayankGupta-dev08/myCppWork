// To write a program ..for conerting infix expression to prefix
/*Algo-
-   same as infix to postfix, with few minor changes
1.  reverse the given string before the conversion and after it also
2.  while converting using algo of infix to postfix, just by replacing '(' with ')' symbol and vice versa.
*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int preced(char c){
    if(c=='^')
        return 3;
    
    else if(c=='*' || c=='/')
        return 2;

    else if(c=='+' || c=='-')
        return 1;
    
    else
        return -1;
}

string infix2Prefix(string s){
    stack<char> st;
    string ans;

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++){
        
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            ans += s[i];

        else if(s[i]==')')  //instead of '(' as in postfix
            st.push(s[i]);

        else if(s[i]=='('){  //instead of ')' as in postfix
            while(!st.empty() && st.top()!=')'){
                ans += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else{
            while(!st.empty() && preced(s[i])<=preced(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    // while stack is still not empty but for loop is over
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    cout<<"Infix: (a-b/c)*(a/k-l) \nto Prefix: "<<infix2Prefix("(a-b/c)*(a/k-l)")<<endl;
    cout<<"-------------------------------------------------\n";
    cout<<"Infix: K+L-M*N+(O^P)*W/U/V*T+Q^J^A \nto Prefix: "<<infix2Prefix("K+L-M*N+(O^P)*W/U/V*T+Q^J^A")<<endl;
    return 0;
}

// Infix: (a-b/c)*(a/k-l) 
// to Prefix: *-a/bc-/akl
// -------------------------------------------------
// Infix: K+L-M*N+(O^P)*W/U/V*T+Q^J^A 
// to Prefix: +K-L+*MN+*^OP/W/U*VT^Q^JA