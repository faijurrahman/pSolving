#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

#include<algorithm>
#include<numeric>
#include<string>

#include<iostream>
using namespace std;

class calPermComb 
{
	public:
	long long Fact(int n)
	{
		if(n < 0) return -1;//Someting is wrong
		int i, result=1;
		for(i=1; i<=n; i++) result*=i;
		return result;
	}

	//long long Fact(int n)
	//{
	//	if(n < 0) return -1;//Someting is wrong
	//	if(n <= 1) return 1;
	//	return(n * Fact(n-1));
	//}

	long long Perm(int n, int r)
	{
		if(n-r < 0) return -1;//Someting is wrong
		return( Fact(n) / Fact(n-r) );
	}

	long long Comb(int n, int r)
	{
		if(n-r < 0) return -1;//Someting is wrong
		return( Perm(n,r) / Fact(r) );
	}
};

class calRepPermComb 
{
	public:
	calPermComb calSimple;

	template <class Type> 
	long long Perm(vector<Type> element, int r)
	{
		int n = element.size();
		if(n-r < 0) return -1;//Someting is wrong
	
		//Clear the repSet
		for(int i=0; i<50; i++)
		{
			repSet[i].clear();
		}

		//Analyze repetation
		for(int i=0; i<n; i++)
		{			
			for(int j=1; j<=n; j++)
			{
				if(repSet[j].count(element[i]) == 0)
				{
					repSet[j].insert(element[i]);
					break;
				}
			}
		}


		if(repSet[2].size() > 0)
		{ 
			//Yes! there is repetation
			map<int, set<Type>> elementMap;
			for(int i=1; i<=n; i++)
			{
				if(repSet[i].size() <= 0) break;
				elementMap.insert(std::make_pair(i,repSet[i]));
			}
			
			return _calRecurPerm(elementMap,r);
		}

		return calSimple.Perm(n,r);//No Repetation
	}


	private:
	set<char> repSet[51];

	template <class Type> 
	long long _calRecurPerm(map<int, set<Type>> elementMap, int r)
	{
		if(r==0 || elementMap.empty()) return 0;

		if(r==1 || elementMap.size() == 1) 
			return calSimple.Perm(elementMap.begin()->second.size(),r);


		long long result = 0;
		int repNum;
		set<Type> elementTempSet;
		map<int, set<Type>>::iterator elementIt = elementMap.end();
		do
		{
			--elementIt;
			repNum = elementIt->first;
			elementTempSet = elementIt->second;
			elementMap.erase(elementIt);
		}
		while(repNum > r);

		elementTempSet.erase(--elementTempSet.end());
		if(elementTempSet.size()) 
			elementMap.insert(std::make_pair(repNum,elementTempSet));

		if(repNum == r) result++;


		return(result + _calRecurPerm(elementMap,r-repNum));
	}

	template <class Type> 
	long long _calRecurComb(map<int, set<Type>> elementMap, int r)
	{
		if(elementMap.empty()) return 1;

		if(elementMap.size() == 1) 
			return calComb(elementMap.begin()->second.size(),r);

		long long result = 1;
		map<int, set<Type>>::iterator elementIt = elementMap.end();
		--elementIt;
		//for( ; elementIt != elementMap.end(); ++elementIt);
		int repNum = elementIt->first;
		set<Type> elementTempSet = elementIt->second;
		elementMap.erase(elementIt);

		if(repNum < r) 
		{

			elementTempSet.erase(--elementTempSet.end());
			if(elementTempSet.size()) elementMap.insert(std::make_pair(repNum,elementTempSet));
		}

		return(1 + _calRecurComb(elementMap,r-1));
	}
};

class listPermComb 
{
	public:
	char permMem[1000][3];
	calPermComb calSimple;

    template <class Type> 
	long long permutation(vector<Type> element, int r)
	{
		recurPerm(element, r, 0, 0);
		return calSimple.Perm(element.size(),r);
	}

	private:
	template <class Type> 
	int recurPerm(vector<Type> element, int r, int start, int pos)
	{
		int n = element.size();
		int nPr = calSimple.Perm(n,r);
		if(nPr < 0) return -1;//Someting is wrong

		if(nPr==n && r==1)
		{
			for(int i=0; i<n; i++)
			{
				permMem[start+i][pos]=element[i];
			}
			return 0;
		}

		for(int j=0; j<n; j++)
		{
			int tempMemPos = start;
			for(int k=0; k<(nPr/n); k++)
			{
				permMem[tempMemPos++][pos]=element[j];
			}
			std::swap(element[j], element[n-1]);
			vector<Type> newElement = element;
			newElement.pop_back();
			recurPerm(newElement, r-1, start, pos+1);
			std::swap(element[n-1], element[j]);//backtrack
			start+=(nPr/n);
		}

		return 0;
	}
};


// BEGIN CUT HERE 
int main()
{
	listPermComb testObject; 

	string str="ABA";
	vector<char> vec;
	for(char i:str) vec.push_back(i);

	int n=vec.size(), r=3;
	int nPr = testObject.calSimple.Perm(n,r);
	
	testObject.permutation(vec,r); 

	for(int i = 0; i < nPr; ++i)
    {
        for(int j = 0; j < r; ++j)
            cout << testObject.permMem[i][j];
        cout << endl;
    }
	calRepPermComb testRepObj;
	cout <<"n=" <<n <<" r=" <<r << " nPr=" <<testRepObj.Perm(vec,r) <<endl;
} 
// END CUT HERE 
    
