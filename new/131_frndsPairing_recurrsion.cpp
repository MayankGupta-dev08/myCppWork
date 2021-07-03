// To write a program ..There are n friends, we have to find all the pairings possible. Each person can be paired with only one person or does not pair with anyone.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int pairingFriends(int n){
    if(n==0 || n==1 || n==2)
        return n;

    else
        return ( pairingFriends(n-1) + pairingFriends(n-2)*(n-1) );
} 

int main(){

    int n;
    cout<<"Enter number of friends: ";
    cin>>n;
    cout<<pairingFriends(n)<<endl;

    return 0;
}

/*Output
Enter number of friends: 4
10
Enter number of friends: 3
4
*/