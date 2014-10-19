#include<vector>
#include<algorithm>
#include<iostream>
#include <sstream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)
#define All(c) (c).begin(),(c).end()

struct point
{
    public: double x,y;	
	point(double a, double b){x=a;y=b;} point(){}
	void setPoint(double a, double b){x=a;y=b;}
	double dist(point p){ return sqrt(pow(x-p.x,2)+pow(y-p.y,2));}
	double dot(point A, point B){point OA(A.x-x,A.y-y), OB(B.x-x,B.y-y); return(OA.x*OB.x+OA.y*OB.y);}
	double cross(point A, point B){point OA(A.x-x,A.y-y), OB(B.x-x,B.y-y); return(OA.x*OB.y - OA.y*OB.x);}
	bool onSegment(point A, point B){bool ok=(x<=max(A.x,B.x) && x>=min(A.x,B.x) && y<=max(A.y,B.y) && y>=min(A.y,B.y)); return ok?1:0;}
	bool operator <(const point &p) const{ return x<p.x || (x==p.x && y<p.y);}
};

//Line equations
//double A,B,C; //Equation: Ax+By=C
//double m,mc; //Equation: y=mx+c => y=-(A/B)x + (C/B)
//double a,b; //Equation: x/a + y/b = 1 => x/(C/A) + y/(C/B) = 1
struct line
{
    public: double A,B,C; bool ok;
	line(double A0, double B0, double C0){A=A0;B=B0;C=C0;} line(){}
	line(point pa, point pb){setPoint(pa,pb);}
	void setPoint(point pa, point pb){ A=pa.y-pb.y; B=pa.x-pb.x; C=A*pa.x+B*pa.y;}
	double dist(point pa){ return abs(A*pa.x+B*pa.y-C)/sqrt(A*A+B*B);}//Distance from a line to a point
	line parallelLine(point pa){ return line(A,B,A*pa.x+B*pa.y);}//Parallel line goes through point pa
	line perpendiculerLine(point pa){ return line(-B,A,-B*pa.x+A*pa.y);}//Perpendiculer line goes through point pa
	point intersect(line L){double D=A*L.B-L.A*B;ok=D?false:true; return D?point((L.B*C-B*L.C)/D, (A*L.C-L.A*C)/D):point(0,0);}
};

struct triangle
{
    public: point A,B,C;
	triangle(point pa, point pb, point pc){setPoint(pa,pb,pc);} triangle(){}
	void setPoint(point pa, point pb, point pc){A=pa; B=pb; C=pc;}
	double area(){ return abs(A.cross(B,C)/2);}
	point side(){ return point(A.dist(B), abs(A.cross(B,C)/A.dist(B)));}
};

struct rectangle
{
    public: point A,B,C;
	rectangle(point pa, point pb, point pc){setPoint(pa,pb,pc);} rectangle(){}
	void setPoint(point pa, point pb, point pc){A=pa; B=pb; C=pc;}
	double area(){ return B.dist(A)*B.dist(C);}
	double diagonal(){ return sqrt(pow(B.dist(A),2)+pow(B.dist(C),2));}
	point side(){ return point(B.dist(A),B.dist(C));}
};

struct circle
{
    public: point center; double radius;
	circle(point cent, double radi){center=cent;radius=radi;} circle(){}
	double area(){ return radius*radius*3.14159265358979;}	
	void setPoint(point cent, double radi){center=cent;radius=radi;}
	void setPoint(point a, point b, point c)
	{
		double A1=a.x-b.x, A2=b.x-c.x;
		double B1=a.y-b.y, B2=b.y-c.y;
		double C1=(A1*(a.x+b.x)+B1*(a.y+b.y))/2;
		double C2=(A2*(b.x+c.x)+B2*(b.y+c.y))/2;
		double del=A1*B2-A2*B1;
		if(del!=0){ center.y=(A1*C2-A2*C1)/del; center.x = -(B1*C2-B2*C1)/del; radius=center.dist(a);}
	}
};

