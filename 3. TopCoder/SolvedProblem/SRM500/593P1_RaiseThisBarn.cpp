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


class RaiseThisBarn {

	public:
	int calc(string str) {
		int i, cc=0,c=0,n=str.size();
		for(i=0;i<n;i++) if(str.at(i)=='c') c++;
		if(c%2!=0) return 0;
		if(c==0) return n-1;

		for(i=0;i<n;i++)
		{
			if(str.at(i)=='c') cc++;
			if(cc==c/2) break;
		}

		for(int j=i+1;j<n;j++)
		{
			string s=str.substr(j);
			int pos=str.substr(j).find('c');
			if(pos!=string::npos) return pos+1;
		}
		return 0;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cc..c.c"; int Arg1 = 3; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arg0 = "c....c....c"; int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arg0 = "............"; int Arg1 = 11; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arg0 = ".c.c...c..ccc.c..c.c.cc..ccc"; int Arg1 = 3; verify_case(3, Arg1, calc(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    RaiseThisBarn ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
