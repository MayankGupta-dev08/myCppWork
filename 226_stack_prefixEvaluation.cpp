// To write a program ..for evaluating a prefix expression
// pre fix expression example = "/52"
    // untill i>=0
    // start iterating from index = arr.length-1
    // push in stack untill an a nondigit char
    // pop 2 elements from stack 
    // oprand1 = st.top(); st.pop();
    // oprand2 = st.top(); st.pop();
    // ans = oprand1 exp oprand2
    // push ans

/* trick to remember - postfix --> -ab = a-b
    pre -->jo pehle pop hua hai stack se vo oprand1*/


//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int prefixEvaluation(string s){
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--){
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');

        else{
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            switch (s[i])
            {
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

    cout<<"Prefix Eval. of -+7*45+20 -> "<<prefixEvaluation("-+7*45+20")<<endl;
    return 0;
}

// Prefix Eval. of -+7*45+20 -> 25