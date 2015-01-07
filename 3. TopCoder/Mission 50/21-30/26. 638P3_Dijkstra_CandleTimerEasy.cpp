//C Header
#include<set>
#include<list>
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
#define INF 1000000
class CandleTimerEasy 
{
	public:

	int differentTime(vector<int> A, vector<int> B, vector<int> len)
	{ 
		set<int> ans; int X=A.size()+1;
		vector<list<int>> adj(X); vector<int> leaf;
		vector<vector<int>> G(X,vector<int>(X,INF));
 
		loop(i,A.size())
		{
			adj[A[i]].push_back(B[i]);
			adj[B[i]].push_back(A[i]);
			G[A[i]][B[i]]=G[B[i]][A[i]]=len[i]*=2;
		}		
		loop(i,X) if(adj[i].size()==1) leaf.push_back(i);

		LOOP(mask,1,1<<leaf.size())
		{
			vector<int> parent(X,-1), dist(X,INF), Q; int mx=0;
			loop(i,leaf.size()) if(mask & (1<<i)) dist[leaf[i]]=0, Q.push_back(leaf[i]);
			while(Q.size()) 
			{ 
				int s=0;
				loop(i,Q.size()) if(dist[Q[i]]<dist[Q[s]]) s=i;
				int x=Q[s]; MAX(mx,dist[x]);
				Q[s]=Q[Q.size()-1]; Q.pop_back();

				for(int y:adj[x]) if(dist[y]>dist[x]+G[x][y]) 
				{
					parent[y]=x; dist[y]=dist[x]+G[x][y];
					if(count(All(Q),y)==0) Q.push_back(y);
				}
			}

			loop(i,A.size())
			{
				int ai=A[i], bi=B[i], d=abs(dist[ai]-dist[bi]);
				if((parent[ai]!=bi) && (parent[bi]!=ai) && d<=len[i]) 
					MAX(mx, dist[ai]+(len[i]-d)/2);
			}
			ans.insert(mx);
		}

		return ans.size();
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,1}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,1,1,2,3,3,2,4}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,3,2,4,6,8,7,1}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(3, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123,456,789,1000}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0}; vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, differentTime(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    CandleTimerEasy ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
