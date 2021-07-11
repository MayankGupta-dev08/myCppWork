// Given a binary array nums, return the maximum number of consecutive 1's in the array.

#include<iostream>
using namespace std;

int maxConsecutiveOnes(int nums[], int n){
    int currOnes = 0, maxOnes=0;
    for (int i = 0; i < n; i++){
        if(nums[i]==0)
            currOnes = 0;
        else if(nums[i]==1){
            currOnes++;
            maxOnes = max(currOnes, maxOnes);
        }
    }
    return maxOnes;
}

int main(){

    int arr[] = {1,1,0,1,1,1};
    cout<<maxConsecutiveOnes(arr,6)<<endl;  //3
    int arr2[] = {1,0,1,1,0,1};
    cout<<maxConsecutiveOnes(arr2,6)<<endl; //2
    return 0;
}