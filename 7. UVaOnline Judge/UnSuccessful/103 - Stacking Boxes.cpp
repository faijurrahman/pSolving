#include<vector>
#include<algorithm>
#include<sstream>
#include<iostream>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define All(c) (c).begin(),(c).end()
#define N 30
int dp[N+1];

bool isLess(vector<int> a, vector<int> A)
{
	int X = A.size()-1;
	loop(i,X) if(a[i]>=A[i]) return false;
	return true;
}

bool compare(vector<int> a, vector<int> A)
{
	int X = A.size()-1;
	loop(i,X) if(a[i]>=A[i]) return false;
	return true;
}

void processBox(vector<vector<int>> data)
{
	int X = data.size();
	int Y = data[0].size();

	loop(i,X) 
	{
		sort(All(data[i]));
		data[i].push_back(i+1);
	}
	sort(All(data), compare);

	loop(i,X) dp[i] = 1;
	loop(i,X) loop(j,i) if(isLess(data[j], data[i])) dp[i] = max(dp[i], dp[j] + 1);

	int maxLIS = 0;
	loop(i,X) maxLIS = max(maxLIS, dp[i]);
	
	vector<int> index;
	int temp = maxLIS, lastIndx=X-1;
	for(int i=X-1; i>=0; i--)
	{
		if(dp[i] == temp && 
			(temp == maxLIS || //Initial case
			isLess(data[i], data[lastIndx]))// All other case
		   )
		{
			index.push_back(data[i][Y]);
			lastIndx = i;
			temp--;
		}
	}
	reverse(All(index));

	cout<<maxLIS<<endl;
	loop(i,maxLIS)
	{
		cout << index[i]; 
		if(i!=maxLIS-1) cout<< " ";
	}
	cout<<endl;
}

#define INVALID -1
// Driver program to test above function
int main()
{
	int X, Y;
	string input;

	while (getline(cin, input))
	{
		stringstream ss(input);
		X=INVALID, Y=INVALID;
		ss >> X >> Y;

		if(X!=INVALID && X!=0 && Y!=INVALID)
		{
			vector<vector<int>> data;
			data.resize(X);
			loop(i,X)
			{
				data[i].resize(Y);
				getline(cin, input);
				stringstream sss(input);
				loop(j,Y) sss >> data[i][j];
			}
			processBox(data);
		}
		else if(X==0)
		{
			cout<<"0 "<<endl;
		}
	}
	return 0;
}