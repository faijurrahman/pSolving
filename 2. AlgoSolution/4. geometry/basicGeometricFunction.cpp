#include <vector>
#include <iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

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

//find radious of the circle which goes though points a, b, c
double radiousOfCircle(point a, point b, point c)
{
	double A1 = a.x-b.x;
	double A2 = b.x-c.x;
	double B1 = a.y-b.y;
	double B2 = b.y-c.y;
	double C1 = (A1*(a.x+b.x) + B1*(a.y+b.y))/2;
	double C2 = (A2*(b.x+c.x) + B2*(b.y+c.y))/2;

	double del = A1*B2-A2*B1;
	if(del==0) return dist(a,point(0,0));

	double y = (A1*C2-A2*C1)/del;
	double x = -(B1*C2-B2*C1)/del;
	return dist(a,point(x,y));
}

// Driver program to test above functions
int main()
{

    vector<point> points;
	points.push_back(point(0.72,2.28));//Point A
	points.push_back(point(2.66,4.71));//Point B
	points.push_back(point(5,3.5));    //Point C
	points.push_back(point(3.63,2.52));//Point D
	points.push_back(point(4,1.6));    //Point E
	points.push_back(point(1.9,1));    //Point F

	cout<<"Distance Between A and B = "		<< dist(points[0],points[1])					<<endl;
	cout<<"Dot Product of points A,B,C = "	<< dotProd(points[0],points[1],points[2])		<<endl;
	cout<<"Cross Product of points A,B,C = "<< crossProd(points[0],points[1],points[2])		<<endl;
	cout<<"Distance of C from line AB = "	<< linePointDist(points[0],points[1],points[2])	<<endl;
	cout<<"Area of Polygon ABCDEF = "		<< polygonArea(points)							<<endl;
	
	cout<<endl<<"Property of the circle goes thorough points a,b,c :"<<endl;
	point center = centerOfCircle(points[0],points[1],points[2]);
	cout<<"Center = (" << center.x << ", " << center.y << ")" <<endl;
	cout<<"Radius = "<< radiousOfCircle(points[0],points[1],points[2])<<endl;
	
    return 0;
}