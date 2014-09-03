//C Header
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>

//STL Header
#include<array>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
//#include<forward_list>
//#include<unordered_map>
//#include<unordered_set>

//Essential Header
#include<algorithm>
#include<numeric>
#include<string>

//IO Header
#include<iostream>
#include<fstream> 
#include<sstream>

using namespace std;

//Some Definition
#define LOOP(i,a,b) for(int i=(a);i<(b);i++)
#define loop(i,n) LOOP(i,0,n)

#define dLOOP(i,a,b) for(int i=(a);i>=(b);i--)
#define dloop(i,n) dLOOP(i,0,n)


#define All(container) container.begin(),container.end()
#define rAll(container) container.rbegin(),container.rend()


class BinPackingEasy {

	public:
	int minBins(vector <int> item) {
		sort(All(item));

		int c=0, sum=0, p;
		while(!item.empty())
		{
			c++;
			sum=0;
			p=item.size()-1;
			while(p>=0)
			{
				if(sum+item.at(p)<=300)
				{
					sum+=item.at(p);
					item.erase(item.begin()+p);
				}
				p--;
			}
		}
		return c;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {150, 150, 150, 150, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minBins(Arg0)); }
	void test_case_1() { int Arr0[] = {130, 140, 150, 160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minBins(Arg0)); }
	void test_case_2() { int Arr0[] = {101, 101, 101, 101, 101, 101, 101, 101, 101}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, minBins(Arg0)); }
	void test_case_3() { int Arr0[] = {101, 200, 101, 101, 101, 101, 200, 101, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, minBins(Arg0)); }
	void test_case_4() { int Arr0[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minBins(Arg0)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    BinPackingEasy ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
