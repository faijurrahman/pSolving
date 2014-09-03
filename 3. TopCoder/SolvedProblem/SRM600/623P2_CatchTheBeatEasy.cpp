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

#define _N 50
struct xy
{
	int x,y;
	xy(int _x, int _y){ x=_x, y=_y;}	
	bool operator <(xy pos) const { return y<pos.y;}	
};

class CatchTheBeatEasy 
{

	public:
	string ableToCatchAll(vector <int> x, vector <int> y) 
	{
		int X = x.size();
		vector<xy> pos;
		loop(i,X) pos.push_back(xy(x[i],y[i]));
		sort(All(pos));
		xy cpos=xy(0,0);

		loop(i,X) 
		{
			if(pos[i].y<(abs(pos[i].x-cpos.x)+cpos.y)) return "Not able to catch";
			else cpos.y=pos[i].y, cpos.x=pos[i].x;
		}
		return "Able to catch";
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(0, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not able to catch"; verify_case(1, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not able to catch"; verify_case(2, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, -1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(3, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {70,-108,52,-70,84,-29,66,-33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {141,299,402,280,28,363,427,232}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not able to catch"; verify_case(4, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(5, Arg2, ableToCatchAll(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Able to catch"; verify_case(6, Arg2, ableToCatchAll(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    CatchTheBeatEasy ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
