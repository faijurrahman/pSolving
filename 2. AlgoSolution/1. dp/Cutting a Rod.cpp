//http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
// A Dynamic Programming solution for Rod cutting problem
#include<limits>
#include<algorithm>
#include<iostream>
using namespace std;

#define N 20
int dp[N];
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i<=n; i++)
		for (int j = 0; j < i; j++)
			dp[i] = max(dp[i], price[j] + dp[i-j-1]);

	return dp[n];
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Maximum Obtainable Value is "<< cutRod(arr, size);
	getchar();
	return 0;
}