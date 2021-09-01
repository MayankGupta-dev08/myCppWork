/*Sum of Elements between k1 smallest and k2 smallest numbers
    Given an array of integers and two numbers k1 and k2. Find the sum of all elements between given two k1’th and k2’th smallest elements of the array. It may  be assumed that all elements of array are distinct.

    Example :
    Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6  
    Output : 26          
            {4, 8, 10, 12, 14, 20, 22}
            3rd smallest element is 10. 6th smallest element is 20.
            Sum of all element between k1 & k2 is 12 + 14 = 26

    Input : arr[] = {1, 3, 12, 5, 15, 11},  k1 = 3,  k2 = 6  
    Output : 23          
            {1, 3, 5, 11, 12, 15}
            3rd smallest element is 5. 6th smallest element is 15.
            Sum of all element between k1 & k2 is 11 + 12 = 23
*/

#include <iostream>
#include <queue>
using namespace std;

long int sumOfElementsBwK1thandK2thSmallest(int arr[], int n, int k1, int k2){
    int ul = max(k1, k2);
    int ll = min(k1, k2);
    if(k1==k2 || ul>n || ll<0)
        return -1;

    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size()>=ul)
            maxHeap.pop();
    }
    long int res=0;
    while(maxHeap.size()>ll){
        res += maxHeap.top();
        maxHeap.pop();
    }
    return res;
}

int main(){
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k1=3, k2=6;
    cout<<sumOfElementsBwK1thandK2thSmallest(arr, n, k1, k2)<<endl; //26

    int arr2[] = {1, 3, 12, 5, 15, 11};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<sumOfElementsBwK1thandK2thSmallest(arr2, n2, k1, k2)<<endl; //23
    return 0;
}