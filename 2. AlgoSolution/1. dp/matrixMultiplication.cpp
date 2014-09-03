//http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
#include <climits>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define each(it,c) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define MOD (int)(1e9+7)
#define _N 50
int dp[_N][_N];
int dpf[_N][_N];

int chain(vector<int> dim)
{
	int X=dim.size();
	ZERO(dp); ZERO(dpf);
	LOOP(len,2,X) loop(i,X-len)
	{
		int j=i+len-1;
		dp[i][j]=INT_MAX;
		LOOP(k,i,j)
		{
			int t = dp[i][k]+dp[k+1][j] + dim[i]*dim[k+1]*dim[j+1];
			if(t<dp[i][j]) dp[i][j]=t, dpf[i][j]=k+1;
		}
	}
	return dp[0][X-2];
}


int main()
{
	int m[] = {30, 35, 15, 5, 10, 20, 25};
	int X = sizeof(m)/sizeof(m[0]);

	vector<int> dimension;
	loop(i,X) dimension.push_back(m[i]);
	cout <<"Total Cost: " <<chain(dimension) <<endl;

	X--;
	loop(i,X) 
	{
		loop(j,X) cout <<setw(5) <<dp[i][j] <<" ";
		cout <<endl;
	}
	cout <<endl;
	loop(i,X) 
	{
		loop(j,X) cout <<setw(5) <<dpf[i][j] <<" ";
		cout <<endl;
	}

	return 0;
}