
// Simple CPP program to find MSB for a number n.

#include <iostream>
#include <cmath>
using namespace std;

int MSBitNumber(int n){
	if (n == 0)
		return 0;

	int msb = 0;
	n = n / 2;
	while (n != 0) {
		n = n / 2;
		msb++;
	}

	return msb;
}


int setBitNumber(int n){

	// To find the position of the most significant set bit
	int k = (int)(log2(n));

	// To return the the value of the number with set bit at k-th position
	// return (1 << k);
	return k;
}


// Driver code
int main()
{
	int n = 8;
    int ans = MSBitNumber(n);
    int msb_num = (1 << ans);
	cout<<"msb: "<<ans<<endl;
    cout<<"MSB number: "<<msb_num<<endl<<endl;

    cout<<"MSB: "<<setBitNumber(n)<<endl;
    cout<<"MSB number: "<<(1<<setBitNumber(n));
	return 0;
}