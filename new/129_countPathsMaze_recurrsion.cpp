// To write a program ..count the number of paths possible for a maze of nxn, to reach from starting point (0,0) to end point (n-1 x n-1) using recurrsion 

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// h -> horizontal movement
// v -> vertical movement
int countPathsMaze(int n, int h, int v){
    // when starting from (0,0)

    if (h==n-1 || v==n-1){
        return 1;
    }
    if (h>=n || v>=n){
        return 0;
    }
    else    
        return ( countPathsMaze(n,h+1,v)+countPathsMaze(n,h,v+1) );
}

// int countPathsMaze(int n, int h, int v){
    // When starting from (1,1)

//     if (h==n || v==n){
//         return 1;
//     }
//     if (h>n || v>n){
//         return 0;
//     }
//     else    
//         return ( countPathsMaze(n,h+1,v)+countPathsMaze(n,h,v+1) );
// }

int main(){

    int n;
    cout<<"Enter value of s pt and e pt: ";
    cin>>n;
    cout<<"Number of paths: "<<countPathsMaze(n,0,0)<<endl;
    // cout<<"Number of paths: "<<countPathsMaze(n,1,1)<<endl; //When starting from (1,1)
    
    return 0;
}

/*OUTPUT
Enter value of s pt and e pt: 3
Number of paths: 6
*/