/*
LSB - LEAST SIGNIFICANT BIT - RIGHTMOST BIT - FIRST SET BIT

(n&~(n-1)) always return the binary number containing rightmost set bit as 1.

if N = 12 (1100) then it will return 4 (100) and if did log2 the it will return power or index from left starting from 2

position is starting from 1 and from left to right
index is starting from 0 and from right to left
power of 2 also starts from 0 and from left to right
*/



// C++ program for Position of rightmost set bit
#include <iostream>
#include <math.h>
using namespace std;

int getFirstSetBitPos(int n){
	return log2(n & -n) + 1;
}

int lsb(int n){
    return log2(n & ~(n-1)) + 1;
}

// function to find the rightmost set bit
int PositionRightmostSetbit(int n){
	int position = 1;
	int m = 1;

	while (!(n & m)) {

		// left shift
		m = m << 1;
		position++;
	}
	return position;
}


int main(){
	int n = 12;
	
    cout<<getFirstSetBitPos(n)<<endl;
    
    cout<<lsb(n)<<endl;
	
	cout << PositionRightmostSetbit(n);
    
    return 0;
}