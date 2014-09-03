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

class MyVeryLongCake 
{

	public:
	int cut(int n) 
	{
		int N=n, fac=0, res=1;
		for(int i=2; i*i<=N; i++,fac=0) if(N%i==0)
		{
			while(N%i==0) N/=i, fac++;
			res*=pow(i,fac-1)*(i-1);
		}
		if(N>1) res*=N-1;
		return n-res;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 600000000; verify_case(3, Arg1, cut(Arg0)); }
	void test_case_4() { int Arg0 = 577007436; int Arg1 = 384671628; verify_case(4, Arg1, cut(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    MyVeryLongCake ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
