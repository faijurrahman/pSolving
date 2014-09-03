//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) LOOP(i,0,n)

class LeftAndRightHandedDiv2 
{

	public:
	int count(string S) 
	{

		
		int X = S.size();

		int c=0;
		char last = S[0];
		for(int i=1; i<X; i++)
		{
			if(last == 'R' && S[i] == 'L') c++;
	
			last = S[i];
		}
		return c;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "L"; int Arg1 = 0; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "LRLRLR"; int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "LLLRRR"; int Arg1 = 0; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "RLRLRL"; int Arg1 = 3; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    LeftAndRightHandedDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
