// DYNAMIC MEMORY ALLOCATION
// C++ program to dynamically allocate the memory for 3D array in C++ using new operator

// Method 2: using an array of pointer: Here an array of pointers is created and then to each memory block.

#include <iostream>
using namespace std;

void print2Darray(int** a, int m, int n){
	
	// Traverse the 2D array
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			// Print the values of memory blocks created
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	// Dimensions of the 2D array
	int m, n, val;
	cout<<"Enter the size of 2D array: ";
	cin>>m>>n;

	// Declare memory block of size m for rows
	int** a = new int*[m];

	for (int i = 0; i < m; i++){
		// Declare a memory block of size n for columns
		a[i] = new int[n];
	}

	// Traverse the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			val=0;
			cout<<"Enter element "<<i<<j<<": ";
			cin>>val;
			
			// Assign values to the memory blocks created
			a[i][j] = val;
		}
	}

	print2Darray(a, m, n);

	//Delete the array created
	for(int i=0;i<m;i++) 
		delete [] a[i];		//To delete the inner arrays
	
	delete [] a;	//To delete the outer array which contained the pointers of all the inner arrays
	
	return 0;
}

// OUTPUT
// Enter the size of 2D array: 3 3
// Enter element 00: 10
// Enter element 01: 20
// Enter element 02: 30
// Enter element 10: 40
// Enter element 11: 50
// Enter element 12: 60
// Enter element 20: 70
// Enter element 21: 80
// Enter element 22: 90
// 10 20 30 
// 40 50 60
// 70 80 90