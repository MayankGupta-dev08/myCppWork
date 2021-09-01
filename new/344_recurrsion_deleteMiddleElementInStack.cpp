// delete the middle element of a stack using recurrsion, where the idx of the mid element is (stack.size()/2 +1).
/* stack {top,......, bottom}
    stk {}
        stk.push(0);
        stk.push(1);
        stk.push(2);
        stk.push(3);
        stk.push(4);
        stk.push(5);
    
    Before deleting - 
    stk {5 4 3 2 1 0} -->if stk.size() is even, middle elementIdx = stk.size()/2 +1= 4 --> 2
    After deleting -
    stk {5 4 3 1 0}
    
    Before deleting - 
    stk {5 4 3 2 1} -->if stk.size() is odd, middle elementIdx = stk.size()/2 +1= 3 --> 3
    After deleting -
    stk {5 4 2 1}
*/

#include <iostream>
#include <stack>
using namespace std;

void deleteByRecurrsion(stack<int> &stk, int k){
    if(k==1){
        stk.pop();
        return;
    }
    
    int temp = stk.top();
    stk.pop();
    deleteByRecurrsion(stk, k-1);
    stk.push(temp);
}

void deleteMidElement(stack<int> &stk){
    if(stk.size()==0)
        return;
    
    int midIdx = stk.size()/2 +1;
    deleteByRecurrsion(stk, midIdx);
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

    cout<<"Before deleting ";
    printStack(stk);
    deleteMidElement(stk);
    cout<<"After deleting ";
    printStack(stk);
    return 0;
}

// Before deleting elements of stack-   
// 5 4 3 2 1 0
// After deleting elements of stack-    
// 5 4 3 1 0

// Before deleting elements of stack-
// 5 4 3 2 1 
// After deleting elements of stack-
// 5 4 2 1