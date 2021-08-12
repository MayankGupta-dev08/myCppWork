/*Program for nth Catalan Number
    Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

        #   Count the number of possible Binary Search Trees with n keys
        #   Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
        #   Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
        #   Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.

    The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, … 

    Remember:
        C0 = 1
        C1 = 1
        C2 = C0C1 + C1C0 = 1*1 + 1*1 = 2
        C3 = C0C2 + C1C1 + C2C0 = 1*2 + 1*1 + 2*1 = 5
        and so on....
*/

#include <iostream>
using namespace std;

// A recursive function to find nth catalan number
unsigned long int catalan(unsigned int n){
	if (n <= 1)
		return 1;

	// catalan(n) is sum of catalan(i)*catalan(n-i-1)
	unsigned long int res = 0;
	for (int i = 0; i < n; i++)
		res += catalan(i) * catalan(n-1-i);

	return res;
}
// Time complexity of above implementation is equivalent to nth catalan number.
// The value of nth catalan number is exponential that makes the time complexity exponential.

int main(){
    cout<<"First 10 catalan numbers:-\n";
	for (int i = 0; i < 10; i++)
		cout << catalan(i) << " ";
	cout<<"\n";
    return 0;
}

// First 10 catalan numbers:-
// 1 1 2 5 14 42 132 429 1430 4862