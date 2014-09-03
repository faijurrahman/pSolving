#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))

#define MOD 1000000007
#define _N 100
int dp[_N][_N];

int main()
{
	int X;
	while(cin>>X)
	{
		int k,p;		
		cin>>k>>p;
		
		int val; vector<int> odd,even; 
		loop(i,X)
		{
			cin>>val; 
			if(val%2==0)even.push_back(val);
			else odd.push_back(val);
		}
		int Y=odd.size();
		int Z=even.size();

		int temp=Y-(k-p);
		if(temp<0 || temp%2!=0) cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			int c=1; bool done=false;
			temp=k-p;
			loop(i,temp)
			{
				if(c++==k)
				{
					cout<<Y-i+Z;
					LOOP(j,i,Y) cout<<" "<<odd[j];
					loop(j,Z) cout<<" "<<even[j];
					cout<<endl;
					done = true;
					break;
				}
				else cout<<1<<" "<<odd[i]<<endl;
			}

			if(!done)
			{
				temp=Y-(k-p);
				if(temp>0)
				{
					for(int i=k-p; (i+1)<Y; i+=2)
					{
						if(c++==k)
						{
							cout<<Y-i+Z;
							LOOP(j,i,Y) cout<<" "<<odd[j];
							loop(j,Z) cout<<" "<<even[j];
							cout<<endl;
							done = true;
							break;
						}
						else cout<<2<<" "<<odd[i]<<" "<<odd[i+1]<<endl;
					}
				}
			}

			if(!done)
			{
				loop(i,Z)
				{
					if(c++==k)
					{
						cout<<Z-i;
						LOOP(j,i,Z) cout<<" "<<even[j];
						cout<<endl;
						done = true;
						break;
					}
					else cout<<1<<" "<<even[i]<<endl;
				}
				
			}
		}
	}
	return 0;
}