/*
ID: faijur1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	vector<string> name;
	vector<int> account, initAcc;
	int n=0;
	fin>>n;
	name.resize(n);
	account.resize(n);
	initAcc.resize(n);

	for(int i=0; i<n; i++)
	{
		account[i] = 0;
		initAcc[i] = 0;
		fin>>name[i];
	}

	string tName;
	int j, amount, fNum;
	for(int i=0; i<n; i++) 
	{
		fin>>tName; 
		fin>>amount>>fNum;

		for(j=0; j<n; j++) 
			if(tName == name[j])
			{
				initAcc[j] = amount;
				if(fNum > 0) account[j] += amount%fNum;
				else account[j] += amount;
				break;
			}
		

		string tgName;
		for(int k=0; k<fNum; k++)
		{
			fin>>tgName;
			for(j=0; j<n; j++) 
				if(tgName == name[j])
				{
					if(fNum > 0) account[j] += amount/fNum;
					break;
				}
		}
	}

	for(int i=0; i<n; i++) fout << name[i] << " " << account[i] - initAcc[i] << endl;
  
    return 0;
}