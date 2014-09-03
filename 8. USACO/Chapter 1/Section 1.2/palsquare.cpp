/*
ID: faijur1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool isPalin(string str)
{
	int i=0, n=str.size()-1;
	while(i<=n && str[i++]==str[n--])
	if(i>n) return true;
	return false;
}

int main() 
{
	ofstream fout ("palsquare.out");
	ifstream fin ("palsquare.in");

	char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

	int base;
	fin>>base;

	for(int i=1; i<=300; i++)
	{
		//vector<char> num;
		string pNum;
		string num;
		int t=i;
		while(t)
		{
			num.insert(num.begin(),digit[t%base]);
			t=(t/base);
		}

		t=i*i;
		while(t)
		{
			pNum.insert(pNum.begin(),digit[t%base]);
			t=(t/base);
		} 
		if(isPalin(pNum)) fout<<num<<' '<< pNum<<endl;
	}
	return 0;
}