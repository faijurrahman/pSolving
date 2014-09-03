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
#define _N 101
bool dp[_N][_N];

#define FILE_NAME_SMALL "B-small-practice"
#define FILE_NAME_LARGE "B-large-practice"
#define FILE_NAME_SAMPLE "sample"

class codeJam
{
public:
	string calOuput(vector<vector<int>> in)
	{
		int ans = 1;
		int X = in.size();
		int Y = in[0].size();
		set<int> lst;
		ZERO(dp);

		loop(i,X) loop(j,Y) lst.insert(in[i][j]);
		int Z = lst.size();

		for(set<int>::reverse_iterator it=lst.rbegin(); it!=lst.rend(); it++)
		{
			int val = *it;
			loop(i,X) 
			{
				bool ok = true;
				loop(j,Y) if(val < in[i][j]) ok = false;
				if(ok) loop(j,Y) if(val == in[i][j]) dp[i][j] = true;
			}

			loop(j,Y) 
			{
				bool ok = true;
				loop(i,X) if(val < in[i][j]) ok = false;
				if(ok) loop(i,X) if(val == in[i][j]) dp[i][j] = true;
			}

			loop(i,X) loop(j,Y) if(val == in[i][j] && !dp[i][j]) return "NO";
		}
		
		return "YES";
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
			vector<vector<int>> input;
			int X, Y, val;
			fin >> X >> Y;
			input.resize(X);

			loop(i,X) loop(j,Y)
			{
				fin >> val;
				input[i].push_back(val);
			}

			fout << "Case #" << k+1 << ": " << calOuput(input) << endl;
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