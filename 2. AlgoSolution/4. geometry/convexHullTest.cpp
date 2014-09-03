#include <algorithm>
#include <vector>
#include <utility>
#include<iostream>
using namespace std;


class cHull
{
	template<class Type>
	long long crossProduct(const Type &O, const Type &A, const Type &B)
	{
		//(X1Y2-X2Y1 == (X1-X0)*(Y2-Y0) - (X2-X0) * (Y1-Y0)
		//Negative if OA is counter-clockwise of OB
		cout<<"{("<< O.first << " " << O.second << "), ";
		cout<<"("<< A.first << " " << A.second << "), ";
		cout<<"("<< B.first << " " << B.second << ")} = ";
		cout<<(A.first - O.first) * (B.second - O.second) - (B.first - O.first) * (A.second - O.second)<<endl;
		return(A.first - O.first) * (B.second - O.second) - (B.first - O.first) * (A.second - O.second);
	}

public:
	template<class Type>
	vector<Type> convexHull(vector<Type> P)
	{
		int n = P.size(), k = 0;
		sort(P.begin(), P.end());

		vector<Type> H(2*n);

		for (int i = 0; i < n; i++) 
		{
			while (k >= 2 && crossProduct(H[k-2], H[k-1], P[i]) <= 0) k--;
			H[k++] = P[i];
		}

		for (int i = n-2, t = k+1; i >= 0; i--) 
		{
			while (k >= t && crossProduct(H[k-2], H[k-1], P[i]) <= 0) k--;
			H[k++] = P[i];
		}

		H.resize(k-1);
		return H;
	}
};

int main()
{
	cHull testHall; 

	vector<pair<int, int>> input, output;

	input.push_back(make_pair(0, 3)); 
	input.push_back(make_pair(1, 1)); 
	input.push_back(make_pair(4, 4)); 
	input.push_back(make_pair(0, 0)); 
	input.push_back(make_pair(2, 3)); 
	input.push_back(make_pair(3, 1)); 


	//pair<int, int> xy;
	//cout<<"Enter Your Number: ";
	//while(cin >> xy.first >> xy.second) input.push_back(xy);

	output = testHall.convexHull(input);


	cout << "Input:" << endl;
	for (int i = 0; i < input.size(); i++) 
		cout<<"("<< input[i].first << " " << input[i].second << "), ";

	cout <<endl << "Convex Hull:" << endl;
	for (int i = 0; i < output.size(); i++) 
		cout<<"("<< output[i].first << " " << output[i].second << "), ";

	
} 

