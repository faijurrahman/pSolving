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
#define _N 100000
bool dp[_N];

class LightSwitchingPuzzle 
{

	public:
	int minFlips(string s) 
	{
		int ans = 0;
		int X = s.size();
		ZERO(dp);
		loop(i,X) dp[i]=(s[i]=='Y'?1:0);
	
		loop(i,X) if(dp[i])
		{
            ans++;
			for(int j=i; j<X; j+=(i+1)) dp[j]^=1;
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YYYYYY"; int Arg1 = 1; verify_case(0, Arg1, minFlips(Arg0)); }
	void test_case_1() { string Arg0 = "YNYNYNYNY"; int Arg1 = 2; verify_case(1, Arg1, minFlips(Arg0)); }
	void test_case_2() { string Arg0 = "NNNNNNNNNN"; int Arg1 = 0; verify_case(2, Arg1, minFlips(Arg0)); }
	void test_case_3() { string Arg0 = "YYYNYYYNYYYNYYNYYYYN"; int Arg1 = 4; verify_case(3, Arg1, minFlips(Arg0)); }
	void test_case_4() { string Arg0 = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"; int Arg1 = 12; verify_case(4, Arg1, minFlips(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    LightSwitchingPuzzle ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
