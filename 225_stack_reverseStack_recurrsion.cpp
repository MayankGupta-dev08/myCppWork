// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();  //storing the topmost element
    st.pop();
    insertAtBottom(st, ele);

    st.push(topele);    //pushing it to the top
}

void reverseStack(stack<int> &st){
    if(st.empty())
        return;

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);    //earliest call for this function will be by last ele with empty stack
}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout<<"Original Stack\n";
    display(st);
    
    cout<<"Reversed Stack\n";
    reverseStack(st);
    display(st);
    
    return 0;
}

// Original Stack
// 1 2 3 4 5 
// Reversed Stack
// 5 4 3 2 1