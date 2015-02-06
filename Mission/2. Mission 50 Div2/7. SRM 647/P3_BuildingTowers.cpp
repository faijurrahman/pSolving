//C Header
#include<tuple>
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

long long kk;

bool isOK(long long mid, long long h, long long d)
{
	long long steps = (mid+kk-1)/kk + (abs(mid-h)+kk-1)/kk;
	//long long steps = ceil(mid/(double)kk) + ceil(abs(mid-h)/(double)kk);
	if(steps>d) return true;
	return false;
}

long long bSearch(long long h1, long long h2, long long d)
{	
	long long hi,mid,lo;
	lo=min(h1,h2); h2=abs(h1-h2); h1=lo;
	hi=h2+d*kk; lo=0;
	while(lo<hi)
	{
		mid=lo+(hi-lo+1)/2;
		if(isOK(mid,h2,d)) hi=mid-1;
		else lo=mid;
	}
	return h1+lo;
}


class BuildingTowers 
{

	public:
	long long maxHeight(int N, int K, vector <int> x, vector <int> t) 
	{
		long long ans=0; int cur,pos; 
		int X = x.size(); kk=K;
		if(X==0) return (N-1)*kk;

		loop(i,X) t[i]=min(0LL+t[i], kk*(x[i]-1));
		loop(i,X) loop(j,X) t[i]=min(0LL+t[i], t[j]+kk*abs(x[i]-x[j]));

		cur=0,pos=1;
		loop(i,X)
		{
			MAX(ans,bSearch(cur,t[i],x[i]-pos));
			cur=t[i]; pos=x[i];
		}

		cur=t[X-1],pos=N-x[X-1];
		MAX(ans,bSearch(cur,cur+pos*kk,pos));

		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; int Arr2[] = {3,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 3LL; verify_case(0, Arg4, maxHeight(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 999999999000000000LL; verify_case(1, Arg4, maxHeight(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 3; int Arr2[] = {4,7,13,15,18}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8,22,1,55,42}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 22LL; verify_case(2, Arg4, maxHeight(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 780; int Arg1 = 547990606; int Arr2[] = {34,35,48,86,110,170,275,288,313,321,344,373,390,410,412,441,499,525,538,568,585,627,630,671,692,699,719,752,755,764,772}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {89,81,88,42,55,92,19,91,71,42,72,18,86,89,88,75,29,98,63,74,45,11,68,34,94,20,69,33,50,69,54}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 28495511604LL; verify_case(3, Arg4, maxHeight(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7824078; int Arg1 = 2374; int Arr2[] = {134668,488112,558756,590300,787884,868112,1550116,1681439,1790994,
1796091,1906637,2005485,2152813,2171716,2255697,2332732,2516853,
2749024,2922558,2930163,3568190,3882735,4264888,5080550,5167938,
5249191,5574341,5866912,5936121,6142348,6164177,6176113,6434368,
6552905,6588059,6628843,6744163,6760794,6982172,7080464,7175493,
7249044}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8,9,171315129,52304509,1090062,476157338,245,6,253638067,37,500,
29060,106246500,129,22402,939993108,7375,2365707,40098,10200444,
3193547,55597,24920935,905027,1374,12396141,525886,41,33,3692,
11502,180,3186,5560,778988,42449532,269666,10982579,48,3994,1,9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1365130725LL; verify_case(4, Arg4, maxHeight(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    BuildingTowers ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
