#include<climits>
#include<algorithm>
#include<numeric>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<iostream>
#include <sstream>
using namespace std;

#define each(it,o) for(auto it=(o).begin(); it!=(o).end(); ++it)
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()
#define DEL(v,val) v.erase(remove(All(v),val),v.end())
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))

#define ll long long
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

#define PI 3.14159265358979
#define INF 1e9
#define DIFF 1e-9
#define MOD 1000000007
#define _N 100
int dp[_N][_N];

int main()
{
	long long ans=0;
	int X, Y=0;
	cin>>X;
	int i=1,sum=0;
	for(; i<1e4;i++)
	{
		Y+=i;
		sum+=Y;
		if(sum==X) break;
		else if(sum>X) { i--;break;}
	}

	cout<<i<<endl;
	//cout<<setprecision(15)<<ans<<endl;
	return 0;
}