/*
ID: faijur1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;



int main() 
{
	ofstream fout ("barn1.out");
	ifstream fin ("barn1.in");

	int res=0;
	int p, n, c;
	int cN[200],tD[200];
	fin>>p>>n>>c;
	for(int i=0; i<c; i++) fin>>cN[i];
	sort(cN, cN+c);
	res=cN[c-1]-cN[0]+1;

	for(int i=0; i<c-1; i++) tD[i]=cN[i+1]-cN[i]-1;
	sort(tD, tD+c-1);
	
	for(int i=0; i<p-1 && c-i-2>=0 ; i++) 
		res-=tD[c-i-2];

	fout<<res<<endl;

	return 0;
}