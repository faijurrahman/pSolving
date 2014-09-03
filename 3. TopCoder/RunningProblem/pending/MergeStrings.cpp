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
#define _N 100
int dp[_N][_N];

class MergeStrings 
{

	public:
	bool isOne(int num, int pos)
	{
		return (num & 1<<pos)  == 1;
	}

	string getmin(string S, string A, string B) 
	{
		int Z = S.size();
		unsigned long int bZ = (unsigned long int)(1<<Z);
		int X = A.size();
		int Y = B.size();
		string ans="";
		
		for(unsigned long int k=0; k<bZ; k++) 
		{
			
			int ai=0, bi=0;
			char tS=0;
			string t="";		
			loop(i,Z)
			{	
				tS=0;
				if(isOne(k,i))
				{				
					if(ai<X) tS=A[ai++]; 
					else tS=0; 
				}	
				else if(bi<Y) tS=B[bi++]; 
				else tS=0;

				if(tS!=0 && (tS == S[i] || S[i]=='?')) t+=tS;
			}
		
			if(t.length()==Z && (ans=="" || t<ans)) ans = t;

		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "??CC??"; string Arg1 = "ABC"; string Arg2 = "BCC"; string Arg3 = "ABCCBC"; verify_case(0, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "WHAT?"; string Arg1 = "THE"; string Arg2 = "WA"; string Arg3 = ""; verify_case(1, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "PARROT"; string Arg1 = "PARROT"; string Arg2 = ""; string Arg3 = "PARROT"; verify_case(2, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "???????????"; string Arg1 = "AZZAA"; string Arg2 = "AZAZZA"; string Arg3 = "AAZAZZAAZZA"; verify_case(3, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "????K??????????????D???K???K????????K?????K???????"; string Arg1 = "KKKKKDKKKDKKDDKDDDKDKK"; string Arg2 = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"; string Arg3 = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"; verify_case(4, Arg3, getmin(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    MergeStrings ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
