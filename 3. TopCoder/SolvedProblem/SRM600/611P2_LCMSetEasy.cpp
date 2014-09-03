//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

class LCMSetEasy 
{
	long long gcd(long long m, long long n )
	{
		long long rem;
		while( n != 0 )
		{
			rem = m % n;
			m = n;
			n = rem;
		}
		return m;
	}

	long long lcm(long long m, long long n )
	{
		return((long long)(m*n)/gcd(m,n) );
	}

public:
	string include(vector <int> S, int x) 
	{
		long long l = 1; 
		for (int v : S) if(x % v == 0) l = lcm(l, v); 
		if (l == x) return "Possible"; 
		return "Impossible"; 
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 232792560; string Arg2 = "Possible"; verify_case(0, Arg2, include(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {858993462,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; string Arg2 = "Impossible"; verify_case(1, Arg2, include(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "Possible"; verify_case(2, Arg2, include(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; string Arg2 = "Possible"; verify_case(3, Arg2, include(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100,200,300,400,500,600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000; string Arg2 = "Possible"; verify_case(4, Arg2, include(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {100,200,300,400,500,600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8000; string Arg2 = "Impossible"; verify_case(5, Arg2, include(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {1000000000,999999999,999999998}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999999; string Arg2 = "Possible"; verify_case(6, Arg2, include(Arg0, Arg1)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	LCMSetEasy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

