//C Header
#include<set>
#include<stack>
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

struct point
{
public:
	long long x,y; int z;
	point(int a, int b, int c){x=a;y=b;z=c;}
};

class PowerOfThree 
{

	public:
	string ableToGet(int x, int y) 
	{
		stack<point> s;s.push(point(0,0,0));
		while(!s.empty())
		{
			point p=s.top(); s.pop();
			if(max(p.x,p.y)==max(x,y) && min(p.x,p.y)==min(x,y)) return "Possible";
			if(p.z<11)
			{
				loop(i,2) loop(j,2)
				{
					long long v=pow(3,(long long)p.z); 
					point np=p;
					if(i) np.x+=j?v:-v; 
					else np.y+=j?v:-v; 
					np.z++;
					s.push(np);
				}
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
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -6890; int Arg1 = 18252; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1000000000; int Arg1 = -1000000000; string Arg2 = "Impossible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 0; int Arg1 = 0; string Arg2 = "Possible"; verify_case(7, Arg2, ableToGet(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    PowerOfThree ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
