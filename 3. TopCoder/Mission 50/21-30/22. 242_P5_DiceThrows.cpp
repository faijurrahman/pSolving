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
#define _N 120000
double dp[2][_N+10], dp1[2][_N+10];

class DiceThrows 
{

	public:
	double winProbability(int numDiceA, vector <int> sidesA, int numDiceB, vector <int> sidesB) 
	{
		double ans = 0;		
		ZERO(dp);ZERO(dp1);

		bool cur=1;
		loop(i,6) dp[cur^1][sidesA[i]]+=1/6.0;	

		loop(k,numDiceA-1)
		{
			ZERO(dp[cur]);
			loop(i,_N) if(dp[cur^1][i]) 
				loop(j,6) dp[cur][i+sidesA[j]]+=dp[cur^1][i]/6.0;
			cur^=1;
		}

		if(cur==0) loop(i,_N) dp[0][i]=dp[1][i];

		cur=1;
		loop(i,6) dp1[cur^1][sidesB[i]]+=1/6.0;		
		loop(k,numDiceB-1)
		{
			ZERO(dp1[cur]);
			loop(i,_N) if(dp1[cur^1][i]) 
				loop(j,6) dp1[cur][i+sidesB[j]]+=dp1[cur^1][i]/6.0;
			cur^=1;
		}

		if(cur==0) loop(i,_N) dp1[0][i]=dp1[1][i];
		ZERO(dp1[1]);

		LOOP(i,1,_N) dp1[1][i]=dp1[0][i]+dp1[1][i-1];

		LOOP(i,1,_N) if(dp[0][i])
			ans+=dp[0][i]*dp1[1][i-1];

		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = {1,2,3,4,5,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.41666666666666663; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 200; int Arr1[] = {1,3,8,18,45,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; int Arr3[] = {1,4,10,21,53,100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.25240407058279035; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,1,1,2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {1,1,1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.25; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 200; int Arr1[] = {6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; int Arr3[] = {3,4,6,5,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.49416239842107595; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arr1[] = {1,1,1,1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 199; int Arr3[] = {1,1,1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1.5306467074865068E-78; verify_case(4, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    DiceThrows ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
