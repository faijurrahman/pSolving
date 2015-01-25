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
#define MOD 1000000007
#define _N 1000050
bool dp[_N];

class PrimeAnagrams 
{

	public:
	vector <int> primes(string anagram) 
	{
		vector <int> ans; long long minProd=1e18;
		int X=pow(10,anagram.size()-2);
		sort(All(anagram));

		LOOP(i,2,X) dp[i]=true;
		for(int i=2; i*i<=X; i++) if(dp[i])
			for(int j=i+i; j<=X; j+=i) 
				dp[j]=false;

		map<int,int> ana;
		loop(i,anagram.size())
			ana[anagram[i]-'0']++;

		
		if(anagram.size()>2)
		{
			vector<int> ePrimeList;
			loop(i,X) if(dp[i])
			{
				string str=to_string(i);
				map<int,int> strMap;
				loop(j,str.size())
					strMap[str[j]-'0']++;

				bool ok=true;
				loop(j,10) if(ana[j]<strMap[j]) ok=false;
				if(ok) ePrimeList.push_back(i);
			}

			X=ePrimeList.size();	
			loop(i,X) loop(j,X) loop(k,X)
			{								
				string str=to_string(ePrimeList[i]);
				str+=to_string(ePrimeList[j]);
				str+=to_string(ePrimeList[k]);
			
				if(str.size()==anagram.size())
				{
					sort(All(str));
					if(str==anagram)
					{
						long long prod=(long long) ePrimeList[i]*ePrimeList[j]*ePrimeList[k];
						if(minProd>prod)
						{
							minProd=prod;
							ans.resize(0);
							ans.push_back(ePrimeList[i]);
							ans.push_back(ePrimeList[j]);
							ans.push_back(ePrimeList[k]);
						}
					}
				}
			}
			sort(All(ans));
		}
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
    
