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

// Driver program to test above function
int main()
{
	countLCS cntLCS; string in1, in2;
	cout<<"Please enter both strings: ";
	while(cin>>in1>>in2)
	{
		cout<<"LCString   Len: "<<cntLCS.subStr(in1,in2)<<endl;
		cout<<"LCSequence Len: "<<cntLCS.subSeq(in1,in2)<<endl;
		in1.empty(); in2.empty(); cout<<endl<<"Please enter both strings again: ";
	}

	getchar();
	return 0;
}