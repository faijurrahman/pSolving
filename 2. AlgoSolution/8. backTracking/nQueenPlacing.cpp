//http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
#include<stdio.h>
#define N 4
int board[N][N];

/* A utility function to check if a queen can be placed on board[row][col]
   Note that this function is called when "col" queens are already placeed
   in columns from 0 to col -1. So we need to check only left side for
   attacking queens */
bool isSafe(int col, int row)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < row; i++)
    {
        if (board[col][i])
            return false;
    }
 
    /* Check upper diagonal on left side */
    for (i = col, j = row; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
 
    /* Check lower diagonal on left side */
    for (i = col, j = row; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }
 
    return true;
}
 
bool solveNQueen(int row)
{
    if (row >= N)
        return true;
 
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(i, row) )
        {
            board[i][row] = 1;
 
            if ( solveNQueen(row + 1) == true )
                return true;

            board[i][row] = 0; // BACKTRACK
        }
    }
    return false;
}

// driver program to test above function
int main()
{

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = 0;
 
    if ( solveNQueen(0) == false )
    {
      printf("Solution does not exist");
      return false;
    }
    
	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
 
    getchar();
    return 0;
}