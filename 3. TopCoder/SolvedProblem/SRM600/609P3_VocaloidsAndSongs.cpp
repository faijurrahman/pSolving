//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) LOOP(i,0,n)
#define ITR(i,n) for(__typeof(c.begin()) x=c.begin(); x!=c.end(); x++)
#define All(c) c.begin(),c.end()
#define rAll(c) c.rbegin(),c.rend()
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define ZERO(arr) FILL(arr,0)

#define mod 1000000007
#define N 51
int dp[2][N][N][N];

class VocaloidsAndSongs {

public:
	int count(int S, int gumi, int ia, int mayu) {
		ZERO(dp);
		dp[0][gumi][ia][mayu]=1;
		loop(x,S)
		{
			int cur=x%2, tar=cur^1;
			ZERO(dp[tar]);
			loop(i,N) loop(j,N) loop(k,N)
			{
				if(dp[cur][i][j][k] == 0) continue;
				if(i&&j&&k) (dp[tar][i-1][j-1][k-1]	+= dp[cur][i][j][k])%=mod;
				if(i&&j)	(dp[tar][i-1][j-1][k]	+= dp[cur][i][j][k])%=mod;
				if(i&&k)	(dp[tar][i-1][j][k-1]	+= dp[cur][i][j][k])%=mod;
				if(j&&k)	(dp[tar][i][j-1][k-1]	+= dp[cur][i][j][k])%=mod;
				if(i)		(dp[tar][i-1][j][k]		+= dp[cur][i][j][k])%=mod;
				if(j)		(dp[tar][i][j-1][k]		+= dp[cur][i][j][k])%=mod;
				if(k)		(dp[tar][i][j][k-1]		+= dp[cur][i][j][k])%=mod;
			}
		}
		return dp[S%2][0][0][0];
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 6; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 9; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 12; int Arg2 = 8; int Arg3 = 9; int Arg4 = 81451692; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 198591037; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	VocaloidsAndSongs ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

