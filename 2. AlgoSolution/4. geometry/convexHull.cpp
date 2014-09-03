// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

class cHull
{
	template<class Type>
	long long crossProduct(const Type &O, const Type &A, const Type &B)
	{
		//(X1Y2-X2Y1 == (X1-X0)*(Y2-Y0) - (X2-X0) * (Y1-Y0)
		//Negative if OA is counter-clockwise of OB
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



//*****************************************************************************
//From Wikipedia
//*****************************************************************************
// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <vector>
using namespace std;

typedef int coord_t;         // coordinate type
typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point 
{
	coord_t x, y;

	bool operator <(const Point &p) const
	{
		return x < p.x || (x == p.x && y < p.y);
	}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; i++) 
	{
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) 
	{
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}