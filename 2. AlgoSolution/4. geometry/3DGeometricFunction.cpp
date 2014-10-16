#include <vector>
#include <iostream>
using namespace std;

#define LOOP(i,s,n) for(int i=(s);i<(n);i++)
#define loop(i,n) for(int i=0;i<(n);i++)

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
		r=r0; theta=theta0; phi=phi0;
		x=r*cos(theta)*sin(phi);
		y=r*sin(theta)*sin(phi);
		z=r*cos(phi);
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

// Driver program to test above functions
int main()
{

    vector<point> points;
	points.push_back(point(0.72,2.28,5.01));//Point A
	points.push_back(point(2.66,4.71,0.56));//Point B
	points.push_back(point(5.75,3.50,4.50));//Point C
	points.push_back(point(3.63,2.52,3.24));//Point D
	points.push_back(point(4.25,1.60,1.26));//Point E

	cout<<"Distance Between A and B = "		<< dist(points[0],points[1])					<<endl;
	cout<<"Dot Product of points A,B,C = "	<< dotProd(points[0],points[1],points[2])		<<endl;
	cout<<"Cross Product of points A,B,C = "<< crossProd(points[0],points[1],points[2])		<<endl;
	cout<<"Distance of C from line AB = "	<< linePointDist(points[0],points[1],points[2])	<<endl;
		
    return 0;
}