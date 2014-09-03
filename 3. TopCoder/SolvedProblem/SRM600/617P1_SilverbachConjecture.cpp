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

class SilverbachConjecture 
{
	bool isCom(int n)
	{
		for(int i=2; i<n; i++) if(n%i==0) return true;
		return false;
	}
	public:
	vector <int> solve(int n) 
	{
		vector<int> res;
		set<int> ans;
		for(int i=n-2; i>=2; i--)
		{
			if(isCom(i)) ans.insert(i);
		}
		
		for(set<int>::iterator it1=ans.begin(); it1!=ans.end(); it1++)
			for(set<int>::iterator it2=ans.begin(); it2!=ans.end(); it2++)
			{

				if(it1!=it2) if((*it1)+(*it2) == n) {res.push_back(*it1); res.push_back(*it2); return res;}
			}
		return res;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 20; int Arr1[] = {8, 12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arg0 = 30; int Arr1[] = {15, 15 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arg0 = 999; int Arr1[] = {699, 300 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arg0 = 45; int Arr1[] = {15, 30 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    SilverbachConjecture ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
