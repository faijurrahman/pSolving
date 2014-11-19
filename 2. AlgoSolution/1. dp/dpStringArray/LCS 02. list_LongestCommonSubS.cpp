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
	int subStr(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length(); ZERO(dp);
		int maxLen=0; 
		LOOP(i,1,X+1) LOOP(j,1,Y+1) if(S1[i-1]==S2[j-1]) MAX(maxLen,(dp[i][j]=dp[i-1][j-1]+1));
		return maxLen;
	}

	int subSeq(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length(); ZERO(dp);
		LOOP(i,1,X+1) LOOP(j,1,Y+1)
			if(S1[i-1]==S2[j-1]) dp[i][j]=dp[i-1][j-1]+1; 
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		return dp[X][Y];
	}
};

class listLCS
{
public:
	string subStr(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length(); ZERO(dp);
		int endStr=0, maxLen=0; 
		LOOP(i,1,X+1) LOOP(j,1,Y+1)
		{
			if(S1[i-1]==S2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				if(maxLen<dp[i][j]) endStr=i, maxLen=dp[i][j];
			}
		}
		return S1.substr(endStr-maxLen,maxLen);
	}

	string subSeq(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length(); ZERO(dp);
		LOOP(i,1,X+1) LOOP(j,1,Y+1)
			if(S1[i-1]==S2[j-1]) dp[i][j]=dp[i-1][j-1]+1; 
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

		string tmp="", ans=""; 	
		for(int i=X,j=Y; i>=0 && j>=0;)
		{
			if(S1[i]==S2[j]){ tmp+=S1[i]; i--, j--;}
			else if(dp[i][j]==dp[i-1][j]) i--;
			else j--;
		}
		for(int i=tmp.size()-1; i>=0; i--) ans+=tmp[i];
		return ans;
	}
};

// Driver program to test above function
int main()
{
	countLCS cntLCS; listLCS strLCS; string in1, in2;
	cout<<"Enter both strings: ";
	while(cin>>in1>>in2)
	{
		cout<<"LCString  : Len = "<<cntLCS.subStr(in1,in2)<<", Str = "<<strLCS.subStr(in1,in2)<<endl;
		cout<<"LCSequence: Len = "<<cntLCS.subSeq(in1,in2)<<", Seq = "<<strLCS.subSeq(in1,in2)<<endl;

		in1.empty(); in2.empty();
		cout<<endl<<"Enter both strings separated by space: ";
	}

	getchar();
	return 0;
}