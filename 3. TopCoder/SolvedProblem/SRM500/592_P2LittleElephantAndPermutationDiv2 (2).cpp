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
//long long ar[SZ][SZ];

class LittleElephantAndPermutationDiv2 
{
	public:
	long long getNumber(int N, int K) 
	{
		unsigned long long c=0, sum=0;
		vector<int> A,B;
		for(int i=1; i<=N; i++)
		{
			A.push_back(i);
			B.push_back(i);
		}
			
		do
		{
			sum=0;
			for(int j=0; j<N; j++)
			{
				sum+=max(A.at(j), B.at(j));
			}

			if( sum >= K)
			{
				c++;
			}
				
		}
		while(next_permutation(All(B)) );

		for(int j=1; j<=N; j++) c*=j;

		return c;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; long long Arg2 = 4LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; long long Arg2 = 18LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 47; long long Arg2 = 13168189440000LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    LittleElephantAndPermutationDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
