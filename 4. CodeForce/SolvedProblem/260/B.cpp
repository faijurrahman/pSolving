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
	int ans=1;
	string num;
	cin>>num;
	int a, X = num.size();

	if(X>1) a = (10*(num[X-2]-'0')+num[X-1]-'0')%4;
	else a = (num[0]-'0')%4;
	ans+=(int)pow(2.0,a)%5;
	ans+=(int)pow(3.0,a)%5;
	ans+=(int)pow(4.0,a)%5;

	cout<<ans%5;
	return 0;
}