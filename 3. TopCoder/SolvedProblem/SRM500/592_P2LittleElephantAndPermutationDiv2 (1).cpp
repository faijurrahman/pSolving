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

class LittleElephantAndBooks 
{
	public:
	int getNumber(vector <int> pages, int number) 
	{
		sort(All(pages));
		long long sum=0;
		for(int i=0; i<number-1; i++)
		{
			sum+=pages.at(i);
		}
		sum+=pages.at(number);
		return sum;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {74, 7, 4, 47, 44}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 58; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3, 1, 9, 7, 2, 8, 6, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 29; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {74, 86, 32, 13, 100, 67, 77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 80; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    LittleElephantAndBooks ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
