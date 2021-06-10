/*Find the smallest positive missing number in the given array.
Example: [0, -10, 1, 3, -20], Ans = 2
*/

#include<iostream>
using namespace std;

void missingNum(int a[], int n){
    bool check[n];
    for(int i=0; i<n; i++){
        check[i] = false;
    }
    for(int i=0; i<n; i++){
        if(a[i]>=0){
            check[a[i]] = true;
        }
    }
    for(int i=0; i<n; i++){
        if(check[i]==false){
            cout<<"Smallest positive missing number:"<<i<<endl;
            break; 
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    missingNum(a,n);
    return 0;
}