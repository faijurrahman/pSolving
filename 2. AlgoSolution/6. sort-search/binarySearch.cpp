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

	int bSearchAdv(int high, int low)
	{
		X=searchSpace.size();
		while(high>low) 
		{
			int mid = low+(high-low)/2;
			if(calVal(mid)<=target) high=mid;
			else low=mid+1;
		}
		return low;
	}

	int calVal(int x)
	{
		int required=1, load=0;
		loop(i,X)
		{
			if(load+searchSpace[i]<=x) load+=searchSpace[i];
			else{ ++required; load=searchSpace[i];}             
		}
		return required;
	}
};
