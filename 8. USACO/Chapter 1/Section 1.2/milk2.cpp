/*
ID: faijur1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

	vector<int> start, end;
    int n;
	fin >> n;

	start.resize(n);
	end.resize(n);

	for(int i=0; i<n; i++)
	{
		fin >> start[i] >> end[i];
	}

	for(int i=0; i<n; i++)
	{
		int t=i;
		for(int j=i; j<n; j++) if(start[t]>start[j]) t=j;

		if(t!=i)
		{
			start[i] ^= start[t] ^= start[i] ^= start[t];
			end[i] ^= end[t] ^= end[i] ^= end[t];
		}
	}

	int lastStart = start[0];
	int lastEnd = end[0];
	int activeTime = lastEnd-lastStart;
	int idleTime = 0; 
	for(int i=0; i<n; i++)
	{
		if(start[i]<=lastEnd && lastEnd<end[i])
		{
			lastEnd = end[i];
		}
		else if(start[i]>lastEnd)
		{
			activeTime = max(activeTime, lastEnd-lastStart);
			idleTime = max(idleTime, start[i]-lastEnd);
			lastStart = start[i];
			lastEnd = end[i];
		}
	}			

	fout << activeTime << " " << idleTime << endl;   
    return 0;
}