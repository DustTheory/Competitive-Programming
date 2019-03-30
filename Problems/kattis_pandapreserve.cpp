#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

#define EPS 1e-6

#define YLINE 1<<29
#define XLINE 0

struct Point{
	double x, y;
	Point(double _x, double _y){
		x = _x;
		y = _y;
	}
	Point(){}
	bool operator<(const Point &b) const {
		return abs(x-b.x) < EPS ? (y < b.y) : x < b.x;
	}
};

struct LineSg{
	Point a, b;
	LineSg(Point _a, Point _b){
		if(a.x < b.x + EPS)
			swap(a, b);
		else if(fabs(a.x - b.x) < EPS && a.y < b.y + EPS)
			swap(a, b);
		a = _a;
		b = _b;
	}
	LineSg(){}
	double slope(){
		if(fabs(a.x-b.x) < EPS) // Line is paralel with y axis
			return YLINE;
		else if(fabs(a.y - b.y) < EPS) // Line is paralel with x axis
			return XLINE;
		else
			return (a.y - b.y)/(a.x - b.x);	
	}
	double intercept(){
		return a.y - a.x*slope();	
	}
	bool includes_point(Point &p){
		double k = slope();
		double n = intercept();
		if(k == XLINE)
			return abs(p.y - a.y) < EPS && p.x >= a.x - EPS && p.x <= b.x + EPS;
		double miny = min(a.y, b.y);
		double maxy = max(a.y, b.y);
		if(k == YLINE)
			return abs(p.x - a.x) < EPS && p.y >= miny - EPS && p.y <= maxy + EPS;		
		return abs(p.y - (p.x*k + n)) < EPS && p.y >= miny - EPS && p.y <= maxy + EPS && p.x >= a.x - EPS && p.x <= b.x + EPS;
	}
};

struct Circle{
	Point center;
	double radius;
	Circle(Point _center, double _radius){
		center = _center;
		radius = _radius;
	}
	Circle(double _x, double _y, double _radius){
		center = Point(_x, _y);
		radius = _radius;
	}
	Circle(){}
};

struct Triangle{
	Point A, B, C;
	LineSg side_a, side_b, side_c;
	Triangle(Point _A, Point _B, Point _C){
		A = _A;
		B = _B;
		C = _C;
		side_a = LineSg(C, B);
		side_b = LineSg(A, C);
		side_c = LineSg(A, B);
	}
};

