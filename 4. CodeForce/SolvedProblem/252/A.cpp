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
	int X,Y,Z;
	cin>>X>>Y;
	
	vi ans;
	int val, sum=0;
	loop(i,X)
	{
		vi a;
		cin>>Z;
		loop(j,Z)
		{
			cin>>val; 
			a.push_back(val);
		}
		loop(j,Z){ if(Y>a[j]){ ans.push_back(i+1);break;}}
	}

	cout<<ans.size()<<endl;
	loop(i,ans.size()) cout<<" "<<ans[i];

	return 0;
}