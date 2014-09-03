//http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/
#include<vector>
#include<algorithm>
#include<iostream>
#include <iomanip>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define MIN(val1, val2) (val1) = min((val1),(val2))

vector<vector<int>> floydWarshell (vector<vector<int>> G)
{
	int X = G.size();
	loop(k,X) loop(i,X) loop(j,X) MIN(G[i][j], G[i][k]+G[k][j]);
	return G;
}


#define V 4
#define INF 99999

void printMatrix(vector<vector<int>>& input)
{
	int X = input.size();
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (input[i][j] == INF) cout << setw(6) << "INF";
			else cout << setw(6) << input[i][j];
		}
		cout << endl;
	}
}

int main()
{
	/* 
	10
	(0)------->(3)
	|         /|\
	5 |          |
	|          | 1
	\|/         |
	(1)------->(2)
	3           
	*/
	int graph[V][V] = { {0,   5,  INF, 10},
						{INF, 0,   3, INF},
						{INF, INF, 0,   1},
						{INF, INF, INF, 0}
					  };

	vector<vector<int>> input, output;
	input.resize(V);
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			input[i].push_back(graph[i][j]);

	cout << "Input Matrix:" << endl;
	printMatrix(input);

	output = floydWarshell(input);

	cout << endl << "Output Matrix:" << endl;
	printMatrix(output);

	return 0;
}