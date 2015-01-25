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

class DivisibilityCriteria 
{

	public:
	vector <int> multipliers(int N, int P) 
	{
		int mult=1; 
		vector<int> ans;
		ans.resize(N);
		for(int i=N-1; i>=0; i--) 
		{
			ans[i]=mult; 
			mult=(mult*10)%P;
		}
		return ans;
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 7; int Arr2[] = {5, 4, 6, 2, 3, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, multipliers(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 11; int Arr2[] = {1, 10, 1, 10, 1, 10, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, multipliers(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 13; int Arr2[] = {3, 12, 9, 10, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, multipliers(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, multipliers(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 16; int Arg1 = 97; int Arr2[] = {45, 53, 15, 50, 5, 49, 34, 81, 76, 27, 90, 9, 30, 3, 10, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, multipliers(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    DivisibilityCriteria ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
