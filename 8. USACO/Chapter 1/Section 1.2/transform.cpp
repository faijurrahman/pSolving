/*
ID: faijur1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

int main() 
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int n;
	fin >> n;

	vector<string> A, B, T;
	A.resize(n);
	B.resize(n);

	for(int i=0; i<n; i++) fin >> A[i];
	for(int i=0; i<n; i++) fin >> B[i];
	T=A;
	bool flag;
	
	flag=true;
	for(int i=0, a=n-1; i<n; i++, a--)	
		for(int j=0, b=0; j<n; j++, b++)
			if(A[i][j] != B[b][a]){flag=false; break;}
	if(flag==true){fout << '1' << endl; return 0;}

	flag=true;
	for(int i=0, a=n-1; i<n; i++, a--)	
		for(int j=0, b=n-1; j<n; j++, b--)
			if(A[i][j] != B[a][b]){flag=false; break;}
	if(flag==true){fout << '2' << endl; return 0;}

	flag=true;
	for(int i=0, a=0; i<n; i++, a++)	
		for(int j=0, b=n-1; j<n; j++, b--)
			if(A[i][j] != B[b][a]){flag=false; break;}
	if(flag==true){fout << '3' << endl; return 0;}

	for(int i=0, a=0; i<n; i++, a++)	
		for(int j=0, b=n-1; j<n; j++, b--)
			T[i][j] = B[a][b];
	if(A==T){fout << '4' << endl; return 0;}

	
	flag=true;
	for(int i=0, a=n-1; i<n; i++, a--)	
		for(int j=0, b=0; j<n; j++, b++)
			if(A[i][j] != T[b][a]){flag=false; break;}
	if(flag==true){fout << '5' << endl; return 0;}

	flag=true;
	for(int i=0, a=n-1; i<n; i++, a--)	
		for(int j=0, b=n-1; j<n; j++, b--)
			if(A[i][j] != T[a][b]){flag=false; break;}
	if(flag==true){fout << '5' << endl; return 0;}

	flag=true;
	for(int i=0, a=0; i<n; i++, a++)	
		for(int j=0, b=n-1; j<n; j++, b--)
			if(A[i][j] != T[b][a]){flag=false; break;}
	if(flag==true){fout << '5' << endl; return 0;}

	flag=true;
	for(int i=0, a=0; i<n; i++, a++)	
		for(int j=0, b=0; j<n; j++, b++)
			if(A[i][j] != B[a][b]){flag=false; break;}
	if(flag==true){fout << '6' << endl; return 0;}


	fout << '7' << endl;		  
    return 0;
}