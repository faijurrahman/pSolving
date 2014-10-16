//C Header
#include<set>
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
#define pb push_back
#define _N 1000001
bool prime[_N+10];

void genPrime(void)
{
	LOOP(i,2,_N) prime[i]=true;
	for(int i=2; i*i<=_N; i++)
		if(prime[i]){int j=i+i; while(j<_N) prime[j]=false, j+=i;}

}

class PrimeAnagrams 
{

public:
	vector <int> primes(string anagram)
	{
		vector<int> ans;
		long long minProd = 1e18;
		int X=anagram.size();

		sort(All(anagram));
		genPrime();

		do 
		{
			if(anagram[0]=='0') continue;
			loop(i,X-2) if(anagram[i+1]!='0')
			{
				LOOP(j,i+1,X-1) if(anagram[j+1]!='0')
				{			
					string str; int a,b,c;
					str=string(anagram, 0,   i+1); a=atoi(&str[0]);
					str=string(anagram, i+1, j-i); b=atoi(&str[0]);
					str=string(anagram, j+1, X-1); c=atoi(&str[0]);
					if(prime[a] && prime[b] && prime[c])
					{
						long long prod = (long long)a*b*c;
						if(minProd>prod)
						{
							minProd=prod; ans.clear();
							ans.pb(a); ans.pb(b); ans.pb(c);
						}
					}
				}
			}
		} 
		while(next_permutation(All(anagram)));

		sort(All(ans));
		return ans;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "39151"; int Arr1[] = { 5,  13,  19 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, primes(Arg0)); }
	void test_case_1() { string Arg0 = "921179"; int Arr1[] = { 2,  17,  199 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, primes(Arg0)); }
	void test_case_2() { string Arg0 = "01123"; int Arr1[] = { 2,  3,  101 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, primes(Arg0)); }
	void test_case_3() { string Arg0 = "0707070"; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, primes(Arg0)); }
	void test_case_4() { string Arg0 = "222"; int Arr1[] = { 2,  2,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, primes(Arg0)); }
	void test_case_5() { string Arg0 = "123"; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, primes(Arg0)); }

	// END CUT HERE


};

// BEGIN CUT HERE 
int main()
{
	PrimeAnagrams ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

