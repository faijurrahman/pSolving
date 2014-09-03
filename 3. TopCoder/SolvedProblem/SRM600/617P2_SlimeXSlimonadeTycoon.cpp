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

#define _N 55
int dp[_N];

class SlimeXSlimonadeTycoon 
{
	int X, L;
	long stall(int a, int b)
	{
		long sum=0;
		loop(i,L) dp[L-i-1] = dp[L-i-2];
		dp[0] = a;

		loop(i,L)
		{
			if(dp[L-i-1]>b)
			{
				sum+=b;
				dp[L-i-1]-=b;
				b=0;
			}
			else
			{
				sum+=dp[L-i-1];
				b-=dp[L-i-1];
				dp[L-i-1]=0;
			}

			if(b<=0) break;
		}

		return sum;
	}
	public:
	int sell(vector <int> morning, vector <int> customers, int stale_limit) 
	{
		int ans = 0;
		X = morning.size();	
		L= stale_limit;
		ZERO(dp);	
		
		loop(i,X)
		{
			ans+=stall(morning[i], customers[i]);
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 40; verify_case(1, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 5, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 15; verify_case(2, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10000, 0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 8, 16, 32, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 15; verify_case(3, Arg3, sell(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    SlimeXSlimonadeTycoon ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
