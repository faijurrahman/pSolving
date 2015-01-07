#include<algorithm>
#include<bitset>
#include<tuple>
#include<vector>
#include<string>
#include<iostream>
#include <sstream>
#include<cstring>
#include<climits>
#include<set>
using namespace std;

#define ld long double
#define ll long long
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
const int INF = 1001001001;

class CandleTimer 
{

	public:
	int X; vector<int> leaf;
	vector<vector<int>> G, adj;

	bool check(int a, int da, int b, int db, int l) 
	{
		set<tuple<int,int>> q; 
		vector<int> dist(X,INF);

		for(int u:leaf)
			if(G[u][a]<=G[u][b] && G[u][a]+da>=l) dist[u]=0, q.emplace(0, u);
			else if( G[u][a]>G[u][b] && G[u][b]+db>=l) dist[u]=0, q.emplace(0, u);


		int c, u;
		for(auto tup:q) 
		{	
			tie(c,u)=tup;
			for(int v:adj[u]) 
			{
				int cc=c+G[u][v];
				if (dist[v]>cc) 
				{
					auto iter=q.find(make_tuple(dist[v],v) );
					if(iter!=q.end()) q.erase(iter);
					dist[v]=cc;
					q.emplace(cc,v);
				}
			}
		}

		loop(u,X) for(int v:adj[u]) 
			if((dist[u]+dist[v]+G[u][v])/2 > l) 
				return false;
		return true;
	}    

	int differentTime(vector <int> A, vector <int> B, vector <int> len) 
	{
		set<int> ans; X=A.size()+1;
		adj.clear(); adj.resize(X); 
		leaf.clear(); leaf.resize(0);
		G.resize(0); G.resize(X); 
		loop(i,X){ G[i].resize(X,INF); G[i][i]=0;}
 
		loop(i,A.size())
		{
			adj[A[i]].push_back(B[i]);
			adj[B[i]].push_back(A[i]);
			G[A[i]][B[i]]=G[B[i]][A[i]]=len[i]*=2;
		}		
		loop(i,X) if(adj[i].size()==1) leaf.push_back(i);
		loop(k,X) loop(i,X) loop(j,X) MIN(G[i][j], G[i][k]+G[k][j]);

		for(int u:leaf) for(int v:leaf) 
		{
			int x=adj[v][0], Guv=G[u][v], Guv2=Guv/2;
			if(check(v,0, x,G[v][x], Guv)) ans.insert(Guv);

			loop(x,X) for(int y:adj[x])
			{
				int Gux=G[u][x], Gxy=G[x][y], Gyv=G[y][v];
				if(Guv==Gux+Gxy+Gyv && Gux<=Guv2 && Guv2<Gux+Gxy && 
					check(x,Guv2-Gux, y,Gux+Gxy-Guv2, Guv2) )	
						ans.insert(Guv2);
			}
		}
		return ans.size();
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,1,1,2,3,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,3,2,4,6,8,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(3, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123,456,789,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,0,0,0,1,0,0,0,2,5,4,7,13,13,6,15,11,18,19,21,22,16,19,19,20,18,22,27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {59,58,147,169,34,14,150,55,156,151,130,109,124,15,100,1,156,16,38,97,99,132,150,18,27,91,110,127,15,105}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 65; verify_case(5, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(6, Arg3, differentTime(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    CandleTimer ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
