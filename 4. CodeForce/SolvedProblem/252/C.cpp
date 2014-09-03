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

int X, Y, Z;

int convert(int y)
{
	if((y/Y)%2==1) return (Y-1-y%Y);
	else return y%Y;
}

int main()
{

	cin>>X>>Y>>Z;
	int len=X*Y/Z;
	int c=0, y=0;
	bool d=true;
	loop(i,Z)
	{
		if(++c==Z)
		{
			len = X*Y - i*len;
			cout<<len;
			loop(j,len)
			{
				cout<<" "<<(y/Y)+1<<" "<<convert(y)+1;
				y++; 
			}
			cout<<endl;
			break;
		}
		else
		{
			cout<<len;
			loop(j,len)
			{
				cout<<" "<<(y/Y)+1<<" "<<convert(y)+1;
				y++;
			}
			cout<<endl;
		}
	}
	return 0;
}