#include<climits>
#include<algorithm>
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
	vs a; vi b; vb c; c.resize(4,false);
	string s;
	loop(i,4){ cin>>s; a.pb(s); b.pb(a[i].size()-2);}
	int t=0;
	loop(i,4)loop(j,4) t+=(c[i]=b[i]<b[j]/2);
	if(t==1) loop(i,4) if(b[i]==true) cout<<'A'+i;
	else if(t==3) loop(i,4) if(b[i]==false) cout<<'A'+i;
	else cout<<"C";
	return 0;
}