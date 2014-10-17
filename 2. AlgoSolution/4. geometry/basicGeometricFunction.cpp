#include <vector>
#include <iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

struct point
{
    public: 
	double x,y;
	point(){}
	point(double a, double b){x=a;y=b;}
	void setXY(double a, double b){x=a;y=b;}
	double dist(point p){ return sqrt(pow(x-p.x,2)+pow(y-p.y,2));}
	bool operator <(const point &p) const{ return x<p.x || (x==p.x && y<p.y);}
};

struct line
{
    public: 
	bool ok;
	double A,B,C; //Equation: Ax+By=C
	//double m,mc; //Equation: y=mx+c => y=-(A/B)x + (C/B)
	//double a,b; //Equation: x/a + y/b = 1 => x/(C/A) + y/(C/B) = 1

	line(){}
	line(double A0, double B0, double C0){A=A0;B=B0;C=C0;}
	line(point pa, point pb){setPoint(pa,pb);}
	void setPoint(point pa, point pb){ A=pa.y-pb.y; B=pa.x-pb.x; C=A*pa.x+B*pa.y;}
	double dist(point pa){ return abs(A*pa.x+B*pa.y-C)/sqrt(A*A+B*B);}//Distance from a line to a point
	line parallelLine(point pa){ return line(A,B,A*pa.x+B*pa.y);}//Parallel line goes through point pa
	line perpendiculerLine(point pa){ return line(A,-B,A*pa.x-B*pa.y);}//Perpendiculer line goes through point pa
	point intersect(line ab)
	{
		ok=false;
		double x,y,det=A*ab.B-ab.A*B;
		if(det)
		{
			x=(ab.B*1-B*ab.C)/det;
			y=(A*ab.C-ab.A*C)/det;
			ok=true;
		}
		return point(x,y);
	}

};

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
	return abs(crossProd(a,b,c)/a.dist(b));
}

double polygonArea(vector<point> poly)
{
	double area = 0;
	int X = poly.size();	
	LOOP(i,1,X-1) area+=crossProd(poly[0],poly[i],poly[i+1]);
	return abs(area/2.0);
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
	if(del==0) return a.dist(point(0,0));

	double y = (A1*C2-A2*C1)/del;
	double x = -(B1*C2-B2*C1)/del;
	return a.dist(point(x,y));
}

//Check whether point c is inside the line segment ab
bool onSegment(point a, point b, point c)
{
    if (c.x<=max(a.x,b.x) && c.x>=min(a.x,b.x) && 
		c.y<=max(a.y,b.y) && c.y>=min(a.y,b.y))
			return true;
    return false;
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

	cout<<"Distance Between A and B = "		<< points[0].dist(points[1])					<<endl;
	cout<<"Dot Product of points A,B,C = "	<< dotProd(points[0],points[1],points[2])		<<endl;
	cout<<"Cross Product of points A,B,C = "<< crossProd(points[0],points[1],points[2])		<<endl;
	cout<<"Distance of C from line AB = "	<< linePointDist(points[0],points[1],points[2])	<<endl;
	cout<<"Area of Polygon ABCDEF = "		<< polygonArea(points)							<<endl;
	
	cout<<endl<<"Property of the circle goes thorough points a,b,c :"<<endl;
	cout<<"Radius = "<< radiousOfCircle(points[0],points[1],points[2])<<endl;
	
    return 0;
}