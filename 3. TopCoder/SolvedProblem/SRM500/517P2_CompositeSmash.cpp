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


class CompositeSmash 
{
	public:
	string thePossible(int num, int target) 
	{
		if(num==target) return "Yes";
		if(num%target) return "No";

		bool ok = false;
		for(int i=2; i*i<=num; i++)
		{
			if(num%i==0) 
			{
				ok = true;
				if( thePossible(i, target) == "No" && thePossible(num/i, target) == "No") return "No";
			}
		}

		return ok?"Yes":"No";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 517;		int Arg1 = 47;		string Arg2 = "Yes";	verify_case(0, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8;			int Arg1 = 4;		string Arg2 = "Yes";	verify_case(1, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12;			int Arg1 = 6;		string Arg2 = "No";		verify_case(2, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5;			int Arg1 = 8;		string Arg2 = "No";		verify_case(3, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000;		int Arg1 = 100000;	string Arg2 = "Yes";	verify_case(4, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 5858;		int Arg1 = 2;		string Arg2 = "Yes";	verify_case(5, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 81461;		int Arg1 = 2809;	string Arg2 = "No";		verify_case(6, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 65536;		int Arg1 = 256;		string Arg2 = "No";		verify_case(7, Arg2, thePossible(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    CompositeSmash ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
