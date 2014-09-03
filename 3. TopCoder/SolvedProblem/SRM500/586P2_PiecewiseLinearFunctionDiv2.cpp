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
#include<new>

//IO Header
#include<iostream>
#include<fstream> 
#include<sstream>

using namespace std;

//Some Definition
#define LOOP(i,a,b) for(int i=(a);i<(b);i++)
#define loop(i,n) LOOP(i,0,n)

#define All(container) container.begin(),container.end()
#define rAll(container) container.rbegin(),container.rend()


class PiecewiseLinearFunctionDiv2 {

	public:
	vector <int> countSolutions(vector <int> Y, vector <int> query) {
		
		vector<int> result, final;
		int c = 0;
		int n=query.size();
		int nn=Y.size();
		for(int i=0; i<n; i++)
		{
			c=0;
			int q = query.back();
			for(int j=0; j<nn-1; j++)
			{
				int yj = Y.at(j);
				int yjj = Y.at(j+1);

				if(q==yj && q==yjj)
				{
					c=-1;
					break;
				}
				else if(q==yj)
				{
					c++;
				}
				else if(q==yjj)
				{
					c++;
					j++;
				}
				else if(q>min(yj,yjj) && q<max(yj,yjj))
				{
					c++;
				}
			}
			query.pop_back();
			result.push_back(c);
			//else result.push_back(-1);
		}
		for(int i=n-1; i>=0; i--) final.push_back(result.at(i));

		return final;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 4, -1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2, -1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, -1, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 4, 8, 0, 3, -6, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 0, 65536}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 4, 5, 4, 3, 3, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-178080289, -771314989, -237251715, -949949900, -437883156, -835236871, -316363230, -929746634, -671700962}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-673197622, -437883156, -251072978, 221380900, -771314989, -949949900, -910604034, -671700962, -929746634, -316363230}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 6, 3, 0, 7, 1, 4, 8, 3, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, countSolutions(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    PiecewiseLinearFunctionDiv2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
