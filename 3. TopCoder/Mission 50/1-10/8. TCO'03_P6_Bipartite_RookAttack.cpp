//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define _N 100
int dp[_N][_N];


class maxBPM
{
private:
	int X, Y;
	vector<bool> seen;
	vector<int> matchRec;
	vector<vector<bool>> graph;

	bool bpmRecur(int u)
	{
		loop(v,Y)
		{
			if (graph[u][v] && !seen[v])
			{
				seen[v] = true;
				if( matchRec[v]<0 || bpmRecur(matchRec[v]) )
				{
					matchRec[v] = u;
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
		Y = graph[0].size();
		matchRec.resize(Y,-1);

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

class RookAttack 
{

	public:
	int howMany(int rows, int cols, vector <string> cutouts) 
	{
		vector<vector<bool>> Graph(vector<vector<bool>>(rows, vector<bool>(cols,true)));
		int m = cutouts.size();
		int r,c; char ch;		
		loop(i,m) 
		{
			istringstream ss(cutouts[i]);
			int n=1;
			LOOP(j,1,cutouts[i].size()) if(cutouts[i][j]==',') n++;
			loop(j,n)
			{
				ss>>r>>c>>ch;
				Graph[r][c]=false;
			}
		}
		maxBPM bp;
		return bp.findMaxBPM(Graph);
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 8; string Arr2[] = {"0 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0","0 1","1 1","1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0 0","1 0","1 1","2 0","2 1","2 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0 0","1 2","2 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 200; int Arg1 = 200; string Arr2[] = {"0 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 200; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    RookAttack ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
