/*Print the elements of an array in the decreasing frequency, if 2 numbers have same frequency then print the one which came first.

Example:
Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6}
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <vector>
#include<algorithm>
using namespace std;

// first = idx , second.first = num , second.second = freq
typedef pair<int, pair<int, int>> pipii;

struct compare{
    bool operator()(pipii p1, pipii p2){
        if(p1.second.second==p2.second.second)
            return p1.first>p2.first;   // num with small idx first if freq is same
        else
            return p1.second.first<p2.second.first; //num with large freq first
    }
};

typedef priority_queue<pipii, vector<pipii>, compare> pq;

void frquencySort(int arr[], int n){
    unordered_map<int, int> umap;
    vector<pair<int, int>> nums;
    for(int i=0; i<n; i++)
        umap[arr[i]]++;
    
    copy(umap.begin(), umap.end(), back_inserter(nums));
    
    
    
    pq maxHeap;   //klogk or nlogn
    for()
    
    while(!maxHeap.empty()){
        for(int i=0; i<maxHeap.top().second; i++)
            cout<<maxHeap.top().first<<" ";
        maxHeap.pop();
    }
    cout<<endl;
}

int main(){
    int arr[] = {2, 5, 2, 8, 5, 6, 8, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    frquencySort(arr, n);

    // int arr2[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    // int n2 = sizeof(arr2)/sizeof(arr2[0]);
    // frquencySort(arr2, n2);

    return 0;
}

// 8 8 8 2 2 5 5 6
// 8, 8, 8, 2, 2, 5, 5, 6

// 8 8 8 2 2 5 5 9999999 -1 6
// 8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999
