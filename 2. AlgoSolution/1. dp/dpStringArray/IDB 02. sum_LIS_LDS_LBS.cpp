#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//sum of Longest IDB (Incresing, Decresing and Biotonic) subSequence
class sumLongestIDBsubSequence
{
public:
	//Sum of Longest Incresing subSequence
	//Time = O(N2) and space = O(N)
	int sumLIS(vector<int> input)
	{
		int n = input.size();
		int *dp = new int[n];

		//Init
		for (int i = 0; i < n; i++ )
			dp[i] = input[i];

		for (int i = 0; i < n; i++ )
			for (int j = 0; j < i; j++ )
				if ( input[i] > input[j])
					dp[i] = max(dp[i], dp[j] + input[i]);

		int maxSum = 0;
		for (int i = 0; i < n; i++)
			maxSum = max(maxSum, dp[i]);

		return maxSum;
	}
	
	//Sum of Longest Decresing subSequence
	//Time = O(N2) and space = O(N)
	int sumLDS(vector<int> input)
	{
		int n = input.size();
		int *dp = new int [n];
		
		//Init
		for (int i = 0; i < n; i++ )
			dp[i] = input[i];

		for (int i = n-1; i >= 0; i-- )
			for (int j = n-1; j > i; j-- )
				if ( input[i] > input[j])
					dp[i] = max(dp[i], dp[j] + input[i]);

		int maxSum = 0;
		for (int i = 0; i < n; i++)
			maxSum = max(maxSum, dp[i]);

		return maxSum;
	}

	//Sum of Longest Biotonic Subsequence
	//Time = O(N2) and space = O(2N)
	int sumLBS(vector<int> input)
	{
		int n = input.size();		
		int *dp = new int[n];
		int *dp1 = new int [n];

		//Init LIS and LDS
		for (int i = 0; i < n; i++ )
		{
			dp[i] = input[i];
			dp1[i] = input[i];
		}

		for (int i = 0; i < n; i++ )
			for (int j = 0; j < i; j++ )
				if ( input[i] > input[j])
					dp[i] = max(dp[i], dp[j] + input[i]);

		for (int i = n-1; i >= 0; i-- )
			for (int j = n-1; j > i; j-- )
				if ( input[i] > input[j])
					dp1[i] = max(dp1[i], dp1[j] + input[i]);


		int maxSum = 0;
		for (int i = 0; i < n; i++)
			maxSum = max(maxSum, dp[i] + dp1[i] - input[i]);

		return maxSum;
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

	sumLongestIDBsubSequence subSeq;
	cout<<"Sum of Longest Incresing subSequence (maxSIS): "<<subSeq.sumLIS(input)<<endl;
	cout<<"Sum of Longest Decresing subSequence (maxSDS): "<<subSeq.sumLDS(input)<<endl;
	cout<<"Sum of Longest Biotonic subSequence  (maxSBS): "<<subSeq.sumLBS(input)<<endl;

	getchar();
	return 0;
}