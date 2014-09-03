#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class activitySchedule
{
	void sortMulti(vector<int>& X, vector<int>& Y)
	{
		int n = X.size();

		for(int i = 0; i < n; i++)
		{
			int t = i;
			for(int j = i; j < n; j++)
				if(X[t] > X[j]) 
					t = j;

			if(t != i)
			{
				std::swap(X[i],	X[t]);
				std::swap(Y[i],	Y[t]);				
			}
		}
	}

public:
	vector<pair<int, int>> activitySelect(vector<int> X, vector<int> Y)
	{
		sortMulti(Y, X);
		int n = X.size();

		vector<pair<int, int>> res;
		int t = 0;
		res.push_back(make_pair(X[0],Y[0]));

		for (int i = 1; i < n; i++)
		{
			if (X[i] >= Y[t])
			{
				res.push_back(make_pair(X[i],Y[i]));
				t = i;
			}
		}
		return res;
	}

};

// Driver program to test above function
int main()
{
	int s[] =  {1, 3, 0, 5, 5, 8, 5};
	int f[] =  {2, 4, 6, 9, 7, 9, 9};
	int n = sizeof(s)/sizeof(s[0]);

	vector<int> start, finish;
	for (int i=0; i<n; i++)
	{
		start.push_back(s[i]);
		finish.push_back(f[i]);
	}
	activitySchedule scheduler;

	vector<pair<int, int>> result = scheduler.activitySelect(start, finish);

	cout << "Input Activity" << endl;
	for(int i=0; i<n; i++) cout << s[i] << " -- " << f[i] << endl;

	cout << endl << "Selected Activity" << endl;
	for(int i=0; i<result.size(); i++) cout << result[i].first << " -- " << result[i].second << endl;

	getchar();
	return 0;
}