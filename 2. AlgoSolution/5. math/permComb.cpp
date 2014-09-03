#include<string>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

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

		cout<<endl<<"Press Ctrl+Z+Enter to exit. \nEnter string again: ";
	}
} 

