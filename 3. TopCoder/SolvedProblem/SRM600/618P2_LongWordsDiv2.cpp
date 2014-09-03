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

class LongWordsDiv2 
{

	public:
	string find(string word) 
	{
		bool ok = true;
		int X = word.size();
		
		
		for(int i=1; i<X; i++)
			if(word[i-1]==word[i]) ok=false;
		if(!ok) return "Dislikes";
		
		for(int i=0; i<X; i++)
			for(int j=i+1; j<X; j++)
			{
				string a="";
				a+= word[i];
				a+= word[j];

				for(int k=j+1; k<X; k++)
					for(int l=k+1; l<X; l++)
					{
						string b="";
						b+= word[k];
						b+= word[l];

						if(a==b) ok=false;
					}

			}
		return ok?"Likes":"Dislikes";
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAA"; string Arg1 = "Dislikes"; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arg0 = "ABCBA"; string Arg1 = "Likes"; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arg0 = "ABCBAC"; string Arg1 = "Dislikes"; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arg0 = "TOPCODER"; string Arg1 = "Likes"; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arg0 = "VAMOSGIMNASIA"; string Arg1 = "Dislikes"; verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { string Arg0 = "SINGLEROUNDMATCH"; string Arg1 = "Likes"; verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { string Arg0 = "DALELOBO"; string Arg1 = "Likes"; verify_case(6, Arg1, find(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    LongWordsDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
