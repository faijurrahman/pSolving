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

#define FILE_NAME_SMALL "A-small-practice"
#define FILE_NAME_LARGE "A-large-practice"
#define FILE_NAME_SAMPLE "sample"

class codeJam
{
public:
	string calOuput(vector<string> in)
	{
		int X = in.size();
		int cX=0, cO=0, cD=0;

		loop(i,X) 
		{
			cX=0, cO=0;
			loop(j,X)
			{
				if(in[i][j]=='X' || in[i][j]=='T') cX++; 
				if(cX>=4) return "X won";

				if(in[i][j]=='O' || in[i][j]=='T') cO++;								
				if(cO>=4) return "O won";

				if(in[i][j]=='.') cD++;
			}
		}

		loop(j,X) 
		{
			cX=0, cO=0;
			loop(i,X)
			{
				if(in[i][j]=='X' || in[i][j]=='T') cX++; 
				if(cX>=4) return "X won";

				if(in[i][j]=='O' || in[i][j]=='T') cO++;								
				if(cO>=4) return "O won";
			}
		}

		cX=0, cO=0;
		loop(i,X) 
		{
			if(in[i][i]=='X' || in[i][i]=='T') cX++; 
			if(cX>=4) return "X won";

			if(in[i][i]=='O' || in[i][i]=='T') cO++;								
			if(cO>=4) return "O won";
		}

		cX=0, cO=0;
		for(int i=0, j=X-1; i<X; i++, j--) 
		{
			if(in[i][j]=='X' || in[i][j]=='T') cX++; 
			if(cX>=4) return "X won";

			if(in[i][j]=='O' || in[i][j]=='T') cO++;								
			if(cO>=4) return "O won";
		}

		return cD ? "Game has not completed" : "Draw";
	}

	void processInput(string file)
	{
		ifstream fin;
		ofstream fout;
		int X;

		fin.open(file+".in" );
		fout.open(file+".out");	
		fin >> X;

		loop(i,X)
		{
			int ans = 0;
			string str;
			vector<string> input;
			loop(j,4)
			{
				fin >> str;
				input.push_back(str);
			}

			fout << "Case #" << i+1 << ": " << calOuput(input) << endl;
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