// DYNAMIC MEMORY ALLOCATION
// C++ program to dynamically allocate the memory for 2D array in C++ using new operator.

// Method 1: using a single pointer – In this method, a memory block of size M*N is allocated
//  and then the memory blocks are accessed using pointer arithmetic

#include <iostream>
using namespace std;

void print2Darray(int* arr, int m, int n){
	
	// Traverse the 2D array
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			// Print values of the memory block
			cout<< *(arr + i * n + j)<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	// Dimensions of the 2D array
	int m, n, val;
	cout<<"Enter the size of 2D array: ";
	cin>>m>>n;

	// Declare a memory block of size m*n, which is a pointer array of type int
	int* arr = new int[m * n];
	// Its actually a 1D array of size m*n, but here we want 2D array, so we will use it like 2D. 

	// Traverse the 2D array
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			val = 0;
			cout<<"Enter element "<<i<<j<<": ";
			cin>>val; 

			// Assign values to the memory block
			*(arr + i * n + j) = val;
		}
	}

	print2Darray(arr, m, n);

	//Delete the array created
	delete[] arr;

	return 0;
}

// OUTPUT
// Enter the size of 2D array: 3 3
// Enter element 00: 1
// Enter element 01: 2
// Enter element 02: 3
// Enter element 10: 4
// Enter element 11: 5
// Enter element 12: 6
// Enter element 20: 7
// Enter element 21: 8
// Enter element 22: 9
// 1 2 3 
// 4 5 6 
// 7 8 9