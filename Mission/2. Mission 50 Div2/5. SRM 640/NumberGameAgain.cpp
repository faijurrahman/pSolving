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
long long dp[_N];

class NumberGameAgain 
{

	public:
	long long solve(int k, vector<long long> table) 
	{
		long long ans = pow((long long)2,k)-2;
		int X = table.size();
		if(X==0) return ans;

		sort(All(table));

		for(int i=X-1; i>=0; i--)
		{
			loop(k,41)
			{
				long long val=table[i]/pow((long long)2,k);

				if(val>=table[0]) loop(j,i) if(val==table[j]) {table[i]=-1; break;}
			}
		}

		dp[0]=1;
		LOOP(i,1,43) dp[i]=dp[i-1]*2;
		
		loop(i,X) 
		{
			if(table[i]!=-1)
			{
				long long val = table[i], p=0;
				for(int j=41; j>0; j--)
				{
					if(dp[j-1]<=val && val<dp[j]){ p=j-1; break;}
				}

				if(k-p>0) ans-=pow((long long)2,k-p)-1;
				else if(k-p==0) ans--;
			}

		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arr1[] = {2,4,6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; long long Arr1[] = {2,3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; long long Arr1[] = {0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 30LL; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 40; long long Arr1[] = {2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 549755748288LL; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 40; long long Arr1[] = {0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1099511627774LL; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    NumberGameAgain ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
