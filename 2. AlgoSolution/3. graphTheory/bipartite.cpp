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
	int X;
	vector<bool> seen;
	vector<int> matchRecord;
	vector<vector<bool>> graph;

	bool bpmRecur(int u)
	{
		loop(v,X)
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
	int findMaxBPM(vector<vector<bool>>& Graph)
	{
		graph = Graph;
		X = graph.size();
		matchRecord.resize(X,-1);

		int ans = 0; 
		loop(u,X)
		{
			seen.clear();
			seen.resize(X,false);
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
	vector<vector<bool>> Graph; Graph.resize(X);
	loop(i,X) loop(j,X) Graph[i].push_back( bpGraph[i][j] );

	maxBPM objMaxBPM;
	int ans =  objMaxBPM.findMaxBPM(Graph);
    cout << "The BPM is " << ans << endl;

	return 0;
}