/*
ID: faijur1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;;
	string str;
    fin >> n;
	fin >> str;

	int count=0, pos=0;

	int p=0;
	while(p<=n+1 && str[p%n]==str[(p+1)%n]) p++;

	if(p>=n) count = n;
	else
	{
		for(int i=0; i<n; i++) 
		{
			if(str[i] != str[(i+1)%n])
			{
				int j=0; 
				if(str[(i+1)%n] == 'b') while(j<n && (str[(i+1+j)%n]=='b' || str[(i+1+j)%n]=='w')) j++;
				else if(str[(i+1)%n] == 'r') while(j<n && (str[(i+1+j)%n]=='r' || str[(i+1+j)%n]=='w')) j++;
				else 
				{
					while(j<n && (str[(i+1+j)%n]=='b' || str[(i+1+j)%n]=='w')) j++;
					int t=j;
					j=0;
					while(j<n && (str[(i+1+j)%n]=='r' || str[(i+1+j)%n]=='w')) j++;
					j = max(j,t);
				}

				int k=n;
				if(str[i] == 'b') while(k>0 && (str[(i+k)%n]=='b' || str[(i+k)%n]=='w')) k--;
				else if(str[i] == 'r') while(k>0 && (str[(i+k)%n]=='r' || str[(i+k)%n]=='w')) k--;
				else 
				{
					while(k>0 && (str[(i+k)%n]=='b' || str[(i+k)%n]=='w')) k--;
					int t=k;
					k=n;
					while(k>0 && (str[(i+k)%n]=='r' || str[(i+k)%n]=='w')) k--;
					k = min(k,t);
				}

				if(count != max(count, j+(n-k)) )
				{
					count = max(count, j+(n-k));
					if(count>n) count = n;
					pos = (i+1)%n;
				}
			}
		}
	}

	fout << count << endl;
  
    return 0;
}