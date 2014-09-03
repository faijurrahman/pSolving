/*
ID: faijur1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    int a=1, b=1;
	string A, B;
    fin >> A >> B;
	for(int i=0; i<A.size(); i++) a*=(A[i]-65+1);
	for(int i=0; i<B.size(); i++) b*=(B[i]-65+1);
	if(a%47 == b%47) fout << "GO" << endl;
	else fout << "STAY" << endl;
    
    return 0;
}