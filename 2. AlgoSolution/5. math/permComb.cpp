#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))

int r;
string inputStr;
set<string> permSet, combSet;

bool isSafe(string str, char C)
{
	int count=0, p1=-1, p2=-1;
	while((p1=inputStr.find(C,p1+1)) != string::npos) count++;
	while((p2=str.find(C,p2+1)) != string::npos) count--;
	if(count>0) return true;
	return false;
}

void permComb(string str)
{
	if(str.size() == r)
	{
		permSet.insert(str);
		sort(str.begin(), str.end());
		combSet.insert(str);
		return;
	}

	for(int i=0; i<(int)inputStr.size(); i++)
		if(isSafe(str,inputStr[i]))
		{
			str.push_back(inputStr[i]);
			permComb(str);
			str.pop_back();
		}
}

string str;
void permut(int i)
{
	static int cnt=0;
	if(i==str.size()-1){cout<<(++cnt)<<". "<<str<<endl; return;}
	LOOP(j,i,str.size())
	{
		if(i!=j) str[i]^=str[j]^=str[i]^=str[j];
		permut(i+1);
		if(i!=j) str[i]^=str[j]^=str[i]^=str[j];
	}
}

int main()
{
	int nPr, nCr;

	cout<<"Enter string: ";
	while(cin >> inputStr)
	{
		cout<<"String length, n: "<< inputStr.length() << endl;
		cout<<"Enter value of r: ";
		cin>>r;

		if((int)inputStr.length() >= r)
		{
			nPr = nCr = 0;	
			permComb("");//calculate permutation and combination of inputStr

			cout<<endl<<"Permutation:"<<endl;
			for (set<string>::iterator it=permSet.begin(); it!=permSet.end(); ++it)
				cout  << ++nPr << ": " << *it << endl;

			cout<<endl<<"Combination:"<<endl;
			for (set<string>::iterator it=combSet.begin(); it!=combSet.end(); ++it)
				cout  << ++nCr << ": " << *it << endl;
		}
		else
		{
			cout<<"Error: value of r is greater than n."<<endl;
		}

		cout<<endl<<"All permutations"<<endl;
		str=inputStr;
		permut(0);
		cout<<endl<<"Press Ctrl+Z+Enter to exit. \nEnter string again: ";
	}
} 

