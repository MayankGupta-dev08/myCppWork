// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

#include<iostream>
#include<stack>
using namespace std;

int tappingRainwater(int arr[], int n){
    int left = 0;
    int right = n-1;
    int result = 0, left_max = 0, right_max = 0;

    while(left <= right){

        if(left_max <= right_max){
            result += max(0, left_max - arr[left]);
            left_max = max(left_max, arr[left]);
            left++;
        }
        else {
            result += max(0, right_max - arr[right]);
            right_max = max(right_max, arr[right]);
            right--;
        }
    }
    return result;
}

int main(){
    int arr[] = {3,0,0,2,0,4};
    cout<<"Maximum rainwater that can be tapped: "<<tappingRainwater(arr, 6)<<endl;     //10

    int arr2[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"Maximum rainwater that can be tapped: "<<tappingRainwater(arr2, 12)<<endl;   //6
    return 0;
}