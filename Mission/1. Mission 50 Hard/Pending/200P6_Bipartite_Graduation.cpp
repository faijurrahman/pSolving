#include<algorithm>
#include<bitset>
#include<vector>
#include<string>
#include<iostream>
#include <sstream>
#include<cstring>
#include<climits>
#include<set>
using namespace std;

#define ld long double
#define ll long long
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007
#define _N 3000
int dp[2600][200];

class maxBPM
{
public:
	int X,Y;
	vector<bool> seen;
	vector<int> matchRecord;
	vector<vector<int>> graph;

	bool bpmRecur(int u)
	{
		loop(v,Y)
		{
			if (graph[u][v] && !seen[v])
			{
				seen[v] = true;
				if( matchRecord[v]<0 || bpmRecur(matchRecord[v]) )
				{
					matchRecord[v] = u;
					return true;
				}
			}
		}
		return false;
	}

public:
	int findMaxBPM(vector<vector<int>>& Graph)
	{
		graph = Graph;
		X = graph.size();
		Y = graph[0].size();

		matchRecord.resize(Y,-1);

		int ans = 0; 
		loop(u,X)
		{
			seen.clear();
			seen.resize(Y,false);
			if(bpmRecur(u)) ans++;
		}
		return ans;
	}

};

class Graduation 
{

	public:
	string moreClasses(string classesTaken, vector <string> requirements) 
	{
		int X=0,Y=150,Z = requirements.size();


		ZERO(dp);
		sort(All(classesTaken));
		int count=0,val;
		loop(i,Z) 
		{
			istringstream ss(requirements[i]);
			ss>>val;
			

			int m=0,n=0,p=0;
			int ctLen = classesTaken.size();
			int strLen = requirements[i].size();
			while(requirements[i][p]>='0' && requirements[i][p]<='9') p++;
			
			if(val>(strLen-p+1)) return "0";

			vector<char> str;
			LOOP(j,p,strLen) str.push_back(requirements[i][j]);
			sort(All(str));
			strLen = str.size();
			
			while(m<ctLen && n<strLen) 
			{
				if(classesTaken[m]==str[n]) { str[n]=-1; m++; n++; val--;}
				else if(classesTaken[m]<str[n]) m++; 
				else n++;
			}

			if(val>0) 
			{
				X+=val;
				int j_init=count;
				for(count=j_init; count<(val+j_init); count++) loop(k,strLen)
						if(str[k]!=-1) dp[count][str[k]-33]=true;
			}
		}

		if(X==0) return "";

		vector<vector<int>> g(vector<vector<int>>(X,vector<int>(Y,0)));
		
		loop(i,X) loop(j,Y) g[i][j]=dp[i][j];

		maxBPM bp;
		bp.findMaxBPM(g);

		
		vector<char> sss;
		loop(j,Y) if(bp.matchRecord[j]!=-1) sss.push_back(33+j);
		string res(All(sss));
		return res;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arr1[] ={"2ABC","2CDE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BCD"; verify_case(0, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+/NAMT"; string Arr1[] = {"3NAMT","2+/","1M"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(1, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "A"; string Arr1[] = {"100%*Klju"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "0"; verify_case(2, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ""; string Arr1[] = {"5ABCDE","1BCDE,"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ",ABCDE"; verify_case(3, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "CDH"; string Arr1[] = {"2AP", "3CDEF", "1CDEFH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AEP"; verify_case(4, Arg2, moreClasses(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    Graduation ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
