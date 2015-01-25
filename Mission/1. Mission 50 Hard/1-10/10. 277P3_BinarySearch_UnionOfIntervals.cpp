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
	vector<int> lb, ub;

	int bSearchAdv(int high, int low)
	{
		while(high>low) 
		{
			int mid = ((long long)high+low+1)/2;
			if(calVal(mid)<=target) low=mid;
			else high=mid-1;
		}
		return low;
	}

	long long calVal(long long x)
	{
		long long count=0;
		loop(i,X) if(lb[i]<=x)
		{
			if(x<=ub[i]) count+=(x-lb[i]); 
			else if(x>ub[i]) count+=(ub[i]-lb[i]+1); 
		}           
		return count;
	}
};

class UnionOfIntervals 
{

	public:
	int nthElement(vector <int> lowerBound, vector <int> upperBound, int n) 
	{
		binSearch bs;
		bs.X= lowerBound.size();
		bs.target=n;		
		bs.lb=lowerBound;
		bs.ub=upperBound;

		int high=*max_element(All(upperBound));
		int low=*min_element(All(lowerBound));
		return bs.bSearchAdv(high,low);

	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6; verify_case(0, Arg3, nthElement(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 1, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(1, Arg3, nthElement(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { -1500000000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1500000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1500000091; int Arg3 = 91; verify_case(2, Arg3, nthElement(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    UnionOfIntervals ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
