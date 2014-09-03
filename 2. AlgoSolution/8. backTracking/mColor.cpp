//http://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/
#include<stdio.h>

#define V 4
int colorNum, color[V];
int graph[V][V];

bool isSafe (int v, int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoring(int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= colorNum; c++)
    {
        if (isSafe(v, c))
        {
           color[v] = c;

           if (graphColoring(v+1) == true)
             return true;

           color[v] = 0;
        }
    }

    return false;
}

// driver program to test above function
int main()
{
    /* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    int pGraph[V][V] = {
							{0, 1, 1, 1},
							{1, 0, 1, 0},
							{1, 1, 0, 1},
							{1, 0, 1, 0},
					   };

	colorNum = 3; // Number of colors
	
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			graph[i][j] = pGraph[i][j];

	for(int i = 0; i < V; i++)
       color[i] = 0;

    // Call graphColoringUtil() for vertex 0
    if (graphColoring(0) == false)
    {
      printf("Solution does not exist");
      return false;
    }

	printf("Solution Exists: Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");

    return 0;
}