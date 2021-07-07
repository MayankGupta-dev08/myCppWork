// Write a program for printing the NGR - nearest greater element to right for a given array

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

// brute force approach
// O(n*n)
void nearGreaterElem(vector<int> v){
    vector<int> ans;
    for (int i = 0; i < v.size()-1; i++){
        for (int j = i+1; j < v.size(); j++){
            if(v[j]>v[i]){
                ans.push_back(v[j]);
                break;
            }
            if(v[j]<=v[i] && j==v.size()-1)
                ans.push_back(-1);
        }
    }
    ans.push_back(-1);
    cout<<"Array of NGR-\n";
    for(auto i: ans)
        cout<<i<<" ";
    cout<<"\n";
}

// optimised approach O(n) using stack
void NGR(vector<int> v){
    stack<int> s;
    vector<int> ans;
    for (int i = v.size()-1; i >= 0; i--){
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
    reverse(ans.begin(), ans.end());
    cout<<"Array of NGR-\n";
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

    // nearGreaterElem(v);
    NGR(v);
}

// Enter size of array: 4
// 1 3 2 4
// Array-       
// 1 3 2 4      
// Array of NGR-
// 3 4 4 -1  