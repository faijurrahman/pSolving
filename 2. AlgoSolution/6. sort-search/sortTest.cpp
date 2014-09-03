//STL Header
#include<array>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>

//Essential Header
#include<algorithm>
#include<numeric>
#include<string>

//IO Header
#include<iostream>
using namespace std;


class sortTest 
{
	public:
		//Sorting multiple STL togather based on some rule
	
    template <class Type> void sortMultiSTL(Type& first, Type& second)
	{
		Type sortBase;
		int sortLength = first.size();

		for(int sortIndx1 = 0; sortIndx1 < sortLength; sortIndx1++)
		{
			sortBase.push_back(first[sortIndx1]);
			//sortBase.push_back(first[sortIndx1] + second[sortIndx1]);
			//sortBase.push_back(abs(first[sortIndx1] - second[sortIndx1]));
		}

		cout<<"inside sort"<<endl;
		for(int i:sortBase)cout<<i<<' ';cout<<endl;
		for(int i:first)cout<<i<<' ';cout<<endl;
		for(int i:second)cout<<i<<' ';cout<<endl;

		for(int sortIndx1 = 0; sortIndx1 < sortLength; sortIndx1++)
		{
			int sortTempIndx = sortIndx1;
			for(int sortIndx2 = sortIndx1; sortIndx2 < sortLength; sortIndx2++)
			{
				if(sortBase[sortTempIndx] > sortBase[sortIndx2]) 
				{
					sortTempIndx = sortIndx2;
				}
			}

			if(sortTempIndx != sortIndx1)
			{
				std::swap(sortBase[sortIndx1],	sortBase[sortTempIndx]);
				std::swap(first[sortIndx1],		first[sortTempIndx]);
				std::swap(second[sortIndx1],	second[sortTempIndx]);
				
			}
		}
	}
};

// BEGIN CUT HERE 
int main()
{
    sortTest testObject; 
	int s[]={100,21,5,40,30}, t[]={15,2,500,40,13};

	vector<int> A, B;
	for(int i:s) A.push_back(i);
	for(int i:t) B.push_back(i);

	cout<<"before sort"<<endl;
	for(int i:A)cout<<i<<' ';cout<<endl;
	for(int i:B)cout<<i<<' ';cout<<endl;

	testObject.sortMultiSTL(A,B); 

	cout<<"after sort"<<endl;
	for(int i:A)cout<<i<<' ';cout<<endl;
	for(int i:B)cout<<i<<' ';cout<<endl;
} 
// END CUT HERE 
    