double dist_nosqrt(double x1, double y1, double x2, double y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

double dist(double x1, double y1, double x2, double y2){
	return sqrt(dist_nosqrt(x1, y1, x2, y2));
}

double dist(Point a, Point b){
	return dist(a.x, a.y, b.x, b.y);
}

pair<Point, Point> circle_circle_cross(Circle &c1, Circle &c2){
	// Oof this gonna be hard af
	//
	// Line segment between	centers of two circles
	// First handle edgecases: lines paralel with the x and y axis
	double q;
	if(fabs(c1.center.x-c2.center.x) < EPS) // Line is paralel with y axis
		q = YLINE;
	else if(fabs(c1.center.y - c2.center.y) < EPS) // Line is paralel with x axis
		q = XLINE;
	else
		q = (c1.center.y - c2.center.y)/(c1.center.x - c2.center.x);
	
	// Now get the slope of the line perpendicular to it
	if(q == YLINE)
		q = XLINE;
	else if(q == XLINE)
		q = YLINE;
	else
		q = -1/q;
		
	// Find their intersection (center of the first line)
	double x1 = (c1.center.x + c2.center.x)/2.0;
	double y1 = (c1.center.y + c2.center.y)/2.0;
	
	// we need a function with form y = qx + n; We need to find n; n = y1-q*x1;
	double n = y1 - q*x1;

	//     /|
	//  r / |
	//   /  |d
	//  /   |
	// /____|
	//   a
	// r is circle radius
	// a is dist from circle center to point (x1, y1)
	// we need to find d using Pythagora's theorem
	// first find a*a
	double a_squared = dist_nosqrt(x1, y1, c1.center.x, c1.center.y);
	double r = c1.radius;
	double d = sqrt(r*r - a_squared);	
	// The intersections of these two circles are points that fit the function y = qx+n
	// that are exactly d distance from point (x1, y1)

	// atan(q) gives the angle of the line with the x axis in radians
	// Of course we handle the two danmn edgecases
	double angle;
	if(q == YLINE)
		angle = M_PI/4;
	else if(q == XLINE)
		angle = 0;
	else
		angle = atan(q);
	
	// We'll need sin(angle) and cos(angle)
	double sn, cs;
	if(q == YLINE || q == XLINE) // just ignore these
		sn = cs = 0;
	else{
		sn = sin(angle);
		cs = cos(angle);
	}

	// Finally let's generate the points
	// Edgecases smh
	Point point1, point2;
	if(q == XLINE){
		point1 = Point(x1+d, y1);
		point2 = Point(x1-d, y1);
	}else if(q == YLINE){ 
		point1 = Point(x1, y1+d);
		point2 = Point(x1, y1-d);
	}else{
		// Reel maths yee
		point1 = Point(x1 + cs*d, y1 + sn*d);
		point2 = Point(x1 - cs*d, y1 - sn*d);
	}

	return {point1, point2};

}

vector<Point> circle_linesg_cross(Circle &c, LineSg &l){
	// Solution: project center of circle onto the line segment
	// Then find dist between projected point and the center
	// Use Pythagora's theorem get distance d between the projected point and our (unknown) intersection points
	// Our intersection points are on the line segment and are at d distance from our projected point
	// LESGO CODE THIS!
	
	// ########## PROJECTION PART #############
	double px, py; // Projected point coordinates
	double q1; // slope of the line segment
	if(fabs(l.a.x - l.b.x) < EPS)
		q1 = YLINE;
	else if(fabs(l.a.y - l.b.y) < EPS)
		q1 = XLINE;
	else
		q1 = (l.a.y-l.b.y)/(l.a.x-l.b.x);
	double n1;
	if(q1 != XLINE && q1 != YLINE)
		n1 = l.a.y - q1*l.a.x;
	
	// Now get slope of line perpendicular to line segment
	double q2;
	if(q1 == XLINE)
		q2 = YLINE;
	else if(q1 == YLINE)
		q2 = XLINE;
	else
		q2 = -1/q1;


	double n2;
	if(q2 != XLINE && q2 != YLINE)
		n2 = c.center.y - q2*c.center.x;

	// Intersection to get projected point
	if(q1 == XLINE){
		py = l.a.y;
		px = c.center.x;
	}else if(q1 == YLINE){
		px = l.a.x;
		py = c.center.y;
	}else{
		px = (n2-n1)/(q1-q2);
		py = q1*px + n1;
	}

	// Dist from circle center to projected point
	double d = dist_nosqrt(px, py, c.center.x, c.center.y);
	double r = c.radius; // circle radius
	// Check if line and circle cross
	if(r*r - d > EPS){ // They do
		double a = sqrt(r*r - d);
		// atan(q) gives the angle of the line with the x axis in radians
		// Of course we handle the two danmn edgecases
		double angle;
		if(q1 == YLINE)
			angle = M_PI/4;
		else if(q1 == XLINE)
			angle = 0;
		else
			angle = atan(q1);
		// We'll need sin(angle) and cos(angle)
		double sn, cs;
		if(q1 == YLINE || q1 == XLINE) // just ignore these
			sn = cs = 0;
		else{
			sn = sin(angle);
			cs = cos(angle);
		}	
		// Now we get our intersections
		Point point1, point2;
		if(q1 == XLINE){
			point1 = Point(px+a, py);
			point2 = Point(px-a, py);
		}else if(q1 == YLINE){ 
			point1 = Point(px, py+a);
			point2 = Point(px, py-a);
		}else{
			// Reel maths yee
			point1 = Point(px + cs*a, py + sn*a);
			point2 = Point(px - cs*a, py - sn*a);
		}
		vector<Point> intersections;
		// If points are within the circles radius and on the line segment
		if(dist(point1, c.center) < c.radius+EPS && l.includes_point(point1))
			intersections.push_back(point1);
		if(dist(point2, c.center) < c.radius+EPS && l.includes_point(point2))
			intersections.push_back(point2);
		return intersections;
	}
	return vector<Point>();
}


vector<Point> circle_triang_cross(Circle &c, Triangle &t){
	vector<Point> res;
	vector<Point> side_a_cross = circle_linesg_cross(c, t.side_a);
	vector<Point> side_b_cross = circle_linesg_cross(c, t.side_b);
	vector<Point> side_c_cross = circle_linesg_cross(c, t.side_c);
	res.insert(res.end(), side_a_cross.begin(), side_a_cross.end());
	res.insert(res.end(), side_b_cross.begin(), side_b_cross.end());
	res.insert(res.end(), side_c_cross.begin(), side_c_cross.end());
	return res;
}

bool triangle_covered(Triangle &t, vector<Circle> &circles){
	list<Point> tocheck;
	tocheck.push_back(t.A);
	tocheck.push_back(t.B);
	tocheck.push_back(t.C);
	for(int i = 0; i < circles.size(); i++){
		Circle c = circles[i];
		for(int j = i; j < circles.size(); j++){
			for (auto it = tocheck.begin(); it != tocheck.end();)
				if(dist(*it, circles[j].center) < circles[j].radius + EPS)
					it = tocheck.erase(it);
				else 
			    		++it;
		}
		vector<Point> crs = circle_triang_cross(c, t);
		for(Point p : crs){
			tocheck.push_back(p);
			cout << p.x << ' ' << p.y << endl;
		}
	}
	for(int j = 0; j <= circles.size(); j++){
		for (auto it = tocheck.begin(); it != tocheck.end();)
			if(dist(*it, circles[j].center) < circles[j].radius + EPS)
				it = tocheck.erase(it);
			else 
				++it;
}
	return tocheck.empty();
}

int main(){
	
	//Circle c1 = Circle(2, 2, 1);
	//Circle c2 = Circle(4, 2, 1);

	//pair<Point, Point> i = circle_circle_cross(c1, c2);

	//cout << i.first.x << ' ' << i.first.y << endl;
 	//cout << i.second.x << ' ' << i.second.y << endl;
	
	//Circle c3 = Circle(2, 2, 1);
	//LineSg l1 = LineSg(Point(1, 1), Point(4, 2.5));
	//vector<Point> i2 = circle_linesg_cross(c3, l1);
	//for(Point p : i2){
	//	cout << p.x << ' ' << p.y << endl;
	//}

	//Circle c4 = Circle(2, 2, 1);
	//Triangle tg1 = Triangle(Point(2, 4), Point(3, 1), Point(2, 2));
	//vector<Point> i3 = circle_triang_cross(c4, tg1);
	//for(Point p : i3){
	//	cout << p.x << ' ' << p.y << endl;
	//}

	vector<Circle> cv;
       	cv.push_back(Circle(0, 0, 1));
        cv.push_back(Circle(5, 5, 1));
       	cv.push_back(Circle(2, 2, 1));
	Triangle tg2 = Triangle(Point(0, 0), Point(5, 5), Point(2, 2));
	cout << triangle_covered(tg2, cv) << endl;
}
