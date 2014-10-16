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
#define _N 100
int dp[_N][_N];

class PrimePalindromic 
{
	bool isPrime(string str)
	{
		loop(i,str.size()/2) if(str[i]!=str[str.size()-i-1]) return false;
		return true;
	}

	public:
	int count(int A, int B) 
	{
		int ans = 0;
		
		LOOP(i,A,B+1)
		{
			vector<int> pl;
			int j, num=i;
			for(j=2; j*j<=num; j++)
				while(num%j==0){pl.push_back(j); num/=j;}
			if(num>1) pl.push_back(num);
			sort(All(pl));
			do
			{
				string str;
				loop(j,pl.size())
					str+=to_string(pl[j]);

				if(isPrime(str))
				{
					ans++; 
					break;
				}
			}
			while(next_permutation(All(pl)));
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2260; int Arg1 = 2262; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 9; int Arg2 = 7; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 36; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    PrimePalindromic ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
