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
    public: int x,y;	
	point(int a, int b){x=a;y=b;} point(){}
	void setPoint(int a, int b){x=a;y=b;}
	bool operator <(const point &p) const{ return x<p.x || (x==p.x && y<p.y);}
};

int main()
{
	double ans=0;
	long long X, Y;
	cin>>X>>Y;

	long long val; vector<long long> a;
	loop(i,X)
	{
		cin>>val; 
		a.pb(val);
	}

	sort(All(a));
	if(a[0]!=0){ a.push_back(-a[0]); X++;}

	sort(All(a));
	if(a[X-1]!=Y) {a.push_back(2*Y-a[X-1]); X++;}
	

	sort(All(a));
	if(X==2) MAX(ans,abs(a[0]-a[1])/2.0);
	LOOP(i,1,X-1)
	{
		MAX(ans,abs(a[i]-a[i-1])/2.0);
		MAX(ans,abs(a[i]-a[i+1])/2.0);
	}
	//cout<<ans<<endl;
	cout<<setprecision(12)<<ans<<endl;
	return 0;
}