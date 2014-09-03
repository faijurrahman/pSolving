#include<algorithm>
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
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define _N 101
ll dp[2][_N][_N];

class ChessMetric 
{
public:
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves) 
	{
		int cur=0; ZERO(dp);
		dp[cur][start[1]][start[0]] = 1;
		while(numMoves--)
		{
			cur^=1; ZERO(dp[cur]);
			loop(i,size) loop(j,size)
				LOOP(ii, i-2, i+3) LOOP(jj, j-2, j+3)
					if(ii>=0 && jj>=0 && ii<size && jj<size) 
					{
						int dist = (ii-i)*(ii-i) + (jj-j)*(jj-j);
						if(dist==1 || dist==2 || dist==5) dp[cur][i][j] += dp[!cur][ii][jj];
					}
		}

		return dp[cur][end[1]][end[0]];
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 1LL; verify_case(0, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 1LL; verify_case(1, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 0LL; verify_case(2, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 5LL; verify_case(3, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,99}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; long long Arg4 = 243097320072600LL; verify_case(4, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	ChessMetric ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

