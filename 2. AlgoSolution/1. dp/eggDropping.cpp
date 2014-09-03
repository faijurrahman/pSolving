//http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
# include <string>
# include <iostream>
using namespace std;

#define N 50
int dp[N][N];
 
int eggDrop(int n, int k)
{
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (int j = 1; j <= k; j++)
        dp[1][j] = j;
 
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= k; j++)
		{
			dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
                dp[i][j] = min(dp[i][j], max(dp[i-1][x-1], dp[i][j-x])+1);
		}
 
    return dp[n][k];
}
 
/* Driver program to test to pront printDups*/
int main()
{
    int n = 2, k = 36;
    cout<<eggDrop(n, k)<<endl;
    return 0;
}