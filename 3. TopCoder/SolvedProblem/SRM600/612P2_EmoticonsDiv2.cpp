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
#define ITR(i,n) for(__typeof(c.begin()) x=c.begin(); x!=c.end(); x++)
#define All(c) c.begin(),c.end()
#define rAll(c) c.rbegin(),c.rend()
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define ZERO(arr) memset(arr,0,sizeof(arr))

#define mod 1000000007
#define N 1010
int dp[N];

class EmoticonsDiv2 
{

	public:
	int printSmiles(int smiles) 
	{
		ZERO(dp);
		for(int i=2; i<=smiles; i++)
		{
			int div = 1;
			for(int j=i-1; j>=2; j--) if(i%j==0){ div = j; break;}
			if(div==1) dp[i] = i;
			else dp[i] = dp[div]+max(i/div,2);
		}
		return dp[smiles];
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 5; verify_case(1, Arg1, printSmiles(Arg0)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 11; verify_case(2, Arg1, printSmiles(Arg0)); }
	void test_case_3() { int Arg0 = 16; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 21; verify_case(4, Arg1, printSmiles(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    EmoticonsDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
