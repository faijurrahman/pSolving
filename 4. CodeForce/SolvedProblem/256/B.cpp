#include<climits>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
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

#define vi vector<int>
#define vii vector<int,int>
#define vl vector<long>
#define vll vector<long,long>
#define vd vector<double>
#define vdd vector<double,double>
#define vs vector<string>
#define vb vector<bool>
#define mp make_pair
#define pb push_back

#define MOD 1000000007
#define _N 100
int dp[_N][_N];

int main()
{
	string ans="both";
	string X, Y;
	cin>>X>>Y;
	string x=X, y=Y;

	if(X.find(Y)!=string::npos || Y.find(X)!=string::npos) ans="automaton";
	else
	{
		sort(All(x));
		sort(All(y));
		if(x==y) ans="array";
		else
		{
			loop(i,Y.size())
			{
				if(X.find(Y[i])==string::npos){ans="need tree";break;}
			}
		}
	}
	cout<<ans;
	return 0;
}