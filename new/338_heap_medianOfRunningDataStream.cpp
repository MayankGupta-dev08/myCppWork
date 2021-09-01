/*Median of Stream of Running Integers
    Given that integers are being read from a data stream. Find the median of all the elements read so far starting from the first integer till the last integer. This is also called the Median of Running Integers. The data stream can be any source of data, for example, a file, an array of integers, input stream etc.
    
    What is Median?
        Median can be defined as the element in the data set which separates the higher half of the data sample from the lower half. In other words, we can get the median element as, when the input size is odd, we take the middle element of sorted data. If the input size is even, we pick an average of middle two elements in the sorted stream.

    Examples: 
        Input: 5 10 15 
        Output: 5, 7.5, 10 
        Explanation: Given the input stream as an array of integers [5,10,15]. Read integers one by one and print the median correspondingly. So, after reading first element 5,median is 5. After reading 10,median is 7.5 After reading 15 ,median is 10.

        Input: 1, 2, 3, 4 
        Output: 1, 1.5, 2, 2.5 
        Explanation: Given the input stream as an array of integers [1, 2, 3, 4]. Read integers one by one and print the median correspondingly. So, after reading first element 1,median is 1. After reading 2,median is 1.5 After reading 3 ,median is 2.After reading 4 ,median is 2.5. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<float> mediansOfRunningDataStream(int arr[], int n){
    vector<float> medians;
    priority_queue<int> maxHeap;    // for left half of the data stream
    priority_queue<int, vector<int>, greater<int>> minHeap; // for right half of the data stream
    
    for(int i=0; i<n; i++){
        // entering the element in mone of the heaps
        if(maxHeap.empty() || arr[i]<maxHeap.top())
            maxHeap.push(arr[i]);
        else
            minHeap.push(arr[i]);
        
        // moving it to the correct heap
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // for calculating the current avg
        if(maxHeap.size()==minHeap.size()){
            float m = (float(maxHeap.top())+float(minHeap.top()))/2;
            medians.push_back(m);
        }
        else if(maxHeap.size()>minHeap.size())
            medians.push_back(maxHeap.top());
        else
            medians.push_back(minHeap.top());
    }
    return medians;
}

int main(){
    int arr[] = {5, 2, 3, 1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<float> mdian = mediansOfRunningDataStream(arr, n);
    for(auto i: mdian)
        cout<<i<<", ";      //5, 3.5, 3, 2.5, 3, 3.5,
    cout<<endl;
    return 0;
}

/*
Running Data         Medians
_______________     ____________
5               ==>         5
2,5             ==>         3.5
2,3,5           ==>         3
1,2,3,5         ==>         2.5
1,2,3,5,6       ==>         3
1,2,3,4,5,6     ==>         3.5
*/