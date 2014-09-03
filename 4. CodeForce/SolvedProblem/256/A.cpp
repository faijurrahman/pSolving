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
	int ans=0;
	int X;

	int val, c=0,m=0;
	loop(i,3) 
	{
		cin>>val; 
		c+=val;
	}

	loop(i,3) 
	{
		cin>>val; 
		m+=val;
	}
	cin>>X;
	ans=c/5+m/10;
	if(c%5>0)ans++;
	if(m%10>0)ans++;
	if(ans<=X) cout<<"YES";
	else cout<<"NO";

	return 0;
}