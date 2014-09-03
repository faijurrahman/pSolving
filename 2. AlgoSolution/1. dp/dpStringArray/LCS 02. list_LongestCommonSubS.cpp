#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAX_LEN 100
int dp[MAX_LEN][MAX_LEN];
//bool dp[m+1][n+1];

class listLCS
{
public:
	string subString(string S1, string S2)
	{
		int X = S1.length();
		int Y = S2.length();
		int startStr = 0;
		int maxLen = 0;

		for (int i=0; i<=X; i++)
			for (int j=0; j<=Y; j++)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else if (S1[i-1] == S2[j-1])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
					if(maxLen < dp[i][j])
					{
						startStr = i;
						maxLen = dp[i][j];
					}
				}
				else
				{
					dp[i][j] = 0;
				}

			}

		return S1.substr(startStr - maxLen, maxLen);
	}

	string subSequence(string S1, string S2)
	{
		int X = S1.length();
		int Y = S2.length();

		return "Not Implemented";
	}
};

// Driver program to test above function
int main()
{
	listLCS lcs;
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