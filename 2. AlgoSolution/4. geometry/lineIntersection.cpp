// A C++ program to check if two given line segments intersect
#include <iostream>
using namespace std;

struct point
{
    int x,y;
	point(int a, int b){x=a;y=b;}
	void setXY(int a, int b){x=a;y=b;}
};
 
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
 
int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: -1; // clock or counterclock wise
}
 
bool doIntersect(point A, point B, point C, point D)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(A, B, C);
    int o2 = orientation(A, B, D);
    int o3 = orientation(C, D, A);
    int o4 = orientation(C, D, B);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;

 	//All points are coliniar, means there are infinite number of common points
	//if(o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0)

    // Special Cases
    if (o1 == 0 && onSegment(A, C, B)) return true;
    if (o2 == 0 && onSegment(A, D, B)) return true;
    if (o3 == 0 && onSegment(C, A, D)) return true;
    if (o4 == 0 && onSegment(C, B, D)) return true;
 
    return false; 
}

// Driver program to test above functions
int main()
{
    struct point p1(1, 1), q1(10, 1);
	struct point p2(1, 2), q2(10, 2);
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
 
    p1.setXY(10, 0), q1.setXY(0, 10);
    p2.setXY(0, 0), q2.setXY(10, 10);
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
 
    p1.setXY(-5, -5), q1.setXY(0, 0);
    p2.setXY(1, 1), q2.setXY(10, 10);
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
 
    return 0;
}