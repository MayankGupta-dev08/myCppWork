// To write a program ..

#include <iostream>
using namespace std;

// 1 way
void print1(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";    
    }
    cout<<endl;
}

// 2 way
void print2(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";    
    }
    cout<<endl;
}

int main(){
    
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];    
    }
    cout<<endl;
    
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"size:"<<size<<endl;
    // print1(arr, n);
    print2(arr, n);
    return 0;
}