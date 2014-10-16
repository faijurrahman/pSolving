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
#define PI 3.1415926535897
#define DIFF 1e-10

struct point
{
    public: 
	double x,y,z,r,theta,phi;
	point(){x=y=z=r=theta=phi=0;}
	point(double x0, double y0, double z0){setCartesian(x0,y0,z0);}

	void setCartesian(double x0, double y0, double z0)
	{
		x=x0; y=y0; z=z0;
		r=sqrt(x*x+y*y+z*z);
		theta=atan(y/x);
		phi=atan(sqrt(x*x+y*y)/z);
	}

	void setSpherical(double r0, double theta0, double phi0)
	{
		r=r0; theta=PI*theta0/180; phi=PI*phi0/180;
		x=r*cos(theta)*cos(phi);
		y=r*sin(theta)*cos(phi);
		z=r*sin(phi);
	}

	bool operator <(const point &p) const
	{
		return x<p.x || (x==p.x && y<p.y) || (x==p.x && y==p.y && z<p.z);
	}
};

//compute the distance from a to b
double dist(point a, point b)
{
	double i = a.x-b.x;
	double j = a.y-b.y;
	double k = a.z-b.z;
	return sqrt(i*i+j*j+k*k);
}

//compute the dot product ab · bc
double dotProd(point a, point b, point c)
{
	point ab(b.x-a.x, b.y-a.y, b.z-a.z);
	point bc(c.x-b.x, c.y-b.y, c.z-a.z);
	return(ab.x*bc.x + ab.y*bc.y + ab.z*bc.z);
}

//compute the cross product ab x ac
double crossProd(point a, point b, point c)
{
	point ab(b.x-a.x, b.y-a.y, b.z-a.z);
	point ac(c.x-a.x, c.y-a.y, c.z-a.z);	
	double i = ab.y*ac.z - ab.z*ac.y;
	double j = ab.z*ac.x - ab.x*ac.z;
	double k = ab.x*ac.y - ab.y*ac.x;
	return sqrt(i*i+j*j+k*k);
}

//compute the distance from ab to c
double linePointDist(point a, point b, point c)
{
	return abs(crossProd(a,b,c)/dist(a,b));
}

double minDist(point high, point low)
{
	double hi, mi, lo;
	point o(0,0,0);

	if(dist(low,o)>dist(high,o))
	{
		point temp=high; 
		high=low; 
		low=temp;
	}

	hi=dist(high,o);
	lo=dist(low,o);
	while((hi-lo)>DIFF)
	{
		point mid( (high.x+low.x)/2, (high.y+low.y)/2, (high.z+low.z)/2 );
		mi=dist(mid,o);

		if(hi>=mi) hi=mi, high=mid;
		else lo=mi, low=mid;
	}
	return lo;
}

class Satellites 
{

	public:
	vector<int> detectable(vector <string> rockets, vector <string> satellites) 
	{
		vector<int> ans;
		int X = rockets.size(); 
		int Y = satellites.size(); 
		
		vector<point> roc, sat;
		roc.resize(X); sat.resize(Y); 
		
		stringstream ss;
		double alt,lat,lon;

		loop(i,X) 
		{
			ss.clear();
			ss.str(rockets[i]);
			ss>>lat>>lon;
			roc[i].setSpherical(6400,lon,lat);
		}

		loop(i,Y) 
		{
			ss.clear();
			ss.str(satellites[i]);
			ss>>lat>>lon>>alt;
			sat[i].setSpherical(6400+alt,lon,lat);
		}

		loop(i,X) 
		{
			int cnt=0;
			loop(j,Y) if(minDist(roc[i],sat[j])>=6400 ) cnt++;
			if(cnt>=3) ans.push_back(i);
		}

		return ans;
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"+0000.000 -0000.000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "+0000.000 -0000.000 +0200.000",
  "+0000.000 -0000.000 +0400.000",
  "+0000.000 -0000.000 +1200.000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, detectable(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"-0050.000 +0045.000","+0040.000 -0135.000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"+0090.000 +0000.000 +1200.000",
 "-0090.000 +0000.000 +1200.000",
 "+0000.000 +0000.000 +1200.000",
 "+0000.000 -0090.000 +1200.000",
 "+0000.000 +0180.000 +1200.000",
 "-0000.000 -0045.000 +1200.000",
 "-0000.000 -0135.000 +1000.000",
 "-0011.000 -0136.000 +1086.828"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, detectable(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"+0037.431 -0143.361",
 "+0037.443 -0143.375",
 "+0037.413 -0143.364"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"+0037.470 -0143.316 +0513.143",
 "+0037.443 -0143.388 +0342.159",
 "+0037.434 -0143.361 +1034.123"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  1,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, detectable(Arg0, Arg1)); }

// END CUT HERE
 

};

// BEGIN CUT HERE 
int main()
{
    Satellites ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE 
    
