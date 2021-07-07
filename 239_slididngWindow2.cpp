// optimised method of solving sliding window problem

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter size of array & window: ";
    cin>>n>>k;
    vector<int> a(n);
    for (auto &i: a)
        cin>>i;
    
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < k; i++){
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    ans.push_back(a[dq.front()]);
    for (int i = k; i < n; i++){
        if(dq.front()==i-k)
            dq.pop_front();
        
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }
    
    for (auto i: ans)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}

// Enter size of array & window: 8 3
// 1 3 -1 -3 5 3 6 7
// 3 3 5 5 6 7 