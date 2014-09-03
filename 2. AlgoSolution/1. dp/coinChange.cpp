#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

int dp[10000];
int dpCoinCount( vector<int> note, int amount )
{
	int numOfNote = note.size();
	// Initialize all dp values as 0
	memset(dp, 0, sizeof(dp));

	// Base case (If given value is 0)
	dp[0] = 1;

	// Pick all coins one by one and update the dp[] values
	// after the index greater than or equal to the value of the
	// picked coin
	for(int i=0; i<numOfNote; i++)
		for(int j=note[i]; j<= amount; j++)
			dp[j] += dp[j-note[i]];

	return dp[amount];
}

int table[10000][60];
int dpBUCoinCount( vector<int> note, int amount )
{
	int i, j, x, y;
	int numOfNote = note.size();

	// Fill the enteries for 0 value case (n = 0)
	for (i=0; i<numOfNote; i++)
		table[0][i] = 1;

	// Fill rest of the table enteries in bottom up manner  
	for (i = 1; i < amount+1; i++)
	{
		for (j = 0; j < numOfNote; j++)
		{
			// Count of solutions including S[j]
			x = (i-note[j] >= 0)? table[i - note[j]][j]: 0;

			// Count of solutions excluding S[j]
			y = (j >= 1)? table[i][j-1]: 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[amount][numOfNote-1];
}

// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int recurCoinCount( int S[], int m, int n )
{
	// If n is 0 then there is 1 solution (do not include any coin)
	if (n == 0)
		return 1;

	// If n is less than 0 then no solution exists
	if (n < 0)
		return 0;

	// If there are no coins and n is greater than 0, then no solution exist
	if (m <=0 && n >= 1)
		return 0;

	// count is sum of solutions (i) including S[m-1] (ii) excluding S[m-1]
	return recurCoinCount( S, m - 1, n ) + recurCoinCount( S, m, n-S[m-1] );
}

int dp1[20];
int dpCoinCountMy( vector<int> note, int amount )
{

	int numOfNote = note.size();
	// Initialize all dp values as 0
	memset(dp1, 0, sizeof(dp));

	// Base case (If given value is 0)
	dp1[0] = 1;

	// Pick all coins one by one and update the dp[] values
	// after the index greater than or equal to the value of the
	// picked coin
	int i, j, k;
	for(i=0; i<numOfNote; i++)
		for(j=note[i]; j<= amount; j+=note[i])
			for(k=0; k<note[i] && k<= amount; k++)
			{
				if(k!=0 && dp1[k]!=0) 
					dp1[j+k] = dp1[j] + dp1[k] - 1;

				if(k==0) dp1[j] += 1;
			}

	return dp1[amount];
}
// Driver program to test above function
int main()
{
	int amount = 26;
	int arr[] = {1, 2, 5, 10};
	int m = sizeof(arr)/sizeof(arr[0]);
	cout<<"Recursion:"<<recurCoinCount(arr, m, amount)<<endl;

	vector<int> notes;
	for(int i=0; i<m; i++) notes.push_back(arr[i]);

	cout<<"Optimized DP:"<<dpCoinCount(notes, amount)<<endl;
	cout<<"BottomUp DP:"<<dpBUCoinCount(notes, amount)<<endl;


	getchar();
	return 0;
}