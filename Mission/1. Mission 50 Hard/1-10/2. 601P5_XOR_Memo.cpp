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
#define MAX_BITS 11
#define MAX_N 2000
long dp[MAX_N + 1][1 << MAX_BITS][2];

class WinterAndSnowmen 
{

public:
	int i, X, Y;
	int rec(int t, int z, int b)
	{
		long &res=dp[t][z][b];
		if(res==-1) 
		{
			if(t==0) 
			{
				if(z==1 && b==0) res=1;
				else res=0;
			}
			else
			{			
				res=rec(t-1,z,b);// xor number t to neither A or B:			
				if(t<=X) res+=rec(t-1, z^(t>>i), b^((t>>i)&1));// xor number t to A:		
				if(t<=Y) res+=rec(t-1, z^(t>>i), b);// xor number q = p+1 to B:
			}
		}
		return res%=MOD;
	}

	int getNumber(int N, int M)
	{
		long res = 0;
		this->X=N; this->Y=M;
		loop(i,MAX_BITS) 
		{
			FILL(dp,-1);
			this->i=i;
			res+=rec(max(X,Y),0,0);
		}
		return(res%MOD);
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 74; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 216; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 962557390; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	WinterAndSnowmen ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

