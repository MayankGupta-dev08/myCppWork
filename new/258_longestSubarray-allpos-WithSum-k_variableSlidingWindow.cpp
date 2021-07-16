/*Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
Example 1:
    Input :
        A[] = {10, 5, 2, 7, 1, 9} and K = 15
        Output : 4
    Explanation:
        The sub-array is {5, 2, 7, 1}.
Example 2:
    Input :
        B[] = {4,1,1,1,2,3,5} and K = 5
        Output : 4
    Explanation:
        The sub-array is {1,1,1,2}.
*/

#include <iostream>
using namespace std;

// array has only positive numbers
int longestSubarrayOfSum_K(int arr[], int n, long sum){
    int len=0, currSum=0; //len is window size which has to be maximised for given sum
    int i=0, j=0;
    while(j<n){
        currSum = currSum+arr[j];
        if(currSum>sum){
            while(currSum>sum){
                currSum = currSum-arr[i];
                i++;
            }
        }
        if(currSum==sum){
            len = max(len, j-i+1);  //j-i+1 = window size
        }
        j++;
    }
    return len;
}

int main(){
    int a[] = {4,1,1,1,2,3,5};
    int n = sizeof(a)/sizeof(a[0]);
    long sum = 5;
    cout<<longestSubarrayOfSum_K(a,n,sum)<<endl;    //4
    
    int b[] = {-5, 8, -14, 2, 4, 12};
    n = sizeof(b)/sizeof(b[0]);
    sum = -5;
    cout<<longestSubarrayOfSum_K(b,n,sum)<<endl;    //4
    return 0;
}
 