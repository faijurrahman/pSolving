//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

#define All(c) (c).begin(),(c).end()



class TheNumberGameDiv2 
{

	public:
	int minimumMoves(int A, int B) 
	{
		string sa = to_string(A);
		string sb = to_string(B);
		
		int X = sa.size();
		int Y = sb.size();

		bool isPalin=true;
		for(int i=0; i<Y/2; i++)
			if(sb[i] != sb[Y-1-i])
			{
				isPalin=false;
				break;
			}

		int c=X-Y, rc=X-Y;
		int fpos = sa.find(sb);
		if( fpos != string::npos)
		{
			if(X == Y) c=0;
			else if(fpos==0) c=c;
			else if(isPalin) c++;
			else c+=2;

		}
		else
		{
			c = -1;
		}

		reverse(All(sa));
		fpos = sa.find(sb);
		if( fpos != string::npos)
		{
			if(X == Y) rc=1;
			else rc++;
		}
		else
		{
			rc=-1;
		}


		if(c!=-1 && rc!=-1) return min(c,rc);
		if(c!=-1) return c;
		if(rc!=-1) return rc;

		return -1;
	}
	


	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 25; int Arg1 = 5; int Arg2 = 2; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5162; int Arg1 = 16; int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 334; int Arg1 = 12; int Arg2 = -1; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 218181918; int Arg1 = 9181; int Arg2 = 6; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9798147; int Arg1 = 79817; int Arg2 = -1; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    TheNumberGameDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
