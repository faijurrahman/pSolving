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

class Surveyor 
{

	public:
	int area(string direction, vector <int> length) 
	{
		int X = length.size();
		vector<point> poly;
		int x=0,y=0;
		loop(i,X)
		{
			switch(direction[i])
			{
				case 'E':
					x+=length[i];
					break;

				case 'W':
					x-=length[i];
					break;

				case 'N':
					y+=length[i];
					break;

				case 'S':
					y-=length[i];
					break;
			}
			poly.push_back(point(x,y));
		}

		return polygonArea(poly);
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "NWWSE"; int Arr1[] = {10,3,7,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; verify_case(0, Arg2, area(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "NESWNWSW"; int Arr1[] = {20,200,30,100,20,30,10,70}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4700; verify_case(1, Arg2, area(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    Surveyor ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
