//http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
#include<queue>
#include<climits>
#include<algorithm>
#include<vector>
#include<iostream>
#include <sstream>
using namespace std;
#define loop(i,n) for(int i=0;i<(n);i++)

class maxFlow
{
private:	
	int X, source, sink;
	vector<int> path;
	vector<vector<int>> Graph;

	bool bfs(void)
	{
		vector<bool> seen;
		seen.resize(X,false);
		seen[source] = true;

		queue<int> q;
		q.push(source);
		while (!q.empty())
		{
			int u = q.front(); q.pop();
			loop(v,X) if(seen[v]==false && Graph[u][v]>0)
			{
				q.push(v);
				path[v] = u;
				seen[v] = true;
				if(seen[sink]) return true;
			}
		}

		return false;
	}

public:
	int fordFulkerson(vector<vector<int>> graph, int s, int t)
	{
		Graph = graph;
		X = Graph.size();
		source=s, sink=t;
		path.resize(X,0);

		int u, v, max_flow = 0; 
		while (bfs() == true)
		{
			int path_flow = INT_MAX;
			for (v=sink; v!=source; v=path[v])
			{
				u = path[v];
				path_flow = min(path_flow, Graph[u][v]);
			}

			for (v=sink; v!=source; v=path[v])
			{
				u = path[v];
				Graph[u][v] -= path_flow;
				Graph[v][u] += path_flow;
			}

			max_flow += path_flow;
		}

		return max_flow;
	}
};

int main()
{
    int G[6][6] = { 
					{ 0, 16, 13,  0,  0,  0},
                    { 0,  0, 10, 12,  0,  0},
                    { 0,  4,  0,  0, 14,  0},
                    { 0,  0,  9,  0,  0, 20},
                    { 0,  0,  0,  7,  0,  4},
                    { 0,  0,  0,  0,  0,  0}
                  };

	int X = (int) sqrt(sizeof(G)/sizeof(G[0][0]));
	vector<vector<int>> Graph; Graph.resize(X);
	loop(i,X) loop(j,X) Graph[i].push_back(G[i][j]);

	maxFlow objMaxFlow;
	int ans =  objMaxFlow.fordFulkerson(Graph, 0, 5);
    cout << "The maxFlow is " << ans << endl;

    return 0;
}