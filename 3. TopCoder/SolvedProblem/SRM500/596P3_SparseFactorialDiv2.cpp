//C Header
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>

//STL Header
#include<array>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
//#include<forward_list>
//#include<unordered_map>
//#include<unordered_set>

//Essential Header
#include<algorithm>
#include<numeric>
#include<string>

//IO Header
#include<iostream>
#include<fstream> 
#include<sstream>

using namespace std;

//Some Definition
#define LOOP(i,a,b) for(int i=(a);i<(b);i++)
#define loop(i,n) LOOP(i,0,n)

#define All(container) container.begin(),container.end()
#define rAll(container) container.rbegin(),container.rend()


class SparseFactorialDiv2 {

	public:
	long long getCount(long long lo, long long hi, long long divisor) {
			long long c=0, p=1;
			for(long long i=lo;i<=hi;i++)
			{
				for(int j=0;(i-pow(j,2))>0;i++) p*=i-pow(j,2);
				if(p%divisor==0) c++;

			}
			return c;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 3LL; long long Arg3 = 3LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 9LL; long long Arg1 = 11LL; long long Arg2 = 7LL; long long Arg3 = 1LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000000000000LL; long long Arg2 = 2LL; long long Arg3 = 999999999999LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 16LL; long long Arg1 = 26LL; long long Arg2 = 11LL; long long Arg3 = 4LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 10000LL; long long Arg1 = 20000LL; long long Arg2 = 997LL; long long Arg3 = 1211LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 123456789LL; long long Arg1 = 987654321LL; long long Arg2 = 71LL; long long Arg3 = 438184668LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    SparseFactorialDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
