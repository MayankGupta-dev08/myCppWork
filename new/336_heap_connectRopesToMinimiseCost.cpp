/*Connect Ropes to Minimise the Cost
    There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

    For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
        1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
        2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
        3) Finally connect the two ropes and all ropes have connected.

    Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long int connectRopes2MinimiseCost(int arr[], int n){
    if(n==1)
        return arr[0];
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++)
        minHeap.push(arr[i]);

    long int cost=0;
    while(minHeap.size()>=2){
        int c1 = minHeap.top();
        minHeap.pop();
        int c2 = minHeap.top();
        minHeap.pop();
        cost += c1+c2;
        minHeap.push((c1+c2));
    }
    // minHeap.top()    //length of final rope
    return cost;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Minimum cost of connecting all the ropes: "
        <<connectRopes2MinimiseCost(arr, n)<<endl;      //33

    int arr2[] = {4, 3, 2, 6};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Minimum cost of connecting all the ropes: "
        <<connectRopes2MinimiseCost(arr2, n2)<<endl;    //29

    return 0;
}