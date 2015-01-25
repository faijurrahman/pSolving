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

struct point
{
    public: long long x,y;	
	point(long long a, long long b){x=a;y=b;} point(){}
	void setPoint(long long a, long long b){x=a;y=b;}
	bool operator <(const point &p) const{ return x<p.x || (x==p.x && y<p.y);}
};

int main()
{
	long long ans=0;
	long long X, Y,avg,tot;
	cin>>X>>Y>>avg;
	tot=X*avg;
	long long v1,v2; vector<point> a;
	loop(i,X)
	{
		cin>>v1>>v2; tot-=v1;
		a.pb(point(v2,v1));
	}

	if(tot<=0){ cout<<ans<<endl; return 0;}

	sort(All(a));
	loop(i,X)
	{
		if(tot>0)
		{
			ans+=min(Y-a[i].y,tot)*a[i].x;
			tot-=Y-a[i].y;
		}
	}

	cout<<ans<<endl;
	//cout<<setprecision(15)<<ans<<endl;
	return 0;
}