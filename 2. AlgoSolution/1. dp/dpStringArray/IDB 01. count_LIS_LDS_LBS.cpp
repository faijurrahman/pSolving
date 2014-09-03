//http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define N 100
int dp[N];
//count Longest IDB (Incresing, Decresing and Biotonic) subSequence
class countLongestIDBsubSequence
{
public:
	//Longest Incresing subSequence
	//Time = O(N2) and space = O(N)
	int countLIS(vector<int> input)
	{
		int maxLIS = 0;
		int X = input.size();
		memset(dp, 0, sizeof(dp));
	    loop(i,X) dp[i] = 1;
		loop(i,X) loop(j,i) if(input[i] > input[j]) dp[i] = max(dp[i], dp[j] + 1);
		loop(i,X) maxLIS = max(maxLIS, dp[i]);
		return maxLIS;
	}
	
	//Longest Decresing subSequence
	//Time = O(N2) and space = O(N)
	int countLDS(vector<int> input)
	{
		int maxLDS = 0;
		int X = input.size();
		memset(dp, 0, sizeof(dp));
	    loop(i,X) dp[i] = 1;

		/* Compute LDS values from right to left */
		for (int i = X-1; i >= 0; i-- )
			for (int j = X-1; j > i; j-- )
				if ( input[i] > input[j])
					dp[i] = max(dp[i], dp[j] + 1);

		loop(i,X) maxLDS = max(maxLDS, dp[i]);
		return maxLDS;
	}

	//Longest Biotonic Subsequence
	//Time = O(N2) and space = O(2N)
	int countLBS(vector<int> input)
	{
		int X = input.size();		
		memset(dp, 0, sizeof(dp));
		int *dp1 = new int [X];

		loop(i,X) {dp[i] = 1; dp1[i] = 1;}
		loop(i,X) loop(j,i) if(input[i] > input[j]) dp[i] = max(dp[i], dp[j] + 1);

		for (int i = X-1; i >= 0; i-- )
			for (int j = X-1; j > i; j-- )
				if ( input[i] > input[j])
					dp1[i] = max(dp1[i], dp1[j] + 1);

		int maxLBS = 0;
		loop(i,X) maxLBS = max(maxLBS, dp[i]);
		return maxLBS;
	}
};

// Driver program to test above function
int main()
{
	//int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> input;
	for(int i=0; i<n; i++)
		input.push_back(arr[i]);

	countLongestIDBsubSequence subSeq;
	cout<<"Longest Incresing subSequence (LIS): "<<subSeq.countLIS(input)<<endl;
	cout<<"Longest Decresing subSequence (LDS): "<<subSeq.countLDS(input)<<endl;
	cout<<"Longest Biotonic subSequence  (LBS): "<<subSeq.countLBS(input)<<endl;

	getchar();
	return 0;
}