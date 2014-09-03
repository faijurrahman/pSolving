//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()
#define ZERO(arr) memset(arr,0,sizeof(arr))

#define mod 1000000007
#define N 100
int dp[N][N];

class PalindromeMatrix 
{

	public:
	int minChange(vector<string> A, int rowCount, int columnCount) 
	{
		ZERO(dp);
		
		int X = A.size();
		int Y = A[0].size();
		int ans=INT_MAX;
		loop(m,X-rowCount+1) loop(n,Y-columnCount+1) 
		{
			int cost=0, count;
			int mR=m+rowCount/2, nC=n+columnCount/2;
			int mP=2*m+rowCount-1, nP=2*n+columnCount-1;
			LOOP(i,m,mR) LOOP(j,n,nC)
			{
				int a = A[i][j]=='1';
				int b = A[i][nP-j]=='1';
				int c = A[mP-i][j]=='1';
				int d = A[mP-i][nP-j]=='1';
				count = a+b+c+d;
				cost += min(count,4-count);		
			}

			if(rowCount%2==1) LOOP(j,n,n+columnCount/2)
			{
				int a = A[mR][j]=='1';
				int b = A[mR][nP-j]=='1';
				count = a+b;
				cost += min(count,2-count);		
			}

			if(columnCount%2==1) LOOP(i,m,m+rowCount/2)
			{
				int a = A[i][nC]=='1';
				int b = A[mP-i][nC]=='1';
				count = a+b;
				cost += min(count,2-count);		
			}
			MIN(ans,cost);
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"01"
,"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1110"
,"0001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(3, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 8; verify_case(4, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 9; int Arg3 = 14; verify_case(5, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 8; int Arg3 = 31; verify_case(6, Arg3, minChange(Arg0, Arg1, Arg2)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    PalindromeMatrix ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
