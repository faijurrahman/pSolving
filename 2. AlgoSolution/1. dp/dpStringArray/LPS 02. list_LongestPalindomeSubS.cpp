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

class countLPS
{
public:
	//Time = O(N2) and space = O(N2)
	int subStr(string S) 
	{
		int X=S.length(), begin=0, maxLen=1; ZERO(dp);
		LOOP(len,1,X+1) for(int i=0,j=len-1; j<X; i++,j++)
			if(S[i]==S[j] && (len<=2 || dp[i+1][j-1])) dp[i][j]=1, begin=i, maxLen=len;
		return maxLen;
	}

	//Time = O(N2) and space = O(N2)
	int subSeq(string S) 
	{
		int X=S.length(); ZERO(dp); loop(i,X) dp[i][i]=1;
		LOOP(len,2,X+1) for(int i=0,j=len-1; j<X; i++,j++)
			if(S[i]==S[j]) dp[i][j]=dp[i+1][j-1]+2;
			else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);

		return dp[0][X-1];
	}
};

class listLPS
{
public:
	//Time = O(N2) and space = O(N2)
	string subStr(string S)
	{
		int X=S.length(), begin=0, maxLen=1; ZERO(dp);
		LOOP(len,1,X+1) for(int i=0,j=len-1; j<X; i++,j++)
			if(S[i]==S[j] && (len<=2 || dp[i+1][j-1])) dp[i][j]=1, begin=i, maxLen=len;
		return S.substr(begin,maxLen);
	}

	//Time = O(N2) and space = O(N2)
	string subSeq(string S) 
	{
		int X=S.length(); ZERO(dp); loop(i,X) dp[i][i]=1;
		LOOP(len,2,X+1) for(int i=0,j=len-1; j<X; i++,j++)
			if(S[i]==S[j]) dp[i][j]=dp[i+1][j-1]+2;
			else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);

		string ans="",tmp=""; 	
		for(int i=0,j=X-1; i<X && j>=0;)
			if(dp[i][j]==0) break;	
			else if(dp[i][j]==1){ans+=S[i]; break;}	
			else if(dp[i][j]==dp[i][j-1]) j--;
			else if(dp[i][j]==dp[i+1][j]) i++;
			else ans+=S[i],tmp+=S[i],i++,j--;	
		for(int i=tmp.size()-1; i>=0; i--) ans+=tmp[i];
		return ans;
	}

};

// Driver program to test above function
int main()
{
	countLPS cntLPS; listLPS strLPS; string input;
	cout<<"Please enter a string: ";
	while(cin>>input)
	{
		cout<<"LCString  : Len = "<<cntLPS.subStr(input)<<", Str = "<<strLPS.subStr(input)<<endl;
		cout<<"LCSequence: Len = "<<cntLPS.subSeq(input)<<", Seq = "<<strLPS.subSeq(input)<<endl;
		input.empty(); cout<<endl<<"Please enter another string: ";
	}
	getchar();
	return 0;
}