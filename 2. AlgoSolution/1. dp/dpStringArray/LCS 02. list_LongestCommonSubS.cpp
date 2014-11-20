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
		int X=S1.length(), Y=S2.length(), maxLen=0; ZERO(dp);
		loop(i,X) loop(j,Y) 
			if(S1[i]==S2[j]) MAX(maxLen,(dp[i+1][j+1]=dp[i][j]+1));
		return maxLen;
	}

	int subSeq(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length(); ZERO(dp); 
		loop(i,X) loop(j,Y)
			if(S1[i]==S2[j]) dp[i+1][j+1]=dp[i][j]+1; 
			else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
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
		loop(i,X) loop(j,Y) 
			if(S1[i]==S2[j] && maxLen<(dp[i+1][j+1]=dp[i][j]+1)) 
					endStr=i, maxLen=dp[i+1][j+1];
		return S1.substr(endStr+1-maxLen,maxLen);
	}

	string subSeq(string S1, string S2)
	{
		int X=S1.length(), Y=S2.length(); ZERO(dp);
		loop(i,X) loop(j,Y)
			if(S1[i]==S2[j]) dp[i+1][j+1]=dp[i][j]+1; 
			else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);

		string tmp="", ans=""; 	
		for(int i=X-1,j=Y-1; i>=0 && j>=0;)
			if(S1[i]==S2[j]){ tmp+=S1[i]; i--, j--;}
			else if(dp[i+1][j+1]==dp[i][j+1]) i--;
			else j--;
		for(int i=tmp.size()-1; i>=0; i--) ans+=tmp[i];
		return ans;
	}
};

// Driver program to test above function
int main()
{
	countLCS cntLCS; listLCS strLCS; string in1, in2;
	cout<<"Please enter both strings: ";
	while(cin>>in1>>in2)
	{
		cout<<"LCString  : Len = "<<cntLCS.subStr(in1,in2)<<", Str = "<<strLCS.subStr(in1,in2)<<endl;
		cout<<"LCSequence: Len = "<<cntLCS.subSeq(in1,in2)<<", Seq = "<<strLCS.subSeq(in1,in2)<<endl;
		in1.empty(); in2.empty(); cout<<endl<<"Please enter both strings again: ";
	}

	getchar();
	return 0;
}