//http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze/
#include<stdio.h>

#define N 4 
int maze[N][N], sol[N][N];
 
bool isSafe(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
 
    return false;
} 
 
bool solveMaze(int x, int y)
{
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }
 
    if(isSafe(x, y) == true)
    {
        sol[x][y] = 1;
 
        if (solveMaze(x+1, y) == true)
            return true;
 
        if (solveMaze(x, y+1) == true)
            return true;
 
        sol[x][y] = 0;
    }   

    return false;
}
 
// driver program to test above function
int main()
{
    int initMaze[N][N]  =  { 
								{1, 0, 0, 0},
								{1, 1, 0, 1},
								{0, 1, 0, 0},
								{1, 1, 1, 1}
							};

	for (int x = 0; x < N; x++)
	{
        for (int y = 0; y < N; y++)
		{
			maze[x][y] = initMaze[x][y];
            sol[x][y] = 0;
		}
	}
 
    if(solveMaze(0, 0) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }

    getchar();
    return 0;
}
