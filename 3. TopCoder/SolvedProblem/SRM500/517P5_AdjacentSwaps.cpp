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

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD (int)(1e9+7)
#define _N 51
int dp[_N][_N], nCr[_N][_N];

class AdjacentSwaps 
{


	public:
	int theCount(vector <int> p) 
	{
		int X = p.size();
		int b[51], c[51];

		ZERO(dp), ZERO(nCr);
		for(int i=0;i<=X;i++) nCr[i][0] = 1;
		for(int i=1;i<=X;i++) for (int j=1;j<=i;j++) 
			nCr[i][j] = (nCr[i-1][j]+nCr[i-1][j-1]) % MOD;

		for(int i=X-1;i>=0;i--) for(int j=i;j<X;j++)
			if(i == j) dp[i][j] = 1; 
			else 
			{
				for(int k=i;k<=j;k++) b[k] = p[k];
				sort(b+i,b+j+1);
				for(int k=i;k<j;k++) 
				{
					ZERO(c);
					for(int q=i;q<k;q++) c[b[q]] = 1;
					c[b[k+1]] = 1;

					int ok = 1;
					for(int q=i;q<=k;q++) if(!c[p[q]]){ok = 0; break;}
					if(ok) 
					{
						int temp = (long long)dp[i][k] * dp[k+1][j] % MOD;
						temp = (long long)temp * nCr[j-i-1][k-i] % MOD;
						dp[i][j] = (dp[i][j] + temp) % MOD;
					}
				}
			}

		return dp[0][X-1];
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 716743312; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    AdjacentSwaps ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
