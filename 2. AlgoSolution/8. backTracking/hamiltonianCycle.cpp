//http://www.geeksforgeeks.org/backtracking-set-7-hamiltonian-cycle/
// Program to print Hamiltonian cycle
#include<stdio.h>
 
// Number of vertices in the graph
#define V 5
bool graph[V][V];
int path[V];

 
bool isSafe(int v, int pos)
{
    if (graph[path[pos-1]][v] == 0)
        return false;
 
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
bool hamCycle(int pos)
{
    if (pos == V)
    {
        if ( graph[path[pos-1]][path[0]] == 1 )
           return true;
        else
          return false;
    }
 
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;
 
            if (hamCycle(pos+1) == true)
                return true;
 
            path[pos] = -1;
        }
    }
    return false;
}
 

bool hamSolution(bool pGraph[V][V])
{
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			graph[i][j] = pGraph[i][j];

    for(int i = 0; i < V; i++)
        path[i] = -1;
 
    path[0] = 0;
    if ( hamCycle(1) == false )
    {
        printf("\nSolution does not exist\n");
        return false;
    }
 
    printf ("Solution Exists: Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
 
    printf(" %d ", path[0]);
    printf("\n");
	return true;
}
 
 
// driver program to test above function
int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
    // Print the solution
    hamSolution(graph1);
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
 
    // Print the solution
    hamSolution(graph2);
 
    return 0;
}