//http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
#include<stdio.h>
#define N 4
int sol[N][N];
/* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
int xMove[8] = {2, 1, -1, -2, -2, -1,  1,  2};
int yMove[8] = {1, 2,  2,  1, -1, -2, -2, -1};

int isSafe(int x, int y)
{
    if ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
        return 1;
    return 0;
}
 
int solveKnightTour(int x, int y, int movei)
{
   int k, next_x, next_y;
   if (movei == N*N)
       return true;

   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y))
       {
         sol[next_x][next_y] = movei;
         if (solveKnightTour(next_x, next_y, movei+1) == true)
             return true;
         else
             sol[next_x][next_y] = -1;// backtracking
       }
   }
 
   return false;
}
 
/* Driver program to test above functions */
int main()
{
    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
 

 
    // Since the Knight is initially at the first block
    sol[0][0]  = 0;
 
    /* Start from 0,0 and explore all tours using solveKTUtil() */
    if(solveKnightTour(0, 0, 1) == false)
        printf("Solution does not exist \n");


	for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }

    getchar();
    return 0;
}