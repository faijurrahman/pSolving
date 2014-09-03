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

class UndoHistory {

public:
	int minPresses(vector <string> lines) 
	{
		int n= lines.size();
		int c=0;
		for(int i=0; i<n; i++)
		{
			string s = lines[i];
			int t = s.size()+1;
			int opt=0;

			if(i!=0) 
			{
				for(int j=i-1; j>=0; j--)
				{
					string str = lines[j];
					int m=0;

					if(s.size()>str.size())
						m = str.size();
					else
						m = s.size();

					
					for(int k=m; k>0; k--)
					{
						if(s.substr(0,k) == str.substr(0,k))
						{
							if(k==str.size() && j==i-1)
							{
								opt = max(opt,2+k);
							}
							else
							{
								opt = max(opt,k);
							}
							break;
						}

					}
				}
				t+=(2-opt);
			}

			c+=t;
		}

		return c;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tomorrow", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, minPresses(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minPresses(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "ab", "abac", "abacus" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minPresses(Arg0)); }
	void test_case_3() { string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(3, Arg1, minPresses(Arg0)); }
	void test_case_4() { string Arr0[] = {"ba","a","a","b","ba"}
	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minPresses(Arg0)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	UndoHistory ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
