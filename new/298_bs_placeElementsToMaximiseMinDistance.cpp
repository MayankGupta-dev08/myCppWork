/*Question related to  binary search

Place k elements such that minimum distance is maximized
    Given an array representing n positions along a straight line. Find k (where k <= n, will be given to you) such elements from the array such that the minimum distance between any two is maximized.

    Examples :  
        Input : arr[] = {1, 2, 8, 4, 9}
                k = 3
        Output : 3
            Largest minimum distance = 3
            3 elements arranged at positions 1, 4 and 8, 
            Resulting in a minimum distance of 3

        Input  : arr[] = {1, 2, 7, 5, 11, 12}
                k = 3
        Output : 5
            Largest minimum distance = 5
            3 elements arranged at positions 1, 7 and 12, resulting in a minimum distance of 5 (between 7 and 12)

    A Naive Solution is to consider all subsets of size 3 and find the minimum distance for every subset. Finally, return   the largest of all minimum distances.

    An Efficient Solution is based on Binary Search. We first sort the array. Now we know maximum possible value result     is arr[n-1] – arr[0] (for k = 2). We do a binary search for maximum result for given k. We start with the middle of     the maximum possible result. If the middle is a feasible solution, we search on the right half of mid. Else we search   is left half. To check feasibility, we place k elements under given mid-distance.
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int arr[], int n, int k, int mid){
    int pos=arr[0], numOfElements=1;

    for (int i = 1; i < n; i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            numOfElements++;
            if(numOfElements==k)
                return true;
        }
    }
    return false;
}

int largestMinimumDisatance(int arr[], int n, int k){
    sort(arr, arr+n);
    int left = 1, right = arr[n-1];
    int ans = -1;

    while(left<right){
        int mid = (left+right)/2;
        if(isFeasible(arr, n, k, mid)){
            ans = max(ans, mid);
            left = mid+1;
        }
        else
            right = mid;
    }

    return ans;
}

int main(){
    int ar[] = {11,2,7,5,1,12};
    int n = sizeof(ar)/sizeof(ar[0]);
    cout<<"largest minimum distance: "<<largestMinimumDisatance(ar, n, 3)<<endl;
    return 0;
}