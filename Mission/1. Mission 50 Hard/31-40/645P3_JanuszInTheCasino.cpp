//C Header
#include<map>
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

class JanuszInTheCasino 
{
	int M; map<pair<long long,int>,double> mp;
	double prob(long long n, int k)
	{
		if(n==0) return 0;
		if(k==0) return 1.0;

		pair<int,int> p=make_pair(n,k);
		if(mp.find(p)!=mp.end()) return mp[p];

		long long q=n/M, rem=n%M; k--;
		double res=prob(n-q,k)*(M-rem);
		res+=prob(n-q-1,k)*rem;
		
		return mp[p]=res/M;
	}

	public:
	double findProbability(long long n, int m, int k) 
	{
		M=m; map<pair<long long,int>,double> temp; mp=temp;		
		return prob(n,k);
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 2; int Arg2 = 2; double Arg3 = 0.75; verify_case(0, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; int Arg1 = 3; int Arg2 = 3; double Arg3 = 0.2962962962962962; verify_case(1, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 4LL; int Arg1 = 3; int Arg2 = 2; double Arg3 = 1.0; verify_case(2, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 5LL; int Arg1 = 4; int Arg2 = 5; double Arg3 = 0.87109375; verify_case(3, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 1000000000000LL; int Arg1 = 2; int Arg2 = 40; double Arg3 = 0.9094947017729282; verify_case(4, Arg3, findProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    JanuszInTheCasino ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
