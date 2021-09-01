// Sort an array using recurrsion. Time complexity is greater than other sorting methods but just to understand the implementation of recurrsion, doing this thing.

#include <iostream>
#include <vector>
using namespace std;

void insertByRecurrsion(vector<int> &arr, int val){
    if(arr.size()==0 || arr[arr.size()-1]<=val){
        arr.push_back(val);
        return;
    }
    
    int temp = arr[arr.size()-1];
    arr.pop_back();
    insertByRecurrsion(arr, val);
    insertByRecurrsion(arr, temp);
}

void sortByRecurrsion(vector<int> &arr){
    if(arr.size()==1)
        return;
    
    int lastVal = arr[arr.size()-1];
    arr.pop_back();
    sortByRecurrsion(arr);
    insertByRecurrsion(arr, lastVal);
}

void printVector(vector<int> arr){
    cout<<"elements of vector-\n";
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(3);

    cout<<"Before sorting ";
    printVector(arr);
    sortByRecurrsion(arr);
    cout<<"After sorting ";
    printVector(arr);
    return 0;
}

// Before sorting elements of vector-
// 1 5 0 2 4 3 
// After sorting elements of vector-
// 0 1 2 3 4 5 