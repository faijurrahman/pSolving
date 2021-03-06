//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<numeric>

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

class binSearch
{
	public:
	int X;
	int target;
	vector<int> searchSpace;

	binSearch(vector<int> sSpace, int tar)
	{
		searchSpace = sSpace;
		target = tar;
		X = searchSpace.size();
	}

	int bSearch(int high, int low)
	{
		int mid;
		while(high>low)
		{
			mid=low+(high-low)/2;
			if(searchSpace[mid]==target) return mid; 
			else if(searchSpace[mid]<target) low=mid+1; 
			else high=mid-1;
		}
		return -1;
	}

	long long bSearchAdv(long long high, long long low)
	{
		X=searchSpace.size();
		while(high>low) 
		{
			long long mid = (high+low+1)/2;
			if(isOk(mid)) high=mid;
			else low=mid+1;
		}
		return low;
	}

	bool isOk(long long x)
	{
		long long count=0;
		loop(i,X)
		{
			if(searchSpace[i]<=x)
			{
				count++;  
			}   
			else
			{
				count+=2;
			}       
		}
		return count<=target;
	}
};


int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int X = sizeof(arr)/sizeof(arr[0]);

   vector<int> arra;
   loop(i,X) arra.push_back(arr[i]);

   binSearch bs(arra,arr[3]);
   int ans = bs.bSearch(X-1,0);
   if(ans==-1) cout<<"Element is not present in array"<<endl;
   else cout<<"Element is present at index "<<ans<<endl;
   return 0;
}
    
