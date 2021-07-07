// To write a program ..for evaluating a postfix expression

//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int postfixEvaluation(string s){
    stack<int> st;
    for (int i = 0; i< s.length(); i++){
        
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');

        else{
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (s[i]){
                case '+': 
                    st.push(operand1+operand2);
                    break;
                case '-': 
                    st.push(operand1-operand2);
                    break;
                case '*': 
                    st.push(operand1*operand2);
                    break;
                case '/': 
                    st.push(operand1/operand2);
                    break;
                case '^': 
                    st.push(pow(operand1, operand2));
                    break;
            }
        }
    }
    return (st.top());
}

int main(){

    cout<<"Postfix Eval. of 46+2/5*7+ -> "<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}

// Postfix Eval. of 46+2/5*7+ -> 32 