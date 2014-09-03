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
	int X;
	cin>>X;

	int val; vi a;
	loop(i,X)
	{
		cin>>val; 
		a.pb(val);
	}

	sort(All(a));
	
	long long i=0, c=0, c2=0;
	while(i<X && a[0]==a[i]){ i++;c++;}
	i=X-1;
	if(c!=X) while(a[X-1]==a[i]){ i--;c2++;}
	else {c2=1; c=X*(X-1); c/=2;}
	cout<<a[X-1]-a[0]<<" ";
	cout<<c*c2;

	return 0;
}