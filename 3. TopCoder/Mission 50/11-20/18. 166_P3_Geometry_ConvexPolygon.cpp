//C Header
#include<set>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include <sstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define MAX(mVal, oVal) (mVal) = max((mVal),(oVal))
#define MIN(mVal, oVal) (mVal) = min((mVal),(oVal))
#define All(c) (c).begin(),(c).end()

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

//compute the dot product ab · bc
double dotProd(point a, point b, point c)
{
	point ab(b.x-a.x, b.y-a.y);
	point bc(c.x-b.x, c.y-b.y);
	return(ab.x*bc.x + ab.y*bc.y);
}

//compute the cross product ab x ac
double crossProd(point a, point b, point c)
{
	point ab(b.x-a.x, b.y-a.y);
	point ac(c.x-a.x, c.y-a.y);
	return(ab.x*ac.y - ab.y*ac.x);
}

//compute the distance from ab to c
double linePointDist(point a, point b, point c)
{
	return abs(crossProd(a,b,c)/dist(a,b));
}

double polygonArea(vector<point> poly)
{
	double area = 0;
	int X = poly.size();	
	LOOP(i,1,X-1) area+=crossProd(poly[0],poly[i],poly[i+1]);
	return abs(area/2.0);
}

class ConvexPolygon 
{

	public:
	double findArea(vector <int> x, vector <int> y) 
	{
		int X = x.size();		
		vector<point> poly;
		loop(i,X) poly.push_back(point(x[i],y[i]));
		return polygonArea(poly);
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(0, Arg2, findArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-10000,-10000,10000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,-10000,-10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.0E8; verify_case(1, Arg2, findArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,80,30,-30,-80,-100,-80,-30,30,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,58,95,95,58,0,-58,-95,-95,-58}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 29020.0; verify_case(2, Arg2, findArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1646,-9172,-9830,-9802,-9749,-9474,-8668,-6832,120,8380,9338,9307,8042}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-9998,-8619,-7863,3976,4541,5975,8127,9500,9612,8734,5216,-9042,-9689}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.55115104E8; verify_case(3, Arg2, findArea(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-6010,-7937,-8782,-9506,-9654,-9852,-9854,-9998,-9999,-9996,-9901,-9811,
-9444,-8798,-8580,-2085,6842,8339,9827,9946,9993,9959,9940,9855,9657,
8504,8262,7552,6326,5537,4723}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-9976,-9947,-9873,-9739,-9654,-8501,-8475,-5009,475,4926,7078,8673,9417,
9785,9820,9974,9986,9979,9862,9211,-5070,-6599,-7121,-8624,-8912,-9710,
-9766,-9863,-9914,-9941,-9962}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.939960635E8; verify_case(4, Arg2, findArea(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    ConvexPolygon ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
