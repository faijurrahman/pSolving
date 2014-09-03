/*
ID: faijur1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



int main() 
{
	ofstream fout ("milk.out");
	ifstream fin ("milk.in");

	int tot, n;
	fin>>tot>>n;

	vector<int> p, a;
	int price, amount;
	for(int i=0; i<n; i++)
	{
		fin>>price>>amount;
		p.push_back(price);
		a.push_back(amount);
	}

	for(int i=0; i<n; i++)
	{
		int t=i;
		for(int j=t; j<n; j++)
			if(p[j] < p[t]) t=j;

		if(i!=t)
		{
			p[i] ^= p[t] ^= p[i] ^= p[t];
			a[i] ^= a[t] ^= a[i] ^= a[t];
		}
	}

	int pr=0, am=0;
	for(int i=0; i<n; i++)
	{
		if(am+a[i]<tot)
		{
			am+=a[i];
			pr+=(a[i]*p[i]);
		}
		else
		{
			pr+=(tot-am)*p[i];
			break;
		}
	}

	fout<<pr<<endl;

	return 0;
}