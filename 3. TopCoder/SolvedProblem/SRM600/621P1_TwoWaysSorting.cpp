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
#define All(c) (c).begin(),(c).end()



class TwoWaysSorting 
{

	public:
	string sortingMethod(vector <string> stringList) 
	{

		int X = stringList.size();
		if(X==1) return "both";

		bool len=true, lex=true;
		loop(i,X-1)
		{
			int Y = stringList[i].size(); 
			int Z = stringList[i+1].size();
			
			for(int j=0; j<Y && j<Z; j++) 
				if(stringList[i][j] > stringList[i+1][j]) lex=false;	
			//if(lex && Y>Z) lex=false;
			if(Y>Z) len=false;
		}

		if(lex && len) return "both";
		else if(lex) return "lexicographically"; 
		else if(len) return "lengths";
		return "none";
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"afzmd", "aizgprtuchtxouwtqgzxnvmcaoitzpxqrcaltloukiygnmc", "akqkikdgnhduisqawpznqxpdlnfwslquxoptulfxlwuufinsdf", "bjltywdrgpjteyg", "cwewapumhggpsescaudk", "fzkexkpdvllsozehdqqkerhvlrc", "hsresaf", "nrgvhmfueoaqvxodwzibkcdpdnafhepeujbxoomxmrltozlkc", "sgoqtrfaehdncijxvoilpxvnkjoiiaxpclzlkmowrx", "wkwdjzagzyklffbhdqkbadssly"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(0, Arg1, sortingMethod(Arg0)); }
	void test_case_1() { string Arr0[] = {"c", "bb", "aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lengths"; verify_case(1, Arg1, sortingMethod(Arg0)); }
	void test_case_2() { string Arr0[] = {"etdfgfh", "aio"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "none"; verify_case(2, Arg1, sortingMethod(Arg0)); }
	void test_case_3() { string Arr0[] = {"aaa", "z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(3, Arg1, sortingMethod(Arg0)); }
	void test_case_4() { string Arr0[] = {"z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(4, Arg1, sortingMethod(Arg0)); }
	void test_case_5() { string Arr0[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(5, Arg1, sortingMethod(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    TwoWaysSorting ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
