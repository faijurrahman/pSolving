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
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
long dp[2000];
// extract divisors of n:
vector<int> getDivisors(int n)
{
    vector<int> div;
    for(int i=1; i*i<=n; i++) if(n%i==0) 
	{   
		div.push_back(i);
		if(n/i!=i) div.push_back(n/i);
    }
    sort(div.begin(), div.end());
    return div;
}
 
// Find x raised to the y-th power modulo MOD    
long modPow(long x, int y)
{
    long r=1;
    while(y>0) 
	{
        if(y&1) r=(r*x)%MOD;
        x=(x*x)%MOD;
        y/=2;
    }
    return r;
}

class PairsOfStrings 
{

public:
int getNumber(int n, int k)
{
    vector<int> d=getDivisors(n);
    long res=0;
	ZERO(dp);

    for(int i=0; i<d.size(); i++) 
	{ 
        long x=modPow(k,d[i]);// find k ^ d[i]:
        for(int j=0; j<i; j++) if(d[i]%d[j]==0) x=(x-dp[j]+MOD)%MOD;
        dp[i]=x;
        res+=(dp[i]*d[i])%MOD;
    }
    return (int)(res%MOD);
}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 6; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 20; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 184; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 348; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 26; int Arg2 = 46519912; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    PairsOfStrings ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
