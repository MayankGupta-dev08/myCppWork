// reverse a stack using recurrsion.
/* stack {top,......, bottom}
    
    Before reversing - 
    stk {5 4 3 2 1 0}
    After reversing -
    stk {0 1 2 3 4 5}
*/

#include <iostream>
#include <stack>
using namespace std;

// reversing a stack using extra space using another stack
void reverseStack_extraSpace(stack<int> stk, stack<int> &rev_stk){
    while(!stk.empty()){
        rev_stk.push(stk.top());
        stk.pop();
    }
}

void insertAtEndInStack(stack<int> &stk, int temp){
    if(stk.size()==0){
        stk.push(temp);
        return;
    }
    int val = stk.top();
    stk.pop();
    insertAtEndInStack(stk, temp);
    stk.push(val);
}

// reversing a stack without using extra space using recurrsion
void reverseStackRecurrsion(stack<int> &stk){
    if(stk.size()<=1)
        return;

    int temp = stk.top();
    stk.pop();
    reverseStackRecurrsion(stk);
    insertAtEndInStack(stk, temp);
}

void printStack(stack<int> stk){
    cout<<"elements of stack-\n";
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> stk;
    stk.push(0);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    // reversing the stack but not the original one
    cout<<"Before reversing ";
    printStack(stk);
    stack<int> rev_stk;
    reverseStack_extraSpace(stk, rev_stk);
    cout<<"After reversing ";
    printStack(rev_stk);
    cout<<"--------------------------------\n";

    // reversing the original stack without any extra space using recurrsion
    cout<<"Before reversing ";
    printStack(stk);
    reverseStackRecurrsion(stk);
    cout<<"After reversing ";
    printStack(stk);
    return 0;
}

// Before reversing elements of stack-
// 5 4 3 2 1 0 
// After reversing elements of stack-
// 0 1 2 3 4 5 
// --------------------------------
// Before reversing elements of stack-
// 5 4 3 2 1 0 
// After reversing elements of stack-
// 0 1 2 3 4 5