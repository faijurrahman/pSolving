#include<set>
#include<climits>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include <iomanip>
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

//#define FILE_NAME_SMALL "B-small-attempt0"
#define FILE_NAME_LARGE "B-large"
#define FILE_NAME_SAMPLE "sample"

class codeJam
{
public:
	double calOuput(double C, double F, double T)
	{
		double ans = 0;
		double cokNum = 2;

		while(1)
		{
			double timeWithAnotherF = C/cokNum + T/(cokNum+F);
			double timeReqT = T/cokNum;
			if(timeReqT <= timeWithAnotherF)
			{
				ans += T/cokNum;
				break;
			}
			else
			{
				ans += C/cokNum;
				cokNum+=F;
			}
		}

		
		return ans;
	}

	void processInput(string file)
	{
		ifstream fin;
		ofstream fout;
		fout.unsetf(std::ios::floatfield);
		fout.precision(7);
		int X;

		fin.open(file + ".in" );
		fout.open(file + ".out");	
		fin >> X;

		loop(i,X)
		{
			double C, F, T;
			fin >> C >> F >> T;
			double ans = calOuput(C, F, T);
			char output[100];
			sprintf_s(output, "%.7f",ans);
			fout << "Case #" << i+1 << ": " << output << endl;
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
	#endif
	getchar();
	return 0;
}