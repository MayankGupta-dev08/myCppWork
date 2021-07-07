// Write a program for printing the NGL - nearest greater element to left of an element in an array

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

// brute force approach
// O(n*n)
void ngl(vector<int> v){
    vector<int> ans;
    ans.push_back(-1);
    for(int i=0; i<v.size(); i++){
        for (int j = i-1; j>=0; j--){
            if(v[j]>v[i]){
                ans.push_back(v[j]);
                break;
            }
            if(v[j]<=v[i] && j==0)
                ans.push_back(-1);
        }
    }
    cout<<"Array of NGL-\n";
    for(auto i: ans)
        cout<<i<<" ";
    cout<<"\n";
}

// optimised approach O(n) using stack
void NGL(vector<int> v){
    stack<int> s;
    vector<int> ans;
    for (int i=0; i<v.size(); i++){
        if(s.empty())
            ans.push_back(-1);
        else if(!s.empty() && s.top()<=v[i]){
            while(!s.empty() && s.top()<=v[i])
                s.pop();

            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        else
            ans.push_back(s.top());

        s.push(v[i]);
    }

    cout<<"Array of NGL-\n";
    for(auto i: ans)
        cout<<i<<" ";
    cout<<"\n";
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> v(n);
    for(auto &i: v)
        cin>>i;
    
    cout<<"Array-\n";
    for(auto i: v)
        cout<<i<<" ";
    cout<<"\n";

    // ngl(v);
    NGL(v);
}

// Enter size of array: 4
// 1 3 2 4
// Array-
// 1 3 2 4 
// Array of NGL-
// -1 -1 3 -1