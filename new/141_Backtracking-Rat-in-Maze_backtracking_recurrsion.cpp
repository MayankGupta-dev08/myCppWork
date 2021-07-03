// To write a program ..Backtracking - Rat in a Maze

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isSafe(int** arr, int n, int x, int y, int** solArr){
    if (x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratInMaze(int** arr, int n, int x, int y, int** solArr){

    if((x==(n-1)) && (y==(n-1))){       //base condition
        solArr[x][y] =1;                //it will stop when rat reaches endpoint
        return true;
    }

    if(isSafe(arr, n, x, y, solArr)){   //if for x,y is safe
        solArr[x][y]=1;            //for now we are assuming that this will give ans
        if (ratInMaze(arr, n, x+1, y, solArr)){ //moving to next by recurrsion
            return true;
        }
        if (ratInMaze(arr, n, x, y+1, solArr)){ //if by x+1, we don't get than we move y+1
            return true;
        }
        // if we are not able to find the solution from above, ie, both if conditions gets false
        solArr[x][y]=0;     //backtracking
        return false;
    }
    return false;
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    
    // allocating the memory of our array dynamically
    int** arr= new int*[n];
    for(int i=0; i<n; i++){     //now for allocating memory to each 1D array 
        arr[i] = new int[n];
    }   //from this memory of our 2D array will get allocated
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    
    int** solArr= new int*[n];
    for(int i=0; i<n; i++){     //now for allocating memory to each 1D array 
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++){
            solArr[i][j]=0;
        }
    }

    if(ratInMaze(arr, n, 0,0, solArr)){ //if we reach end point then print
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
            cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }        
    }

    return 0;
}

// Input
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1

// Output
// 1 0 0 0 0 
// 1 1 1 1 0 
// 0 0 0 1 0 
// 0 0 0 1 1 
// 0 0 0 0 1
