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
#define loop(i,n) LOOP(i,0,n)
#define ITR(i,n) for(__typeof(c.begin()) x=c.begin(); x!=c.end(); x++)
#define All(c) c.begin(),c.end()
#define rAll(c) c.rbegin(),c.rend()
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define ZERO(arr) memset(arr,0,sizeof(arr))


class InterestingNumber 
{

	public:
	string isInteresting(string x) 
	{

		
		int X = x.size();
		int i, j;
		for(i=0; i<10; i++)
		{
			int c = 0;
			for(j=0; j<X; j++)
				if(x[j] - '0' == i) c++;

			if(c>2) return "Not interesting"; 

			for(j=0; j<X; j++)
				if(x[j] - '0' == i) break;

			if(j<X)
			{
				if((i+j+1)<X)
				{
					if(x[j] != x[i+j+1]) return "Not interesting"; 

					for(int k=j+1; k<i+j+1; k++)
						if(i == x[k]) return "Not interesting";	
					
				}	
				else
				{
					return "Not interesting";
				}
			}

		}
		return "Interesting";
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "2002"; string Arg1 = "Interesting"; verify_case(0, Arg1, isInteresting(Arg0)); }
	void test_case_1() { string Arg0 = "1001"; string Arg1 = "Not interesting"; verify_case(1, Arg1, isInteresting(Arg0)); }
	void test_case_2() { string Arg0 = "41312432"; string Arg1 = "Interesting"; verify_case(2, Arg1, isInteresting(Arg0)); }
	void test_case_3() { string Arg0 = "611"; string Arg1 = "Not interesting"; verify_case(3, Arg1, isInteresting(Arg0)); }
	void test_case_4() { string Arg0 = "64200246"; string Arg1 = "Interesting"; verify_case(4, Arg1, isInteresting(Arg0)); }
	void test_case_5() { string Arg0 = "631413164"; string Arg1 = "Not interesting"; verify_case(5, Arg1, isInteresting(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    InterestingNumber ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
