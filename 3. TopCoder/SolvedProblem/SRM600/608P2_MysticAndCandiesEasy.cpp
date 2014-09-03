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

class MysticAndCandiesEasy {

public:
	int minBoxes(int C, int X, vector <int> high) {
		sort(All(high));
		int c, n = high.size();
		c=n;
		vector <int> t;
		for(int i=0; i<n; i++)
		{
			C -= high[i];
			if( C>=X )
			{
				c = n-(i+1);
			}
		}


		return c;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, minBoxes(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 7; int Arr2[] = {3, 3, 3, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minBoxes(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 63; int Arr2[] = {12, 34, 23, 45, 34}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(2, Arg3, minBoxes(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 19; int Arg1 = 12; int Arr2[] = {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 22; verify_case(3, Arg3, minBoxes(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 326; int Arg1 = 109; int Arr2[] = {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 15; verify_case(4, Arg3, minBoxes(Arg0, Arg1, Arg2)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	MysticAndCandiesEasy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
