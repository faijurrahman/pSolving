#include<set>
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

//#define FILE_NAME_SMALL "D-small-attempt0"
#define FILE_NAME_LARGE "D-large"
//#define FILE_NAME_SAMPLE "sample"


class codeJam
{
public:
	string calculateOuput(vector<double> wt1, vector<double> wt2)
	{
		
		int X = wt1.size();
		sort(All(wt1));
		sort(All(wt2));

		int ans1=0, ans2 = 0;

		for(int i=X-1, j=X-1; i>=0 && j>=0; j--)
		{
			if(wt1[i] > wt2[j]){ans1++; i--;}
		}

		for(int i=X-1, j=X-1; i>=0 && j>=0; i--)
		{
			if(wt1[i] < wt2[j]){ans2++; j--;}
		}
		ans2 = X-ans2;


		
		string ans = "";
		ans += to_string(ans1);
		ans += " ";
		ans += to_string(ans2);

		return ans;
	}

	void processInput(string file)
	{
		ifstream fin;
		ofstream fout;
		int Z;

		fin.open(file + ".in" );
		fout.open(file + ".out");	
		fin >> Z;

		loop(k,Z)
		{
			vector<double> input1, input2;
			double val;
			int X;
			
			fin >> X;
			input1.resize(X);
			input2.resize(X);
			loop(i,X)
			{
				fin >> val;
				input1[i] = val;
			}

			loop(i,X)
			{
				fin >> val;
				input2[i] = val;
			}

			string ans = calculateOuput(input1, input2);
			fout << "Case #" << k+1 << ": " << ans << endl;
		}

		fin.close();
		fout.close();
	}
};

class unitTesting
{
	ifstream fSampleIn;
	ifstream fSampleOut;
	ifstream fSampleOutForVerify;	

public:
	void run_test(string sampleFileName) 
	{ 
		const int GET_LINE_LENGHT = 100;

		fSampleIn.open(sampleFileName + ".in");
		fSampleOut.open(sampleFileName +  ".out");
		fSampleOutForVerify.open("sampleForVerify.out");

		int X;
		fSampleIn >> X;
		loop(i,X)
		{
			char resultFromProgram[GET_LINE_LENGHT+1], sampleForVerifyOutput[GET_LINE_LENGHT+1];
			fSampleOut.getline(resultFromProgram,GET_LINE_LENGHT);
			fSampleOutForVerify.getline(sampleForVerifyOutput,GET_LINE_LENGHT);
			if(strcmp(resultFromProgram,sampleForVerifyOutput) == 0) cout << "Case " << i << ": Passed" << endl;
			else
			{
				cout << "Case " << i << ": Failed" << endl;
				cout << "\tExpected: " << sampleForVerifyOutput << endl; 
				cout << "\tReceived: " << resultFromProgram << endl; 
			}
		}

		fSampleIn.close();
		fSampleOut.close();
		fSampleOutForVerify.close();
	}
};

int main()
{
	codeJam codeJamObj;

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

	//Test Code
	#ifdef FILE_NAME_SAMPLE
		cout << endl << "Unit Testing... " << endl;
		codeJamObj.processInput(FILE_NAME_SAMPLE);
		unitTesting testProgramOutput;
		testProgramOutput.run_test(FILE_NAME_SAMPLE);
	#else
		#ifndef FILE_NAME_SMALL
			#ifndef FILE_NAME_LARGE  
				cout << endl << "Unit Testing... " << endl;
				codeJamObj.processInput("sample");
				unitTesting testProgramOutput;
				testProgramOutput.run_test("sample");
			#endif
		#endif
	#endif
	getchar();
	return 0;
}