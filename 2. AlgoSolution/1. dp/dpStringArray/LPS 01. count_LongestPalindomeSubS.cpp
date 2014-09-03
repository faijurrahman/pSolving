#include<string>
#include<iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define ZERO(arr) memset(arr,0,sizeof(arr))

#define MOD 1000000007
#define _N 10
int dp[_N][_N];

class countLPS
{
public:
	//Time = O(N2) and space = O(N2)
	int subString(string in) {
		int X=in.length();
		int begin=0, maxLen=1;

		ZERO(dp);loop(i,X) dp[i][i]=1;
		LOOP(len,2,X+1) loop(i,X-len+1)
		{
			int j=i+len-1;
			if(in[i]==in[j] && dp[i+1][j-1]) dp[i][j]=1, begin=i, maxLen=len;
		}
		return maxLen;
	}

	//Time = O(N2) and space = O(N2)
	int subSequence(string in) 
	{
		int X=in.length();
		ZERO(dp); loop(i,X) dp[i][i]=1;
		LOOP(len,2,X+1) loop(i,X-len+1)
		{
			int j=i+len-1;
			if (in[i] == in[j]) dp[i][j]=dp[i+1][j-1]+2;
			else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
		}
		return dp[0][X-1];
	}

};

// Driver program to test above function
int main()
{
	countLPS lps;
	string input;
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