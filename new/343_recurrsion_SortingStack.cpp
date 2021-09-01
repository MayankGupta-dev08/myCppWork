// Sort a stack using recurrsion.
/* stack {top,......, bottom}
    stk {}
        stk.push(1);
        stk.push(5);
        stk.push(0);
        stk.push(2);
        stk.push(4);
        stk.push(3);
    
    Before sorting - 
    stk {3 4 2 0 5 1} --> stk.top() = 3 
    After Sorting -
    stk {5 4 3 2 1 0} --> stk.top() = 5 
*/

#include <iostream>
#include <stack>
using namespace std;

void insertByRecurrsion(stack<int> &stk, int val){
    if(stk.size()==0 || stk.top()<=val){    //curr in desc order //if reverse order is req, use opp sign
        stk.push(val);
        return;
    }
    
    int temp = stk.top();
    stk.pop();
    insertByRecurrsion(stk, val);
    insertByRecurrsion(stk, temp);
}

void sortByRecurrsion(stack<int> &stk){
    if(stk.size()==1)
        return;
    
    int lastVal = stk.top();
    stk.pop();
    sortByRecurrsion(stk);
    insertByRecurrsion(stk, lastVal);
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
    stk.push(1);
    stk.push(5);
    stk.push(0);
    stk.push(2);
    stk.push(4);
    stk.push(3);

    cout<<"Before sorting ";
    printStack(stk);
    sortByRecurrsion(stk);
    cout<<"After sorting ";
    printStack(stk);
    return 0;
}

// Before sorting elements of stack-
// 3 4 2 0 5 1 
// After sorting elements of stack-
// 5 4 3 2 1 0