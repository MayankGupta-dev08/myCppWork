// C++ program to find GCD aka HCF of two numbers
// best approch is through Euclidean's algorithm

#include <iostream>
using namespace std;

// brute force approach
int gcd_brute(int a, int b){
	int ans=1;
	int n = min(a,b);
	for(int i=2; i<=n; i++){
		if(a%i==0 && b%i==0)
			ans=i;
	}
	return ans;
}

// Recursive function to return gcd of a and b
int gcd(int a, int b){
	// Everything divides 0
	if (a == 0)
	return b;
	if (b == 0)
	return a;

	// base case
	if (a == b)
		return a;

	// a is greater
	if (a > b)
		return gcd(a-b, b);
	return gcd(a, b-a);
}

// Using Euclidean's algorithm
	// if (a<b && b!=0) -> GCD(b, a%b) = GCD(b, a)
	// if (a>b && b!=0) -> GCD(b, a%b) = GCD(b, r)
	// if (a>b && b==0) -> return a
int GCD(int a, int b){
	if(b==0)
		return a;

	return GCD(b, a%b);
}

int main(){
	int a = 60, b = 36;
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd_brute(a, b)<<endl;
	cout<<"GCD of "<<3<<" and "<<7<<" is "<<gcd_brute(3, 7)<<endl;
	
	cout<<"GCD of "<<3<<" and "<<12<<" is "<<gcd(3, 12)<<endl;
	cout<<"GCD of "<<10<<" and "<<15<<" is "<<gcd(10, 15)<<endl;
	
	cout<<"GCD of "<<3<<" and "<<12<<" is "<<GCD(12, 3)<<endl;
	cout<<"GCD of "<<10<<" and "<<15<<" is "<<GCD(10, 15)<<endl;
	cout<<"GCD of "<<10<<" and "<<14<<" is "<<GCD(10, 14)<<endl;
	return 0;
}

// GCD of 60 and 36 is 12
// GCD of 3 and 7 is 1
// GCD of 3 and 12 is 3
// GCD of 10 and 15 is 5
// GCD of 3 and 12 is 3
// GCD of 10 and 15 is 5
// GCD of 10 and 14 is 2