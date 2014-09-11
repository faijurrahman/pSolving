#include<algorithm>
#include<bitset>
#include<vector>
#include<string>
#include<iostream>
#include <sstream>
#include<cstring>
#include<climits>
#include<set>
using namespace std;


int binarySearch(int arr[], int high, int low, int target)
{
	int mid;
	while(high>low)
	{
		mid=low+(high-low)/2;
		if(arr[mid]==target) return mid; 
		else if(arr[mid]<target) low=mid+1; 
		else high=mid-1;
	}
	return -1;
}
 
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int X = sizeof(arr)/sizeof(arr[0]);
   int ans = binarySearch(arr,X-1,0,arr[2]);
   if(ans==-1) cout<<"Element is not present in array"<<endl;
   else cout<<"Element is present at index "<<ans<<endl;
   return 0;
}
    
