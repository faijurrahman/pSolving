#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
#include <fstream>
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
int dp[_N][_N];

int main()
{
	int X;
	while(cin>>X)
	{
		int t, val;
		vector<int> a;
		cin>>t;
		loop(i,X)
		{
			cin>>val; a.push_back(val);
		}
		sort(All(a));
		long long ans=0;
		loop(i,X)
		{
			if(t<=1) ans+=a[i];
			else ans+=(long long)a[i]*t--;
		}
		cout<<ans;
	}
	return 0;
}