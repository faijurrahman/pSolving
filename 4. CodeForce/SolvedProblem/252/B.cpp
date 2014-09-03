#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
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

struct tree
{
	int d,f;
	void operator =(pair<int,int> pos) { d=pos.first; f=pos.second;}
	bool operator <(tree pos)const
	{ return d<pos.d;}	
};
int a[3002];

int main()
{
	int X, Y;
	cin>>X>>Y;
	ZERO(a);
	int val1,val2;
	loop(i,X)
	{
		cin>>val1>>val2; 
		a[val1]+=val2;
	}

	long long ans=0;

	int v=Y;
	if(v>=a[0]){ ans+=a[0]; a[0]=0;}
	else { ans+=v; a[0]-=v;}

	LOOP(i,1,3003)
	{
		v=Y;
		if(v>=a[i-1]){ ans+=a[i-1]; v-=a[i-1]; a[i-1]=0;}
		else { ans+=v; a[i-1]-=v; v=0;}

		if(v>=a[i]){ ans+=a[i]; a[i]=0;}
		else { ans+=v; a[i]-=v;}
	}

	cout<<ans;
	return 0;
}