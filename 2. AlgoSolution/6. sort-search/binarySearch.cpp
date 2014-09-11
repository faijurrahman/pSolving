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
		while(high>low+1) 
		{
			long long mid = low+(high-low)/2;
			if(isOk(mid)) high=mid;
			else low=mid;
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
