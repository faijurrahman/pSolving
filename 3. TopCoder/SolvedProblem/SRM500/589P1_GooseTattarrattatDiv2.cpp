#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<iostream>
using namespace std;

#define LOOP(i,a,b) for(int i=(a);i<(b);i++)
#define loop(i,n) LOOP(i,0,n)
#define All(container) container.begin(),container.end()
#define rAll(container) container.rbegin(),container.rend()

//Max Value long long 2500*2500 = int 4000*4000 = 64MB
#define SZ 2000 
long long ar[SZ][SZ];

class GooseTattarrattatDiv2 
{
	public:
	int getmin(string S) 
	{
		sort(All(S));
				
		int n1 = S.size();
		if(n1==0) return n1;
		int a=1,mx=1;
		for(int i=1; i<n1; i++)
		{
			if(S[i-1] == S[i]) mx=max(mx,++a);
			else a=1;
		}

		return n1-mx;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 6; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "www"; int Arg1 = 0; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 43; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    GooseTattarrattatDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
