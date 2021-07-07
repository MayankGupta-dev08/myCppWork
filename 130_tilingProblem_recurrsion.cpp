// given a 2xn board (2 rows and n columns), and tiles of size (2x1), count the number of ways to tile the given board using these tiles.


//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int tilingWays(int n){
    if (n==1)
        return 1;
    if (n<=0)
        return 0;
    else
        return ( tilingWays(n-1) + tilingWays(n-2) );
        // n-1 for placing vert
        // n-2 for placing horiz

}

int main(){

    int n;
    cout<<"Enter the number columns in the board of size (2xn): ";
    cin>>n;
    cout<<tilingWays(n)<<endl;
    
    return 0;
}

/*Output
Enter the number columns in the board of size (2xn): 4        
3
*/