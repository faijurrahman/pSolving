//http://www.geeksforgeeks.org/maximum-bipartite-matching/
//C Header
#include<queue>
#include<climits>
#include<algorithm>
#include<vector>
#include<iostream>
#include <sstream>
using namespace std;
#define loop(i,n) for(int i=0;i<(n);i++)


class maxBPM
{
private:
	int X,Y;
	vector<bool> seen;
	vector<int> matchRecord;
	vector<vector<int>> graph;

	bool bpmRecur(int u)
	{
		loop(v,Y)
		{
			if (graph[u][v] && !seen[v])
			{
				seen[v] = true;
				if( matchRecord[v]<0 || bpmRecur(matchRecord[v]) )
				{
					matchRecord[v] = u;
					return true;
				}
			}
		}
		return false;
	}

public:
	int findMaxBPM(vector<vector<int>>& Graph)
	{
		graph = Graph;
		X = graph.size();
		Y = graph[0].size();

		matchRecord.resize(Y,-1);

		int ans = 0; 
		loop(u,X)
		{
			seen.clear();
			seen.resize(Y,false);
			if(bpmRecur(u)) ans++;
		}
		return ans;
	}

};

// Driver program to test above functions
int main()
{
	bool bpGraph[6][6] = {  
							{0, 1, 1, 0, 0, 0},
							{1, 0, 0, 1, 0, 0},
							{0, 0, 1, 0, 0, 0},
							{0, 0, 1, 1, 0, 0},
							{0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 1}
						 };

	int X = (int) sqrt(sizeof(bpGraph)/sizeof(bpGraph[0][0]));
	vector<vector<int>> Graph; Graph.resize(X);
	loop(i,X) loop(j,X) Graph[i].push_back( bpGraph[i][j] );

	maxBPM objMaxBPM;
	int ans =  objMaxBPM.findMaxBPM(Graph);
    cout << "The BPM is " << ans << endl;

	return 0;
}