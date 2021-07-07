// To write a program ..count the number of paths possible in a maze/matrix of nxm, to reach from starting point (1,1) to end point (n x m) using recurrsion 

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int countPathsMaze(int n, int m){

    if (n==1 || m==1)
        return 1;

    return ( countPathsMaze(n-1, m) + countPathsMaze(n, m-1) );
}

int main(){

    int n, m;
    cout<<"Enter the size of the matrix (row col): ";
    cin>>n>>m;
    cout<<"Number of paths: "<<countPathsMaze(n, m)<<endl;
    
    return 0;
}

/*OUTPUT
Enter the size of the matrix (row col): 3 3
Number of paths: 6

Enter the size of the matrix (row col): 4 3
Number of paths: 10

Enter the size of the matrix (row col): 5 1
Number of paths: 1

Enter the size of the matrix (row col): 1 5
Number of paths: 1
*/