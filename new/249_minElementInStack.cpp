// important question

// Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

#include<iostream>
#include<stack>
using namespace std;

stack<int> s;   //main stack
int minimum;

void add(int v){
    cout<<"---adding "<<v<<" in stack---\n";
    if(s.empty()){
        minimum = v;
        s.push(v);  //firstly adding in main stack
    }
    else if(v<=minimum){
        s.push((2*v)-minimum);  //pushing flag value
        // thru which we can return back
        minimum = v;    //later updating minimum
    }
    else
        s.push(v);
}

void del(){
    cout<<"---deleting from stack---\n";
    if(s.empty()){
        cout<<"No element to pop!\n";
        return;
    }
    if(s.top()<minimum){    //this means that we have encounterd flag value
        //updating min to get prev min of stack
        minimum = (2*minimum - s.top());
        s.pop();
    }
    else
        s.pop();
}

int topmost(){
    if(s.empty())
        return -1;
    else if(s.top()<minimum)
        return minimum;
    else
        return s.top();
}

int getMin(){
    if(s.empty())
        return -1;
    return minimum;
}

int main(){
    add(18);
    cout<<"Top of stack: "<<topmost()<<endl;
    add(19);
    cout<<"Top of stack: "<<topmost()<<endl;
    add(20);
    cout<<"Top of stack: "<<topmost()<<endl;
    
    cout<<"---------------------------\n";
    cout<<"Minimum in stack: "<<getMin()<<endl;
    
    add(15);
    cout<<"Top of stack: "<<topmost()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;
    add(15);
    cout<<"Top of stack: "<<topmost()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;
    del();
    cout<<"Top of stack: "<<topmost()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;
    del();
    cout<<"Top of stack: "<<topmost()<<endl;
    cout<<"Minimum in stack: "<<getMin()<<endl;

    return 0;
}

// ---adding 18 in stack---
// Top of stack: 18
// ---adding 19 in stack---
// Top of stack: 19
// ---adding 20 in stack---
// Top of stack: 20
// ---------------------------
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