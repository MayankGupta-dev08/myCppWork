// Write a program for stock span problem - consecutive smaller or equal to element

#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

// concept of NGL will be used
vector<int> stockSpan(vector<int> v){
    stack<pair<int, int>> st;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++){
        if(st.empty())
            ans.push_back(-1);
        else if(!st.empty() && st.top().first<= v[i]){
            while(!st.empty() && st.top().first<= v[i]){
                st.pop();
            }
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top().second);
        }
        else
            ans.push_back(st.top().second);
        
        st.push({v[i], i});
    }
    for (int i = 0; i < v.size(); i++){
        ans[i] = i-ans[i];
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> v(n), ans(n);
    cout<<"Array-\n";
    for(auto &i: v)
        cin>>i;

    ans = stockSpan(v);
    cout<<"Solution for stock span problem-\n";
    for(auto i: ans)
        cout<<i<<" ";
    cout<<"\n";
}

// Enter size of array: 7
// Array-
// 100 80 60 70 60 75 85
// Solution for stock span problem-        
// 1 1 1 2 1 4 6 