// Brute force method of solving sliding window problem
// order O(nlogn)

#include<iostream>
#include<vector>
#include<set>
#include<functional>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter size of array & window: ";
    cin>>n>>k;
    vector<int> a(n);
    for (auto &i: a)
        cin>>i;
    
    multiset<int, greater<int>> s;
    vector<int> ans;
    for (int i = 0; i < k; i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    for (int i = k; i < n; i++){
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    
    for (auto i: ans)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}

// Enter size of array & window: 8 3
// 1 3 -1 -3 5 3 6 7
// 3 3 5 5 6 7