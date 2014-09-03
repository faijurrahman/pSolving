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
#define _N 55
char dp[_N][_N];

#define FILE_NAME_SMALL "C-small-attempt3"
//#define FILE_NAME_LARGE "large"
//#define FILE_NAME_SAMPLE "sample"

class codeJam
{
public:
	bool calculateOuput(int X, int Y, int M)
	{
		bool ok=false;
		int x=0, y=0, m=M;
		FILL(dp,'.');
		dp[X-1][Y-1] = 'c';

		if(X==1)
		{
			loop(j,M) dp[0][j] = '*';
			dp[0][Y-1] = 'c';
			if(M<Y) return true; 
			else return false;
		}
		else if(Y==1)
		{
			loop(i,M) dp[i][0] = '*';
			dp[X-1][0] = 'c';
			if(M<X) return true; 
			else return false; 
		}

		if(M>=(X*Y-4))
		{
			if(M == (X*Y-1) || M == (X*Y-4)) 
			{
				loop(i,X) loop(j,Y) dp[i][j] = '*';
				if( M == (X*Y-4) )
				{
					dp[X-1][Y-2] = '.';
					dp[X-2][Y-1] = '.';
					dp[X-2][Y-2] = '.';
				}
				dp[X-1][Y-1] = 'c';
				return true;
			}
			else return false;
		}
		

		while(1)
		{
			if(m<=0) break;

			if(m>=(X-x) && (Y-y)>=3)
			{
				for(int i=x; i<X; i++) dp[i][y] = '*';
				m-=(X-x);
				y++;
			}
			else if(m>=(Y-y) && (X-x)>=3)
			{
				for(int j=y; j<Y; j++) dp[x][j] = '*';
				m-=(Y-y);
				x++;
			}
			else break;

		}

		if(m <= (X-x)*(Y-y) - 8)
		{
			int i=x, j=y;
			while(m)
			{
				dp[i][j++] = '*';
				if(Y-j<=3){j=y; x++; i=x;}
				m--;
			}
			y=j;
		}
		else if((X-x)*(Y-y) == 9)
		{
			if(m==5) loop(i,3){dp[X-3][Y-1-i] = '*'; dp[X-1-i][Y-3] = '*';}
			else if(m==3) loop(i,3) dp[X-3][Y-1-i] = '*'; 
			m=0;
		}
		
		if(m==0) ok=true;

		return ok;
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
			int X, Y, M;
			fin >> X >> Y >> M;
			bool ok = calculateOuput(X, Y, M);

			fout << "Case #" << k+1 << ":" << endl;
			if(ok)
			{
				loop(i,X)
				{
					loop(j,Y) fout << dp[i][j] << " ";
					fout << endl;
				}
			}
			else
			{
				fout << "Impossible" << endl;
			}
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
				cout << "\tReceived: " << resultFromProgram << endl << endl; 
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