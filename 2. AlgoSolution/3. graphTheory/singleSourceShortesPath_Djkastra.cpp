//http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
#include <stdio.h>
#include <climits>
#include <time.h>
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define V 9
#define INF 999999

class dijkstra
{
private:
	int X;
	vector<int> dist;  
	vector<bool> sptSet;
	 
	int minDistance()
	{
		int min = INT_MAX, min_index; 
		loop(v,X) if(!sptSet[v] && dist[v] <= min) min = dist[v], min_index = v; 
		return min_index;
	}

	void printSolution()
	{
		printf("Vertex   Distance from Source\n");
		loop(i,X) printf("%3d    %4d\n", i, dist[i]);
	}

public:
	void calculateSolutin(vector<vector<int>> graph, int src)
	{
		X = graph.size();
		dist.resize(X,INT_MAX);  
		sptSet.resize(X,false); 

		dist[src] = 0;
		loop(count,X-1)
		{
			int u = minDistance();
			sptSet[u] = true;

			loop(v,X) 
				if(!sptSet[v]  && graph[u][v] && dist[u] != INT_MAX)  
					MIN(dist[v], dist[u] + graph[u][v]);
		}
		printSolution();
	}
};

int main()
{
	int G[9][9] = {
						{  0,	  4,	INF,	INF,	INF,	INF,	INF,	  8,	INF},
						{  4,	  0,	  8,	INF,	INF,	INF,	INF,	 11,	INF},
						{INF,	  8,	  0,	  7,	INF,	  4,	INF,	INF,	  2},
						{INF,	INF,	  7,	  0,	  9,	 14,	INF,	INF,	INF},
						{INF,	INF,	INF,	  9,	  0,	 10,	INF,	INF,	INF},
						{INF,	INF,	  4,	INF,	 10,	  0,	  2,	INF,	INF},
						{INF,	INF,	INF,	 14,    INF,	  2,	  0,	  1,	  6},
						{  8,	 11,	INF,	INF,	INF,	INF,	  1,	  0,	  7},
						{INF,	INF,	  2,	INF,	INF,	INF,	  6,	  7,	  0}
				  };

	clock_t start, finish;
    start = clock();
	int X = (int) sqrt(sizeof(G)/sizeof(G[0][0]));
	vector<vector<int>> graph; graph.resize(X);
	loop(i,X) loop(j,X) graph[i].push_back( G[i][j] );

	dijkstra objDijkastra;
	objDijkastra.calculateSolutin(graph, 0);
	  finish = clock();
    std::cout << "Time for sort (miliseconds): "
         << ((double)(finish - start)) <<endl;

	return 0;
}