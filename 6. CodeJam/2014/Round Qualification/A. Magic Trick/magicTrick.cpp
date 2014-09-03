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

#define FILE_NAME_SMALL "A-small-attempt0"
//#define FILE_NAME_LARGE "B-large-practice"
#define FILE_NAME_SAMPLE "sample"

class codeJam
{
public:
	string calOuput(int row1, vector<vector<int>> in1, int row2, vector<vector<int>> in2)
	{
		int ans = 0, val = 0;
		set<int> setRow1, setRow2;

		loop(i,4)
		{
			setRow1.insert(in1[row1][i]);
			setRow2.insert(in2[row2][i]);
		}

		for(set<int>::iterator it1=setRow1.begin(); it1!=setRow1.end(); it1++)
			for(set<int>::iterator it2=setRow2.begin(); it2!=setRow2.end(); it2++)
				if(*it1 == *it2){val = *it1; ans++;}

		if(ans == 1) return to_string(val);
		else if(ans == 0) return "Volunteer cheated!";
		
		return "Bad magician!";
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
			vector<vector<int>> input1, input2;
			int row1, row2, val;
			input1.resize(4);
			input2.resize(4);

			fin >> row1;
			loop(i,4) loop(j,4)
			{
				fin >> val;
				input1[i].push_back(val);
			}

			fin >> row2;
			loop(i,4) loop(j,4)
			{
				fin >> val;
				input2[i].push_back(val);
			}

			fout << "Case #" << k+1 << ": " << calOuput(row1-1, input1, row2-1, input2) << endl;
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