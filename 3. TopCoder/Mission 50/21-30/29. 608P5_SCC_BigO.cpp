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

class BigO 
{

	public:
	int minK(vector <string> graph) 
	{
		int ans=0, X=graph.size();	vector<bool> seen(X);	
		loop(i,X) loop(j,X) dp[i][j]=((graph[i][j]=='Y')?1:0);
		loop(k,X) loop(i,X) loop(j,X) dp[i][j] |= dp[i][k] & dp[k][j];
		loop(i,X) if(!seen[i]) 
		{
			vector<int> scc(1,i);
			LOOP(j,i+1,X) if(dp[i][j] && dp[j][i]) scc.push_back(j), seen[j]=1;     
			for(int j:scc) 
			{
				int deg=0;
				for(int k:scc) if(j!=k && graph[j][k]=='Y') deg++;
				if(deg>1) return -1;
				MIN(ans,deg);
			}
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, minK(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY",
 "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minK(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNNN",
 "YNNNN",
 "NNNYN",
 "NNNNY",
 "NNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minK(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYYNYYYNNYYYYYYNYNN",
 "NNNNYNYYNNYYYNYYNYYN",
 "NYNNYYYNNNYYYYNYNYNN",
 "NYYNNYYYYNNNYYNNYNYY",
 "NYNYNNNNNNYYYYYNYYYN",
 "YNNNNNNYNNYNNYYYYYYY",
 "NNYYNNNNNYNYNYNNYNYY",
 "NNYNYYNNNNYNYNYYYYNN",
 "NYYNYYNNNYNNYYYNYNYN",
 "YYNNYNNYYNYNNNNNYNNN",
 "YYNYYNNYYYNYYNYNYYYY",
 "YYNNYYNYNYNNNNYNNNNY",
 "NNYYNYYYNNNNNYYYYYNY",
 "YNNNYNNNNYNNNNNYNNNY",
 "YYYYNYYNNYNNNNNYNNNN",
 "NYYYYNYNYYNNYNNNYNNY",
 "YYYYYNNNYYYYNYYYNNYN",
 "NNYNNYNYNYNNNNNNYNYN",
 "YYNYYNNNNNYNNYNYNNNY",
 "YYYYNYNYYNNYNYNYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minK(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYNYYYNYYYNYYNYYNYYNYYNYNNYYYYNNNYYNNNYNYYNYNNNYNY",
 "NNNNNNNNNNNNNNNNYNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNNNN",
 "NYNYYYYNYNYYNNYYYYYYYYYYNYYYNYYYYYYNNYYYYYYYNNYYYY",
 "NYNNYYNNNNNNNNNNNYNNNYNYNNYNYNYYNYYNNYYYNNNNNNNYYY",
 "NNNNNNNNNNNNYNNYYNNNYNNNNYNNYNNYNNYNNYNYNNNNNNNYYN",
 "NNNNNNNNNNNNNNNNYNNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNN",
 "YYNYNNNYNYYYYNYYYYYYYYYYNYYYYYYYNYYNNYNYYYYYNNYNYY",
 "NYNYYNNNYYNNYNNYYYNNYYNYNYYNYYYNNNYNNYYYNNNNNNNYYY",
 "NYNYYYNYNYNNNNNYYYNNNNNNNYYNYYYYNYYNNYYYNNNNNNNYYY",
 "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYNNYYNNYNYNNNYNNNNYN",
 "NYNYYYNNYYNYYNYNYYNYYYNYNYYNYYYYNYNNNNYYYYNYNNNYNY",
 "NYNNYYNNNYNNYNNYYYNNYYNNNYYNYYNNNYYNNNNYNNNYNNNYYY",
 "NNNNNNNNNNNNNNNYYNNNYNNNNNNNYNNYNYNNNYYNNNNNNNNYNN",
 "YYYYNYYYYYYYYNYYYYNYYYYYYYYYYYNYYNYYYNYYYYYNNYYNYN",
 "NYNYYNNYYYNYYNNYYYNYNYNYNYYNYYYYNYYNNYYYYYNYNNNNNY",
 "NYNNNNNNNNNNNNNNYNNNYNNNNNYNYNYYNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYYNNNNNNNNNNNYNYYNYYNNYNNNNNNNNNYYN",
 "NYNYYYNNYYNYNNYYYYNYYYNYNYYYYNNYNNYNNYNYYYYNNNYYYY",
 "NNNYYYNNNYNYYNNYYYNNYYNNNYYNYYYYNYYNNNYYNYNYNNNYYY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYNNNNNNNNNYYNYYYYNYYNNYNNNNNNNNNYYN",
 "YYNYYYNNYYNYYNYNYYNYNYNYNYYYYYYYNYNNNYYYYYNYNNYYYY",
 "NYNYYYNNNNNNYNNNYYNNYYNNNYYNYYYYNYYNNYYYNNNNNNNYNY",
 "YNNNYYYYYYYYYNYYYYYYYYYNNYYNYNYNYNNYYYYYYYNYNNYYYY",
 "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYYNYYNNNNYNNNNNNNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
 "NYNYYYNYYYNYNNNNYYNYYNNYNYYNYYYYNYYNNNNNYYNYNNYYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYYNNNYNNNNNNNNNYYNYYNNNNYNNNNNNNYYY",
 "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNNNYNNNNNYNNNYNNNNNNNNNNNNNNNNNNN",
 "NYNYYNNYYYNNNNNYYYNYYYNNNYYYYYYYNYYNNYYYYNNYNNNNYY",
 "NNNNNNNNNNNNNNNYYNNNYNNNNNYNYNYYNNNNNYNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNNYNNNYNNNNNYNNNYYNNNNNNNNNNNNNNNYNN",
 "NYNYYYYYNYYYYNYYYYYYNYYYNNNYYYYYNYYNYNYYYYYYNYYYNY",
 "YYNYYYNYYYNNNNNYNYYYYNYNNNYYYYYYNYYNNYYNYNNYNNYNNY",
 "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYYNNNNYNNNNYNYNNYNNNNNYNYNNNNNNNYNN",
 "NYNNNYNNNNNNNNNYYNNNNNNNNYYNYNYNNYYNNNNNNNNNNNNYNN",
 "NYNYYYNYYYNYNNNNNYNNYYNYNNYNNYYYNYYNNYYYNNNNNNNYYY",
 "NYNYYNNNNYNYYNNYYYNYYYNNNYYNYYYNNYYNNYYYNNNYNNNNYY",
 "NYNYNYNYYYNYYNYYNYNYNYYYNNYYYYYYNNNNNYYYNYNYNNYNYY",
 "NYNNNYNNNYNNNNNYYYNNYNNNNNYNYNNNNYYNNYNYNNNNNNNYYN",
 "YYYNNYNYYYNYNNYYYYYNYYNYNYYYYYNYYNYNYYYYYNNYNNYNYN",
 "YYNNYYYYYYYNYNYYNYYYYYYYYYYNYYYNYYYNNYYYYNYYNNYYYY",
 "NYNNYYNYYYNNYNNYYYNYNYNYNYYNNYYNNYNNNYYYNYNYNNNNYY",
 "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNYNN",
 "NYNNYYNNNNNNNNNYYNNNNNNNNYYNYNNYNYYNNYNYNNNNNNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minK(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    BigO ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
