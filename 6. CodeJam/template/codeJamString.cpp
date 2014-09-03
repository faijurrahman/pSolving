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
#define _N 100
int dp[_N][_N];

#define FILE_NAME_SAMPLE "1.sample"
#define FILE_NAME_SMALL "2.small"
#define FILE_NAME_LARGE "3.large"

class codeJam
{
public:
	string calculateOuput(vector<string> in)
	{
		int ans = 1;
		int X = in.size();
		
		return ans ? "Possible" : "Impossible";
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
			loop(i,4)
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