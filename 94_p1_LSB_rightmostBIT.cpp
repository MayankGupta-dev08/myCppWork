/*
LSB - LEAST SIGNIFICANT BIT - RIGHTMOST BIT - FIRST SET BIT

(n&~(n-1)) always return the binary number containing rightmost set bit as 1.

if N = 12 (1100) then it will return 4 (100) and if did log2 the it will return power or index from left starting from 0, in this case it will return 2 = log2(100)

position is starting from 1 and from right to left		<----
index is starting from 0 and from right to left			<----
power of 2 also starts from 0 and from right to left    <----
*/



// C++ program for Position of rightmost set bit
#include <iostream>
#include <math.h>
using namespace std;

int getFirstSetBitPos(int n){
	return log2(n & -n) + 1;
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

// best
int lsb(int n){	//we are returning the actual index value of lsb or rightmost set bit
    return log2(n & ~(n-1));
}

int main(){
	int n = 12;	//1100
	
	// position we consider starts from 1, so ...4,3,2,1
    cout<<getFirstSetBitPos(n)<<endl;	//3
	cout << PositionRightmostSetbit(n)<<endl;	//3
    
	// index we consider starts from 0, so ...3,2,1,0
    cout<<lsb(n)<<endl;	//2
    return 0;
}