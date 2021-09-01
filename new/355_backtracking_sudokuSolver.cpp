/*Sudoku Solver
    Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9. 
    https://www.youtube.com/watch?v=FWAIf_EVUKE

    Example: 

        Input:
        grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                {0, 0, 5, 2, 0, 6, 3, 0, 0} }
        Output:
                3 1 6 5 7 8 4 9 2
                5 2 9 1 3 4 7 6 8
                4 8 7 6 2 9 5 3 1
                2 6 3 4 1 5 9 8 7
                9 7 4 8 6 3 1 2 5
                8 5 1 7 9 2 6 4 3
                1 3 8 9 4 7 2 5 6
                6 9 2 3 5 1 8 7 4
                7 4 5 2 8 6 3 1 9
        Explanation: Each row, column and 3*3 box of 
        the output matrix contains unique numbers.
*/

#include <iostream>
using namespace std;

bool isValidValue(int board[9][9], int row, int col, int val){
    for (int i = 0; i < 9; i++){
        if(board[row][i]==val)
            return false;
        
        if(board[i][col]==val)
            return false;

        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val)    //for given row and col, it will check 3x3 grid
            return false;
    }
    return true;
}

bool sudokuSolver(int board[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            
            if(board[i][j]==0){
                
                for (int v = 1; v <= 9; v++){
                    if(isValidValue(board, i, j, v)){
                        board[i][j] = v;
                        if(sudokuSolver(board))
                            return true;        //if we got true for this v then we won't check further
                        else
                            board[i][j] = 0;    //backtracking
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(int board[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int board[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                        {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    cout<<"Solve the following Sudoku:-\n";
    printBoard(board);
    sudokuSolver(board);
    cout<<"Solved sudoku:-\n";
    printBoard(board);
    return 0;
}

/*
Solve the following Sudoku:-
3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0 
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0 

Solved sudoku:-
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 
*/