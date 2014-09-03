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
	bool flag=false;
	int X, Y;
	cin>>X;

	int val1, val2; 
	vector<pair<int,int>> a;
	
	loop(i,X)
	{
		cin>>val1>>val2; 
		a.pb(mp(val1,val2));
	}

	sort(All(a));
	loop(i,X-1)
	{
		pair<int,int> b=a[i];
		pair<int,int> c=a[i+1];

		if(b.first<c.first && b.second>c.second){flag=true; break;}
	}

	if(flag) cout<<"Happy Alex";
	else cout<<"Poor Alex";
	return 0;
}