/*Check if a subarray of size K exists whose elements form a number divisible by x
    Given an array arr[], of size N and a positive integer K, the task is to find a subarray of size K whose element's sum is divisible by 3. If no such subarray exists, then print -1.

        Examples: 

        Input: arr[] = {84, 23, 45, 12, 56, 82}, K = 3 
        Output: 12, 56, 82 
        Explanation: 
        Number formed by the subarray {12, 56, 82} is 150, which is divisible by 3.

        Input: arr[] = {84, 23, 45, 14 56, 82}, K = 3 
        Output : -1
*/

#include <iostream>
#include <climits>
using namespace std;

void printNums(int arr[], int s, int e){
    for (int i = s; i <= e; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void numFormedFromSubarrayK_DivByX(int arr[], int n, int k, int x){
    int flag=0;
    for (int i = 0; i < n-k+1; i++){
        int sum=0;
        for (int j = i; j < i+k; j++){
            sum += arr[j];
            if(j-i+1==k && sum%x==0){
                cout<<sum<<endl;
                printNums(arr, i, j);
                flag++;
            }
        }
    }
    if(flag==0)
        cout<<"-1\n";
}

void numFormedFromSubArrayK_DivByX(int arr[], int n, int k, int x){
    int i=0, j=0, sum=0, flag=0;
    while(j<n){
        sum += arr[j];
        if(j-i+1==k){
            if(sum%x==0){
                cout<<sum<<endl;
                printNums(arr, i, j);
                flag++;
            }
            sum -= arr[i];
            i++;
        }
        j++;
    }
    if(flag==0)
        cout<<"-1\n";
}

int main(){
    int arr[] = {84, 23, 45, 12, 56, 82};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3, div = 3;

    cout<<"Number formed from subaaray of size "<<k
        <<" and divisible by "<<div<<": ";
    numFormedFromSubarrayK_DivByX(arr, n, k, div);    //150
    
    cout<<"Number formed from subaaray of size "<<k
        <<" and divisible by "<<div<<": ";
    numFormedFromSubArrayK_DivByX(arr, n, k, div);    //150
    return 0;
}

// Number formed from subaaray of size 3 and divisible by 3: 150
// 12 56 82 

// Number formed from subaaray of size 3 and divisible by 3: 150
// 12 56 82