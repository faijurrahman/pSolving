//http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))

#define _N 10 //Number of Node
int dp[_N+1];

struct edge
{
    int u, v, w;
	edge(int u1, int v1, int w1)
	{
		u=u1; v=v1; w=w1;
	}
	bool operator < (edge E) const
	{
		return w < E.w;
	}
};
 
struct graph
{
    vector<int> node;
    vector<edge> e;
	vector<edge> adj(int u)
	{
		vector<edge> ans;
		for(edge edg:e) if(edg.u==u || edg.v==u) ans.push_back(edg);
		return ans;
	}
}g;

void BellmanFord(graph g)
{
	int X = g.node.size();
	int Y = g.e.size();

    loop(i,X) dp[i]=INT_MAX; dp[0]=0;
	loop(i,X) loop(j,Y) MIN(dp[g.e[j].v], dp[g.e[j].u]+g.e[j].w);
    loop(j,Y) if(dp[g.e[j].v] > dp[g.e[j].u]+g.e[j].w) cout << "Exists negative cycle" << endl;

    cout << "Vertex   Distance from Source" << endl;
    loop(i,X) cout << i << "	" << dp[i] << endl;
}

// Driver program to test above functions
int main()
{
	int universe[] = {0,1,2,3,4};
	int src[]	= { 0,	0,	1,	1,	1,	3,	3,	4};
	int dest[]	= { 1,	2,	2,	3,	4,	2,	1,	3};
	int weight[]= {-1,	4,	3,	2,	2,	5,	1, -3};
	int X = sizeof(src)/sizeof(src[0]);

	for(int node:universe) g.node.push_back(node);
	loop(i,X) g.e.push_back(edge(src[i],dest[i],weight[i]));

    BellmanFord(g);
    return 0;
}