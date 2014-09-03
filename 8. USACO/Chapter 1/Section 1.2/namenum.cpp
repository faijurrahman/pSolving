/*
ID: faijur1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() 
{
	string inStr;
	vector<string> outStr;
	vector<string> numPad;
	
	string line;

	ofstream fout ("namenum.out");
	ifstream fin ("namenum.in");
	ifstream dict("dict.txt");



	numPad.resize(10);
	char alpha = 'A';
	for(int i=2; i<10; i++)
		for(int j=0; j<3; j++)
		{
			if(i<2) numPad[i].push_back('x'); 
			if(alpha=='Q') alpha='R';			
			numPad[i].push_back(alpha++); 
		}

	fin >> inStr;
	for(int i=0; i<inStr.size(); i++) 
		inStr[i]-=0x30;

	while (getline(dict, line)) 
		if(numPad[inStr[0]].find(line[0],0) != string::npos && line.size() == inStr.size()) 
			outStr.push_back(line);


	for(int i=1; i<inStr.size(); i++)
		for(int j=0; j<outStr.size(); j++)
			if(outStr[j].size() == inStr.size()) 
				if(numPad[inStr[i]].find(outStr[j][i],0) == string::npos) 
					outStr.at(j).erase();
	
	for(int j=0; j<outStr.size(); j++)
		if(outStr[j] == "")
			outStr.erase(outStr.begin()+j--);

	if(outStr.size() != 0)
	{
		for(int j=0; j<outStr.size(); j++)
			fout << outStr[j] << endl;
	}
	else
	{
		fout << "NONE" << endl;
	}

	return 0;
}