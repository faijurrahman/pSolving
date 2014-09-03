#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define All(c) (c).begin(),(c).end()

#define MAX_LEN 100
bool dp[MAX_LEN][MAX_LEN];

//list Longest IDB (Incresing, Decresing and Biotonic) subSequence
class listLongestIDBsubSequence
{
public:
	//Longest Incresing subSequence
	//Time = O(N2) and space = O(N)
	void listLIS(vector<int> arr)
	{
		int X = arr.size();
		int *lis = new int[X];

		//Init LIS
		loop(i,X) lis[i] = 1;

		/* Compute LIS values from left to right */
		int maxLIS = 0;
		loop(i,X) loop(j,i) 
			if( arr[i] > arr[j]) 
			{
				lis[i] = max(lis[i], lis[j] + 1);
				maxLIS = max(maxLIS, lis[i]);
			}

		vector<int> index;
		int temp = maxLIS, lastIndx = X-1;
		for(int i=X-1; i>=0; i-- )
		   if(lis[i] == temp && (temp == maxLIS || arr[i] < arr[lastIndx]))
		   {
			  index.push_back(i);
			  lastIndx = i;
			  --temp;
		   }
		reverse(All(index));

		cout<<endl<<"LIS List: ";
		loop(i,(int)index.size()) cout<<arr[index[i]]<<" ";
	}
	
	//Longest Decresing subSequence
	//Time = O(N2) and space = O(N)
	void listLDS(vector<int> arr)
	{
		int X = arr.size();
		int *lds = new int [X];

		//Init LDS
		loop(i,X) lds[i] = 1;

		/* Compute LDS values from right to left */
		int maxLDS = 0;
		for (int i = X-1; i >= 0; i-- )
			for (int j = X-1; j >= i; j-- )
				if ( arr[i] > arr[j])
				{
					lds[i] = max(lds[i], lds[j] + 1);
					maxLDS = max(maxLDS, lds[i]);
				}

		
		vector<int> index;
		int temp = maxLDS, lastIndx = 0;
		loop(i,X)
		   if(lds[i] == temp && (temp == maxLDS || arr[i] < arr[lastIndx]))
		   {
			  index.push_back(i);
			  lastIndx = i;
			  --temp;
		   }

		cout<<endl<<"LDS List: ";
		loop(i,(int)index.size()) cout<<arr[index[i]]<<" ";
	}

	//Longest Biotonic Subsequence
	//Time = O(N2) and space = O(2N)
	void listLBS(vector<int> arr)
	{
		int X = arr.size();		
		int *lis = new int[X];
		int *lds = new int [X];

		//Init LIS and LDS
		loop(i,X) {lds[i]=1; lds[i]=1;}

		/* Compute LIS values from left to right */
		loop(i,X) loop(j,i) 
			if( arr[i] > arr[j]) 
				lis[i] = max(lis[i], lis[j] + 1);


		/* Compute LDS values from right to left */
		for (int i = X-1; i >= 0; i-- )
			for (int j = X-1; j >= i; j-- )
				if ( arr[i] > arr[j])
					lds[i] = max(lds[i], lds[j] + 1);


		int maxIndx=0, maxSeq = 0;
		loop(i,X) 
			if(maxSeq < (lis[i] + lds[i] - 1))
			{
				maxSeq = lis[i] + lds[i] - 1;
				maxIndx = i;
			}

		vector<int> index;
		int maxLIS = lis[maxIndx];
		for(int i=maxIndx; i>=0; i-- )
		   if(lis[i] == maxLIS)
		   {
			  index.push_back(i);
			  --maxLIS;
		   }
		reverse(All(index));

		int maxLDS = lds[maxIndx]-1;
		for(int i=maxIndx+1; i<X; i++)
		   if(lds[i] == maxLDS)
		   {
			  index.push_back(i);
			  --maxLDS;
		   }

		cout<<endl<<"LBS List: Not Implemented Yet";
		//loop(i,(int)index.size()) cout<<arr[index[i]]<<" ";
	}
};

// Driver program to test above function
int main()
{
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	//int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int X = sizeof(arr)/sizeof(arr[0]);

	vector<int> input;
	loop(i,X) input.push_back(arr[i]);

	cout<<"Input: ";
	loop(i,X) cout<<input[i]<<" ";

	listLongestIDBsubSequence subSeq;

	subSeq.listLIS(input);
	subSeq.listLDS(input);
	subSeq.listLBS(input);
	cout<<endl;

	return 0;
}