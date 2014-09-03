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
	vi ans;
	int a, b, c;
	cin>>a>>b>>c;
	
	int mn=0;
	long mx=2+(1000000000-c)/b;
	long t=(int)2+pow(81.0,a);
	MIN(mx,t);

	LOOP(i,mn,mx)
	{
		long long num = i*(long long)b+c;
		if(num>0 && num<1000000000)
		{
			string s=to_string(num);
			double sum=0;
			loop(j,s.size())
			{
				sum+=s[j]-'0';
			}

			if((int)pow(sum,a)==i) ans.push_back(num);
		}
	}
	int sz=ans.size();
	cout<<sz<<endl;
	if(sz)
	{ 
		loop(i,sz) cout<<ans[i]<<" ";
	}
	return 0;
}