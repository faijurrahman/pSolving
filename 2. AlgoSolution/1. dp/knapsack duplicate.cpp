//http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
// A Dynamic Programming solution for Rod cutting problem
#include<limits>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define _N 52
int dp[_N];
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, vector<int> wt, vector<int> val)
{
	int X=wt.size(); ZERO(dp);
	loop(i,X) LOOP(w,wt[i],W+1) MAX(dp[w], dp[w-wt[i]]+val[i]);
    return dp[W];
}
 
int main()
{
    int val[] = {40, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int X = sizeof(val)/sizeof(val[0]);
	vector<int> value, weight;
	loop(i,X)
	{
		value.push_back(val[i]);
		weight.push_back(wt[i]);
	}
    cout << knapSack(W, weight, value) << endl;
    return 0;
}