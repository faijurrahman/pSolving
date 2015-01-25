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
#define _N 50
#define _K 10
int dp[2*_N+1][1<<_K];

class AlienAndSetDiv2 
{

	public:
	int K;
	long rec(int n, int mask)
	{
		long long res=dp[n][mask];
		if(res==-1) 
		{
			res = 0;
			if(n==0) res=((mask==0)?1:0);
			else if(mask==0) res=2*rec(n-1,1)%MOD;
			else 
			{
				int mx=0;
				for(int i=31; i>=0; i--) if(mask&(1<<i)){ mx=i; break;}
				res=rec(n-1, (mask^(1<<mx))<<1)%MOD;         
				if(mx!=K-1) res+=rec(n-1, ((mask<<1)|1))%MOD;  
			}
			dp[n][mask]=res%MOD;
		}
		return res;
	}
 
 
	int getNumber(int N, int K)
	{
		this->K=K;
		memset(dp,-1,sizeof(dp));
		return rec(2*N,0);
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 8; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 44; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 184756; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    AlienAndSetDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
