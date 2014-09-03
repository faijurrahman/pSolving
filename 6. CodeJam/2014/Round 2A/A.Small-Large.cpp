#include<set>
#include<bitset>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()
#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))

#define MOD 1000000007
#define _N 105

#define FILE_NAME_SAMPLE "1.sample"
#define FILE_NAME_SMALL "2.small"
#define FILE_NAME_LARGE "3.large"

class codeJam
{
public:
	int calOpt(vector<int> dp)
	{
		int ans=INT_MAX;
		int X = dp.size();
		sort(All(dp));
		LOOP(i,dp[0], dp[X-1]+1)
		{
			int t=0;
			loop(j,X)
			{
				t+=abs(i-dp[j]);
			}
			MIN(ans,t);
		}
		return ans;
	}

	string calculateOuput(vector<string> in)
	{
		int idx[105];
		ZERO(idx);
		int ans = 0;
		int X = in.size();

		char a=in[0][0];
		while(a!=0)
		{
			vector<int> dp;
			dp.resize(X);
			loop(i,X)
			{
				int j=idx[i];
				dp[i]=0;
				while(a==in[i][j]){ j++; dp[i]++;}		
				if(j==idx[i]) return "Fegla Won";
				idx[i]=j;
			}

			ans += calOpt(dp);
			if(idx[0]<in[0].size())a = in[0][idx[0]];
			else break;
		}
		
		loop(i,X) if(idx[i] != in[i].size()) return "Fegla Won";
		
		return to_string(ans);
	}

	void processInput(string fileName)
	{
		ifstream fin(fileName + ".in" );
		ofstream fout(fileName + ".out");	

		int T; fin >> T;
		loop(t,T)
		{
			string str;
			vector<string> input;
			int X;
			fin >> X;
			loop(i,X)
			{
				fin >> str;
				input.push_back(str);
			}
			string ans = calculateOuput(input);
			fout << "Case #" << t+1 << ": " << ans << endl;
		}

		fin.close(); fout.close();
	}
};

class unitTesting
{
public:
	void run_test(string sampleFileName) 
	{ 
		const int GET_LINE_LENGHT = 100;
		ifstream fSampleIn(sampleFileName + ".in");
		ifstream fSampleOut(sampleFileName +  ".out");
		ifstream fSampleOutForVerify("1.sampleForVerify.out");

		int X;
		fSampleIn >> X;
		loop(i,X)
		{
			char resultFromProgram[GET_LINE_LENGHT+1], sampleForVerifyOutput[GET_LINE_LENGHT+1];
			fSampleOut.getline(resultFromProgram,GET_LINE_LENGHT);
			fSampleOutForVerify.getline(sampleForVerifyOutput,GET_LINE_LENGHT);
			if(strcmp(resultFromProgram,sampleForVerifyOutput) == 0) cout << "Case " << i+1 << ": Passed" << endl;
			else
			{
				cout << "Case " << i+1 << ": Failed" << endl;
				cout << "\tExpected: " << sampleForVerifyOutput << endl; 
				cout << "\tReceived: " << resultFromProgram << endl << endl; 
			}
		}

		fSampleIn.close(); fSampleOut.close(); fSampleOutForVerify.close();
	}
};

int main()
{
	codeJam codeJamObj;

	//Test Code
	#ifdef FILE_NAME_SAMPLE
		cout << "Unit Testing... " << endl;
		codeJamObj.processInput(FILE_NAME_SAMPLE);
		unitTesting testProgramOutput;
		testProgramOutput.run_test(FILE_NAME_SAMPLE);
		cout << endl;
	#else
		#ifndef FILE_NAME_SMALL
			#ifndef FILE_NAME_LARGE  
				cout << "Unit Testing... " << endl;
				codeJamObj.processInput("sample");
				unitTesting testProgramOutput;
				testProgramOutput.run_test("sample");
				cout << endl;
			#endif
		#endif
	#endif

	#ifdef FILE_NAME_SMALL
		cout << "Small Input: ";
		codeJamObj.processInput(FILE_NAME_SMALL);
		cout << "Complete!" << endl;
	#endif

	#ifdef FILE_NAME_LARGE
		cout << "Large Input: ";
		codeJamObj.processInput(FILE_NAME_LARGE);
		cout << "Complete!" << endl;
	#endif

	getchar();
	return 0;
}