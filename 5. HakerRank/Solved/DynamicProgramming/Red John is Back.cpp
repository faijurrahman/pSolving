//https://www.hackerrank.com/challenges/red-john-is-back
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

#define PRM 1000000
int prime[PRM];

void sieve(long long n)
{
	ZERO(prime);
	int p=2;
	while(p<n)
	{
		for(int i=p+p; i<n; i+=p) prime[i]=1;
		while(prime[++p]);
	}
    
    p=0;
	LOOP(i,2,n) 
	{
		if(!prime[i]) p++;
		prime[i]=p;
	}
}

#define CN (40+1)
long long ncr[CN][CN];

int main()
{
    ZERO(ncr);
    loop(i,CN) ncr[i][0]=1;
    loop(i,CN-1)loop(j,i+1) ncr[i+1][j+1]=ncr[i][j]+ncr[i][j+1];
    sieve(PRM);
    
	int T; cin>>T;
	while(T--)
	{	
		long long ans=1;
		int x;
		cin>>x;
        int four=0;
        while(x>=4)
        {
            x-=4;four++;
            ans+=ncr[x+four][four];
        }
        cout<<prime[ans]<<endl;
	}
	return 0;
}