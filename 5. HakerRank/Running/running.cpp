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
#define _N 100002
int a[_N];

int main()
{	
    ZERO(a);
    int X;
    cin>>X;
    loop(i,X) cin>>a[i]; 

    sort(a,a+X);
    int ans=X;
	if(X==1){ cout<<ans<<endl; return 0;}
    
	int f=0,l=X-1;
	while(l>f)
	{
		while((l-1)>=0 && a[l]==a[l-1]) l--;
		if(l>f && a[l]>a[f]){ans++; l--; f++;}
	}
	cout<<ans<<endl;

	return 0;
}