struct polygon
{
    public: vector<point> points;
	polygon(vector<point> pnts){points=pnts;} polygon(){}	
	void setPoint(vector<point> pnts){points=pnts;}
	double area(){double area=0; LOOP(i,1,points.size()-1) area+=points[0].cross(points[i],points[i+1]); return abs(area/2.0);}
	vector<point> convexHull()
	{
		int X=points.size(), cnt=0;	vector<point> hull(2*X); sort(All(points));		
		loop(i,X){while(cnt>=2 && hull[cnt-2].cross(hull[cnt-1],points[i])<=0) cnt--; hull[cnt++]=points[i];}
		for(int i=X-2,t=cnt+1; i>=0; i--){while(cnt>=t && hull[cnt-2].cross(hull[cnt-1],points[i])<=0) cnt--; hull[cnt++]=points[i];}
		hull.resize(cnt);
		return hull;
	}
};

// Driver program to test above functions
int main()
{

    vector<point> points;
	points.push_back(point(0,0));	//Point A
	points.push_back(point(10,0));	//Point B
	points.push_back(point(10,5));	//Point C
	points.push_back(point(0,5));	//Point D
	points.push_back(point(4,3));	//Point E
	points.push_back(point(5,0));	//Point F

	//**********************************************************************************
	cout<<"Point related operations:"<<endl;
	cout<<"Distance Between A and B = "<< points[0].dist(points[1])<<endl;
	cout<<"Dot Product of points A,B,C = "<< points[0].dot(points[1],points[2])<<endl;
	cout<<"Cross Product of points A,B,C = "<< points[0].cross(points[1],points[2])<<endl;
	string str=points[0].onSegment(points[1],points[2])?"is ":"is not ";
	cout<<"Point A "<<str<<"on the line segment BC"<<endl<<endl;

	//**********************************************************************************
	cout<<"Line related operations:"<<endl;
	line AB(points[0],points[1]);
	cout<<"Equation of line AB "<<AB.A<<"x + "<<AB.B<<"y = "<<AB.C<<endl;

	line ABparaC=AB.parallelLine(points[2]);
	cout<<"Parallel line of AB which goes though C is "<<ABparaC.A<<"x + "<<ABparaC.B<<"y = "<<ABparaC.C<<endl;

	line ABperC=AB.perpendiculerLine(points[3]);
	cout<<"Perpendiculer line of AB which goes though D is "<<ABperC.A<<"x + "<<ABperC.B<<"y = "<<ABperC.C<<endl;

	point inrsP=ABperC.intersect(ABparaC);
	cout<<"Intersetion point of above two lines is ("<<inrsP.x<<","<<inrsP.y<<")"<<endl;
	cout<<"Distance of E from line AB = "<< AB.dist(points[4])<<endl<<endl;

	//**********************************************************************************
	cout<<"Triangle related operations:"<<endl;
	triangle triangl(points[0],points[1],points[2]);
	cout<<"Area of triangle ABC = "<<triangl.area()<<endl;
	cout<<"Base = "<<triangl.side().x<<" and height = "<<triangl.side().y<<endl<<endl;

	//**********************************************************************************
	cout<<"Rectangle related operations:"<<endl;
	rectangle rect(points[0],points[1],points[2]);
	cout<<"Area of triangle ABCD = "<<rect.area()<<endl;
	cout<<"Lenght = "<<rect.side().x<<", weight = "<<rect.side().y<<" diagonal = "<<rect.diagonal()<<endl<<endl;
	
	//**********************************************************************************
	cout<<"Circle related operations:"<<endl;
	circle circ; circ.setPoint(points[0],points[1],points[2]);
	cout<<"Property of the circle goes thorough points A,B,C :"<<endl;
	cout<<"Center = ("<<circ.center.x<<","<<circ.center.y<<")"<<endl;
	cout<<"Radius = "<<circ.radius<<endl;
	cout<<"Area = "<<circ.area()<<endl<<endl;

	//**********************************************************************************
	cout<<"Polygon related operations:"<<endl;
	polygon poly(points);
	cout<<"Area of Polygon ABCDEF = "<< poly.area()<<endl;
	cout<<"Number of points of covex hull obtain from ABCDEF is "<< poly.convexHull().size()<<endl<<endl;

    return 0;
}