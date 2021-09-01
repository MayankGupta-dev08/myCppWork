/*Balanced Parentheses - Write a program to tell whether a string is a balanced paranthesis or not.

    Algorithm: 
        Declare a character stack S.
        Now traverse the expression string exp. 
        Of the stack is empty and the starting char is closing bracket than it is not balanced.
        If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
        If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else brackets are not balanced.
        After complete traversal, if there is some starting bracket left in stack then “not balanced”
*/

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

void showResult(string s){
    if(isValid(s))
        cout<<s<<" is Balanced Parentheses\n";
    else
        cout<<s<<" is not balanced Parentheses\n";
}

int main(){
    string s1="({[]})";
    string s2="({[])";
    string s3="({[]})]";
    string s4="]({[]})";
    string s5="[()]{}{[()()]()}";

    showResult(s1);
    showResult(s2);
    showResult(s3);
    showResult(s4);
    showResult(s5);
    return 0;
}

// ({[]}) is Balanced Parentheses
// ({[]) is not balanced Parentheses
// ({[]})] is not balanced Parentheses
// ]({[]}) is not balanced Parentheses
// [()]{}{[()()]()} is Balanced Parentheses