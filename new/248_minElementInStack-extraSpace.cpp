// implementing minimum element in stack using extra space
// Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc

#include<iostream>
#include<stack>
using namespace std;

stack<int> s;   //main stack
stack<int> ss;  //supporting stack

void add(int v){
    cout<<"---adding "<<v<<" in stack---\n";
    s.push(v);  //firstly adding in main stack

    if(ss.empty() || v<=ss.top()){
        ss.push(v);
    }
}

int del(){
    cout<<"---deleting from stack---\n";
    if(s.empty()){
        cout<<"No element to pop!\n";
        return -1;
    }
    
    int ans = s.top();
    s.pop();
    if(ans==ss.top())
        ss.pop();
    
    return ans;
}

int getMin(){
    if(ss.empty())
        return -1;
    return ss.top();
}

int main(){
    add(18);
    cout<<"Top of stack: "<<s.top()<<endl;
    add(19);
    cout<<"Top of stack: "<<s.top()<<endl;
    add(20);
    cout<<"Top of stack: "<<s.top()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;
    add(15);
    cout<<"Top of stack: "<<s.top()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;
    add(15);
    cout<<"Top of stack: "<<s.top()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;
    del();
    cout<<"Top of stack: "<<s.top()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;
    del();
    cout<<"Top of stack: "<<s.top()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;

    return 0;
}

// ---adding 18 in stack---
// Top of stack: 18        
// ---adding 19 in stack---
// Top of stack: 19        
// ---adding 20 in stack---
// Top of stack: 20        
// Minimum in stack: 18    
// ---adding 15 in stack---
// Top of stack: 15        
// Minimum in stack: 15    
// ---adding 15 in stack---
// Top of stack: 15    
// Minimum in stack: 15
// ---deleting from stack---
// Top of stack: 15
// Minimum in stack: 15
// ---deleting from stack---
// Top of stack: 20
// Minimum in stack: 18