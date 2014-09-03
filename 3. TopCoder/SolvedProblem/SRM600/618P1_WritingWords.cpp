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

class WritingWords 
{

	public:
	int write(string word) 
	{
		int ans = 0;
		int X = word.size();		
		loop(i,X)
		{
		 ans += word[i]-0x40;
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; int Arg1 = 1; verify_case(0, Arg1, write(Arg0)); }
	void test_case_1() { string Arg0 = "ABC"; int Arg1 = 6; verify_case(1, Arg1, write(Arg0)); }
	void test_case_2() { string Arg0 = "VAMOSGIMNASIA"; int Arg1 = 143; verify_case(2, Arg1, write(Arg0)); }
	void test_case_3() { string Arg0 = "TOPCODER"; int Arg1 = 96; verify_case(3, Arg1, write(Arg0)); }
	void test_case_4() { string Arg0 = "SINGLEROUNDMATCH"; int Arg1 = 183; verify_case(4, Arg1, write(Arg0)); }
	void test_case_5() { string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"; int Arg1 = 1300; verify_case(5, Arg1, write(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    WritingWords ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
