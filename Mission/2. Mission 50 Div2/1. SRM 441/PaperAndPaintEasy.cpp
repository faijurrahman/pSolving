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

class PaperAndPaintEasy 
{

	public:
	long long computeArea(int w, int h, int xf, int cnt, int x1, int y1, int x2, int y2) 
	{
		long long ans = (long long) w*h - (long long)abs(x1-x2)*abs(y1-y2)*(cnt+1);

		if(xf>(w/2+w%2)) xf=w%xf;

		ans-=x1<xf?(long long)(cnt+1)*abs(x1-(long long)min(x2,xf))*abs(y1-y2):0;

		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 1; int Arg6 = 3; int Arg7 = 2; long long Arg8 = 21LL; verify_case(0, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 13; int Arg2 = 1; int Arg3 = 0; int Arg4 = 1; int Arg5 = 8; int Arg6 = 2; int Arg7 = 12; long long Arg8 = 35LL; verify_case(1, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 12; int Arg2 = 7; int Arg3 = 3; int Arg4 = 3; int Arg5 = 1; int Arg6 = 6; int Arg7 = 2; long long Arg8 = 124LL; verify_case(2, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 4; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; long long Arg8 = 19LL; verify_case(3, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 4; int Arg3 = 3; int Arg4 = 0; int Arg5 = 1; int Arg6 = 2; int Arg7 = 2; long long Arg8 = 24LL; verify_case(4, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_5() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 3; int Arg3 = 0; int Arg4 = 1; int Arg5 = 1; int Arg6 = 3; int Arg7 = 2; long long Arg8 = 30LL; verify_case(5, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    PaperAndPaintEasy ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
