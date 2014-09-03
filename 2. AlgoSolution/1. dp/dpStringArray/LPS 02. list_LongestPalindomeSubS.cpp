#include<string>
#include<iostream>
using namespace std;

#define MAX_LEN 200
int dp[MAX_LEN][MAX_LEN];

class listLPS
{
public:
	//Time = O(N2) and space = O(N2)
	string subString(string input)
	{
		int n = input.length();
		int longestBegin = 0;
		int maxLen = 1;

		//Initialize
		memset(dp, 0, sizeof(dp));

		//Base case 1
		for (int i = 0; i < n; i++)
			dp[i][i] = 1;


		for (int len = 2; len <= n; len++)
		{
			for (int i = 0, j = len-1; j < n; i++, j++) 
			{
				if (input[i] == input[j] && dp[i+1][j-1]) 
				{
					dp[i][j] = 1;
					longestBegin = i;
					maxLen = len;
				}
			}
		}
		return input.substr(longestBegin, maxLen);
	}

	//Time = O(N2) and space = O(N2)
	string subSequence(string input) 
	{


		return "Not Implemented Yet";
	}

};

// Driver program to test above function
int main()
{
	listLPS lps;
	string input="aamadamt";
	cout<<"Enter Input string: ";
	while(cin>>input)
	{
		cout<<"Longest Palindomic Substring: "<<lps.subString(input)<<endl;
		cout<<"Longest Palindomic Subsequence: "<<lps.subSequence(input)<<endl;
		input.empty();
		cout<<"Enter Input string: ";
	}

	return 0;
}