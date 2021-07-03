// C++ program to print all permutations with duplicates allowed 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to swap values at two pointers */
void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

/* Function to print permutations of string 
This function takes three parameters: 
1. String 
2. Starting index of the string //left
3. Ending index of the string. //right */

// for swapping we have used a pointer at string as initially it will point at index 0
void permute(char *a, int l, int r) {  
	if (l == r) 
		cout<<a<<endl; 
	else{ 
		for (int i = l; i <= r; i++) { 
			swap((a+l), (a+i)); //combinations
			permute(a, l+1, r); 
			swap((a+l), (a+i)); //backtrack 
		} 
	} 
} 

/* Driver program to test above functions */
int main() 
{ 
	char str[] = "ABC"; 
	int n = strlen(str); 
	permute(str, 0, n-1); 
	return 0; 
}

// ABC
// ACB
// BAC
// BCA
// CBA
// CAB