// C++ program to find the LCM of two numbers

#include <iostream>
using namespace std;

// brute force approach
    // problem of integer overflow when a & b are large
int LCM(int a, int b){
    int start = min(a,b);
    for(int i=start; i<=a*b; i++){
        if(i%a==0 && i%b==0)
            return i;
    }
    return -1;
}

int gcd(int a, int b){
    if(b==0)
        return a;

    return gcd(b, a%b);
}

// best approach as a*b = gcd(a,b) * lcm(a,b)
int lcm(int a, int b){
    return (a / gcd(a,b))*b;
}

int main(){
    cout<<"LCM of 02 & 03: "<<lcm(2,3)<<endl;
    cout<<"LCM of 04 & 05: "<<lcm(4,5)<<endl;
    cout<<"LCM of 15 & 25: "<<lcm(15,25)<<endl;
    return 0;
}

// LCM of 02 & 03: 6
// LCM of 04 & 05: 20
// LCM of 15 & 25: 75