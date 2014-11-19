#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))

#define MAX_LEN 100
int dp[MAX_LEN][MAX_LEN];

class countLCS
{
public:
	int subString(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length();
		int maxLen=0; ZERO(dp);
		LOOP(i,1,X+1) LOOP(j,1,Y+1) if(S1[i-1]==S2[j-1]) MAX(maxLen,(dp[i][j]=dp[i-1][j-1]+1));
		return maxLen;
	}

	int subSequence(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length(); ZERO(dp);
		LOOP(i,1,X+1) LOOP(j,1,Y+1)
			if(S1[i-1]==S2[j-1]) dp[i][j]=dp[i-1][j-1]+1; 
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		return dp[X][Y];
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