//C Header
#include<map>
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
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define _N 100
long long height[_N][_N];


int ans,tar; long long budget;
bool seen[_N]; vector<int> path; 
vector<vector<int>> tree;


bool isPossible(long long mi, long long b)
{
	vector<long long> cost;
	loop(i,path.size()-1) cost.push_back(height[path[i]][path[i+1]]);
	//sort(All(cost));
	bool ok=true;
	loop(i,cost.size()) if(mi>cost[i])
	{
		long long a = mi-cost[i];
		if(sqrt(b)>a){ b-=a*a;cost[i]=mi;}
		else{ cost[i]+=sqrt(b);ok=false; break;}
	}
	int ret=INT_MAX;
	loop(i,cost.size()) MIN(ret,(int)cost[i]);
	MAX(ans,ret);
	return ok;
}

void calheight()
{
	long long lo=0,mi,hi=1e9;
	while(lo<hi)
	{
 		mi=(lo+hi)/2LL;
		if(!isPossible(mi,budget)) hi=mi;
		else lo=mi+1;
	}
}

void xTree(int n, int p)
{
	loop(i,tree[n].size()) if(!seen[tree[n][i]] && tree[n][i]!=p)
	{
		seen[tree[n][i]]=1;
		path.push_back(tree[n][i]);

		if(tree[n][i]==tar) calheight();
		else xTree(tree[n][i],n);

		path.pop_back();
		seen[tree[n][i]]=0;
	}
}

class TallShoes 
{

	public:
	int maxHeight(int N, vector <int> A, vector <int> B, vector <int> h, long long Bud) 
	{
		int X=A.size();
		ans=INT_MIN; tar=N-1; budget=Bud;
		tree.clear(); tree.resize(N);
		loop(i,N) loop(j,X)
		{
			if(A[j]==i) tree[i].push_back(B[j]);
			if(B[j]==i) tree[i].push_back(A[j]);
		}
		
		loop(i,X) height[A[i]][B[i]]=height[B[i]][A[i]]=h[i];		
		path.clear(); path.resize(0); path.push_back(0);
		ZERO(seen); seen[0]=true;
		xTree(0, -1);
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arr1[] = {3, 0, 0, 0, 3, 4, 8, 3, 1, 8, 4, 1, 5, 4, 8, 9, 0, 6, 8, 6, 7, 6, 3, 2, 7, 7, 2, 4, 0, 7, 9, 6, 3, 2, 8, 7, 3, 2, 5, 10, 5, 6, 5, 10, 1, 2, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 8, 10, 1, 0, 6, 6, 4, 5, 4, 7, 2, 4, 10, 1, 8, 4, 1, 2, 0, 9, 5, 9, 7, 0, 5, 4, 9, 9, 3, 1, 9, 5, 0, 7, 1, 10, 6, 10, 7, 2, 10, 8, 2, 3, 3, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {19, 996440, 114077, 445, 277, 44, 3306, 20517, 3, 55, 1, 181360, 587726, 2214, 216, 3660, 17, 11, 134, 20, 32, 32, 1, 38, 3, 129687, 38, 9955, 829142, 2, 23217, 281, 806054, 1050, 89772, 7190, 36036, 1, 71, 46, 877414, 162641, 6, 36, 68484, 133001, 158966}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 10892604LL; int Arg5 = 4; verify_case(0, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 52LL; int Arg5 = 9; verify_case(1, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 8; int Arr1[] = {0, 0, 3, 3, 4, 4, 4, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1, 2, 3, 5, 6, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000, 1000, 1000, 1000, 1, 1000, 1000, 1000, 1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 3LL; int Arg5 = 2; verify_case(2, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {0,1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0,0,0,0,0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 9876543210123LL; int Arg5 = 1047565; verify_case(3, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {999999,986588,976757,988569,977678,999999,967675,947856,955856,999999,975956,956687,999999,979687,999999}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 0LL; int Arg5 = 999999; verify_case(4, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    TallShoes ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
