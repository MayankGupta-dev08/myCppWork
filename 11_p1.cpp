// Print all numbers from 1 to 100 except those of multiple of 3.

#include<iostream>
using namespace std;

int main(){
    
    for (int i =0; i<=100; i++){

        if (i%3==0){
            continue;
        }
        
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}