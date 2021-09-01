// write a program to print the values from 1 to n and n to 1 for a given value of n using recurrsion

#include <iostream>
using namespace std;

void print1toN(int n){
    if(n<=0)
        return;
    
    print1toN(n-1);
    cout<<n<<" ";
}

void printNto1(int n){
    if(n<=0)
        return;
        
    cout<<n<<" ";
    printNto1(n-1);
}

int main(){
    int N=7;
    cout<<"printing values from 1 to "<<N<<endl;
    print1toN(N);
    cout<<endl;

    cout<<"printing values from "<<N<<" to 1"<<endl;
    printNto1(N);
    cout<<endl;
    return 0;
}

// printing values from 1 to 7
// 1 2 3 4 5 6 7 
// printing values from 7 to 1
// 7 6 5 4 3 2 1 