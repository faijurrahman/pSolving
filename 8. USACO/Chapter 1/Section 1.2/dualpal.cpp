/*
ID: faijur1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>

using namespace std;
char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool isPalin(int num, int base)
{
	string str;
	while(num)
	{
		str.insert(str.begin(), digit[num%base]);
		num = num/base;
	}

	int i=0, n=str.size()-1;
	while(i<=n) if(str[i++] != str[n--]) return false;
	return true;
}

int main() 
{
	ofstream fout ("dualpal.out");
	ifstream fin ("dualpal.in");

	int N, S;
	fin>>N>>S;

	int c=0;
	unsigned int num = S+1;
	while(c<N && num != INT_MAX)
	{
		int pC=0;
		for(int i=2; i<=10; i++)
		{
			if(isPalin(num, i))
			{
				pC++;
				if(pC>=2)
				{
					c++;
					fout<<num<<endl;
					break;
				}
			}
		}
		num++;
	}


	return 0;
}