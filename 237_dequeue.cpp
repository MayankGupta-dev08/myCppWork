#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_front(1);   //1
    dq.push_front(2);   //2 1
    dq.push_back(3);   //2 1 3
    dq.push_back(4);   //2 1 3 4
    for(auto i: dq)
        cout<<i<<" ";
    cout<<"\n";
    dq.pop_back();   //2 1 3
    dq.pop_front();   //1 3
    for(auto i: dq)
        cout<<i<<" ";
    cout<<"\n";

    cout<<"size of dequeue: "<<dq.size()<<endl; //2
}