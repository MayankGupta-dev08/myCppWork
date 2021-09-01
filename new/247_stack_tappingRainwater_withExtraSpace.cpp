// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

#include<iostream>
#include<stack>
using namespace std;

int tappingRainwater(int arr[], int n){
    int maxL [n];
    maxL[0] = arr[0];
    for (int i = 1; i < n; i++)
        maxL[i] = max(maxL[i-1], arr[i]);
        // 3,3,3,3,3,4

    int maxR [n];
    maxR[n-1] = arr[n-1];
    for (int i = n-1; i >= 0; i--)
        maxR[i] = max(maxR[i+1], arr[i]);
        // 4,4,4,4,4,4
    
    int water[n];
    int cumm_water = 0;
    for (int i = 0; i < n; i++){
        water[i] = min(maxR[i], maxL[i]) - arr[i];
        cumm_water += water[i];
    }
    
    return cumm_water;
}

int main(){
    int arr[] = {3,0,0,2,0,4};
    cout<<"Maximum rainwater that can be tapped: "<<tappingRainwater(arr, 6)<<endl;     //10

    int arr2[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"Maximum rainwater that can be tapped: "<<tappingRainwater(arr2, 12)<<endl;   //6
    return 0;
}