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

#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))

class CatAndRat 
{

	public:
	double getTime(int R, int T, int Vrat, int Vcat) 
	{
		if(Vrat>=Vcat) return -1.0;
		double pi=2*acos(0);
		double d0=T*Vrat;
		MIN(d0,pi*R);
		return d0/(Vcat-Vrat);
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; double Arg4 = -1.0; verify_case(0, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; double Arg4 = 1.0; verify_case(1, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; double Arg4 = -1.0; verify_case(2, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 1; int Arg3 = 1000; double Arg4 = 1.001001001001001; verify_case(3, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000; int Arg2 = 1; int Arg3 = 2; double Arg4 = 3.141592653589793; verify_case(4, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    CatAndRat ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
