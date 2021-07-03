/* C++ program to solve n Queen Problem using backtracking */
// Finding the position of n Queens to be placed on a n*n board such that no two queens attack one another.
    // 1.   No two queens can be in one row
    // 2.   No two queens can be in one column
    // 3.   No two queens can be diaginal to each other

// Please note that there may be more than one solutions, this program prints one of the feasible solutions.
// Apart from the solution which we give one could be the mirror image of what we give. 

#include <iostream>
using namespace std;

void printSolArray(int** board, int n){
	cout<<"Solution matrix for the nQueen Problem"<<endl;
    for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout<<board[i][j]<<" ";
    cout<<endl;
    }
}

bool isSafe(int** board, int n, int row, int col){

	/* Check this col on for all rows */
	for (int i = 0; i < row; i++)
		if (board[i][col]==1)		//because we can't use that col than
			return false;
	
	/* Check this row on left side */
	for (int i = 0; i < col; i++)
		if (board[row][i]==1)
			return false;

	/* Check upper diagonal on left side */
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j]==1)
			return false;

	/* Check upper diagonal on right side */
	for (int i = row, j = col; i >= 0 && j < n; i--, j++)
		if (board[i][j]==1)
			return false;

	return true;
}

bool nQueen(int** board, int n, int row){

    if(row==n)                          //base condition, if reached at end and found all position
        return true;

    for(int col=0; col<n; col++)
    {    
        if(isSafe(board, n, row, col)){
            board[row][col] = 1;
            if (nQueen(board, n, row+1))
                return true;
            else
                board[row][col] = 0;    //for backtracking (if row+1 gives false than we move back to )
        }
    }
    return false;       
    //this will take place when whole for loop gets exhausetd for a particular row, 
    // then it will return false so backtracking will take place
}

int main(){

    int n;
    cout<<"Enter the board size in terms of no. of rows: ";
    cin>>n;

    int** board = new int*[n];          //creating a pointer array by DMA of memory block n
    for (int i = 0; i < n; i++){
        board[i] = new int[n];          // Declare a memory block of size n for each board[i]
        for (int j = 0; j < n; j++){
            board[i][j] = 0;            // Assigning each element of 2D array value = 0 
        }
    }

    if (nQueen(board, n, 0))
        printSolArray(board, n);
    
    else
        cout<<"Solution does not exist"<<endl;

    return 0;
}

// OUTPUT

// Enter the board size in terms of no. of rows: 4
// Solution matrix for the nQueen Problem
// 0 1 0 0 
// 0 0 0 1 
// 1 0 0 0 
// 0 0 1 0 

// Enter the board size in terms of no. of rows: 5
// Solution matrix for the nQueen Problem
// 1 0 0 0 0 
// 0 0 1 0 0 
// 0 0 0 0 1 
// 0 1 0 0 0 
// 0 0 0 1 0