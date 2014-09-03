#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

int main()
{
	int X;
	while(cin>>X)
	{
		int T, t=0, val;
		cin>>T;
		t+=(X-1)*10;
		loop(i,X){cin>>val; t+=val;}
		if(t>T)cout<<-1;
		else
		{
			int ans=2*(X-1);
			ans+=(T-t)/5;
			cout<<ans;
		}
	}
	return 0;
}