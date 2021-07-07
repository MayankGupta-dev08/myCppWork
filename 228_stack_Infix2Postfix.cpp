/*Infix to Postfix
Algorithm 
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.*/

// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c){
    
    if(c == '^')
        return 3;
    
    else if(c == '*' || c == '/')
        return 2;

    else if(c == '+' || c == '-')
        return 1;

    else
        return -1;
}

string infix2Postfix(string s){
    string ans;
    stack<char> stk;

    for (int i = 0; i < s.length(); i++){
        
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            ans += s[i];

        else if(s[i]=='(')
            stk.push(s[i]);
        
        else if(s[i]==')'){
            while(!stk.empty() && stk.top()!='('){
                ans += stk.top();
                stk.pop();
            }//when above condtion gets false - 2 options either '(' is top or empty
            if(!stk.empty())
                stk.pop();
        }

        // now we have to write for s[i] == operator 
        else{
            while(!stk.empty() && precedence(s[i])<=precedence(stk.top())){
                ans += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    // checking if stack is still not empty, after scanning whole infix expression
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

int main(){

    cout<<"Infix: (a-b/c)*(a/k-l) \nto Postfix: "<<infix2Postfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<"-------------------------------------------------\n";
    cout<<"Infix: K+L-M*N+(O^P)*W/U/V*T+Q^J^A \nto Postfix: "<<infix2Postfix("K+L-M*N+(O^P)*W/U/V*T+Q^J^A")<<endl;
    return 0;
}

// Infix: (a-b/c)*(a/k-l) 
// to Postfix: abc/-ak/l-*
// -------------------------------------------------
// Infix: K+L-M*N+(O^P)*W/U/V*T+Q^J^A 
// to Postfix: KL+MN*-OP^W*U/V/T*+QJ^A^+