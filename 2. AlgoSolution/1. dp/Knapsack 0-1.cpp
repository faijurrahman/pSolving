//http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
// A Dynamic Programming solution for 0/1 Knapsack problem
#include<limits>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define _N 101
int dp[_N][_N];

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, vector<int> wt, vector<int> val)
{
	int X = wt.size(); ZERO(dp);
	loop(i,X) loop(w,W+1)
	{
		if(wt[i]<=w) dp[i+1][w] = max(dp[i][w], dp[i][w-wt[i]]+val[i]);
		else dp[i+1][w]=dp[i][w];
	}
	return dp[X][W];
}

int main()
{
	int  W = 60;
	int val[] = {60, 100, 120};
	int wt[] = {20, 50, 10};
	int X = sizeof(val)/sizeof(val[0]);
	vector<int> Weight, Value;
	for(int i=0; i<X; i++)
	{
		Weight.push_back(wt[i]);
		Value.push_back(val[i]);
	}
	cout << knapSack(W, Weight, Value) << endl;
	return 0;
}