#include<bits/stdc++.h>
using namespace std;


// if n is an odd number, just by subtracting 1 we can remove rightmost set bit at it is at index 0
int removeRightmostSetBitFromN(int n){
    return (n & (n-1));
}

int isNPowerOf2(int n){
    if(n==0)
        return 0;

    if((n & (n-1))==0)
        return 1;
    else
        return 0;
}

int main(){
    int n = 14;
    // n=14 --> 1110
    // after removing rightmost set bit --> 1100
    // ans = 12

    int ans = removeRightmostSetBitFromN(n);
    cout<<ans<<endl;    //12
    return 0;
}