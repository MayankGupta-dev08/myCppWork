/*Find k numbers with most occurrences in the given array
    Given an array of n numbers and a positive integer k. The problem is to find k numbers with most occurrences, i.e., the top k numbers having the maximum frequency. If two numbers have the same frequency then the larger number should be given preference. The numbers should be displayed in decreasing order of their frequencies. It is assumed that the array consists of k numbers with most occurrences.

    Examples: 

        Input: arr[] = {3, 1, 4, 4, 5, 2, 6, 1}, k = 2
        Output: 4 1
        Explanation:
            Frequency of 4 = 2
            Frequency of 1 = 2
            These two have the maximum frequency and 4 is larger than 1.

        Input : arr[] = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}, k = 4
        Output: 5 11 7 10
        Explanation: 
            Frequency of 5 = 3
            Frequency of 11 = 2
            Frequency of 7 = 2
            Frequency of 10 = 1
            These four have the maximum frequency and 5 is largest among rest.

    Algorithm : 
        *   Create a Hashmap hm, to store key-value pair, i.e. element-frequency pair.
        *   Traverse the array from start to end.
        *   For every element in the array update hm[array[i]]++
        *   Store the element-frequency pair in a Priority Queue and create the Priority Queue, this takes O(n) time.
        *   Run a loop k times, and in each iteration remove the top of the priority queue and print the element.
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

// comparator struct is made to do function call operator overloading
// for comparing two elements at a time to create a maxHeap of type priority queue with elements of pair type
// so that comparison can be done on our terms
struct compare{
    bool operator () (pair<int, int> p1, pair<int, int> p2){
        // if freq of two are same than larger one should come first
        if(p1.second==p2.second)
            return p1.first < p2.first;
        else    // freq of both are different
            return p1.second < p2.second;
    }
};

void topK_mostFrequentNumbers(int arr[], int n, int k){
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
        umap[arr[i]]++;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap(umap.begin(), umap.end());

    // dispalying the top k freq numbers
    cout<<"The top "<<k<<" most freq numbers are:\n";
    for (int i = 0; i < k; i++){
        cout<<"Num: "<<maxHeap.top().first<<" -> Freq: "<<maxHeap.top().second<<endl;
        maxHeap.pop();
    }
}

int main(){
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    topK_mostFrequentNumbers(arr, n, k);
    return 0;
}

// The top 2 most freq numbers are:
// Num: 4 -> Freq: 2
// Num: 1 -> Freq: 2