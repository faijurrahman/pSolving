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
	int ans=-1;
	int x, y, x2, y2;
	cin>>x>> y>> x2>> y2;


	if(x==x2 && y!=y2)
	{
		int d= abs(y-y2);
		cout<<(x+d)<<" "<<y<< " " <<(x2+d)<<" "<<y2;
	}
	else if(x!=x2 && y==y2)
	{
		int d= abs(x-x2);
		cout<<x<<" "<<y+d<< " " <<x2<<" "<<y2+d;
	}
	else if(abs(x-x2)==abs(y-y2))
	{
		cout<<x<<" "<<y2<< " " <<x2<<" "<<y;
	}
	else
	{
		cout<<-1;
	}


	return 0;
}