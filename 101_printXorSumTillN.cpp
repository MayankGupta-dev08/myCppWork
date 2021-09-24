/* In Xor - if odd number of 1s then only result is 1
       - if even number of 1s or only 0s then result is 0 
       
       also - n^n = 0 and 0^n = n
*/

#include <bits/stdc++.h>
using namespace std;

int XorSumTillN(int n){
    if(n%4==0)
        return n;

    if(n%4==1)
        return 1;

    if(n%4==2)
        return n+1;

    else    // if(n%4==3)
        return 0;
}

int main(){
    int n;
    cout<<"enter a number: ";
    cin>>n;
    cout<<"Xor sum till "<<n<<" is = ";
    cout<<XorSumTillN(n)<<endl;
    return 0;
}


/* 
enter a number: 7
Xor sum till 7 is = 0 
*/


/* 
N = 1  -->  XorSum till N = 1
N = 2  -->  XorSum till N = 3
N = 3  -->  XorSum till N = 0
N = 4  -->  XorSum till N = 4
N = 5  -->  XorSum till N = 1
N = 6  -->  XorSum till N = 7
N = 7  -->  XorSum till N = 0
N = 8  -->  XorSum till N = 8
N = 9  -->  XorSum till N = 1 
*/