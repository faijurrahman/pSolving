//http://www.geeksforgeeks.org/backtracking-set-7-suduku/
#include <stdio.h>
 
#define UNASSIGNED 0
#define N 9
int grid[N][N];

bool UsedInRow(int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInCol(int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInBox(int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
bool isSafe(int row, int col, int num)
{
    return !UsedInRow(row, num) &&
           !UsedInCol(col, num) &&
           !UsedInBox(row - row%3 , col - col%3, num);
}

bool FindUnassignedLocation(int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool SolveSudoku()
{
    int row, col;
 
    if (!FindUnassignedLocation(row, col))
       return true; // success!
 
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(row, col, num))
        {
            grid[row][col] = num;
 
            if (SolveSudoku())
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    return false; 
}
  
/* Driver Program to test above functions */
int main()
{
    // 0 means unassigned cells
    int pGrid[N][N] = {
						{3, 0, 6, 5, 0, 8, 4, 0, 0},
						{5, 2, 0, 0, 0, 0, 0, 0, 0},
						{0, 8, 7, 0, 0, 0, 0, 3, 1},
						{0, 0, 3, 0, 1, 0, 0, 8, 0},
						{9, 0, 0, 8, 6, 3, 0, 0, 5},
						{0, 5, 0, 0, 9, 0, 6, 0, 0},
						{1, 3, 0, 0, 0, 0, 2, 5, 0},
						{0, 0, 0, 0, 0, 0, 0, 7, 4},
						{0, 0, 5, 2, 0, 6, 3, 0, 0}
					  };

	for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
			grid[x][y] = pGrid[x][y];


    if (SolveSudoku() == true)
	{
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < N; col++)
					printf("%2d", grid[row][col]);
			printf("\n");
		}
	}
    else
         printf("No solution exists");
 
    return 0;
}