/*Print the elements of an array in the decreasing frequency, if 2 numbers have same frequency then print the one which came first.

    Example:

        Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
        Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

        Input : arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
        Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct compare{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        if(p1.second==p2.second)
            return false;
        else
            return p1.second<p2.second;
    }
};

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void frquencySort(int arr[], int n){
    unordered_map<int, int> umap;
    for(int i=0; i<n; i++)
        umap[arr[i]]++;
    
    pq maxHeap(umap.begin(), umap.end());   //klogk or nlogn
    
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

    int arr2[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    frquencySort(arr2, n2);

    return 0;
}

// 8, 8, 8, 2, 2, 5, 5, 6       --> req o/p
// 8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999  --> req o/p

// 8 8 8 2 2 5 5 6
// 8 8 8 2 2 5 5 9999999 -1 6