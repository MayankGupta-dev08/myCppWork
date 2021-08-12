/*Painter's Partition Problem
    Given an array of integers arr[] of size n, such that ith element of arr represents a board of size arr[i]. Also given number of painters available for job = m.
        A painter paints 1 unit of board in 1 unit of time and each painter will paint  consecutive boards only.
        Find the minimum time that will be required to paint all the boards.

        Example:
            Input:  arr[] = {10,20,30,40}, n=4, m=2
            Output:  60

            Explanaition: Possible partitions-
                [10] [20,30,40] = 90
                [10,20] [30,40] = 70
                [10,20,30] [40] = 60
            So, min time we will be when painter1 paints 60 and painter2 paints 40.
*/

#include <iostream>
#include <climits>
using namespace std;

bool isValid(int arr[], int n, int m, int curr_mx){
    int painterNum=1;
    int currSum=0;
    for (int i = 0; i < n; i++){
        currSum += arr[i];
        if(currSum>curr_mx){
            painterNum++;
            currSum = arr[i];
        }
        if(painterNum>m)
            return false;
    }
    return true;
}

int paintersPartition(int arr[], int n, int m){
    if(n<m)
        return -1;
    
    long sum=0;
    for (int i = 0; i < n; i++)
        sum+=arr[i];

    int start=0, end=sum;
    int result=INT_MAX;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isValid(arr, n, m, mid)){
            result = mid;
            end = mid-1;
        }
        else
            start=mid+1;
    }
    return result;
}

int main(){
    int arr[] = {10, 20, 30, 40};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; //No. of painters

    cout << "Minimum time req for painting = "
         << paintersPartition(arr, n, m) << endl;

    return 0;
}

// Minimum time req for painting = 60