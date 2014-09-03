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
#define ZERO(arr) memset(arr,0,sizeof(arr))

#define _N 20
int dp[_N];

class ColorfulCoinsEasy 
{

	public:
	string isPossible(vector <int> values) 
	{
		int X = values.size();
		int Y = values[X-1]+1;
				
		loop(i,Y)
		{
			ZERO(dp);
			int n=0;
			int amount = i;
			for(int j=X-2; j>=0; j--)
			{	
				if(amount>=values[j])
				{
					dp[j]=amount/values[j];
					amount%=values[j];
					n++;
				}
			}

			bool ok=true;
			if(amount==0 && n==X-1)
			{
				if((X-1)>1) 
					loop(r,X-1) for(int s=r+1; s<X-1;s++) 
						if(dp[r] == dp[s]) 
							ok=false;
				if(ok) return "Possible";
			}

		}

		return "Impossible";
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 5, 15, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 4, 20, 60, 180, 1440, 5760}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(4, Arg1, isPossible(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 7, 21, 105, 630, 3150, 18900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(5, Arg1, isPossible(Arg0)); }
	void test_case_6() { int Arr0[] = {1, 10, 30, 300, 900, 9000, 18000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(6, Arg1, isPossible(Arg0)); }
	void test_case_7() { int Arr0[] = {1, 2, 10, 40, 200, 1000, 4000, 20000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(7, Arg1, isPossible(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    ColorfulCoinsEasy ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
