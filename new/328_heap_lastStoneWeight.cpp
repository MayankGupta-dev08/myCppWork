/*Last Stone Weight
    You are given an array of integers stones where stones[i] is the weight of the ith stone.

    We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
    At the end of the game, there is at most one stone left.

    Return the smallest possible weight of the left stone. If there are no stones left, return 0.

    Example 1:
        Input: stones = [2,7,4,1,8,1]
        Output: 1
        Explanation: 
            We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
            we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
            we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
            we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
    
    Example 2:
        Input: stones = [1]
        Output: 1
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// instead of writing whole line now we can use pq
#define pq priority_queue<int, vector<int>>

// time complexity of this will be O(nlogn)
int lastStoneWeight(pq maxHeap){
    while(maxHeap.size()>1){
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();
        int res = (x>=y)? (x-y) : (y-x);
        if(res!=0)
            maxHeap.push(res); 
    }
    if(maxHeap.size()<1)
        return 0;

    return maxHeap.top();
}

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    // for (int i = 0; i < sizeof(stones)/sizeof(stones[0]); i++)
    //     maxHeap.push(stones[i]);
    pq maxHeap(stones.begin(), stones.end());    

    // while(!maxHeap.empty()){
    //     cout<<maxHeap.top()<<" ";
    //     maxHeap.pop();
    // }

    cout<<"Last stone weight is: "
        <<lastStoneWeight(maxHeap);
    return 0;
}