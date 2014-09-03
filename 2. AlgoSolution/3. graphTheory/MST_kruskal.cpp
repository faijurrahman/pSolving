//https://www.youtube.com/watch?v=5xosHRdxqHA
#include<algorithm>
#include<bitset>
#include<vector>
#include<string>
#include<iostream>
#include <sstream>
#include<cstring>
#include<climits>
#include<set>
#include<unordered_map>
#include<map>
#include <iomanip>
using namespace std;

#define ld long double
#define ll long long
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define each(it,c) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define _N 100
int dp[_N][_N];
 
unordered_map<int,int> parent;
unordered_map<int,int> rnk;

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

int find(int u)
{
    if(parent[u] == u) return u;
	else return find(parent[u]);
}
 
void unionSet(int u, int v)
{
    if(rnk[u] > rnk[v]) parent[v] = u;
    else if(rnk[u] < rnk[v]) parent[u] = v;
    else parent[u] = v, rnk[v]++;
}
 
void makeSet(int v)
{
	parent[v] = v;
	rnk[v] = 0;
}

// The main function to construct MST using Kruskal's algorithm
vector<edge> KruskalMST()
{
	vector<edge> ans;
	for(auto node: g.node) makeSet(node);
	sort(All(g.e));

	for(auto e: g.e)
	{
		int u = find(e.u);
		int v = find(e.v);
		if(u != v)
		{
			ans.push_back(e);
			unionSet(u,v);
		}
	}
	return ans;
}
 
// Driver program to test above functions
int main()
{
	int universe[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	for(int node:universe) g.node.push_back(node);
	g.e.push_back(edge('a','b',4));
	g.e.push_back(edge('a','f',2));
	g.e.push_back(edge('f','b',5));
	g.e.push_back(edge('c','b',6));
	g.e.push_back(edge('c','f',1));
	g.e.push_back(edge('f','e',4));
	g.e.push_back(edge('d','e',2));
	g.e.push_back(edge('d','c',3));

    vector<edge> ans = KruskalMST();
	for(edge e: ans) cout<<(char)e.u <<"--" <<(char)e.v<<" " <<e.w<<endl;

    return 0;
}