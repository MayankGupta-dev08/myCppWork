// To write a program ..


//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 1 Way
const int r = 3;  //global variable for row, (not mandatory)
const int c = 3;  //global variable for col, as complier doesn't give error (mandatory to have a const value)
void func1(int arr[r][c]){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// 2 Way
const int c1 = 3;  //global variable for col, as complier doesn't give error
void func2(int arr[][c1], int r1){
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// 3 Way
void func3(int *arr, int r1, int c1){
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cout<<*( arr+i*c1+j )<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int r0=3, c0=3;
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    
    // func1(arr);
    // func2(arr, r0);
    func3( (int*)arr, r0, c0);
    
    return 0;
}