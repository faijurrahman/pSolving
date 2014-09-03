#include <iostream>
#include<string>
#include<iostream> 
#include<algorithm>
#include<queue>
#include<stack>
#include<numeric>
#include<vector>
#include<set>
#include<sstream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include<map>
using namespace std;

class TypoCoderDiv2 {

	public:
	int count(vector <int> rating) {
		int lastRating = 500, count = 0;
		for(int i=0;i<rating.size();i++)
		{
			if( (rating[i]>=1200 && lastRating < 1200) ||
				(rating[i]<1200 && lastRating >= 1200) )
			{
				count++;
			}
			lastRating = rating[i];
		}
		return count;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1000,1200,1199}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {1500,2200,900,3000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {600,700,800,900,1000,1100,1199}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {0,4000,0,4000,4000,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {575,1090,3271,2496,859,2708,3774,2796,1616,2552,3783,2435,1111,526,562}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    TypoCoderDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
