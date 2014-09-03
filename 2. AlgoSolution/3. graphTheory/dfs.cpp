//Recursion format
dfs(node V)
{
	visited[V]=1;
	for(all W adjacent to V)
		if(!visited[W]) then dfs(W);
}

//Basic Example
dfs(int start, int required)
{
	stack Stack;
	bool visited[n+1];

	for(int i = 0; i <= n; i++) visited[i] = false;

	Stack.push(start);
	visited[start] = true;
	while(!Stack.empty())
	{
		int curNode = Stack.top();Stack.pop();
		if(curNode == required) break;

		for(int i = 0; i <= n; i++)
		{
			if (isConnected(curNode, i) && !visited[i]) 
			{
				Stack.push(i);
				visited[i] = true;
			}
		}
	}
}  

//For Traversion 2D array
public static void main( String[] args ) {
	dfs( 0, 0 ); // Call to start the DFS at the root node, or top-left cell of the matrix.
}

void dfs( int row, int col ) 
{
	// Do whatever you were meant to do to the node because of the problem.
	dfs( row + 1, col ); // To the cell in the bottom.
	dfs( row, col + 1 ); // To the cell to the right.
}
