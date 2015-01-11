#include<set>
#include<list>
#include<queue>
#include<stack>
#include<tuple>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))

#define INF 99999
#define pTYPE int
#define VT vector<pTYPE>
#define VVT vector<vector<pTYPE>>
class Graph
{
private:
	int X,Y,E; VVT G, adj;
	vector<tuple<pTYPE,int,int>> edge;
	vector<int> dist,path,match; vector<bool> seen;

public:
	
	Graph(){} Graph(VVT grph){update(grph);} VVT getGraph(){return G;}
	Graph(int X0, vector<int> U, vector<int> V, VT W){update(X0,U,V,W);} 

	void update(VVT grph){
		G=grph; X=G.size(); adj.clear(); adj.resize(X);
		loop(i,X) loop(j,X) if(G[i][j]!=0){ adj[i].push_back(j); edge.push_back(make_tuple(G[i][j],i,j));}//Directed
		//loop(i,X) loop(j,X) if(G[i][j]!=0){ adj[i].push_back(j); edge.push_back(make_tuple(G[i][j],min(i,j),max(i,j)));}
	}
	void update(int X0, vector<int> U, vector<int> V, VT W){
		int N=U.size(); X=X0; G.clear(); G.resize(X); loop(i,X) G[i].resize(X); adj.clear(); adj.resize(X); edge.resize(0);
		loop(i,N){ G[U[i]][V[i]]=W[i]; adj[U[i]].push_back(V[i]); edge.push_back(make_tuple(W[i],U[i],V[i]));}//Directed
		//loop(i,N){ G[U[i]][V[i]]=G[V[i]][U[i]]=W[i]; adj[U[i]].push_back(V[i]); adj[V[i]].push_back(U[i]); edge.push_back(make_tuple(W[i],U[i],V[i]));}
	}

	bool dfs(int src, int dst){
		seen.clear(); seen.resize(X,0); path.clear(); path.resize(X);
		stack<int> q; q.push(src); seen[src]=1;
		while(!q.empty()){ int u=q.top(); q.pop();
			loop(v,X) if(!seen[v] && G[u][v]>0){ q.push(v); seen[v]=1; path[v]=u; if(seen[dst]) return 1;}} 
		return false;
	}
		
	bool bfs(int src, int dst){
		seen.clear(); seen.resize(X,0); path.clear(); path.resize(X);
		queue<int> q; q.push(src); seen[src]=1; 
		while(!q.empty()){ int u=q.front(); q.pop();
			loop(v,X) if(!seen[v] && G[u][v]>0){ q.push(v); seen[v]=1; path[v]=u; if(seen[dst]) return 1;}} 
		return false;
	}

	void Dijkstra(int src){
		set<tuple<int,int>> Q; Q.insert(make_tuple(0,src)); seen.clear(); 
		seen.resize(X,0); dist.clear(); dist.resize(X,INT_MAX); dist[src]=0;
		while(!Q.empty()){ int du,u; auto it=Q.begin(); tie(du,u)=*it; Q.erase(it); seen[u]=1;
		for(int v:adj[u]) if(!seen[v] && dist[v]>du+G[u][v]){ dist[v]=du+G[u][v]; Q.insert(make_tuple(dist[v],v));}}
	}

	void floydWarshell(void){ loop(k,X) loop(i,X) loop(j,X) MIN(G[i][j], G[i][k]+G[k][j]);}

	int fordFulkerson(int src, int dst) { int maxFlow=0; 
		while(bfs(src,dst)){ int pathFlow=INT_MAX;
			for(int v=dst; v!=src; v=path[v]){ int u=path[v]; MIN(pathFlow,G[u][v]);}
			for(int v=dst; v!=src; v=path[v]){ int u=path[v]; G[u][v]-=pathFlow; G[v][u]+=pathFlow;}
			maxFlow+=pathFlow;} 
		return maxFlow; 
	}

private:
	bool bpmRecur(int u){
		loop(v,Y) if(G[u][v] && !seen[v]){ seen[v]=1;
			if(match[v]<0 || bpmRecur(match[v])){ match[v]=u; return 1;}}
		return false;
	} public:
	int maxBPM(void){ int bpm=0; X=G.size(); Y=G[0].size();
		match.clear(); match.resize(Y,-1);
		loop(u,X){ seen.clear(); seen.resize(Y,0); if(bpmRecur(u)) bpm++;}
		return bpm;
	}


