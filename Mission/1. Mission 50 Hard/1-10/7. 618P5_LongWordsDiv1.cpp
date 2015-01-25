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
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define _N 5001
long long dp[_N];

class LongWordsDiv1 
{

	public:
	long long modFactorial(int x) 
	{
		long long ans=1;
		for(int i=2; i<=x; i++) 
			ans=(ans*i)%MOD;
		return ans;
	}
        
 
	long count(int n) 
	{
		ZERO(dp); dp[0]=1;
		LOOP(i,1,n+1)
		{
			dp[i]=dp[i-1];          
			for(int p=1; p+2<=i; p++) dp[i] += (dp[i-p-1]*dp[p])%MOD;  //multiply f(p)*f(i-1-p)
			dp[i]%=MOD;
		}
		return (dp[n]*modFactorial(n))%MOD;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1080; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 486425238; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    LongWordsDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
