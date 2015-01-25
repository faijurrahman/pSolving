#include<algorithm>
#include<bitset>
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
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal)
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define MAXN 2050
long long dp[MAXN][2], tdp[MAXN][2];

class WinterAndSnowmen 
{

public:
	int getNumber(int N, int M) 
	{
		long long ans=0;
		int X=MAXN, Y=2, Z=max(N,M)+1, B=11;

		loop(b,B) 
		{
			ZERO(dp); dp[0][0]=1;
			LOOP(k,1,Z)
			{
				ZERO(tdp); 
				loop(i,X) loop(j,Y)
				{
					if(k<=N)
					{
						if((k>>b)&1) tdp[i^k][1^j]+=dp[i][j];
						else tdp[i^k][j]+=dp[i][j];
					}
					if(k<=M) tdp[i^k][j]+=dp[i][j];
				}
				loop(i,X) loop(j,Y) dp[i][j]=(dp[i][j]+tdp[i][j])%MOD;
			}
			loop(i,X) if(i>>b==1) ans=(ans+dp[i][0])%MOD;
		}
		return ans;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 74; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 216; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 962557390; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	WinterAndSnowmen ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

