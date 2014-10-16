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

#define ld long double
#define ll long long
#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

#define ZERO(arr) memset(arr,0,sizeof(arr))
#define FILL(arr,val) memset(arr,val,sizeof(arr))
#define MOD 1000000007

struct point
{
    public: double x,y;
	point(){}
	point(double a, double b){x=a;y=b;}
	void setXY(double a, double b){x=a;y=b;}
	bool operator <(const point &p) const
	{
		return x < p.x || (x == p.x && y < p.y);
	}
};

//compute the distance from a to b
double dist(point a, point b)
{
	double d1 = a.x-b.x;
	double d2 = a.y-b.y;
	return sqrt(d1*d1 + d2*d2);
}

//find center of the circle which goes though points a, b, c
point centerOfCircle(point a, point b, point c)
{
	double A1 = a.x-b.x;
	double A2 = b.x-c.x;
	double B1 = a.y-b.y;
	double B2 = b.y-c.y;
	double C1 = (A1*(a.x+b.x) + B1*(a.y+b.y))/2;
	double C2 = (A2*(b.x+c.x) + B2*(b.y+c.y))/2;

	double del = A1*B2-A2*B1;
	if(del==0) return point(0,0);

	double y = (A1*C2-A2*C1)/del;
	double x = -(B1*C2-B2*C1)/del;
	return point(x,y);
}

class TVTower 
{
public:
	int X;
	double ans;
	vector<point> points;
	
	void check(point center)
	{
		double temp=0;
		loop(i,X) MAX(temp, dist(center, points[i]));
		MIN(ans,temp);
	}

	
	double minRadius(vector<int> x, vector<int> y) 
	{
		ans=1e9;
		X = x.size();
		if(X==1) return 0;

		loop(i,X) points.push_back(point(x[i],y[i]));
		LOOP(i,0,X) LOOP(j,i+1,X)
		{
			check(point((x[i]+x[j])/2.0, (y[i]+y[j])/2.0));
			LOOP(k,j+1,X) check( centerOfCircle(points[i], points[j], points[k]) );
		}
		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 0, -1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, minRadius(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {299}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, minRadius(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5, 3, -4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 4, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.743416490252569; verify_case(2, Arg2, minRadius(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    TVTower ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
