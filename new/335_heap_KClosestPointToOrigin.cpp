/*K Closest Points to Origin
Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.
Note: The distance between two points on a plane is the Euclidean distance.

    Examples: 

        Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2
        Output : [[3, 3], [-2, 4]]
        Square of Distance of origin from this point is 
        (3, 3) = 18
        (5, -1) = 26
        (-2, 4) = 20
        So rhe closest two points are [3, 3], [-2, 4].

        Input : point = [[1, 3], [-2, 2]], K  = 1
        Output : [[-2, 2]]
        Square of Distance of origin from this point is
        (1, 3) = 10
        (-2, 2) = 8 
        So the closest point to origin is (-2, 2)
*/

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

// first = (x*x + y*y), second.first = x, second.second = y
typedef pair<int, pair<int, int>> pipii;

void kClosestPoints2Origin(int points[][2], int r, int k){
    priority_queue<pipii, vector<pipii>> maxHeap;
    for(int i=0; i<r; i++){
        int d = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
        maxHeap.push({d, {points[i][0], points[i][1]}});
        if(maxHeap.size()>k)
            maxHeap.pop();
    }
    while(!maxHeap.empty()){
        cout<<"("<<maxHeap.top().second.first<<", "<<maxHeap.top().second.second<<") ";
        maxHeap.pop();
    }
    cout<<endl;
}

int main(){
    int points[3][2] = {{3,3}, {5,-1}, {-2,4}};
    int k = 2;
    kClosestPoints2Origin(points, 3, k);    //(-2, 4) (3, 3)


    int pts[4][2] = {{1,3}, {-2,2}, {5,8}, {0,1}};
    kClosestPoints2Origin(pts, 4, k);       //(-2, 2) (0, 1)
    return 0;
}