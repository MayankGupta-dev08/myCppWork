// To write a program ..to reduce each eleme tof the array in such a way that it's least value element becomes 0, just higher value becomes 1 and so on till max value element becomes n-1, where n is the size of the element
// {10,16,7,14,5,3,12,9} - orignal
// { 4, 7,2, 6,1,0, 5,3} - ans

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int>p2){
    return (p1.first<p2.first);
}

int main(){

    int arr[] = {10,16,7,14,5,3,12,9};
    vector<pair<int, int>> vec;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // original array
    cout<<"original array\n";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    for (int i = 0; i < n; i++){
        vec.push_back(make_pair(arr[i], i));
    }
    
    // sort() is slightly modified by the use of myCompare
    // myCompare is a comparator which will return 1 if our condition is true
    // it will sort our vector on basis of v[i].first
    sort(vec.begin(), vec.end(), myCompare);
    
    for (int i = 0; i < n; i++)
        arr[vec[i].second] = i;    

    // changed array
    cout<<"final ans array\n";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}