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
#define _N 100
int dp[_N][_N];

class binSearch
{
	public:
	int X;
	int target;
	long long loan;
	double rate;
	binSearch(int tar)
	{
		target=tar;
	}
	binSearch(int l, int r, int tar)
	{
		loan=l, rate=(double)r;
		target = tar;
	}

	long long bSearchAdv(long long high, long long low)
	{
		while(high>low+1) 
		{
			long long mid = low+(high-low)/2;
			if(isOk(mid)) high=mid;
			else low=mid;
		}
		return high;
	}

	bool isOk(long long monthly)
	{
		long long amount=loan;
		loop(i,target)
		{
			amount-=monthly;
			if(amount<=0) return true;
			amount+=ceil((amount*rate)/12000);
			if(loan<amount) return false;
		}
		return false;
	}
};

class Mortgage 
{

	public:
	int monthlyPayment(int loan, int interest, int term) 
	{
		binSearch bs(loan, interest, term*12);
		return bs.bSearchAdv(loan,0);
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 50; int Arg2 = 1; int Arg3 = 86; verify_case(0, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2000000000; int Arg1 = 6000; int Arg2 = 1; int Arg3 = 671844808; verify_case(1, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1000; int Arg3 = 988143; verify_case(2, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 129; int Arg2 = 30; int Arg3 = 10868; verify_case(3, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1999999999; int Arg1 = 1000000; int Arg2 = 1; int Arg3 = 1976284585; verify_case(4, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    Mortgage ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
