//  Write a program to find a unique number in an array where all numbers except one, are present thrice.

#include<iostream>
using namespace std;


bool getBit(int n, int pos){
    return ((n & (1<<pos))!=0); //return one if a set bit at pos for n, otherwise 0
}

int setBit(int n, int pos){
    return (n | (1<<pos));  
}

int uniqueNum(int a[], int n){
    
    int result = 0;

    // Assuming that max an element will be of 62 bit in the array ie of 1<<64 size.
    for (int i = 0; i < 64; i++){
        int sum = 0;
        for (int j = 0; j < n; j++){    //traversing thru each element of the array
            if(getBit(a[j], i)){    
            // for every element of array we will check pos = i and see if set bit or not if yes, them sum++
                sum++;
            }
        }

        // if the sum for a given bit value is not a multiple of three than it is the ans
        if(sum%3 != 0){
            result = setBit(result, i);
        }
    }
    return result;
}

int main(){
    int n = 10;
    int a[] = {1,3,2,3,4,2,1,1,3,2};

    cout<<"Unique number: "<<uniqueNum(a, n)<<endl;
    
    return 0;
}