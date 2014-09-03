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



class ChooseTheBestOne 
{

	public:
	int countNumber(int N) 
	{
		int ans = 0;
		vector<int> a;
		a.resize(N);
		loop(i,N) a[i]=i;
		
		int stage=N;
		int pos=0;
		loop(i,N-1)
		{
			long long t=pow((i+1),3);	
			t+=pos-1;
			t%=stage;
			a.erase(a.begin()+t);

			stage--;
			pos=t%stage;
		}
		
		ans=a[0]+1;

		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; verify_case(0, Arg1, countNumber(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 6; verify_case(1, Arg1, countNumber(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 8; verify_case(2, Arg1, countNumber(Arg0)); }
	void test_case_3() { int Arg0 = 1234; int Arg1 = 341; verify_case(3, Arg1, countNumber(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    ChooseTheBestOne ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
