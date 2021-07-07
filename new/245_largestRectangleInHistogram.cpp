#include<iostream>
using namespace std;

int largestRect(int a[], int n){
    int ans=0;
    for (int i = 0; i < n; i++){
        int minh = INT32_MAX;
        for (int j = i; j < n; j++){
            minh = min(a[j], minh);
            int len = j-i+1;
            ans = max(ans, len*minh);
        }
    }
    return ans;
}

int main(){
    int a[] = {2,1,5,6,2,3};
    int n = 6;
    cout<<"Area of largest rectangle in histogram: "<<largestRect(a,n);
    return 0;
}

// Area of largest rectangle in histogram: 10