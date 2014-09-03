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

#define N 5005
int dp[55][N];

class AlbertoTheAviator 
{
	struct pair_ii 
	{
		int Duration, Refuel;
		friend bool operator < (const pair_ii & a, const pair_ii & b) 
		{
			return a.Refuel > b.Refuel;
		}
	};

public:
	int MaximumFlights(int F, vector <int> duration, vector <int> refuel) 
	{
		int X = duration.size();
		int Y = N;

		vector<pair_ii> data;
		loop(i,X)
		{
			pair_ii q; 
			q.Duration = duration[i]; 
			q.Refuel = refuel[i];
			data.push_back(q);
		}
		sort(All(data));

		FILL(dp, -1);
		dp[0][F] = 0;
		int ans = 0;
		loop(curTourNo, X) loop(fuel, Y)
			if (dp[curTourNo][fuel] != -1) 
			{
				int nextTourNo = curTourNo+1;
				dp[nextTourNo][fuel] = dp[curTourNo][fuel];			
				if (data[curTourNo].Duration <= fuel)
				{
					int nextFuel = fuel - data[curTourNo].Duration + data[curTourNo].Refuel;
					dp[nextTourNo][nextFuel] = max(dp[nextTourNo][nextFuel], dp[curTourNo][fuel] + 1);
					ans = max(ans, dp[curTourNo][fuel] + 1);
				}
			}

		return ans;
	}



	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {4, 8, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {8, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; int Arr1[] = {4, 8, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(2, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9; int Arr1[] = {4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arr1[] = {101}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1947; int Arr1[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(5, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	AlbertoTheAviator ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

