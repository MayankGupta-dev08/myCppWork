/*Merge k sorted arrays
    Given k sorted arrays of size n each, merge them and print the sorted output.
    Input: k = 3, n = 4 
        arr[][] = { {1, 3, 5, 7}, 
        {2, 4, 6, 8}, 
        {0, 9, 10, 11}} ;
    Output: 0 1 2 3 4 5 6 7 8 9 10 11 
    
    Approach: Using minHeap 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// <value, <array index, value index>>
typedef pair<int, pair<int, int>> pipii;

vector<int> mergeKSortedArrays(vector<vector<int>> arr){
    vector<int> ans;
    priority_queue<pipii, vector<pipii>, greater<pipii>> minHeap;

    for(int i=0; i<arr.size(); i++)
        minHeap.push({arr[i][0], {i, 0}});

    while(!minHeap.empty()){
        pipii currMin = minHeap.top();
        minHeap.pop();
        ans.push_back(currMin.first);

        int i = currMin.second.first;   // array number
        int j = currMin.second.second;  // value index in the array number
        if(j+1 < arr[i].size())
            minHeap.push({arr[i][j+1], {i, j+1}});
    }
    return ans;
}

void printArray(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int k=3; // k=3 --> 3 arrays
    vector<vector<int>> arr = { {2, 6, 12, 19},
                                {1, 9, 20, 95},
                                {5, 8, 23, 27} };
    cout<<"Merged Sorted array:-\n";
    vector<int> res = mergeKSortedArrays(arr);
    printArray(res);
    return 0;
}

// 1 2 5 6 8 9 12 19 20 23 27 95 