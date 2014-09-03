#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAX_LEN 100
int dp[MAX_LEN][MAX_LEN];
//bool dp[m+1][n+1];

class countLCS
{
public:
	int subString(string X, string Y)
	{
		int m = X.length();
		int n = Y.length();

		for (int i=0; i<=m; i++)
		{
			for (int j=0; j<=n; j++)
			{
				if (i == 0 || j == 0) dp[i][j] = 0;//Base Case
				else if (X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1] + 1; 
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}

		int maxLen = 0;
		for (int i=0; i<=m; i++)
			maxLen = max(maxLen, dp[i]);
		//Not Implemented
		return maxLen;
	}

	int subSequence(string X, string Y)
	{
		int m = X.length();
		int n = Y.length();

		for (int i=0; i<=m; i++)
		{
			for (int j=0; j<=n; j++)
			{
				if (i == 0 || j == 0) dp[i][j] = 0;//Base Case
				else if (X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1] + 1; 
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}

		return dp[m][n];
	}
};

// Driver program to test above function
int main()
{
	countLCS lcs;
	string input1, input2;
	cout<<"Enter both strings separated by space: ";
	while(cin>>input1>>input2)
	{
		cout<<"Longest Common Substring: "<<lcs.subString(input1, input2)<<endl;
		cout<<"Longest Common Subsequence: "<<lcs.subSequence(input1, input2)<<endl;

		input1.empty();
		input2.empty();
		cout<<endl<<"Enter both strings separated by space: ";
	}

	getchar();
	return 0;
}