	void print(void){ loop(i,X){ loop(j,X) if(G[i][j]==INF) cout<<setw(6)<<"INF"; else cout<<setw(6)<<G[i][j]; cout<<endl;}}
	void printDist(void){printf("Vertex   Distance from Source\n"); loop(i,X) printf("%3d    %4d\n", i, dist[i]);}
};


int main()
{
	Graph graph; int X, ans;
	vector<vector<int>> input;

	//*******************************************************************************
	//             Shortest Distance
	//*******************************************************************************
	int shortG[9][9] = {
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


	
	cout<<"**************************************************"<<endl;
	cout<<"Dijkstra's shortest path algorithm"<<endl;


	X=(int) sqrt(sizeof(shortG)/sizeof(shortG[0][0]));input.resize(0);input.resize(X);
	loop(i,X) loop(j,X) input[i].push_back(shortG[i][j]);

	graph.update(input); 
	cout<<endl<<"Input Matrix:"<<endl; graph.print();
	graph.Dijkstra(0);
	graph.printDist();


	cout<<endl<<endl<<"**************************************************"<<endl;
	cout<<"Floyd Warshell All pair shortest path algorithm"<<endl<<endl;


	X=(int)sqrt(sizeof(shortG)/sizeof(shortG[0][0])); input.resize(0); input.resize(X);
	loop(i,X) loop(j,X) input[i].push_back(shortG[i][j]);

	graph.update(input); 
	cout<<"Input Matrix:"<<endl; graph.print();
	graph.floydWarshell();
	cout<<"Output Matrix:"<<endl; graph.print();



	//*******************************************************************************
	//             Max Flow, Min Cut, Bipartite
	//*******************************************************************************

	cout<<endl<<endl<<"**************************************************"<<endl;
	cout<<"Ford Fulkerson Maximum flow"<<endl;
    int G[6][6] = { 
					{ 0, 16, 13,  0,  0,  0},
                    { 0,  0, 10, 12,  0,  0},
                    { 0,  4,  0,  0, 14,  0},
                    { 0,  0,  9,  0,  0, 20},
                    { 0,  0,  0,  7,  0,  4},
                    { 0,  0,  0,  0,  0,  0}
                  };

	X=(int)sqrt(sizeof(G)/sizeof(G[0][0])); input.resize(0);input.resize(X);
	loop(i,X) loop(j,X) input[i].push_back(G[i][j]);

	graph.update(input); 
	cout<<endl<<"Input Matrix:"<<endl; graph.print();
	ans=graph.fordFulkerson(0,5);
	cout<<"Output Matrix:"<<endl; graph.print();
    cout<<endl<<"The maxFlow is "<<ans<<endl;



	cout<<endl<<endl<<"**************************************************"<<endl;
	cout<<"Bipartite Matching"<<endl;
	int bpG[6][6] = {  
						{0, 1, 1, 0, 0, 0},
						{1, 0, 0, 1, 0, 0},
						{0, 0, 1, 0, 0, 0},
						{0, 0, 1, 1, 0, 0},
						{0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 1}
					};

	X=(int) sqrt(sizeof(bpG)/sizeof(bpG[0][0])); input.resize(0);input.resize(X);
	loop(i,X) loop(j,X) input[i].push_back( G[i][j] );
	
	graph.update(input); 
	cout<<endl<<"Input Matrix:"<<endl; graph.print();
	ans=graph.maxBPM();
	cout<<"Output Matrix:"<<endl; graph.print();
    cout<<endl<<"The maxBPM is "<<ans<<endl;


	cout<<endl<<endl;
	return 0;
}